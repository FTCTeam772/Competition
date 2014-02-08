/* Music Player
 *
 * Controls:
 * Orange []: Switch between showing and setting volume and speed
 * < and >: Change value
 */

#include "Player.h"

string songs[] = { "StillAlive.mus", "Mario.mus" };
string names[] = { "Still Alive", "Super Mario Bros." };

task main() {
	display = true;
	nxtDisplayCenteredTextLine(3, "Playing:");
	nxtDisplayCenteredTextLine(4, names[0]);
	setSong(songs[0]);
	wait10Msec(200);
	play();
	while(playing);
}
