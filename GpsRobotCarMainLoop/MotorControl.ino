void MotorControl(int power){
  if(power <= motormin){
    power = motormin;
  }else if(power >= motormax){
    power = motormax;
  }
  motor.writeMicroseconds(1500 - power * 5);
}

