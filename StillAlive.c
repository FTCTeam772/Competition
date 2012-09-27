//PORTAL CREDITS SONG: STILL ALIVE

/* Controls:
 *
 * Orange []: Switch between showing and setting volume and speed
 * < and >: Change value
 */

//sheet music: http://www.scribd.com/doc/2183619/Portals-Still-Alive-Sheet-Music

unsigned short speed = 90;

void MyPlayTone(unsigned short frequency, unsigned short duration) {
	PlayTone(frequency, duration*speed/1000);
}

void MyWait(unsigned short ms) {
	wait1Msec(ms*speed/100);
}

void ClearLyrics() {
	nxtDisplayTextLine(1, "                ");
	nxtDisplayTextLine(2, "                ");
	nxtDisplayTextLine(3, "                ");
	nxtDisplayTextLine(4, "                ");
	nxtDisplayTextLine(5, "                ");
	nxtDisplayTextLine(6, "                ");
}

task GLaDOS() {
  //#: c,f
  //This was a triumph.
	ClearLyrics();
	nxtDisplayTextLine(1, "This was a      "); //16 chars/line
	nxtDisplayTextLine(2, "triumph.        ");
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
  nxtDisplayTextLine(1, "I'm making a    ");
  nxtDisplayTextLine(2, "note here,      ");
  nxtDisplayTextLine(3, "                ");
  nxtDisplayTextLine(4, "                ");
  nxtDisplayTextLine(5, "HUGE SUCCESS.   ");
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
  nxtDisplayTextLine(1, "It's hard to    ");
  nxtDisplayTextLine(2, "overstate my    ");
  nxtDisplayTextLine(3, "satisfaction.   ");
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
  nxtDisplayTextLine(1, "  Aperture      ");
  nxtDisplayTextLine(2, "     Science,   ");
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
  nxtDisplayTextLine(1, "we do what we   ");
  nxtDisplayTextLine(2, "must            ");
  nxtDisplayTextLine(3, "                ");
  nxtDisplayTextLine(4, "   because      ");
  nxtDisplayTextLine(5, "                ");
  nxtDisplayTextLine(6, "       we can.  ");
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
  nxtDisplayTextLine(1, "for the good of ");
  nxtDisplayTextLine(2, "all of us       ");
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
  nxtDisplayTextLine(1, "except the ones ");
  nxtDisplayTextLine(2, "who are dead.   ");
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
  nxtDisplayTextLine(1, "But there's no  ");
  nxtDisplayTextLine(2, "sense crying    ");
  nxtDisplayTextLine(3, "over ev'ry      ");
  nxtDisplayTextLine(4, "mistake,        ");
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
  nxtDisplayTextLine(1, "you just keep on");
  nxtDisplayTextLine(2, "trying till you ");
  nxtDisplayTextLine(3, "run out of cake,");
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
  nxtDisplayTextLine(1, "and the Science ");
  nxtDisplayTextLine(2, "gets done and   ");
  nxtDisplayTextLine(3, "you make a neat ");
  nxtDisplayTextLine(4, "gun             ");
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
  nxtDisplayTextLine(1, "for the people  ");
  nxtDisplayTextLine(2, "who are         ");
  nxtDisplayTextLine(4, "   still alive. ");
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
  nxtDisplayTextLine(3, "I'm not even    ");
  nxtDisplayTextLine(4, "angry.          ");
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
  nxtDisplayTextLine(1, "I'm being so    ");
  nxtDisplayTextLine(2, "sincere right   ");
  nxtDisplayTextLine(3, "now             ");
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
  nxtDisplayTextLine(1, "even though you ");
  nxtDisplayTextLine(2, "broke my heart  ");
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
  nxtDisplayTextLine(3, "  and killed me ");
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
  nxtDisplayTextLine(1, "and tore me to  ");
  nxtDisplayTextLine(2, "    pieces      ");
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
  nxtDisplayTextLine(1, "and threw ev'ry ");
  nxtDisplayTextLine(2, "piece           ");
  nxtDisplayTextLine(4, "   into         ");
  nxtDisplayTextLine(6, "       a fire.  ");
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
  nxtDisplayTextLine(1, "As they burned  ");
  nxtDisplayTextLine(2, "it hurt because ");
  nxtDisplayTextLine(4, "I was so happy  ");
  nxtDisplayTextLine(5, "   for you!     ");
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
  nxtDisplayTextLine(1, "Now these points");
  nxtDisplayTextLine(2, "of data make a  ");
  nxtDisplayTextLine(3, "beautiful line; ");
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
  nxtDisplayTextLine(1, "and we're out of");
  nxtDisplayTextLine(2, " beta,          ");
  nxtDisplayTextLine(4, "we're releasing ");
  nxtDisplayTextLine(5, "on time.        ");
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
  nxtDisplayTextLine(1, "So I'm GLaD.    ");
  nxtDisplayTextLine(2, "I got burned.   ");
  nxtDisplayTextLine(4, "Think of all the");
  nxtDisplayTextLine(5, "things we       ");
  nxtDisplayTextLine(6, "learned         ");
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
  nxtDisplayTextLine(1, "for the people  ");
  nxtDisplayTextLine(2, "who are         ");
  nxtDisplayTextLine(4, "   still alive. ");
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
  nxtDisplayTextLine(1, "One last thing: ");
  nxtDisplayTextLine(3, "Go ahead and    ");
  nxtDisplayTextLine(4, "leave me.       ");
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
  nxtDisplayTextLine(1, "I think I'd     ");
  nxtDisplayTextLine(2, "prefer to stay  ");
  nxtDisplayTextLine(3, "inside.         ");
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
  nxtDisplayTextLine(1, "Maybe you'll    ");
  nxtDisplayTextLine(2, "find someone    ");
  nxtDisplayTextLine(3, "else to help    ");
  nxtDisplayTextLine(4, "you.            ");
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
  nxtDisplayTextLine(1, "Maybe Black Mesa");
  nxtDisplayTextLine(2, "      ...       ");
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
  nxtDisplayTextLine(1, "THAT WAS A JOKE.");
  nxtDisplayTextLine(3, "  HA HA.        ");
  nxtDisplayTextLine(5, "     FAT CHANCE.");
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
  nxtDisplayTextLine(1, "Anyway. This    ");
  nxtDisplayTextLine(2, "cake is great,  ");
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
  nxtDisplayTextLine(1, "it's so         ");
  nxtDisplayTextLine(2, "delicious and   ");
  nxtDisplayTextLine(3, "moist.          ");
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
  nxtDisplayTextLine(1, "Look at me still");
  nxtDisplayTextLine(2, "talking when    ");
  nxtDisplayTextLine(3, "there's Science ");
  nxtDisplayTextLine(4, "to do.          ");
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
  nxtDisplayTextLine(1, "When I look out ");
  nxtDisplayTextLine(2, "there it makes  ");
  nxtDisplayTextLine(3, "me GLaD I'm not ");
  nxtDisplayTextLine(4, "you.            ");
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
  nxtDisplayTextLine(1, "I've experiments");
  nxtDisplayTextLine(2, "to run.         ");
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
  nxtDisplayTextLine(1, "There is        ");
  nxtDisplayTextLine(2, "research to be  ");
  nxtDisplayTextLine(3, "done            ");
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
  nxtDisplayTextLine(1, "on the people   ");
  nxtDisplayTextLine(2, "who are         ");
  nxtDisplayTextLine(4, "    still alive.");
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
  nxtDisplayTextLine(1, "PS:             ");
  nxtDisplayTextLine(3, "And believe me  ");
  nxtDisplayTextLine(4, "I am            ");
  nxtDisplayTextLine(6, "    still alive.");
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
  nxtDisplayTextLine(1, "PPS:            ");
  nxtDisplayTextLine(3, "I'm doing       ");
  nxtDisplayTextLine(4, "science and I'm ");
  nxtDisplayTextLine(6, "    still alive.");
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
  nxtDisplayTextLine(1, "PPPS:           ");
  nxtDisplayTextLine(3, "I feel FANTASTIC");
  nxtDisplayTextLine(4, "and I'm         ");
  nxtDisplayTextLine(6, "    still alive.");
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
  nxtDisplayTextLine(1, "FINAL THOUGHT:  ");
  nxtDisplayTextLine(3, "While you're    ");
  nxtDisplayTextLine(4, "dying I'll be   ");
  nxtDisplayTextLine(6, "    still alive.");
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
  nxtDisplayTextLine(1, "FINAL THOUGHT PS");
  nxtDisplayTextLine(3, "And when you're ");
  nxtDisplayTextLine(4, "dead I will be  ");
  nxtDisplayTextLine(6, "    still alvie.");
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
  nxtDisplayTextLine(4, " STILL ALIVE.   ");
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
  nxtDisplayTextLine(4, " STILL ALIVE.   ");
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
		}
		while(nNxtButtonPressed == 3);
	}
}
