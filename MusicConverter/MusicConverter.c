#include <math.h>
#include <stdio.h>
#include <string.h>

float freqs[] = { 261.63, 277.18, 293.66, 311.13, 329.63, 349.23, 369.99, 392.00, 415.30, 440.00, 466.16, 493.88 };

void getLine(FILE * file, char * buffer, int size) {
	int i = 0;
	char c = fgetc(file);

	while(c != '\n' && c != EOF) {
		if(i < size) {
			buffer[i] = c;
			i++;
		}

		c = fgetc(file);
	}

	buffer[i] = '\0';
}

int main(int argc, char * argv[]) {
	if(argc < 3) {
		fprintf(stderr, "Usage:\t%s <input.mus> <output.nms>\n", argv[0]);

		return 1;
	}

	FILE * in = fopen(argv[1], "r");

	if(in == NULL) {
		fprintf(stderr, "Error: Unable to open input file\n");

		return 2;
	}

	FILE * out = fopen(argv[2], "w");

	if(out == NULL) {
		fprintf(stderr, "Error: Unable to open output file\n");

		return 2;
	}

	float cs = 50;
	int keysig = 0;

	char name[24];
	getLine(in, name, 23);
	fprintf(out, "%s\n", name);

	while(!feof(in)) {
		char line[64];
		getLine(in, line, 63);

		if(line[0] == '#' || line[0] == '\0') {
			fprintf(out, "%s\n", line);
			continue;
		}

		char cmd[64];
		char param[64];
		int number = sscanf(line, "%s %[^\n]", cmd, param);

		if(strcmp(cmd, "note") == 0) {
			char note[3];
			int octave;
			float value;
			char option[10];
			int n = sscanf(param, "%2[ABCDEFG#bn]%d %f %9s", note, &octave, &value, option);

			if(n != 3 && n != 4) {
				fprintf(stderr, "Warning: Incorrect note syntax \"%s\"\n", line);

				continue;
			}

			int freq_index;

			switch(note[0]) {
				case 'C':
					freq_index = 0;

					if(note[1] == '\0') {
						if(keysig >= 2)
							freq_index++;
						else if(keysig <= -6)
							freq_index--;
					}

					break;
				case 'D':
					freq_index = 2;

					if(note[1] == '\0') {
						if(keysig >= 4)
							freq_index++;
						else if(keysig <= -4)
							freq_index--;
					}

					break;
				case 'E':
					freq_index = 4;

					if(note[1] == '\0') {
						if(keysig >= 6)
							freq_index++;
						else if(keysig <= -2)
							freq_index--;
					}

					break;
				case 'F':
					freq_index = 5;

					if(note[1] == '\0') {
						if(keysig >= 1)
							freq_index++;
						else if(keysig <= -7)
							freq_index--;
					}

					break;
				case 'G':
					freq_index = 7;

					if(note[1] == '\0') {
						if(keysig >= 3)
							freq_index++;
						else if(keysig <= -5)
							freq_index--;
					}

					break;
				case 'A':
					freq_index = 9;

					if(note[1] == '\0') {
						if(keysig >= 5)
							freq_index++;
						else if(keysig <= -3)
							freq_index--;
					}

					break;
				case 'B':
					freq_index = 11;

					if(note[1] == '\0') {
						if(keysig >= 7)
							freq_index++;
						else if(keysig <= -1)
							freq_index--;
					}

					break;
			}

			if(note[1] != '\0') {
				switch(note[1]) {
					case 'n':
						break;
					case '#':
						freq_index++;
						break;
					case 'b':
						freq_index--;
						break;
				}
			}

			int wait = value * cs;

			int time;
			if(n == 4) {
				if(strcmp(option, "legato") == 0)
					time = wait;
				else if(strcmp(option, "staccato") == 0)
					time = wait * 2 / 3;
				else
					fprintf(stderr, "Warning: Unknown note option \"%s\"\n", option);
			}
			else {
				time = wait * 5 / 6;
			}

			fprintf(out, "tone %d %d %d\n", (int)round(freqs[freq_index] * pow(2, octave - 4)), time, wait);
		}
		else if(strcmp(cmd, "rest") == 0) {
			float value;
			int n = sscanf(param, "%f", &value);

			if(n != 1) {
				fprintf(stderr, "Warning: Incorrect rest syntax \"%s\"\n", line);

				continue;
			}

			fprintf(out, "wait %d\n", (int)round(value * cs));
		}
		else if(strcmp(cmd, "write") == 0) {
			char lyric[64];
			int n = sscanf(param, "\"%[^\"]", lyric);

			if(n != 1) {
				fprintf(stderr, "Warning: Incorrect lyric syntax \"%s\"\n", line);

				continue;
			}

			fprintf(out, "write \"%s\"\n", lyric);
		}
		else if(strcmp(cmd, "clear") == 0) {
			fprintf(out, "clear\n");
		}
		else if(strcmp(cmd, "keysig") == 0) {
			char key[3];
			int n = sscanf(param, "%2[ABCDEFG#b]", key);

			if(n != 1) {
				fprintf(stderr, "Warning: Incorrect key signature syntax \"%s\"\n", line);

				continue;
			}

			if(strcmp(key, "C") == 0)
				keysig = 0;
			else if(strcmp(key, "G") == 0)
				keysig = 1;
			else if(strcmp(key, "D") == 0)
				keysig = 2;
			else if(strcmp(key, "A") == 0)
				keysig = 3;
			else if(strcmp(key, "E") == 0)
				keysig = 4;
			else if(strcmp(key, "B") == 0)
				keysig = 5;
			else if(strcmp(key, "F#") == 0)
				keysig = 6;
			else if(strcmp(key, "C#") == 0)
				keysig = 7;
			else if(strcmp(key, "F") == 0)
				keysig = -1;
			else if(strcmp(key, "Bb") == 0)
				keysig = -2;
			else if(strcmp(key, "Eb") == 0)
				keysig = -3;
			else if(strcmp(key, "Ab") == 0)
				keysig = -4;
			else if(strcmp(key, "Db") == 0)
				keysig = -5;
			else if(strcmp(key, "Gb") == 0)
				keysig = -6;
			else if(strcmp(key, "Cb") == 0)
				keysig = -7;
		}
		else if(strcmp(cmd, "tempo") == 0) {
			int bpm;
			int n = sscanf(param, "%d", &bpm);

			if(n != 1) {
				fprintf(stderr, "Warning: Incorrect tempo syntax \"%s\"\n", line);

				continue;
			}

			cs = 6000 / bpm;
		}
		else {
			fprintf(stderr, "Warning: Unrecognized command \"%s\"\n", line);
		}
	}

	fclose(out);
	fclose(in);

	return 0;
}
