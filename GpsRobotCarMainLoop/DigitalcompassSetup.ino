void DigitalcompassSetup(){
  //I2C通信開始 
  Wire.begin();
  
  //Continuous Modeに設定する
  Wire.beginTransmission(compassAddress);
  //RAM書き込み用コマンド
  Wire.write('G');
  //書き込み先指定
  Wire.write(0x74);
  //モード設定
  Wire.write(0x72);
  //通信終了
  Wire.endTransmission();
  //処理時間
  delayMicroseconds(70);

  //キャリブレーション開始
  Wire.beginTransmission(compassAddress);
  Wire.write('C');
  Wire.endTransmission();

  //5秒待つ
  //回転させる
  delay(5000);

  //キャリブレーション終了
  Wire.beginTransmission(compassAddress);
  Wire.write('E');
  Wire.endTransmission();
}
