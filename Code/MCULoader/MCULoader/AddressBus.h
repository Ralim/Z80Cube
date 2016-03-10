/* 
* AddressBus.h
*
* Created: 10/03/2016 9:22:28 PM
* Author: Ralim
*/


#ifndef __ADDRESSBUS_H__
#define __ADDRESSBUS_H__
#include <avr/io.h>

class AddressBus
{
//variables
public:
protected:
private:

//functions
public:
	AddressBus();
	~AddressBus();
	void readBus(uint8_t* data,uint16_t* address);//Reads the current bus lines back
	void takeOverBus();//tells the mcu to stop the z80 to take over
	void writeBus(uint8_t data, uint16_t address,bool memory);
	void singleStep();//makes the z80 perform a single step
	void writeValue();
	void readValue(uint8_t* data, uint16_t* address);
protected:
private:
	AddressBus( const AddressBus &c );
	AddressBus& operator=( const AddressBus &c );

}; //AddressBus

#endif //__ADDRESSBUS_H__
