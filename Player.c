/* Music Player
 *
 * Controls:
 * Orange []: Switch between showing and setting volume and speed
 * < and >: Change value
 */

#include "Player.h"

#include "StillAlive.h"
#include "Mario.h"

void (* songs[])() = { StillAlive, Mario };
const char * names[] = { "Still Alive", "Super Mario Bros." };

display = true;

task main() {
	nxtDisplayCenteredTextLine(3, "Playing:");
	nxtDisplayCenteredLine(4, names[0]);
	StartTask(control);
	setSong(songs[0]);
	play();
	while(playing);
}
