//PORTAL CREDITS SONG: STILL ALIVE

/* Controls:
 *
 * Orange []: Switch between showing and setting volume and speed
 * < and >: Change value
 */

//sheet music: http://www.scribd.com/doc/2183619/Portals-Still-Alive-Sheet-Music

unsigned short speed = 90;

void tone(unsigned short frequency, unsigned short duration) {
	PlayTone(frequency, duration*speed/100);
}

void wait(unsigned short ms) {
	wait10Msec(ms*speed/100);
}

void clearLyrics() {
	nxtDisplayTextLine(1, "                ");
	nxtDisplayTextLine(2, "                ");
	nxtDisplayTextLine(3, "                ");
	nxtDisplayTextLine(4, "                ");
	nxtDisplayTextLine(5, "                ");
	nxtDisplayTextLine(6, "                ");
}

task control() {
	while(true) {
		nxtDisplayTextLine(7, "[]speed:%d     ", speed);
    while(nNxtButtonPressed != 3) {
			wait1Msec(175);
			if (nNxtButtonPressed == 2 && speed > 10) {
				speed -= 10;
				nxtDisplayTextLine(7, "[]speed:%d     ", speed);
			}
			if (nNxtButtonPressed == 1 && speed < 200) {
				speed += 10;
				nxtDisplayTextLine(7, "[]speed:%d     ", speed);
			}
			abortTimeslice();
		}
		while(nNxtButtonPressed == 3);
		nxtDisplayTextLine(7, "[]volume: %d   ", nVolume);
		while(nNxtButtonPressed != 3) {
			wait1Msec(175);
			if (nNxtButtonPressed == 2 && nVolume > 0) {
				nVolume -= 1;
				nxtDisplayTextLine(7, "[]volume: %d   ", nVolume);
			}
			if (nNxtButtonPressed == 1 && nVolume < 4) {
				nVolume += 1;
				nxtDisplayTextLine(7, "[]volume: %d   ", nVolume);
			}
			abortTimeslice();
		}
		while(nNxtButtonPressed == 3);
	}
}

task main() {
	StartTask(control);
  //#: c,f
  //This was a triumph.
	clearLyrics();
	nxtDisplayTextLine(1, "This was a      "); //16 chars/line
	nxtDisplayTextLine(2, "triumph.        ");
	tone(784,20); //g3
	wait(24);
	tone(740,20); //f#3
	wait(24);
	tone(659,20); //e3
	wait(24);
	tone(659,20); //e3
	wait(24);
	tone(740,20); //f#3
	wait(24);
	wait(24); //wait 1/8
	wait(48); //wait 1/4
	wait(96); //wait 1/2

  //I'm making a note here, HUGE SUCCESS.
  clearLyrics();
  nxtDisplayTextLine(1, "I'm making a    ");
  nxtDisplayTextLine(2, "note here,      ");
  nxtDisplayTextLine(3, "                ");
  nxtDisplayTextLine(4, "                ");
  nxtDisplayTextLine(5, "HUGE SUCCESS.   ");
	wait(48);
  wait(24);
  tone(440,20);
  wait(24);
  tone(784,20);
  wait(24);
  tone(740,20);
  wait(24);
  tone(659,20);
  wait(24);
  tone(659,40);
  wait(48);
  tone(740,20);
  wait(24);
  wait(48);
  tone(587,40);
  wait(48);
  tone(659,20);
  wait(24);
  tone(440,40);
  wait(48);

  //It's hard to overstate my satisfaction.
  clearLyrics();
  nxtDisplayTextLine(1, "It's hard to    ");
  nxtDisplayTextLine(2, "overstate my    ");
  nxtDisplayTextLine(3, "satisfaction.   ");
  wait(24);
  wait(48);
  wait(48);
  wait(24);
  tone(440,20);
  wait(24);
  tone(659,40);
  wait(48);
  tone(740,40);
  wait(48);
  tone(784,60);
  wait(70);
  tone(659,20);
  wait(24);
  tone(554,40);
  wait(48);
  tone(587,60);
  wait(70);
  tone(659,40);
  wait(48);
  tone(440,20);
  wait(24);
  tone(440,40);
  wait(48);
  tone(740,40);
  wait(48);
  wait(24);
  wait(96);

  //Aperture Science,
  clearLyrics();
  nxtDisplayTextLine(1, "  Aperture      ");
  nxtDisplayTextLine(2, "     Science,   ");
  wait(48);
  wait(24);
  tone(784,20);
  wait(24);
  tone(740,20);
  wait(24);
  tone(659,20);
  wait(24);
  tone(659,20);
  wait(24);
  tone(740,20);
  wait(24);
  wait(24);
  wait(48);
  wait(96);

  //we do what we must because we can.
  clearLyrics();
  nxtDisplayTextLine(1, "we do what we   ");
  nxtDisplayTextLine(2, "must            ");
  nxtDisplayTextLine(3, "                ");
  nxtDisplayTextLine(4, "   because      ");
  nxtDisplayTextLine(5, "                ");
  nxtDisplayTextLine(6, "       we can.  ");
  wait(48);
  wait(24);
  tone(440,20);
  wait(24);
  tone(784,20);
  wait(24);
  tone(740,20);
  wait(24);
  tone(659,20);
  wait(24);
  tone(659,20);
  wait(24);
  wait(48);
  tone(740,20);
  wait(24);
  tone(587,20);
  wait(24);
  wait(48);
  tone(659,20);
  wait(24);
  tone(440,40);
  wait(48);
  wait(24);
  wait(48);
  wait(96);

  //for the good of all of us
  clearLyrics();
  nxtDisplayTextLine(1, "for the good of ");
  nxtDisplayTextLine(2, "all of us       ");
  tone(659,40);
  wait(48);
  tone(740,20);
  wait(24);
  tone(784,60);
  wait(70);
  tone(659,20);
  wait(24);
  tone(554,60);
  wait(70);
  tone(587,20);
  wait(24);
  tone(659,20);
  wait(24);
  wait(24);

  //except the ones who are dead.
  clearLyrics();
  nxtDisplayTextLine(1, "except the ones ");
  nxtDisplayTextLine(2, "who are dead.   ");
  tone(440,20);
  wait(24);
  tone(587,20);
  wait(24);
  tone(659,20);
  wait(24);
  tone(698,20);
  wait(24);
  tone(659,20);
  wait(24);
  tone(587,20);
  wait(24);
  tone(523,20);
  wait(24);
  wait(48);


  //But there's no sense crying over ev'ry mistake,
  //b:b
  clearLyrics();
  nxtDisplayTextLine(1, "But there's no  ");
  nxtDisplayTextLine(2, "sense crying    ");
  nxtDisplayTextLine(3, "over ev'ry      ");
  nxtDisplayTextLine(4, "mistake,        ");
  tone(440,20);
  wait(24);
  tone(466,20);
  wait(24);
  tone(523,40);
  wait(48);
  tone(698,40);
  wait(48);
  tone(659,20);
  wait(24);
  tone(587,20);
  wait(24);
  tone(587,20);
  wait(24);
  tone(523,20);
  wait(24);
  tone(587,20);
  wait(24);
  tone(523,20);
  wait(24);
  tone(523,40);
  wait(48);
  tone(523,40);
  wait(48);

  //you just keep on trying till you run out of cake,
  clearLyrics();
  nxtDisplayTextLine(1, "you just keep on");
  nxtDisplayTextLine(2, "trying till you ");
  nxtDisplayTextLine(3, "run out of cake,");
  tone(440,20);
  wait(24);
  tone(466,20);
  wait(24);
  tone(523,40);
  wait(48);
  tone(698,40);
  wait(48);
  tone(784,20);
  wait(24);
  tone(698,20);
  wait(24);
  tone(659,20);
  wait(24);
  tone(587,20);
  wait(24);
  tone(587,20);
  wait(24);
  tone(659,20);
  wait(24);
  tone(698,20);
  wait(24);
  tone(698,40);
  wait(48);

  //and the Science gets done and you make a neat gun
  clearLyrics();
  nxtDisplayTextLine(1, "and the Science ");
  nxtDisplayTextLine(2, "gets done and   ");
  nxtDisplayTextLine(3, "you make a neat ");
  nxtDisplayTextLine(4, "gun             ");
  tone(784,20);
  wait(24);
  tone(880,20);
  wait(24);
  tone(932,20);
  wait(24);
  tone(932,20);
  wait(24);
  tone(880,40);
  wait(48);
  tone(784,40);
  wait(48);
  tone(698,20);
  wait(24);
  tone(784,20);
  wait(24);
  tone(880,20);
  wait(24);
  tone(880,20);
  wait(24);
  tone(784,40);
  wait(48);
  tone(698,40);
  wait(48);

  //for the people who are still alive.
  clearLyrics();
  nxtDisplayTextLine(1, "for the people  ");
  nxtDisplayTextLine(2, "who are         ");
  nxtDisplayTextLine(4, "   still alive. ");
  tone(587,20);
  wait(24);
  tone(523,20);
  wait(24);
  tone(587,20);
  wait(24);
  tone(698,20);
  wait(24);
  tone(698,20);
  wait(24);
  tone(659,40);
  wait(48);
  tone(659,20);
  wait(24);
  tone(740,20);
  wait(24);
  tone(740,60);
  wait(70);

  wait(48);
  wait(96);
  wait(192);
  wait(192);


  //#:c,f
  //I'm not even angry.
  clearLyrics();
  nxtDisplayTextLine(3, "I'm not even    ");
  nxtDisplayTextLine(4, "angry.          ");
  wait(48);
  wait(24);
  tone(440,20);
  wait(24);
  tone(784,20);
  wait(24);
  tone(740,20);
  wait(24);
  tone(659,20);
  wait(24);
  tone(659,30);
  wait(360);
  tone(740,30);
  wait(360);
  wait(48);
  wait(96);

  //I'm being so sincere right now
  clearLyrics();
  nxtDisplayTextLine(1, "I'm being so    ");
  nxtDisplayTextLine(2, "sincere right   ");
  nxtDisplayTextLine(3, "now             ");
  tone(784,20);
  wait(24);
  tone(740,20);
  wait(24);
  tone(659,20);
  wait(24);
  tone(659,60);
  wait(70);
  tone(740,20);
  wait(24);
  tone(587,40);
  wait(48);
  tone(659,40);
  wait(48);
  tone(440,40);
  wait(48);
  wait(24);
  wait(48);
  wait(96);

  //even though you broke my heart
  clearLyrics();
  nxtDisplayTextLine(1, "even though you ");
  nxtDisplayTextLine(2, "broke my heart  ");
  tone(659,40);
  wait(48);
  tone(740,20);
  wait(24);
  tone(784,60);
  wait(70);
  tone(659,40);
  wait(48);
  tone(554,40);
  wait(48);
  tone(587,20);
  wait(24);
  tone(659,60);
  wait(70);

  //and killed me
  clearLyrics();
  nxtDisplayTextLine(3, "  and killed me ");
  tone(440,20);
  wait(24);
  tone(440,40);
  wait(48);
  tone(740,20);
  wait(24);
  wait(48);
  wait(96);

  //and tore me to pieces
  wait(48);
  wait(24);
  clearLyrics();
  nxtDisplayTextLine(1, "and tore me to  ");
  nxtDisplayTextLine(2, "    pieces      ");
  tone(494,20);
  wait(24);
  tone(784,20);
  wait(24);
  tone(740,20);
  wait(24);
  tone(659,20);
  wait(24);
  tone(659,20);
  wait(24);
  tone(740,20);
  wait(24);
  wait(24);
  wait(48);
  wait(96);

  //and threw ev'ry piece into a fire.
  wait(48);
  wait(24);
  clearLyrics();
  nxtDisplayTextLine(1, "and threw ev'ry ");
  nxtDisplayTextLine(2, "piece           ");
  nxtDisplayTextLine(4, "   into         ");
  nxtDisplayTextLine(6, "       a fire.  ");
  tone(494,20);
  wait(24);
  tone(784,20);
  wait(24);
  tone(740,20);
  wait(24);
  tone(659,20);
  wait(24);
  tone(659,20);
  wait(24);
  wait(48);
  tone(740,20);
  wait(24);
  tone(587,20);
  wait(24);
  wait(48);
  tone(659,20);
  wait(24);
  tone(440,40);
  wait(48);
  wait(24);
  wait(48);
  wait(96);

  //As they burned it hurt because I was so happy for you!
  clearLyrics();
  nxtDisplayTextLine(1, "As they burned  ");
  nxtDisplayTextLine(2, "it hurt because ");
  nxtDisplayTextLine(4, "I was so happy  ");
  nxtDisplayTextLine(5, "   for you!     ");
  tone(659,40);
  wait(48);
  tone(740,20);
  wait(24);
  tone(784,60);
  wait(70);
  tone(659,40);
  wait(48);
  tone(554,40);
  wait(48);
  tone(587,20);
  wait(24);
  tone(659,20);
  wait(24);
  wait(24);
  tone(440,20);
  wait(24);
  tone(587,20);
  wait(24);
  tone(659,20);
  wait(24);
  tone(698,20);
  wait(24);
  tone(659,20);
  wait(24);
  tone(587,20);
  wait(24);
  tone(523,20);
  wait(24);
  wait(48);


  //b:b
  //Now these points of data make a beatiful line;
  clearLyrics();
  nxtDisplayTextLine(1, "Now these points");
  nxtDisplayTextLine(2, "of data make a  ");
  nxtDisplayTextLine(3, "beautiful line; ");
  tone(440,20);
  wait(24);
  tone(466,20);
  wait(24);
  tone(523,40);
  wait(48);
  tone(698,40);
  wait(48);
  tone(659,20);
  wait(24);
  tone(587,20);
  wait(24);
  tone(587,20);
  wait(24);
  tone(523,20);
  wait(24);
  tone(587,20);
  wait(24);
  tone(523,20);
  wait(24);
  tone(523,40);
  wait(48);
  tone(523,40);
  wait(48);

  //and we're out of beta, we're releasing on time.
  clearLyrics();
  nxtDisplayTextLine(1, "and we're out of");
  nxtDisplayTextLine(2, " beta,          ");
  nxtDisplayTextLine(4, "we're releasing ");
  nxtDisplayTextLine(5, "on time.        ");
  tone(440,20);
  wait(24);
  tone(466,20);
  wait(24);
  tone(523,40);
  wait(48);
  tone(698,40);
  wait(48);
  tone(784,20);
  wait(24);
  tone(698,20);
  wait(24);
  tone(659,20);
  wait(24);
  tone(587,20);
  wait(24);
  tone(587,20);
  wait(24);
  tone(659,20);
  wait(24);
  tone(698,40);
  wait(48);
  tone(698,40);
  wait(48);

  //So I'm GLaD. I got burned. Think of all the things we learned
  clearLyrics();
  nxtDisplayTextLine(1, "So I'm GLaD.    ");
  nxtDisplayTextLine(2, "I got burned.   ");
  nxtDisplayTextLine(4, "Think of all the");
  nxtDisplayTextLine(5, "things we       ");
  nxtDisplayTextLine(6, "learned         ");
  tone(784,20);
  wait(24);
  tone(880,20);
  wait(24);
  tone(932,20);
  wait(24);
  tone(932,20);
  wait(24);
  tone(880,40);
  wait(48);
  tone(784,40);
  wait(48);
  tone(698,20);
  wait(24);
  tone(784,20);
  wait(24);
  tone(880,20);
  wait(24);
  tone(880,20);
  wait(24);
  tone(784,20);
  wait(24);
  tone(698,20);
  wait(24);
  tone(698,40);
  wait(48);

  //For the people who are still alive.
  clearLyrics();
  nxtDisplayTextLine(1, "for the people  ");
  nxtDisplayTextLine(2, "who are         ");
  nxtDisplayTextLine(4, "   still alive. ");
  tone(587,20);
  wait(24);
  tone(523,20);
  wait(24);
  tone(587,20);
  wait(24);
  tone(698,20);
  wait(24);
  tone(698,20);
  wait(24);
  tone(659,40);
  wait(48);
  tone(659,20);
  wait(24);
  tone(740,20);
  wait(24);
  tone(740,60);
  wait(70);
  wait(48);
  wait(96);
  wait(192);
  wait(192);


  //#:c,f
  //[One last thing:] Go ahead and leave me.
  clearLyrics();
  nxtDisplayTextLine(1, "One last thing: ");
  nxtDisplayTextLine(3, "Go ahead and    ");
  nxtDisplayTextLine(4, "leave me.       ");
  wait(96);
  tone(784,20);
  wait(24);
  tone(740,10);
  wait(12);
  tone(740,10);
  wait(12);
  tone(659,20);
  wait(24);
  tone(659,40);
  wait(48);
  tone(740,20);
  wait(24);
  wait(48);
  wait(96);

  //I think I'd prefer to stay inside.
  clearLyrics();
  nxtDisplayTextLine(1, "I think I'd     ");
  nxtDisplayTextLine(2, "prefer to stay  ");
  nxtDisplayTextLine(3, "inside.         ");
  wait(48);
  wait(24);
  tone(440,20);
  wait(24);
  tone(784,20);
  wait(24);
  tone(740,20);
  wait(24);
  tone(659,20);
  wait(24);
  tone(659,20);
  wait(24);
  wait(48);
  tone(740,20);
  wait(24);
  tone(587,20);
  wait(24);
  wait(48);
  tone(659,20);
  wait(24);
  tone(440,40);
  wait(48);
  wait(24);
  wait(48);
  wait(96);

  //Maybe you'll find someone else to help you.
  clearLyrics();
  nxtDisplayTextLine(1, "Maybe you'll    ");
  nxtDisplayTextLine(2, "find someone    ");
  nxtDisplayTextLine(3, "else to help    ");
  nxtDisplayTextLine(4, "you.            ");
  tone(659,40);
  wait(48);
  tone(740,20);
  wait(24);
  tone(784,60);
  wait(70);
  tone(659,40);
  wait(48);
  tone(554,40);
  wait(48);
  tone(587,20);
  wait(24);
  tone(659,60);
  wait(70);
  tone(440,20);
  wait(24);
  tone(440,40);
  wait(48);
  tone(740,20);
  wait(24);
  wait(48);
  wait(96);

  //Maybe Black Mesa...
  clearLyrics();
  nxtDisplayTextLine(1, "Maybe Black Mesa");
  nxtDisplayTextLine(2, "      ...       ");
  wait(96);
  tone(784,20);
  wait(24);
  tone(740,20);
  wait(24);
  tone(659,20);
  wait(24);
  tone(659,40);
  wait(48);
  tone(740,20);
  wait(24);
  wait(48);
  wait(96);

  //THAT WAS A JOKE. HA HA. FAT CHANCE
  clearLyrics();
  nxtDisplayTextLine(1, "THAT WAS A JOKE.");
  nxtDisplayTextLine(3, "  HA HA.        ");
  nxtDisplayTextLine(5, "     FAT CHANCE.");
  tone(784,20);
  wait(24);
  tone(740,20);
  wait(24);
  tone(659,20);
  wait(24);
  tone(659,20);
  wait(24);
  wait(48);
  tone(740,20);
  wait(24);
  tone(587,20);
  wait(24);
  wait(48);
  tone(659,20);
  wait(24);
  tone(440,40);
  wait(48);
  wait(24);
  wait(48);
  wait(96);

  //Anyway. This cake is great,
  clearLyrics();
  nxtDisplayTextLine(1, "Anyway. This    ");
  nxtDisplayTextLine(2, "cake is great,  ");
  tone(659,40);
  wait(48);
  tone(740,20);
  wait(24);
  tone(784,60);
  wait(70);
  tone(659,40);
  wait(48);
  tone(554,40);
  wait(48);
  tone(587,20);
  wait(24);
  tone(659,20);
  wait(24);
  wait(24);

  //it's so delicious and moist.
  clearLyrics();
  nxtDisplayTextLine(1, "it's so         ");
  nxtDisplayTextLine(2, "delicious and   ");
  nxtDisplayTextLine(3, "moist.          ");
  tone(440,20);
  wait(24);
  tone(587,20);
  wait(24);
  tone(659,20);
  wait(24);
  tone(698,20);
  wait(24);
  tone(659,20);
  wait(24);
  tone(587,20);
  wait(24);
  tone(523,20);
  wait(24);
  wait(48);


  //b:b
  //Look at me still talking when there's Science to do.
  clearLyrics();
  nxtDisplayTextLine(1, "Look at me still");
  nxtDisplayTextLine(2, "talking when    ");
  nxtDisplayTextLine(3, "there's Science ");
  nxtDisplayTextLine(4, "to do.          ");
  tone(440,20);
  wait(24);
  tone(466,20);
  wait(24);
  tone(523,40);
  wait(48);
  tone(698,40);
  wait(48);
  tone(659,20);
  wait(24);
  tone(587,20);
  wait(24);
  tone(587,20);
  wait(24);
  tone(523,20);
  wait(24);
  tone(587,20);
  wait(24);
  tone(523,20);
  wait(24);
  tone(523,40);
  wait(48);
  tone(523,40);
  wait(48);

  //When I look out there it makes me GLaD I'm not you.
  clearLyrics();
  nxtDisplayTextLine(1, "When I look out ");
  nxtDisplayTextLine(2, "there it makes  ");
  nxtDisplayTextLine(3, "me GLaD I'm not ");
  nxtDisplayTextLine(4, "you.            ");
  tone(440,20);
  wait(24);
  tone(466,20);
  wait(24);
  tone(523,40);
  wait(48);
  tone(698,40);
  wait(48);
  tone(784,20);
  wait(24);
  tone(698,20);
  wait(24);
  tone(659,20);
  wait(24);
  tone(587,20);
  wait(24);
  tone(587,20);
  wait(24);
  tone(659,20);
  wait(24);
  tone(698,40);
  wait(48);
  tone(698,40);
  wait(48);

  //I've experiments to run.
  clearLyrics();
  nxtDisplayTextLine(1, "I've experiments");
  nxtDisplayTextLine(2, "to run.         ");
  tone(784,20);
  wait(24);
  tone(880,20);
  wait(24);
  tone(932,20);
  wait(24);
  tone(932,20);
  wait(24);
  tone(880,20);
  wait(24);
  tone(784,20);
  wait(24);
  tone(784,40);
  wait(48);

  //There is research to be done
  clearLyrics();
  nxtDisplayTextLine(1, "There is        ");
  nxtDisplayTextLine(2, "research to be  ");
  nxtDisplayTextLine(3, "done            ");
  tone(698,20);
  wait(24);
  tone(784,20);
  wait(24);
  tone(880,20);
  wait(24);
  tone(880,20);
  wait(24);
  tone(784,20);
  wait(24);
  tone(698,20);
  wait(24);
  tone(698,40);
  wait(48);

  //on the people who are still alive.
  clearLyrics();
  nxtDisplayTextLine(1, "on the people   ");
  nxtDisplayTextLine(2, "who are         ");
  nxtDisplayTextLine(4, "    still alive.");
  tone(587,20);
  wait(24);
  tone(523,20);
  wait(24);
  tone(587,20);
  wait(24);
  tone(698,20);
  wait(24);
  tone(698,20);
  wait(24);
  tone(659,40);
  wait(48);
  tone(659,20);
  wait(24);
  tone(740,20);
  wait(24);
  tone(740,60);
  wait(70);
  wait(48);
  wait(48);



  //#:c,f
  //[PS:] And believe me I am still alive.
  clearLyrics();
  nxtDisplayTextLine(1, "PS:             ");
  nxtDisplayTextLine(3, "And believe me  ");
  nxtDisplayTextLine(4, "I am            ");
  nxtDisplayTextLine(6, "    still alive.");
  tone(880,20);
  wait(24);
  tone(880,20);
  wait(24);
  tone(988,20);
  wait(24);
  tone(880,20);
  wait(24);
  tone(740,20);
  wait(24);
  tone(587,40);
  wait(48);
  tone(659,20);
  wait(24);
  tone(740,20);
  wait(24);
  tone(740,40);
  wait(48);
  wait(70);
  wait(48);
  wait(24);

  //[PPS:] I'm doing science and I'm still alive.
  clearLyrics();
  nxtDisplayTextLine(1, "PPS:            ");
  nxtDisplayTextLine(3, "I'm doing       ");
  nxtDisplayTextLine(4, "science and I'm ");
  nxtDisplayTextLine(6, "    still alive.");
  tone(880,20);
  wait(24);
  tone(880,20);
  wait(24);
  tone(880,20);
  wait(24);
  tone(988,20);
  wait(24);
  tone(880,20);
  wait(24);
  tone(740,20);
  wait(24);
  tone(587,40);
  wait(48);
  tone(659,20);
  wait(24);
  tone(740,20);
  wait(24);
  tone(740,60);
  wait(70);
  wait(48);
  wait(24);

  //[PPPS:] I feel FANTASTIC and I'm still alive.
  clearLyrics();
  nxtDisplayTextLine(1, "PPPS:           ");
  nxtDisplayTextLine(3, "I feel FANTASTIC");
  nxtDisplayTextLine(4, "and I'm         ");
  nxtDisplayTextLine(6, "    still alive.");
  tone(880,20);
  wait(24);
  tone(880,20);
  wait(24);
  tone(880,20);
  wait(24);
  tone(988,20);
  wait(24);
  tone(880,20);
  wait(24);
  tone(740,20);
  wait(24);
  tone(587,40);
  wait(48);
  tone(659,20);
  wait(24);
  tone(740,20);
  wait(24);
  tone(740,60);
  wait(70);
  wait(48);
  wait(48);

  //[FINAL THOUGHT:] While you're dying I'll be still alive.
  clearLyrics();
  nxtDisplayTextLine(1, "FINAL THOUGHT:  ");
  nxtDisplayTextLine(3, "While you're    ");
  nxtDisplayTextLine(4, "dying I'll be   ");
  nxtDisplayTextLine(6, "    still alive.");
  tone(880,20);
  wait(24);
  tone(880,20);
  wait(24);
  tone(988,20);
  wait(24);
  tone(880,20);
  wait(24);
  tone(740,20);
  wait(24);
  tone(587,40);
  wait(48);
  tone(659,20);
  wait(24);
  tone(740,20);
  wait(24);
  tone(740,40);
  wait(48);
  wait(48);
  wait(24);

  //[FINAL THOUGHT PS:]And when you're dead I will be still alive.
  clearLyrics();
  nxtDisplayTextLine(1, "FINAL THOUGHT PS");
  nxtDisplayTextLine(3, "And when you're ");
  nxtDisplayTextLine(4, "dead I will be  ");
  nxtDisplayTextLine(6, "    still alvie.");
  tone(880,20);
  wait(24);
  tone(880,20);
  wait(24);
  tone(880,20);
  wait(24);
  tone(988,20);
  wait(24);
  tone(880,20);
  wait(24);
  tone(740,20);
  wait(24);
  tone(587,40);
  wait(48);
  tone(659,20);
  wait(24);
  tone(740,20);
  wait(24);
  tone(740,40);
  wait(48);
  wait(48);
  wait(24);

  //STILL ALIVE.
  clearLyrics();
  nxtDisplayTextLine(4, " STILL ALIVE.   ");
  tone(784,20);
  wait(24);
  tone(880,20);
  wait(24);
  tone(880,60);
  wait(70);
  wait(48);
  wait(24);

  //STILL ALIVE.
  clearLyrics();
  nxtDisplayTextLine(4, " STILL ALIVE.   ");
  tone(784,20);
  wait(24);
  tone(740,20);
  wait(24);
  tone(740,60);
  wait(70);
  wait(48);
  wait(96);
}
