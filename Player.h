//Methods

void play();
void pause();
void stop();
void setSong(const char * new_song);

//Variables

char * song = NULL;

bool display = false;
bool paused = false;
bool playing = false;

unsigned short speed = 100;

TFileHandle file;
TFileIOResult result;
int size;

//Song functions

void tone(unsigned short frequency, unsigned short duration) {
	while(paused);
	PlayTone(frequency, duration * 100 / speed);
}

void wait(unsigned short cs) {
	wait10Msec(cs * 100 / speed);
}

void write(int line, const char * str) {
	if(!display)
		return;

	nxtDisplayTextLine(line, str);
}

void clear() {
	if(!display)
		return;

	nxtDisplayTextLine(1, "                ");
	nxtDisplayTextLine(2, "                ");
	nxtDisplayTextLine(3, "                ");
	nxtDisplayTextLine(4, "                ");
	nxtDisplayTextLine(5, "                ");
	nxtDisplayTextLine(6, "                ");
}

//Control functions

task control() {
	while(true) {
		nxtDisplayTextLine(7, "[]speed: %d ", speed);

		while(nNxtButtonPressed != 3) {
			wait10Msec(20);

			if(nNxtButtonPressed == 2 && speed > 10) {
				speed -= 10;
				nxtDisplayTextLine(7, "[]speed: %d ", speed);
			}

			if(nNxtButtonPressed == 1 && speed < 200) {
				speed += 10;
				nxtDisplayTextLine(7, "[]speed: %d ", speed);
			}
		}
		while(nNxtButtonPressed == 3);

		nxtDisplayTextLine(7, "[]volume: %d  ", nVolume);

		while(nNxtButtonPressed != 3) {
			wait10Msec(20);

			if(nNxtButtonPressed == 2 && nVolume > 0) {
				nVolume -= 1;
				nxtDisplayTextLine(7, "[]volume: %d  ", nVolume);
			}

			if(nNxtButtonPressed == 1 && nVolume < 4) {
				nVolume += 1;
				nxtDisplayTextLine(7, "[]volume: %d  ", nVolume);
			}
		}
		while(nNxtButtonPressed == 3);
	}
}

task player() {
	int i = 0;
	while(i < size) {
		char data[64];
		char * ptr = data;
		do {
			ReadByte(file, result, *ptr);
			i++;
			ptr++;
		}
		while(result == ioRsltSuccess && *ptr != '\n');

		if(data[0] == '#')
			continue;

		char cmd[64];
		char param[64];
		sscanf(data, "%s %s\n", cmd, param);

		if(strcmp(cmd, "tone") == 0) {
			int freq, time;
			sscanf(param, "%hd %hd", &freq, &time);
			tone(freq, time);
		}
		else if(strcmp(cmd, "wait") == 0) {
			int time;
			sscanf(param, "%hd", &time);
			wait(time);
		}
		else if(strcmp(cmd, "write") == 0) {
			int line;
			char str[64];
			sscanf(param, "%hd \"%s\"", &line, str);
			write(line, str);
		}
		else if(strcmp(cmd, "clear") == 0) {
			clear();
		}
	}

	stop();
}

void play() {
	if(song == NULL)
		return;

	if(playing)
		stop();

	OpenRead(file, result, song, size);

	if(result != ioRsltSuccess)
		return;

	playing = true;

	if(display)
		StartTask(control);

	StartTask(player);
}

void pause() {
	if(song == NULL)
		return;

	paused = !paused;
}

void stop() {
	if(song == NULL)
		return;

	playing = false;

	if(display) {
		StopTask(control);
		clear();
	}

	StopTask(player);

	Close(file, result);
}

void setSong(const char * new_song) {
	if(playing)
		stop();

	song = new_song;
}
