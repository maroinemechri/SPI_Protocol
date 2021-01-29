//Slave device of the SPI communication
#include"spiSelf.h"
void setup()
{
  // initialize SPI :
  spiSlaveInit();
  Serial.begin(9600);   
}  
 
void loop()
{
  delay(1000);
  Serial.print("The index of the bufferSend = " );
  Serial.println((int)index);
  Serial.print("the bufferSend[]=");
  Serial.println((char)bufferSend[index]);
}
//SPI Interrupt function 
ISR(SPI_STC_vect)
{
    volatile static char cnt=0;
    //Here we read the SPI lines
    //This line will check data for every ASCII codes for 8-bit received data
    //SPDR -> SPI Data Read bit
    //Load the received data to the variable
    volatile char received = SPDR;
    //And send it to the serial communication bus
    Serial.print("receive from the master = ");
    Serial.println(( char)received);
    index=cnt;
    Serial.println((int)cnt);
    bufferSend[cnt]=received;
    cnt++;
    cnt%=64;  
}
