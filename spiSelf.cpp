#include"spiSelf.h"
//#define SlaveSelection  10
void SpiInit(void)
{
   // initialize SPI :
  pinMode(10 , INPUT); // Set SlaveSelection as input
  pinMode(13,OUTPUT);   // Set clk as output
  pinMode(11,OUTPUT);   // Set MOSI as output
  pinMode(12,INPUT);    // Set MISO as input
  
  // SPCR - SPI Control Register
  // According to struct table we enable the SPI and Interface
  SPCR  |= 0b11000000;
  // SPSR - SPI Status Register
  SPSR  |= 0x00;


}

