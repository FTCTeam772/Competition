This repository contains all files used by Team 772 for the FIRST Tech Challenge. A majority of the files are RobotC source files, however there are other files as well for making music for the NXT.

All code is open source under the MIT License, see `LICENSE` for details. All of the music is under copyright by its artist, simplified and reproduced here under fair use.

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
- StillAlive.mus: This was a triumph...
- Mario.mus: Super Mario Bros. theme song

### Music File Format ###
Music files are in a relatively simple format with both a tone and lyric engine. They use the .nms extension on the NXT and can be played by the Player program. The basic structure of a .nms file is as the following:
```
Test song
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
tone 262 20 24
```
