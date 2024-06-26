#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";

int left_indicator=2;
int brake=3;
int right_indicator=4;

struct pack
{
  int left;
  int brake;
  int right;
} packet;


void setup()
{
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();

  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
}

void loop()
{
  packet.left=digitalRead(2);
  packet.brake=digitalRead(3);
  packet.right=digitalRead(4);

  radio.write(&packet,sizeof(packet));
  
}
