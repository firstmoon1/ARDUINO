//Include Libraries
#include <SPI.h>
//#include <nRF24L01.h>
#include <RF24.h>
#include <printf.h>
//create an RF24 object
RF24 radio(9, 10);  // CE, CSN

//address through which two modules communicate.
const byte address[] = "1node";
bool check;
uint8_t num1=0;

void setup()
{
  Serial.begin(115200);
  radio.begin();
  delay(1000);
  radio.setChannel(115);
  radio.setPALevel(RF24_PA_MIN);
  radio.setDataRate(RF24_250KBPS);
  radio.openWritingPipe(address); //set the address
  delay(1000);
  //Set module as transmitter
  radio.stopListening();
}
void loop()
{

  //Send message to receiver
  //const char text[] = "Hello World";
  //check=radio.write(&text, sizeof(text));
  check=radio.write(&num1, sizeof(num1));
  Serial.print("tx1 num1 : ");Serial.print(num1);
  Serial.print(" tx1 check : ");Serial.println(check);
  num1++;
  delay(1000);

}