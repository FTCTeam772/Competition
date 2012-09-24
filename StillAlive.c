//PORTAL CREDITS SONG: STILL ALIVE

/* Controls:
 *
 * Orange []: Switch between showing and setting volume and speed
 * < and >: Change value
 */

//sheet music: http://www.scribd.com/doc/2183619/Portals-Still-Alive-Sheet-Music

unsigned short speed = 90;

void MyPlayTone(unsigned short frequency, unsigned short duration) {
	PlayTone(frequency, duration*speed/100);
}

void MyWait(unsigned short ms) {
	wait1Msec(ms*speed/100);
}

void ClearLyrics() {
	nxtDisplayCenteredTextLine(1, "                ");
	nxtDisplayCenteredTextLine(2, "                ");
	nxtDisplayCenteredTextLine(3, "                ");
	nxtDisplayCenteredTextLine(4, "                ");
	nxtDisplayCenteredTextLine(5, "                ");
	nxtDisplayCenteredTextLine(6, "                ");
	nxtDisplayCenteredTextLine(7, "                ");
}

task GLaDOS() {
  //#: c,f
  //This was a triumph.
	ClearLyrics();
	nxtDisplayCenteredTextLine(1, "This was a      "); //16 chars/line
	nxtDisplayCenteredTextLine(2, "triumph.        ");
	MyPlayTone(784,200); //g3
	MyWait(240);
	MyPlayTone(740,200); //f#3
	MyWait(240);
	MyPlayTone(659,200); //e3
	MyWait(240);
	MyPlayTone(659,200); //e3
	MyWait(240);
	MyPlayTone(740,200); //f#3
	MyWait(240);
	MyWait(240); //wait 1/8
	MyWait(480); //wait 1/4
	MyWait(960); //wait 1/2

  //I'm making a note here, HUGE SUCCESS.
  ClearLyrics();
  nxtDisplayCenteredTextLine(1, "I'm making a    ");
  nxtDisplayCenteredTextLine(2, "note here,      ");
  nxtDisplayCenteredTextLine(3, "                ");
  nxtDisplayCenteredTextLine(4, "                ");
  nxtDisplayCenteredTextLine(5, "HUGE SUCCESS.   ");
	MyWait(480);
  MyWait(240);
  MyPlayTone(440,200);
  MyWait(240);
  MyPlayTone(784,200);
  MyWait(240);
  MyPlayTone(740,200);
  MyWait(240);
  MyPlayTone(659,200);
  MyWait(240);
  MyPlayTone(659,400);
  MyWait(480);
  MyPlayTone(740,200);
  MyWait(240);
  MyWait(480);
  MyPlayTone(587,400);
  MyWait(480);
  MyPlayTone(659,200);
  MyWait(240);
  MyPlayTone(440,400);
  MyWait(480);

  //It's hard to overstate my satisfaction.
  ClearLyrics();
  nxtDisplayCenteredTextLine(1, "It's hard to    ");
  nxtDisplayCenteredTextLine(2, "overstate my    ");
  nxtDisplayCenteredTextLine(3, "satisfaction.   ");
  MyWait(240);
  MyWait(480);
  MyWait(480);
  MyWait(240);
  MyPlayTone(440,200);
  MyWait(240);
  MyPlayTone(659,400);
  MyWait(480);
  MyPlayTone(740,400);
  MyWait(480);
  MyPlayTone(784,600);
  MyWait(700);
  MyPlayTone(659,200);
  MyWait(240);
  MyPlayTone(554,400);
  MyWait(480);
  MyPlayTone(587,600);
  MyWait(700);
  MyPlayTone(659,400);
  MyWait(480);
  MyPlayTone(440,200);
  MyWait(240);
  MyPlayTone(440,400);
  MyWait(480);
  MyPlayTone(740,400);
  MyWait(480);
  MyWait(240);
  MyWait(960);

  //Aperture Science,
  ClearLyrics();
  nxtDisplayCenteredTextLine(1, "  Aperture      ");
  nxtDisplayCenteredTextLine(2, "     Science,   ");
  MyWait(480);
  MyWait(240);
  MyPlayTone(784,200);
  MyWait(240);
  MyPlayTone(740,200);
  MyWait(240);
  MyPlayTone(659,200);
  MyWait(240);
  MyPlayTone(659,200);
  MyWait(240);
  MyPlayTone(740,200);
  MyWait(240);
  MyWait(240);
  MyWait(480);
  MyWait(960);

  //we do what we must because we can.
  ClearLyrics();
  nxtDisplayCenteredTextLine(1, "we do what we   ");
  nxtDisplayCenteredTextLine(2, "must            ");
  nxtDisplayCenteredTextLine(3, "                ");
  nxtDisplayCenteredTextLine(4, "   because      ");
  nxtDisplayCenteredTextLine(5, "                ");
  nxtDisplayCenteredTextLine(6, "       we can.  ");
  MyWait(480);
  MyWait(240);
  MyPlayTone(440,200);
  MyWait(240);
  MyPlayTone(784,200);
  MyWait(240);
  MyPlayTone(740,200);
  MyWait(240);
  MyPlayTone(659,200);
  MyWait(240);
  MyPlayTone(659,200);
  MyWait(240);
  MyWait(480);
  MyPlayTone(740,200);
  MyWait(240);
  MyPlayTone(587,200);
  MyWait(240);
  MyWait(480);
  MyPlayTone(659,200);
  MyWait(240);
  MyPlayTone(440,400);
  MyWait(480);
  MyWait(240);
  MyWait(480);
  MyWait(960);

  //for the good of all of us
  ClearLyrics();
  nxtDisplayCenteredTextLine(1, "for the good of ");
  nxtDisplayCenteredTextLine(2, "all of us       ");
  MyPlayTone(659,400);
  MyWait(480);
  MyPlayTone(740,200);
  MyWait(240);
  MyPlayTone(784,600);
  MyWait(700);
  MyPlayTone(659,200);
  MyWait(240);
  MyPlayTone(554,600);
  MyWait(700);
  MyPlayTone(587,200);
  MyWait(240);
  MyPlayTone(659,200);
  MyWait(240);
  MyWait(240);

  //except the ones who are dead.
  ClearLyrics();
  nxtDisplayCenteredTextLine(1, "except the ones ");
  nxtDisplayCenteredTextLine(2, "who are dead.   ");
  MyPlayTone(440,200);
  MyWait(240);
  MyPlayTone(587,200);
  MyWait(240);
  MyPlayTone(659,200);
  MyWait(240);
  MyPlayTone(698,200);
  MyWait(240);
  MyPlayTone(659,200);
  MyWait(240);
  MyPlayTone(587,200);
  MyWait(240);
  MyPlayTone(523,200);
  MyWait(240);
  MyWait(480);


  //But there's no sense crying over ev'ry mistake,
  //b:b
  ClearLyrics();
  nxtDisplayCenteredTextLine(1, "But there's no  ");
  nxtDisplayCenteredTextLine(2, "sense crying    ");
  nxtDisplayCenteredTextLine(3, "over ev'ry      ");
  nxtDisplayCenteredTextLine(4, "mistake,        ");
  MyPlayTone(440,200);
  MyWait(240);
  MyPlayTone(466,200);
  MyWait(240);
  MyPlayTone(523,400);
  MyWait(480);
  MyPlayTone(698,400);
  MyWait(480);
  MyPlayTone(659,200);
  MyWait(240);
  MyPlayTone(587,200);
  MyWait(240);
  MyPlayTone(587,200);
  MyWait(240);
  MyPlayTone(523,200);
  MyWait(240);
  MyPlayTone(587,200);
  MyWait(240);
  MyPlayTone(523,200);
  MyWait(240);
  MyPlayTone(523,400);
  MyWait(480);
  MyPlayTone(523,400);
  MyWait(480);

  //you just keep on trying till you run out of cake,
  ClearLyrics();
  nxtDisplayCenteredTextLine(1, "you just keep on");
  nxtDisplayCenteredTextLine(2, "trying till you ");
  nxtDisplayCenteredTextLine(3, "run out of cake,");
  MyPlayTone(440,200);
  MyWait(240);
  MyPlayTone(466,200);
  MyWait(240);
  MyPlayTone(523,400);
  MyWait(480);
  MyPlayTone(698,400);
  MyWait(480);
  MyPlayTone(784,200);
  MyWait(240);
  MyPlayTone(698,200);
  MyWait(240);
  MyPlayTone(659,200);
  MyWait(240);
  MyPlayTone(587,200);
  MyWait(240);
  MyPlayTone(587,200);
  MyWait(240);
  MyPlayTone(659,200);
  MyWait(240);
  MyPlayTone(698,200);
  MyWait(240);
  MyPlayTone(698,400);
  MyWait(480);

  //and the Science gets done and you make a neat gun
  ClearLyrics();
  nxtDisplayCenteredTextLine(1, "and the Science ");
  nxtDisplayCenteredTextLine(2, "gets done and   ");
  nxtDisplayCenteredTextLine(3, "you make a neat ");
  nxtDisplayCenteredTextLine(4, "gun             ");
  MyPlayTone(784,200);
  MyWait(240);
  MyPlayTone(880,200);
  MyWait(240);
  MyPlayTone(932,200);
  MyWait(240);
  MyPlayTone(932,200);
  MyWait(240);
  MyPlayTone(880,400);
  MyWait(480);
  MyPlayTone(784,400);
  MyWait(480);
  MyPlayTone(698,200);
  MyWait(240);
  MyPlayTone(784,200);
  MyWait(240);
  MyPlayTone(880,200);
  MyWait(240);
  MyPlayTone(880,200);
  MyWait(240);
  MyPlayTone(784,400);
  MyWait(480);
  MyPlayTone(698,400);
  MyWait(480);

  //for the people who are still alive.
  ClearLyrics();
  nxtDisplayCenteredTextLine(1, "for the people  ");
  nxtDisplayCenteredTextLine(2, "who are         ");
  nxtDisplayCenteredTextLine(4, "   still alive. ");
  MyPlayTone(587,200);
  MyWait(240);
  MyPlayTone(523,200);
  MyWait(240);
  MyPlayTone(587,200);
  MyWait(240);
  MyPlayTone(698,200);
  MyWait(240);
  MyPlayTone(698,200);
  MyWait(240);
  MyPlayTone(659,400);
  MyWait(480);
  MyPlayTone(659,200);
  MyWait(240);
  MyPlayTone(740,200);
  MyWait(240);
  MyPlayTone(740,600);
  MyWait(700);

  MyWait(480);
  MyWait(960);
  MyWait(1920);
  MyWait(1920);


  //#:c,f
  //I'm not even angry.
  ClearLyrics();
  nxtDisplayCenteredTextLine(3, "I'm not even    ");
  nxtDisplayCenteredTextLine(4, "angry.          ");
  MyWait(480);
  MyWait(240);
  MyPlayTone(440,200);
  MyWait(240);
  MyPlayTone(784,200);
  MyWait(240);
  MyPlayTone(740,200);
  MyWait(240);
  MyPlayTone(659,200);
  MyWait(240);
  MyPlayTone(659,300);
  MyWait(360);
  MyPlayTone(740,300);
  MyWait(360);
  MyWait(480);
  MyWait(960);

  //I'm being so sincere right now
  ClearLyrics();
  nxtDisplayCenteredTextLine(1, "I'm being so    ");
  nxtDisplayCenteredTextLine(2, "sincere right   ");
  nxtDisplayCenteredTextLine(3, "now             ");
  MyPlayTone(784,200);
  MyWait(240);
  MyPlayTone(740,200);
  MyWait(240);
  MyPlayTone(659,200);
  MyWait(240);
  MyPlayTone(659,600);
  MyWait(700);
  MyPlayTone(740,200);
  MyWait(240);
  MyPlayTone(587,400);
  MyWait(480);
  MyPlayTone(659,400);
  MyWait(480);
  MyPlayTone(440,400);
  MyWait(480);
  MyWait(240);
  MyWait(480);
  MyWait(960);

  //even though you broke my heart
  ClearLyrics();
  nxtDisplayCenteredTextLine(1, "even though you ");
  nxtDisplayCenteredTextLine(2, "broke my heart  ");
  MyPlayTone(659,400);
  MyWait(480);
  MyPlayTone(740,200);
  MyWait(240);
  MyPlayTone(784,600);
  MyWait(700);
  MyPlayTone(659,400);
  MyWait(480);
  MyPlayTone(554,400);
  MyWait(480);
  MyPlayTone(587,200);
  MyWait(240);
  MyPlayTone(659,600);
  MyWait(700);

  //and killed me
  ClearLyrics();
  nxtDisplayCenteredTextLine(3, "  and killed me ");
  MyPlayTone(440,200);
  MyWait(240);
  MyPlayTone(440,400);
  MyWait(480);
  MyPlayTone(740,200);
  MyWait(240);
  MyWait(480);
  MyWait(960);

  //and tore me to pieces
  MyWait(480);
  MyWait(240);
  ClearLyrics();
  nxtDisplayCenteredTextLine(1, "and tore me to  ");
  nxtDisplayCenteredTextLine(2, "    pieces      ");
  MyPlayTone(494,200);
  MyWait(240);
  MyPlayTone(784,200);
  MyWait(240);
  MyPlayTone(740,200);
  MyWait(240);
  MyPlayTone(659,200);
  MyWait(240);
  MyPlayTone(659,200);
  MyWait(240);
  MyPlayTone(740,200);
  MyWait(240);
  MyWait(240);
  MyWait(480);
  MyWait(960);

  //and threw ev'ry piece into a fire.
  MyWait(480);
  MyWait(240);
  ClearLyrics();
  nxtDisplayCenteredTextLine(1, "and threw ev'ry ");
  nxtDisplayCenteredTextLine(2, "piece           ");
  nxtDisplayCenteredTextLine(4, "   into         ");
  nxtDisplayCenteredTextLine(6, "       a fire.  ");
  MyPlayTone(494,200);
  MyWait(240);
  MyPlayTone(784,200);
  MyWait(240);
  MyPlayTone(740,200);
  MyWait(240);
  MyPlayTone(659,200);
  MyWait(240);
  MyPlayTone(659,200);
  MyWait(240);
  MyWait(480);
  MyPlayTone(740,200);
  MyWait(240);
  MyPlayTone(587,200);
  MyWait(240);
  MyWait(480);
  MyPlayTone(659,200);
  MyWait(240);
  MyPlayTone(440,400);
  MyWait(480);
  MyWait(240);
  MyWait(480);
  MyWait(960);

  //As they burned it hurt because I was so happy for you!
  ClearLyrics();
  nxtDisplayCenteredTextLine(1, "As they burned  ");
  nxtDisplayCenteredTextLine(2, "it hurt because ");
  nxtDisplayCenteredTextLine(4, "I was so happy  ");
  nxtDisplayCenteredTextLine(5, "   for you!     ");
  MyPlayTone(659,400);
  MyWait(480);
  MyPlayTone(740,200);
  MyWait(240);
  MyPlayTone(784,600);
  MyWait(700);
  MyPlayTone(659,400);
  MyWait(480);
  MyPlayTone(554,400);
  MyWait(480);
  MyPlayTone(587,200);
  MyWait(240);
  MyPlayTone(659,200);
  MyWait(240);
  MyWait(240);
  MyPlayTone(440,200);
  MyWait(240);
  MyPlayTone(587,200);
  MyWait(240);
  MyPlayTone(659,200);
  MyWait(240);
  MyPlayTone(698,200);
  MyWait(240);
  MyPlayTone(659,200);
  MyWait(240);
  MyPlayTone(587,200);
  MyWait(240);
  MyPlayTone(523,200);
  MyWait(240);
  MyWait(480);


  //b:b
  //Now these points of data make a beatiful line;
  ClearLyrics();
  nxtDisplayCenteredTextLine(1, "Now these points");
  nxtDisplayCenteredTextLine(2, "of data make a  ");
  nxtDisplayCenteredTextLine(3, "beautiful line; ");
  MyPlayTone(440,200);
  MyWait(240);
  MyPlayTone(466,200);
  MyWait(240);
  MyPlayTone(523,400);
  MyWait(480);
  MyPlayTone(698,400);
  MyWait(480);
  MyPlayTone(659,200);
  MyWait(240);
  MyPlayTone(587,200);
  MyWait(240);
  MyPlayTone(587,200);
  MyWait(240);
  MyPlayTone(523,200);
  MyWait(240);
  MyPlayTone(587,200);
  MyWait(240);
  MyPlayTone(523,200);
  MyWait(240);
  MyPlayTone(523,400);
  MyWait(480);
  MyPlayTone(523,400);
  MyWait(480);

  //and we're out of beta, we're releasing on time.
  ClearLyrics();
  nxtDisplayCenteredTextLine(1, "and we're out of");
  nxtDisplayCenteredTextLine(2, " beta,          ");
  nxtDisplayCenteredTextLine(4, "we're releasing ");
  nxtDisplayCenteredTextLine(5, "on time.        ");
  MyPlayTone(440,200);
  MyWait(240);
  MyPlayTone(466,200);
  MyWait(240);
  MyPlayTone(523,400);
  MyWait(480);
  MyPlayTone(698,400);
  MyWait(480);
  MyPlayTone(784,200);
  MyWait(240);
  MyPlayTone(698,200);
  MyWait(240);
  MyPlayTone(659,200);
  MyWait(240);
  MyPlayTone(587,200);
  MyWait(240);
  MyPlayTone(587,200);
  MyWait(240);
  MyPlayTone(659,200);
  MyWait(240);
  MyPlayTone(698,400);
  MyWait(480);
  MyPlayTone(698,400);
  MyWait(480);

  //So I'm GLaD. I got burned. Think of all the things we learned
  ClearLyrics();
  nxtDisplayCenteredTextLine(1, "So I'm GLaD.    ");
  nxtDisplayCenteredTextLine(2, "I got burned.   ");
  nxtDisplayCenteredTextLine(4, "Think of all the");
  nxtDisplayCenteredTextLine(5, "things we       ");
  nxtDisplayCenteredTextLine(6, "learned         ");
  MyPlayTone(784,200);
  MyWait(240);
  MyPlayTone(880,200);
  MyWait(240);
  MyPlayTone(932,200);
  MyWait(240);
  MyPlayTone(932,200);
  MyWait(240);
  MyPlayTone(880,400);
  MyWait(480);
  MyPlayTone(784,400);
  MyWait(480);
  MyPlayTone(698,200);
  MyWait(240);
  MyPlayTone(784,200);
  MyWait(240);
  MyPlayTone(880,200);
  MyWait(240);
  MyPlayTone(880,200);
  MyWait(240);
  MyPlayTone(784,200);
  MyWait(240);
  MyPlayTone(698,200);
  MyWait(240);
  MyPlayTone(698,400);
  MyWait(480);

  //For the people who are still alive.
  ClearLyrics();
  nxtDisplayCenteredTextLine(1, "for the people  ");
  nxtDisplayCenteredTextLine(2, "who are         ");
  nxtDisplayCenteredTextLine(4, "   still alive. ");
  MyPlayTone(587,200);
  MyWait(240);
  MyPlayTone(523,200);
  MyWait(240);
  MyPlayTone(587,200);
  MyWait(240);
  MyPlayTone(698,200);
  MyWait(240);
  MyPlayTone(698,200);
  MyWait(240);
  MyPlayTone(659,400);
  MyWait(480);
  MyPlayTone(659,200);
  MyWait(240);
  MyPlayTone(740,200);
  MyWait(240);
  MyPlayTone(740,600);
  MyWait(700);
  MyWait(480);
  MyWait(960);
  MyWait(1920);
  MyWait(1920);


  //#:c,f
  //[One last thing:] Go ahead and leave me.
  ClearLyrics();
  nxtDisplayCenteredTextLine(1, "One last thing: ");
  nxtDisplayCenteredTextLine(3, "Go ahead and    ");
  nxtDisplayCenteredTextLine(4, "leave me.       ");
  MyWait(960);
  MyPlayTone(784,200);
  MyWait(240);
  MyPlayTone(740,100);
  MyWait(120);
  MyPlayTone(740,100);
  MyWait(120);
  MyPlayTone(659,200);
  MyWait(240);
  MyPlayTone(659,400);
  MyWait(480);
  MyPlayTone(740,200);
  MyWait(240);
  MyWait(480);
  MyWait(960);

  //I think I'd prefer to stay inside.
  ClearLyrics();
  nxtDisplayCenteredTextLine(1, "I think I'd     ");
  nxtDisplayCenteredTextLine(2, "prefer to stay  ");
  nxtDisplayCenteredTextLine(3, "inside.         ");
  MyWait(480);
  MyWait(240);
  MyPlayTone(440,200);
  MyWait(240);
  MyPlayTone(784,200);
  MyWait(240);
  MyPlayTone(740,200);
  MyWait(240);
  MyPlayTone(659,200);
  MyWait(240);
  MyPlayTone(659,200);
  MyWait(240);
  MyWait(480);
  MyPlayTone(740,200);
  MyWait(240);
  MyPlayTone(587,200);
  MyWait(240);
  MyWait(480);
  MyPlayTone(659,200);
  MyWait(240);
  MyPlayTone(440,400);
  MyWait(480);
  MyWait(240);
  MyWait(480);
  MyWait(960);

  //Maybe you'll find someone else to help you.
  ClearLyrics();
  nxtDisplayCenteredTextLine(1, "Maybe you'll    ");
  nxtDisplayCenteredTextLine(2, "find someone    ");
  nxtDisplayCenteredTextLine(3, "else to help    ");
  nxtDisplayCenteredTextLine(4, "you.            ");
  MyPlayTone(659,400);
  MyWait(480);
  MyPlayTone(740,200);
  MyWait(240);
  MyPlayTone(784,600);
  MyWait(700);
  MyPlayTone(659,400);
  MyWait(480);
  MyPlayTone(554,400);
  MyWait(480);
  MyPlayTone(587,200);
  MyWait(240);
  MyPlayTone(659,600);
  MyWait(700);
  MyPlayTone(440,200);
  MyWait(240);
  MyPlayTone(440,400);
  MyWait(480);
  MyPlayTone(740,200);
  MyWait(240);
  MyWait(480);
  MyWait(960);

  //Maybe Black Mesa...
  ClearLyrics();
  nxtDisplayCenteredTextLine(1, "Maybe Black Mesa");
  nxtDisplayCenteredTextLine(2, "      ...       ");
  MyWait(960);
  MyPlayTone(784,200);
  MyWait(240);
  MyPlayTone(740,200);
  MyWait(240);
  MyPlayTone(659,200);
  MyWait(240);
  MyPlayTone(659,400);
  MyWait(480);
  MyPlayTone(740,200);
  MyWait(240);
  MyWait(480);
  MyWait(960);

  //THAT WAS A JOKE. HA HA. FAT CHANCE
  ClearLyrics();
  nxtDisplayCenteredTextLine(1, "THAT WAS A JOKE.");
  nxtDisplayCenteredTextLine(3, "  HA HA.        ");
  nxtDisplayCenteredTextLine(5, "     FAT CHANCE.");
  MyPlayTone(784,200);
  MyWait(240);
  MyPlayTone(740,200);
  MyWait(240);
  MyPlayTone(659,200);
  MyWait(240);
  MyPlayTone(659,200);
  MyWait(240);
  MyWait(480);
  MyPlayTone(740,200);
  MyWait(240);
  MyPlayTone(587,200);
  MyWait(240);
  MyWait(480);
  MyPlayTone(659,200);
  MyWait(240);
  MyPlayTone(440,400);
  MyWait(480);
  MyWait(240);
  MyWait(480);
  MyWait(960);

  //Anyway. This cake is great,
  ClearLyrics();
  nxtDisplayCenteredTextLine(1, "Anyway. This    ");
  nxtDisplayCenteredTextLine(2, "cake is great,  ");
  MyPlayTone(659,400);
  MyWait(480);
  MyPlayTone(740,200);
  MyWait(240);
  MyPlayTone(784,600);
  MyWait(700);
  MyPlayTone(659,400);
  MyWait(480);
  MyPlayTone(554,400);
  MyWait(480);
  MyPlayTone(587,200);
  MyWait(240);
  MyPlayTone(659,200);
  MyWait(240);
  MyWait(240);

  //it's so delicious and moist.
  ClearLyrics();
  nxtDisplayCenteredTextLine(1, "it's so         ");
  nxtDisplayCenteredTextLine(2, "delicious and   ");
  nxtDisplayCenteredTextLine(3, "moist.          ");
  MyPlayTone(440,200);
  MyWait(240);
  MyPlayTone(587,200);
  MyWait(240);
  MyPlayTone(659,200);
  MyWait(240);
  MyPlayTone(698,200);
  MyWait(240);
  MyPlayTone(659,200);
  MyWait(240);
  MyPlayTone(587,200);
  MyWait(240);
  MyPlayTone(523,200);
  MyWait(240);
  MyWait(480);


  //b:b
  //Look at me still talking when there's Science to do.
  ClearLyrics();
  nxtDisplayCenteredTextLine(1, "Look at me still");
  nxtDisplayCenteredTextLine(2, "talking when    ");
  nxtDisplayCenteredTextLine(3, "there's Science ");
  nxtDisplayCenteredTextLine(4, "to do.          ");
  MyPlayTone(440,200);
  MyWait(240);
  MyPlayTone(466,200);
  MyWait(240);
  MyPlayTone(523,400);
  MyWait(480);
  MyPlayTone(698,400);
  MyWait(480);
  MyPlayTone(659,200);
  MyWait(240);
  MyPlayTone(587,200);
  MyWait(240);
  MyPlayTone(587,200);
  MyWait(240);
  MyPlayTone(523,200);
  MyWait(240);
  MyPlayTone(587,200);
  MyWait(240);
  MyPlayTone(523,200);
  MyWait(240);
  MyPlayTone(523,400);
  MyWait(480);
  MyPlayTone(523,400);
  MyWait(480);

  //When I look out there it makes me GLaD I'm not you.
  ClearLyrics();
  nxtDisplayCenteredTextLine(1, "When I look out ");
  nxtDisplayCenteredTextLine(2, "there it makes  ");
  nxtDisplayCenteredTextLine(3, "me GLaD I'm not ");
  nxtDisplayCenteredTextLine(4, "you.            ");
  MyPlayTone(440,200);
  MyWait(240);
  MyPlayTone(466,200);
  MyWait(240);
  MyPlayTone(523,400);
  MyWait(480);
  MyPlayTone(698,400);
  MyWait(480);
  MyPlayTone(784,200);
  MyWait(240);
  MyPlayTone(698,200);
  MyWait(240);
  MyPlayTone(659,200);
  MyWait(240);
  MyPlayTone(587,200);
  MyWait(240);
  MyPlayTone(587,200);
  MyWait(240);
  MyPlayTone(659,200);
  MyWait(240);
  MyPlayTone(698,400);
  MyWait(480);
  MyPlayTone(698,400);
  MyWait(480);

  //I've experiments to run.
  ClearLyrics();
  nxtDisplayCenteredTextLine(1, "I've experiments");
  nxtDisplayCenteredTextLine(2, "to run.         ");
  MyPlayTone(784,200);
  MyWait(240);
  MyPlayTone(880,200);
  MyWait(240);
  MyPlayTone(932,200);
  MyWait(240);
  MyPlayTone(932,200);
  MyWait(240);
  MyPlayTone(880,200);
  MyWait(240);
  MyPlayTone(784,200);
  MyWait(240);
  MyPlayTone(784,400);
  MyWait(480);

  //There is research to be done
  ClearLyrics();
  nxtDisplayCenteredTextLine(1, "There is        ");
  nxtDisplayCenteredTextLine(2, "research to be  ");
  nxtDisplayCenteredTextLine(3, "done            ");
  MyPlayTone(698,200);
  MyWait(240);
  MyPlayTone(784,200);
  MyWait(240);
  MyPlayTone(880,200);
  MyWait(240);
  MyPlayTone(880,200);
  MyWait(240);
  MyPlayTone(784,200);
  MyWait(240);
  MyPlayTone(698,200);
  MyWait(240);
  MyPlayTone(698,400);
  MyWait(480);

  //on the people who are still alive.
  ClearLyrics();
  nxtDisplayCenteredTextLine(1, "on the people   ");
  nxtDisplayCenteredTextLine(2, "who are         ");
  nxtDisplayCenteredTextLine(4, "    still alive.");
  MyPlayTone(587,200);
  MyWait(240);
  MyPlayTone(523,200);
  MyWait(240);
  MyPlayTone(587,200);
  MyWait(240);
  MyPlayTone(698,200);
  MyWait(240);
  MyPlayTone(698,200);
  MyWait(240);
  MyPlayTone(659,400);
  MyWait(480);
  MyPlayTone(659,200);
  MyWait(240);
  MyPlayTone(740,200);
  MyWait(240);
  MyPlayTone(740,600);
  MyWait(700);
  MyWait(480);
  MyWait(480);



  //#:c,f
  //[PS:] And believe me I am still alive.
  ClearLyrics();
  nxtDisplayCenteredTextLine(1, "PS:             ");
  nxtDisplayCenteredTextLine(3, "And believe me  ");
  nxtDisplayCenteredTextLine(4, "I am            ");
  nxtDisplayCenteredTextLine(6, "    still alive.");
  MyPlayTone(880,200);
  MyWait(240);
  MyPlayTone(880,200);
  MyWait(240);
  MyPlayTone(988,200);
  MyWait(240);
  MyPlayTone(880,200);
  MyWait(240);
  MyPlayTone(740,200);
  MyWait(240);
  MyPlayTone(587,400);
  MyWait(480);
  MyPlayTone(659,200);
  MyWait(240);
  MyPlayTone(740,200);
  MyWait(240);
  MyPlayTone(740,400);
  MyWait(480);
  MyWait(700);
  MyWait(480);
  MyWait(240);

  //[PPS:] I'm doing science and I'm still alive.
  ClearLyrics();
  nxtDisplayCenteredTextLine(1, "PPS:            ");
  nxtDisplayCenteredTextLine(3, "I'm doing       ");
  nxtDisplayCenteredTextLine(4, "science and I'm ");
  nxtDisplayCenteredTextLine(6, "    still alive.");
  MyPlayTone(880,200);
  MyWait(240);
  MyPlayTone(880,200);
  MyWait(240);
  MyPlayTone(880,200);
  MyWait(240);
  MyPlayTone(988,200);
  MyWait(240);
  MyPlayTone(880,200);
  MyWait(240);
  MyPlayTone(740,200);
  MyWait(240);
  MyPlayTone(587,400);
  MyWait(480);
  MyPlayTone(659,200);
  MyWait(240);
  MyPlayTone(740,200);
  MyWait(240);
  MyPlayTone(740,600);
  MyWait(700);
  MyWait(480);
  MyWait(240);

  //[PPPS:] I feel FANTASTIC and I'm still alive.
  ClearLyrics();
  nxtDisplayCenteredTextLine(1, "PPPS:           ");
  nxtDisplayCenteredTextLine(3, "I feel FANTASTIC");
  nxtDisplayCenteredTextLine(4, "and I'm         ");
  nxtDisplayCenteredTextLine(6, "    still alive.");
  MyPlayTone(880,200);
  MyWait(240);
  MyPlayTone(880,200);
  MyWait(240);
  MyPlayTone(880,200);
  MyWait(240);
  MyPlayTone(988,200);
  MyWait(240);
  MyPlayTone(880,200);
  MyWait(240);
  MyPlayTone(740,200);
  MyWait(240);
  MyPlayTone(587,400);
  MyWait(480);
  MyPlayTone(659,200);
  MyWait(240);
  MyPlayTone(740,200);
  MyWait(240);
  MyPlayTone(740,600);
  MyWait(700);
  MyWait(480);
  MyWait(480);

  //[FINAL THOUGHT:] While you're dying I'll be still alive.
  ClearLyrics();
  nxtDisplayCenteredTextLine(1, "FINAL THOUGHT:  ");
  nxtDisplayCenteredTextLine(3, "While you're    ");
  nxtDisplayCenteredTextLine(4, "dying I'll be   ");
  nxtDisplayCenteredTextLine(6, "    still alive.");
  MyPlayTone(880,200);
  MyWait(240);
  MyPlayTone(880,200);
  MyWait(240);
  MyPlayTone(988,200);
  MyWait(240);
  MyPlayTone(880,200);
  MyWait(240);
  MyPlayTone(740,200);
  MyWait(240);
  MyPlayTone(587,400);
  MyWait(480);
  MyPlayTone(659,200);
  MyWait(240);
  MyPlayTone(740,200);
  MyWait(240);
  MyPlayTone(740,400);
  MyWait(480);
  MyWait(480);
  MyWait(240);

  //[FINAL THOUGHT PS:]And when you're dead I will be still alive.
  ClearLyrics();
  nxtDisplayCenteredTextLine(1, "FINAL THOUGHT PS");
  nxtDisplayCenteredTextLine(3, "And when you're ");
  nxtDisplayCenteredTextLine(4, "dead I will be  ");
  nxtDisplayCenteredTextLine(6, "    still alvie.");
  MyPlayTone(880,200);
  MyWait(240);
  MyPlayTone(880,200);
  MyWait(240);
  MyPlayTone(880,200);
  MyWait(240);
  MyPlayTone(988,200);
  MyWait(240);
  MyPlayTone(880,200);
  MyWait(240);
  MyPlayTone(740,200);
  MyWait(240);
  MyPlayTone(587,400);
  MyWait(480);
  MyPlayTone(659,200);
  MyWait(240);
  MyPlayTone(740,200);
  MyWait(240);
  MyPlayTone(740,400);
  MyWait(480);
  MyWait(480);
  MyWait(240);

  //STILL ALIVE.
  ClearLyrics();
  nxtDisplayCenteredTextLine(4, " STILL ALIVE.   ");
  MyPlayTone(784,200);
  MyWait(240);
  MyPlayTone(880,200);
  MyWait(240);
  MyPlayTone(880,600);
  MyWait(700);
  MyWait(480);
  MyWait(240);

  //STILL ALIVE.
  ClearLyrics();
  nxtDisplayCenteredTextLine(4, " STILL ALIVE.   ");
  MyPlayTone(784,200);
  MyWait(240);
  MyPlayTone(740,200);
  MyWait(240);
  MyPlayTone(740,600);
  MyWait(700);
  MyWait(480);
  MyWait(960);
}

task main() {
	StartTask(GLaDOS);
	while(true) {
		nxtDisplayCenteredTextLine(8, "[]speed:%d     ", speed);
    while(nNxtButtonPressed != 3) {
			wait1Msec(175);
			if (nNxtButtonPressed == 2 && speed > 10) {
				speed -= 10;
				nxtDisplayCenteredTextLine(8, "[]speed:%d     ", speed);
			}
			if (nNxtButtonPressed == 1 && speed < 200) {
				speed += 10;
				nxtDisplayCenteredTextLine(8, "[]speed:%d     ", speed);
			}
		}
		nxtDisplayCenteredTextLine(8, "[]volume:%d    ", nVolume);
		while(nNxtButtonPressed != 3) {
			wait1Msec(175);
			if (nNxtButtonPressed == 2 && nVolume > 0) {
				nVolume -= 1;
				nxtDisplayCenteredTextLine(8, "[]volume:%d    ", nVolume);
			}
			if (nNxtButtonPressed == 1 && nVolume < 4) {
				nVolume += 1;
				nxtDisplayCenteredTextLine(8, "[]volume:%d    ", nVolume);
			}
		}
	}
}
