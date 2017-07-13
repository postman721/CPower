# CPower
Repository for ++Power (C++ program)

A program written with C++ for system rebooting, suspension and powering off. The overall content is about 70 lines long.

![power x70132](https://user-images.githubusercontent.com/29865797/28171527-5c8f78d6-67f1-11e7-8c6e-89bab03400cc.jpg)

/*++Power v.1 Copyright (c) 2017 JJ Posti <techtimejourney.net>
This program comes with ABSOLUTELY NO WARRANTY;
for details see: http://www.gnu.org/copyleft/gpl.html.
This is free software, and you are welcome to redistribute it under
GPL Version 2, June 1991″)*/

You need something along the lines of libgtk-3-dev and build-essential
installed in order to compile ++Power. Also make sure to install pkg-config.

Compile with the command:

g++ power.cpp -o power `pkg-config --cflags --libs gtk+-3.0`

-o power is the output file. Adjust cflags and libs to match your system – if needed.

Run the program with this command: ./power . If needed make the progam executable with: chmod +x power .

Note by default ++Power assumes gksudo usage( a sudo account). You can easily change this to gksu if you are having an actual root account. Of course, make sure that you have either gksu or gksudo installed – in order to achieve full functionality.

++Power(C++) vs. Power Manager(Python) considerations:

These two programs do similar tasks.  ++Power remains a more generic alternative while Power Manager has some Openbox integrations and i3lock integrations in it.

-----------------------------------------
Original post is at:
http://www.techtimejourney.net/power-c-is-released/
