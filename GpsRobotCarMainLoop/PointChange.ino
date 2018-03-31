void PointChange(float distance){
  boolean decision = distance < 2.500;
  if(decision){
    if(stopTimerFlag){
      if((Target_count == 0) || (Target_count == 3)){
        motor.writeMicroseconds(1500);
        servo.writeMicroseconds(1500);
        endFlag = true;
      }
      else{
        Target_count++;
        Target_count %= 6;
      }
    }
    else{
      Target_count++;
      Target_count %= 6;
    }
  }  
}

