int DigitalcompassDirect(){
  int direct;
  //デバイスに2バイト分のデータを要求する
  Wire.requestFrom(compassAddress, 2);
  
  //要求したデータが2バイト分来たら
  if (Wire.available() == 2) {
    //1バイト分のデータの読み込み
    direct = Wire.read();
    //読み込んだデータを8ビット左シフト
    direct = direct << 8;
    //次の1バイト分のデータを読み込み
    //1つ目のデータと合成（2バイト）
    direct += Wire.read();
    //2バイト分のデータを10で割る
    direct /= 10;
    direct -=7;//磁北線のずれ
    
    if(direct<0) direct+=360;
    
  }
  return direct;
}
