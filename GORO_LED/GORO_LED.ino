#include <Wire.h>

int gyro_x, gyro_y, gyro_z;

long gyro_x_cal, gyro_y_cal, gyro_z_cal;

boolean set_gyro_angles;


long acc_x, acc_y, acc_z, acc_total_vector;

float angle_roll_acc, angle_pitch_acc;


float angle_pitch, angle_roll;

int angle_pitch_buffer, angle_roll_buffer;

float angle_pitch_output, angle_roll_output;


long loop_timer;

int temp;


void setup() {

  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);

  Wire.begin();                                                   

  setup_mpu_6050_registers();                                    

  for (int cal_int = 0; cal_int < 1000 ; cal_int ++){              

    read_mpu_6050_data();                                            

    gyro_x_cal += gyro_x;                                            

    gyro_y_cal += gyro_y;                                          

    gyro_z_cal += gyro_z;                                          

    delay(3);                                                
  }




  gyro_x_cal /= 1000;                                                

  gyro_y_cal /= 1000;                                                

  gyro_z_cal /= 1000;                                                

  Serial.begin(115200);

  loop_timer = micros();                                        

}


void loop(){


  read_mpu_6050_data();  


  gyro_x -= gyro_x_cal;                                               

  gyro_y -= gyro_y_cal;                                               

  gyro_z -= gyro_z_cal;                                               

        


  angle_pitch += gyro_x * 0.0000611;                                  

  angle_roll += gyro_y * 0.0000611;                                



  angle_pitch += angle_roll * sin(gyro_z * 0.000001066);           

  angle_roll -= angle_pitch * sin(gyro_z * 0.000001066);           




  acc_total_vector = sqrt((acc_x*acc_x)+(acc_y*acc_y)+(acc_z*acc_z)); 



  angle_pitch_acc = asin((float)acc_y/acc_total_vector)* 57.296;     

  angle_roll_acc = asin((float)acc_x/acc_total_vector)* -57.296;      



  angle_pitch_acc -= 0.0;                                             

  angle_roll_acc -= 0.0;


  if(set_gyro_angles){                                                

    angle_pitch = angle_pitch * 0.9996 + angle_pitch_acc * 0.0004;  

    angle_roll = angle_roll * 0.9996 + angle_roll_acc * 0.0004;       

  }

  else{                                                             

    angle_pitch = angle_pitch_acc;                                   

    angle_roll = angle_roll_acc;                                     

    set_gyro_angles = true;                                            
  }





  angle_pitch_output = angle_pitch_output * 0.9 + angle_pitch * 0.1;   

  angle_roll_output = angle_roll_output * 0.9 + angle_roll * 0.1;     

  Serial.print(" | Angle  = "); Serial.println(angle_pitch_output);
if(angle_pitch_output > 0 && angle_pitch_output < 5)
{
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);

}
else if(angle_pitch_output >= 5 && angle_pitch_output <= 20)
  {
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  }
else if(angle_pitch_output >= 20 && angle_pitch_output <= 35)
  {
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  }
else if(angle_pitch_output >= 35 && angle_pitch_output <= 50)
  {
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  }
else if(angle_pitch_output >= 50 && angle_pitch_output <= 65)
  {
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  }
else if(angle_pitch_output >= 65 && angle_pitch_output <= 90)
  {
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  }

  else if(angle_pitch_output <= 0 && angle_pitch_output >= -5)
  {
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  }

else if(angle_pitch_output <= -5 && angle_pitch_output >= -20)
  {
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  }
else if(angle_pitch_output <= -20 && angle_pitch_output >= -35)
  {
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  }
else if(angle_pitch_output <= -35 && angle_pitch_output >= -50)
  {
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  }
else if(angle_pitch_output <= -50 && angle_pitch_output >= -65)
  {
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(13,LOW);
  }
else if(angle_pitch_output <= -65 && angle_pitch_output >= -90)
  {
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(13,HIGH);
  }

 
 while(micros() - loop_timer < 4000);                                
 loop_timer = micros();


}





void setup_mpu_6050_registers(){

  //Activate the MPU-6050

  Wire.beginTransmission(0x68);                                      

  Wire.write(0x6B);                                               

  Wire.write(0x00);                                                 

  Wire.endTransmission();                                            


  Wire.beginTransmission(0x68);                                  

  Wire.write(0x1C);                                           

  Wire.write(0x10);                                                 

  Wire.endTransmission();                                            

  Wire.beginTransmission(0x68);                                     

  Wire.write(0x1B);                                                

  Wire.write(0x08);                                               

  Wire.endTransmission();                                            

}



void read_mpu_6050_data(){                                           

  Wire.beginTransmission(0x68);                                     

  Wire.write(0x3B);                                                  

  Wire.endTransmission();                                             

  Wire.requestFrom(0x68,14);                                       

  while(Wire.available() < 14);                                       

  acc_x = Wire.read()<<8|Wire.read();                                 

  acc_y = Wire.read()<<8|Wire.read();                                 

  acc_z = Wire.read()<<8|Wire.read();                                 

  temp = Wire.read()<<8|Wire.read();                                  

  gyro_x = Wire.read()<<8|Wire.read();                                

  gyro_y = Wire.read()<<8|Wire.read();                                

  gyro_z = Wire.read()<<8|Wire.read();     

                     
}
