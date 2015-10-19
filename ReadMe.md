REACT Festival: Light Bug
===

####Introduction
This is an addon project for Tine Bech's [Light Bug](http://www.react-hub.org.uk/playsandbox/projects/2014/light-bug/) project for [REACT's PlaySandbox](http://www.react-hub.org.uk/playsandbox/).

It will be part of the REACT Festival [The Rooms](http://theroomsfestival.com/).

It takes commands from the Light Bug Swing through UART and outputs DMX signals.

####Requirements
* 1 x Raspberry Pi
* 1 x [Enttec DMXUSB Pro](http://www.enttec.com/?main_menu=Products&pn=70304)
* 1 x [4 Channel Bi-Directional Logic Level Convertor](https://www.coolcomponents.co.uk/logic-level-converter-bi-directional.html)
* 16 x RGB DMX Controlled Lights. Set to RGB 3 channel mode

####How to Compile
After either sshing in or using a monitor and keyboard, move into the directory.

````cd openFrameworks/apps/myApps/REACTFestival_Light-BugRPI````

Then

````make run````

####Connections
You will need to plug the DMXPro into the RPI via the USB Hub, its address is generally /dev/ttyUSB0
Otherwise check the port list
````ls -l /dev/tty*````

Add the name of the port to the config file found in the bin/data folder, under the dmxcontrolleraddress.

Similarly we are using the UART GPIO pins to get data in from the light bug itself.
Its address is generally /dev/ttyAM0.

The pins are connected via a Logic Level Converter, this takes the 5v signal from any input source and makes the signal safe for the RPI which is 3.3v.

![BreadBoard](LighBug_bb.jpg "BreadBoard")

####Protocol
The Light Bug unit sends Serial commands to the RPI which dictates what happens to the lights.
These commands are prefixed with a # which validates the command and allows the app to fire an event to the lights.

For example if I want to tell all the lights to turn off, I call

```#AOFF\n```

The new line signals to the app to fire the message and clear the port ready for the next command.

You can fire multiple commands to the lights by concatinating the commands.

For example light 1 to be red, light 5 to be green2 and light 6 to blue4.
The command would be:

````#1OR1,5OG2,6OB4\n````

Here is a full list of the commands.

Block Colors
```ALL_OFF "AOFF"
ALL_ON_WHITE "AOWH"
ALL_ON_R1 "AOR1"
ALL_ON_R2 "AOR2"
ALL_ON_R3 "AOR3"
ALL_ON_R4 "AOR4"
ALL_ON_G1 "AOG1"
ALL_ON_G2 "AOG2"
ALL_ON_G3 "AOG3"
ALL_ON_G4 "AOG4"
ALL_ON_B1 "AOB1"
ALL_ON_B2 "AOB2"
ALL_ON_B3 "AOB3"
ALL_ON_B4 "AOB4"```

Individual Lights
Replace the * with the light number.
```T*_ON_R1 "*OR1"
T*_ON_R2 "*OR2"
T*_ON_R3 "*OR3"
T*_ON_R4 "*OR4"
T*_ON_G1 "*OG1"
T*_ON_G2 "*OG2"
T*_ON_G3 "*OG3"
T*_ON_G4 "*OG4"
T*_ON_B1 "*OB1"
T*_ON_B2 "*OB2"
T*_ON_B3 "*OB3"
T*_ON_B4 "*OB4"
T*_ON_WH "*OWH"
T*_OFF "*OFF"```
