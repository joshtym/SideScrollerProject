Scroller
==============================================

Dependencies
---------------------------------------------
Allegro 5 libray

Install using:
sudo apt-get install liballegro5

Available Platforms
---------------------------------------------
Currently only compiles on linux. Probably would be easy
to make it compile on OSX or Windows

Description
---------------------------------------------
Simple little game that allows the player to control an animated
2 dimensional character. The game has a constantly moving camera, which
will speed up the longer the player plays. The goal is to survive as long
possible, avoiding deadly objects and avoiding getting squished between]
the edge of the screen and an object. Note, that a current experimental
feature we have is "running off the cliff" at the far right of the map.
So if you go to far to the right, you're toast.

Controls
------------------------------------------------
Simple controls are as follows

- WASD is to control the movement of your character
- Space is to jump at any time.

Execute
-----------------------------------------------------
To execute this script, all you need to do is type is "./executeScript"
This will clean the current compilation and make a new one as well as link
the profiler to be compatible with allegro as well as run the program

Notes
-----------------------------------------------------------
Note that this has been purely built on Ubuntu and will not be
compatible with windows. If running it from the school computers, I've
added a makefileAtSchool file into the src that allows for running at
school
