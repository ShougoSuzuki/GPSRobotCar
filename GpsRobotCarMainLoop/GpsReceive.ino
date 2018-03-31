void GpsReceive(){
  char buf[256]; // 受信用バッファを255文字分確保
  char c; // 受信用文字
  int count = 0; // 受信用カウンタ
  char *gps_n, *gps_nu, *gps_e, *gps_eu;
  float gps_ns,gps_es;
  int gps_nsA , gps_esA;

  do {
    if (Serial.available()) {
      buf[count] = Serial.read();
      count++;
    }
    if (count > 250) break; // バッファが溢れそうなら強制的に一行終了。
  } while (buf[count - 1] != 0x0A);
  buf[count] = '\0';
  if (0 == strncmp("$GPGGA", buf, 6)) { // 先頭6文字を比較
    strtok(buf, ",");
    strtok(NULL, ",");
    gps_n = strtok(NULL, ",");
    strtok(NULL, ",");
    gps_e = strtok(NULL, ",");

    gps_ns = atof(gps_n); // ddmm 緯度
    gps_es = atof(gps_e); // ddmm 経度

    gps_ns = gps_ns / 100; //100で割って dd.mmmにする
    gps_es = gps_es / 100; //100で割ってddd.mmmにする

    gps_nsA = gps_ns; //ddだけ取り出す
    gps_esA = gps_es; //dddだけ取り出す
    
    gps_ns = gps_ns - gps_nsA; //mmmを取り出す
    gps_es = gps_es - gps_esA; //mmmを取り出す
   
    gps_ns = gps_ns / 0.6; //mmm→dddに変換
    gps_es = gps_es / 0.6; //mmm→dddに変換
    
    
    North_point = gps_nsA + gps_ns;// dd.ddd
    East_point = gps_esA + gps_es;//ddd.ddd
  }
}

