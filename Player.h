//Methods

void play();
void pause();
void stop();
void setSong(const char * new_song);

//Variables

char * song = NULL; //Select song filename

bool display = false; //Whether we are using the display
bool paused = false; //Whether we are paused
bool playing = false; //Whether a song is playing

unsigned short speed = 100; //Song speed

TFileHandle file; //Song file
TFileIOResult result; //IO result
int size; //File size
int fileptr; //Current byte in file

//Song functions

void tone(unsigned short frequency, unsigned short duration) {
	while(paused); //If paused, wait before tone
	PlayTone(frequency, duration * 100 / speed); //Speed is percentage out of 100
}

void wait(unsigned short cs) {
	while(paused);
	wait10Msec(cs * 100 / speed);
}

void write(int line, const char * str) {
	if(!display) //Only actually write lyrics if we are using the display
		return;

	nxtDisplayTextLine(line, str);
}

void clear() {
	if(!display) //Only actually clear if we are using the display
		return;

	nxtDisplayTextLine(1, "                ");
	nxtDisplayTextLine(2, "                ");
	nxtDisplayTextLine(3, "                ");
	nxtDisplayTextLine(4, "                ");
	nxtDisplayTextLine(5, "                ");
	nxtDisplayTextLine(6, "                ");
}

//Miscellaneous functions

task control() {
	while(true) {
		nxtDisplayTextLine(7, "[]volume: %d  ", nVolume);

		while(nNxtButtonPressed != 3) { //While center button is not pressed
			wait10Msec(20);

			if(nNxtButtonPressed == 2 && nVolume > 0) { //Decrease volume
				nVolume -= 1;
				nxtDisplayTextLine(7, "[]volume: %d  ", nVolume);
			}

			if(nNxtButtonPressed == 1 && nVolume < 4) { //Increase volume
				nVolume += 1;
				nxtDisplayTextLine(7, "[]volume: %d  ", nVolume);
			}
		}
		while(nNxtButtonPressed == 3); //Wait for center button to be unpressed

		nxtDisplayTextLine(7, "[]speed: %d ", speed);

		while(nNxtButtonPressed != 3) {
			wait10Msec(20);

			if(nNxtButtonPressed == 2 && speed > 10) { //Decrease speed
				speed -= 10;
				nxtDisplayTextLine(7, "[]speed: %d ", speed);
			}

			if(nNxtButtonPressed == 1 && speed < 200) { //Increase speed
				speed += 10;
				nxtDisplayTextLine(7, "[]speed: %d ", speed);
			}
		}
		while(nNxtButtonPressed == 3);
	}
}

void getLine(char * buffer, int buffer_size) {
	int i = 0; //Buffer count

	while(fileptr < size) { //While we are not at the end of the file
		char c;
		ReadByte(file, result, c); //Read a byte
		fileptr++; //Increase the read byte number for file
		writeDebugStream("%c\n", c);
		if(result != ioRsltSuccess || c == '\n') //And if we hit a newline, break
			break;

		if(i < buffer_size) { //If we haven't hit the buffer size, add the character and keep going; if buffer filled, keep going so fileptr is always at a newline
			buffer[i] = c;
			i++; //Increase buffer byte number
		}
	}

	buffer[i] = '\0';
}

task player() {
	while(fileptr < size) { //Go until end of file
		char line[64]; //Line buffer
		getLine(line, 63);

		if(line[0] == '#' || line[0] == '\0') //Skip the whole line if it is a comment or empty
			continue;

		char cmd[64]; //Music command
		char param[64]; //Command parameters
		sscanf(line, "%s %[^\n]", cmd, param); //Scan for a command then parameters to the end of the string

		if(strcmp(cmd, "tone") == 0) { //Play a tone and wait for it to finish
			int freq, hold, time = 0; //time = 0 for backwards compatibility with songs that do not have it
			sscanf(param, "%hd %hd %hd", &freq, &hold, &time); //Get the frequency and the time to play it out of a total wait time
			tone(freq, hold);
			wait(time);
		}
		else if(strcmp(cmd, "wait") == 0) { //Rest for a time
			int time;
			sscanf(param, "%hd", &time); //Get the rest time
			wait(time);
		}
		else if(strcmp(cmd, "write") == 0) { //Write lyrics onto the display
			int line;
			char str[64];
			sscanf(param, "%hd \"%[^\"]", &line, str); //Get the line number and lyric
			write(line, str);
		}
		else if(strcmp(cmd, "clear") == 0) { //Clear the lyrics
			clear();
		}
	}

	stop(); //Stop the song after it is done
}

//Control functions

void play() {
	if(song == NULL) //Make sure a song is selected
		return;

	if(playing) //Stop a currently running song
		stop();

	OpenRead(file, result, song, size); //Open it for reading
	fileptr = 0;

	if(result != ioRsltSuccess) //And make sure it opens
		return;

	char name[24]; //Get the song title
	getLine(name, 23);

	playing = true; //Start playing

	if(display) { //And if using the display, clear it, display controls, and display the song name
		clear();
		StartTask(control);
		nxtDisplayCenteredTextLine(3, "Playing:");
		nxtDisplayCenteredTextLine(4, name);
	}

	StartTask(player); //Start the parser
}

void pause() {
	if(song == NULL)
		return;

	paused = !paused; //Flip the paused flag
}

void stop() {
	if(song == NULL)
		return;

	playing = false; //Stop playing

	StopTask(player); //Stop the parser

	if(display) { //And remove controls and clear screen if done
		StopTask(control);
		wait10Msec(20);
		clear();
	}

	Close(file, result); //And close the file
}

void setSong(const char * new_song) {
	if(playing) //Stop a currently running song
		stop();

	song = new_song; //And change the current song filename
}
