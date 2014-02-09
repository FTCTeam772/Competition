/* Music Player
 *
 * Controls:
 * Orange []: Switch between showing and setting volume and speed
 * < and >: Change value
 */

#include "Player.h"

task main() {
	display = true; //Show music controls

	TFileHandle file; //For saving info about each file
	TFileIOResult result;
	string filename;
	int size;

	nxtDisplayCenteredTextLine(3, "Select a song:");
	FindFirstFile(file, result, "*.mus", filename, size); //Find the first file
	nxtDisplayCenteredTextLine(5, "%s", filename); //And display its name
	while(nNxtButtonPressed != 3) { //While center button is not pressed to select a song
		wait10Msec(20);
		if(nNxtButtonPressed == 1 || nNxtButtonPressed == 2) {
			FindNextFile(file, result, filename, size); //Find the next file
			if(result != ioRsltSuccess) //Unless we hit the end
				FindFirstFile(file, result, "*.mus", filename, size); //Then find the first file again
			nxtDisplayCenteredTextLine(5, "%s", filename); //Display the filename
		}
	}
	while(nNxtButtonPressed == 3); //Wait for unpress

	setSong(filename); //Set the song
	play(); //And play it
	while(playing); //Wait until the end
}
