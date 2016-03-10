/*
* AddressBus.cpp
*
* Created: 10/03/2016 9:22:27 PM
* Author: Ralim
*/


#include "AddressBus.h"

// default constructor
AddressBus::AddressBus()
{
	
	//Data pins 0-7  = PortC
	//Addr pins 8-15 = PortA
	//Addr pins 0-7  = PortK
	DDRC=DDRA=DDRK=0;//all inputs for now
	
} //AddressBus

// default destructor
AddressBus::~AddressBus()
{
} //~AddressBus

void AddressBus::takeOverBus()
{
	DDRJ &= ~(1<<PJ5);//request by pulling the BUSRQ Low
	PORTJ &= ~(1<<PJ5);// ^
	uint8_t val =0xFF;
	while((val & PJ5) == 0x00)
	{
		val = PORTJ;//latch the port reading
	}
//we should now have free run of the bus
}
void AddressBus::readBus(uint8_t* data,uint16_t* address)
{
	(*data) = PORTC;
	(*address) = ((uint16_t)PORTA)<<8 | PORTK;
	
}
//Writes the data to the data bus lines and also set the memory/io line
void AddressBus::writeBus(uint8_t data, uint16_t address,bool memory=true)
{
	
	DDRA=0xFF;//addH
	DDRC=0xFF;//Data
	DDRK=0xFF;//addL
	PORTK=(uint8_t)address;
	PORTA=address>>8;
	PORTC=data;//save the data output
	if(memory)
	{
		//write the MEMRQ line low
		DDRD &=~(1<<PD2);//make it an output
		PORTD &=~(1<<PD2);//write it low
		
	}
	else
	{
		//write the IOREQ line low
		DDRD &=~(1<<PD3);//make it an output
		PORTD &=~(1<<PD3);//write it low
	}
}

//This will pulse the write line low long enough to latch the value into the memory at the other end.
void AddressBus::writeValue()
{
	DDRD &=~(1<<PD7);//make it an output
	PORTD &=~(1<<PD7);//write it low
	for(uint16_t i=0;i<65000;i++){}//delay a bit
	PORTD |=(1<<PD7);//write it high
	DDRD |= (1<<PD7);//make the pin an input
}
//this pulls the read line low and then reads the data on the bus, followed by releasing the read line
void AddressBus::readValue(uint8_t* data, uint16_t* address)
{
	DDRD &=~(1<<PD6);//make it an output
	PORTD &=~(1<<PD6);//write it low
	for(uint16_t i=0;i<65000;i++){}//delay a bit
	readBus(data,address);//read in the values that are on the data lines
	PORTD |=(1<<PD6);//write it high
	DDRD |= (1<<PD6);//make the pin an input
	
}

void AddressBus::singleStep()
{
	
	
}