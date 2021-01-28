//Slave device of the SPI communication
#include"spiSelf.h"

char bufferSend[64];
char i = 0;
char index=0;

void setup()
{
  // initialize SPI :
  SpiInit();
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
    static char cnt=0;
    //Here we read the SPI lines
    //This line will check data for every ASCII codes for 8-bit received data
    //SPDR -> SPI Data Read bit
    SPDR = i;
    i ++;
    if ( i > 255) 
      i = 0;
    while(!(SPSR & (1 << SPIF)));
    //Load the received data to the variable
    char received = SPDR;
    //And send it to the serial communication bus
    Serial.print("receive from the master = ");
    Serial.println((char)received);
   index=cnt;
    bufferSend[cnt]=received;
    cnt++;
    cnt%=64;
  
}
