void PDegDistControl(int Ndeg,float Tdeg,float distance,long kp){
  diff = Tdeg - Ndeg;
  if(diff > 180)diff -= 360;
  else if(diff <- 180)diff += 360;
    diff = diff * kp;
    MotorControl(motormax - sqrt(pow((diff/2),2)));
    ServoControl(diff);
}
