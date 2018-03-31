void ServoControl(int deg){
  if(deg > servomax){
        servo.writeMicroseconds(1500 + servomax * 5.56);
    }else if(deg < servomin){
        servo.writeMicroseconds(1500 + servomin * 5.56);
    }else if(deg >= servomin && deg <= servomax){
        servo.writeMicroseconds(1500 + deg * 5.56);  
    }
}
