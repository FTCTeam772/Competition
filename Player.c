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
	int size;

	string filename[16]; //To store filenames

	//Fill up the array with filenames
	int files = 0;
	FindFirstFile(file, result, "*.nms", filename[0], size);
	while(result == ioRsltSuccess && files < 63) {
		files++;
		FindNextFile(file, result, filename[files], size);
	}

	if(files == 0) { //Notify user if there aren't any
		nxtDisplayCenteredTextLine(4, "No music files found");

		while(nNxtButtonPressed != 3); //Wait for button press
		while(nNxtButtonPressed == 3); //And unpress

		return; //And quit
	}

	//Prompt the user
	nxtDisplayCenteredTextLine(3, "Select a song:");
	nxtDisplayCenteredTextLine(5, "%s", filename[0]); //Show the first song
	int num = 0;
	while(nNxtButtonPressed != 3) { //While center button is not pressed to select a song
		wait10Msec(20);

		if(nNxtButtonPressed == 2 && num > 0) { //If left is pressed, implement bounds and decrement num
			num--;
			nxtDisplayCenteredTextLine(5, "%s", filename[num]); //Display the filename
		}
		else if(nNxtButtonPressed == 1 && num < files - 1) { //Else if right is pressed, increment num
			num++;
			nxtDisplayCenteredTextLine(5, "%s", filename[num]); //Display the filename
		}
	}
	while(nNxtButtonPressed == 3); //Wait for unpress

	setSong(filename[num]); //Set the song
	play(); //And play it
	while(playing); //Wait until the end
}
