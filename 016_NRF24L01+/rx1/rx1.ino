//Include Libraries
#include <SPI.h>
//#include <nRF24L01.h>
#include <RF24.h>
#include <printf.h>

//create an RF24 object
RF24 radio(9, 10);  // CE, CSN

//address through which two modules communicate.
const byte address[] = "1node";
uint8_t num1=0;
void setup()
{

  Serial.begin(115200);
  radio.begin();
  delay(1000);
  radio.setChannel(115);
  radio.setPALevel(RF24_PA_MIN);
  radio.setDataRate(RF24_250KBPS);
  /*
  radio.setPALevel(RF24_PA_MIN);
  radio.disableDynamicPayloads();
  radio.setAutoAck(false);
  radio.setRetries(15, 15);
  printf_begin();
  radio.printDetails();
  */
  //set the address
  radio.openReadingPipe(0, address);
  delay(1000);
  //Set module as receiver
  radio.startListening();
}

void loop()
{
  //Read the data if available in buffer
  if (radio.available())
  {
    //char text[32] = {0};
    //radio.read(&text, sizeof(text));
    radio.read(&num1, sizeof(num1));
    Serial.print("rx1: ");Serial.println(num1);
  }else{
    //Serial.print("rx1: ");Serial.println("unavailable");
  }
  
}