//経度緯度の進数変換
float ConversionPoint(float val){
  int d = val / 100;
  int m = (((val / 100.0) - d) * 100.0) / 60;
  float s = (((((val / 100.0) - d) * 100.0) - m) * 60) / (60*60);
  return float(d + m + s);
}

