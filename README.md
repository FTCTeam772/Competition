This repository contains all files used by Team 772 for the FIRST Tech Challenge. A majority of the files are RobotC source files, however there are other files as well for making music for the NXT.

All code is open source under the MIT License, see `LICENSE` for details. All of the music is copyright by its artist, simplified and reproduced here under fair use.

Below is a list of all of the files and their purposes.

Competition Files
-----------------
- Auto.c: Autonomous mode program
- TeleOp.c: Tele-Operated mode program containing main drive and arm control functions
- common.h: Various functions useful between Auto.c and TeleOp.c
- constants.h: Constants to calibrate the programs to the robot and the field

Music Files
-----------
- Player.c: Song selector and player with speed and volume controls
- Player.h: Song player library that can be used in other programs

Music Folder
------------
- Makefile: A makefile for building the music compiler and compiling the music into NXT Music Files

### Files ###
- SuperMario.mus: Super Mario Bros. theme song
- ImperialMarch.mus: The Imperial March (Darth Vader's Theme)
- 1Up.mus: 1-Up sound from Super Mario Bros.
- CastleComplete.mus: The level complete sound from Super Mario Bros.
- Starman.mus: The sound when Mario is invincible

### NXT ###
- StillAlive.nms: This was a triumph...

### Compiler ###
- Makefile: A makefile for building MusicCompiler
- MusicCompiler.c: The source file for a program that converts music from .mus format to .nms for the NXT

Music File Format
-----------------
There are two music formats that are used, one that is easy to type up and is easy for humans to read and one that is easy for the NXT to read without much processing overhead.

### Music File ###
Music Files are basically a form of typed sheet music, making it easy to write. They use the .mus extension and are made to be compiled to the NXT Music File that is easy for the NXT to read. The basic structure of a .mus file is as the following:
```
Test Song
#That is the name of the song
#These are comments
#Composer: Foster McLane
keysig C
tempo 120

#Play a C on the 4th octave for a value of 1 (the tempo)
note C4 1
#Play an E
note E4 1
#Play a G
note G4 1
#Play a C on the 5th octave
note C5 1
#Go back down
note G4 1
note E4 1
note C4 2

#Wait for a whole rest (four times the value of the tempo)
rest 4

#Play four eigth notes (half of the value of the tempo)
note C4 0.5
note C4 0.5
note D4 0.5
note D4 0.5
#Play two staccato quarter notes (the value of the tempo)
note E4 1 staccato
note F4 1 staccato
#Play two legato quarter notes
note E4 1 legato
note D4 1 legato
#Finish it
note C4 2
```

### NXT Music File ###
NXT Music Files are in a relatively simple format with both a tone and lyric engine. They use the .nms extension on the NXT and can be played by the Player program. The basic structure of a .nms file is as the following:
```
Test Song
#That is the name of the song
#These are comments
#Composer: Foster McLane

#Play a C for 20 out of 24 centiseconds
tone 262 20 24
#Play a E
tone 330 20 24
#Play a G
tone 392 20 24
#Play a high C
tone 523 20 24
#Go back down
tone 392 20 24
tone 330 20 24
tone 262 40 48
```
