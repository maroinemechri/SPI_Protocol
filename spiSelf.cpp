#include"spiSelf.h"

char bufferSend[64]={0};

char index;
void spiSlaveInit(void)
{
   /*initialize SPI :
	pinMode(10 , INPUT); // Set SlaveSelection as input
  	pinMode(13,OUTPUT);   // Set clk as output           //valude
  	pinMode(11,OUTPUT);   // Set MOSI as output          //valude
  	pinMode(12,INPUT);    // Set MISO as input           //valude
   */

  DDRB=0x20;// OR (1<<5)|(1<<3)|(0<<2)|(0<<4);

//register config
  
  // SPCR - SPI Control Register
  // According to struct table we enable the SPI and Interface
  SPCR  |= 0b11000000;
// SPSR - SPI Status Register
  SPSR  |= 0x00;


}

