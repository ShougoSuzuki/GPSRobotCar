float Direction(float x1,float y1,float x2,float y2){
  float radian = PI / 180,degrease = 180 / PI,Dx,Dy,Direct;

//ラジアンに直す
  x1 = x1 * radian;
  x2 = x2 * radian;
  y1 = y1 * radian;
  y2 = y2 * radian;
/*
  Serial.print("現在地 緯度　＝　");
  Serial.print(x1);
  Serial.print("　緯度　＝　");
  Serial.println(y1);
  Serial.print("目的地 緯度　＝　");
  Serial.print(x2);
  Serial.print("　経度　＝　");
  Serial.println(y2);
*/

  Dx = x2 - x1;
  Dy = y2 - y1;

  Direct = atan2f(sinf(Dy),cosf(x1) * tanf(x2) - sinf(x1) * cosf(Dy)) * degrease;

  if(Direct < 0){
    return Direct = Direct + 360;
  }else if(Direct > 0){
    return Direct;
  }else{
    return Direct;
  }
}

