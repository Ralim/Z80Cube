# Z80Cube - Project Zeta
A 5 layer 5cm * 5cm cubish shaped z80 machine
Basically designed as a learning experience.
Big difference from other builds I have seen is the entire system runs on a 64K memory space of ram, and the atmega2560 pre-load's the bootloader into the chip on system startup.
This bootloader for the z80 then allows the user to test memory and load + execute programs.

## Layers
* Bus Display ->Led indicators for the bus
* Z80 CPU
* 64K SRAM/ROM
* Power and Programmer (Atmega 2560+flash storage to store the software)


##ToDo:
Basically everything
* Build PCBs
* Test PCBs
* Write the code for the bootloader (Going to use Arduino to keep it easy for others)
* Write arduino code for storing program packages
* Write arduino code for monitoring the bus
* write arduino code for single stepping operation
