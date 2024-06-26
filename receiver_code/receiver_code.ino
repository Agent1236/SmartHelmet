#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";

int left_ind=2;
int brake=3;
int right_ind=4;

struct pack
{
  int left;
  int Brake;
  int right;
} packet;

void setup()
{
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  
  pinMode(left_ind,OUTPUT);
  pinMode(brake,OUTPUT);
  pinMode(right_ind,OUTPUT);
}

void loop()
{
  if (radio.available()) 
  {
  radio.read(&packet,sizeof(packet));

     if(packet.left==1)
     {
      digitalWrite(2,HIGH);
     }
     else
     {
     digitalWrite(2,LOW);
     }
     
     if(packet.Brake==1)
     {
      digitalWrite(3,HIGH);
     }
     else
     {
     digitalWrite(3,LOW);
     }
     
     if(packet.right==1)
     {
      digitalWrite(4,HIGH);
     }
     else
     {
     digitalWrite(4,LOW);
     }
     
  Serial.print(packet.left);
  Serial.print('\n');
  //delay(1000);
  Serial.print(packet.Brake);
  Serial.print('\n');
  //delay(1000);
  Serial.print(packet.right);
  Serial.print('\n');
  Serial.print('\n');
  //delay(1000);
  }
 
}
