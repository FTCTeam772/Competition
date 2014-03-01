/* Music Player
 *
 * Controls:
 * Orange []: Choose song / Switch between showing and setting volume and speed
 * < and >: Change song / Change value
 */

#include "Player.h"

task main() {
	display = true; //Show music controls

	TFileHandle file; //For saving info about each file
	TFileIOResult result;
	string filename;
	int size;

	//Count the number of files there are
	int files = 0;
	FindFirstFile(file, result, "*.nms", filename, size);
	while(result == ioRsltSuccess) {
		files++;
		FindNextFile(file, result, filename, size);
	}

	if(files < 0) { //Notify user if there aren't any
		nxtDisplayCenteredTextLine(4, "No music files found");

		while(nNxtButtonPressed != 3); //Wait for button press
		while(nNxtButtonPressed == 3); //And unpress

		return; //And quit
	}

	//Fill up an array with filenames
	string filenames[files];
	FindFirstFile(file, result, "*.nms", filenames[0], size);
	for(int i = 1; i < files; i++)
		FindNextFile(file, result, filenames[i], size);

	//Prompt the user
	nxtDisplayCenteredTextLine(3, "Select a song:");
	nxtDisplayCenteredTextLine(5, "%s", filenames[0]); //Show the first song
	int num = 0;
	while(nNxtButtonPressed != 3) { //While center button is not pressed to select a song
		wait10Msec(20);

		if(nNxtButtonPressed == 1 && num > 0) { //If left is pressed, implement bounds and decrement num
			num--;
			nxtDisplayCenteredTextLine(5, "%s", filenames[num]); //Display the filename
		}
		else if(nNxtButtonPressed == 2 && num < files) { //Else if right is pressed, increment num
			num++;
			nxtDisplayCenteredTextLine(5, "%s", filenames[num]); //Display the filename
		}
	}
	while(nNxtButtonPressed == 3); //Wait for unpress

	setSong(filenames[num]); //Set the song
	play(); //And play it
	while(playing); //Wait until the end
}
