//Variables

void (* song)() = NULL;

bool display = false;
bool paused = false;
bool playing = false;

unsigned short speed = 100;

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
	if(song == NULL)
		return;

	song();

	stop();
}

void play() {
	if(song == NULL)
		return;

	if(playing)
		StopTask(player);

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

	if(display)
		StopTask(control);

	StopTask(player);
}

void setSong(void (* new_song)()) {
	song = new_song;
}

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
