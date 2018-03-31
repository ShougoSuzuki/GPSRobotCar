float Distance(float x1, float y1, float x2, float y2){
  /* x1 現在地緯度　y1 現在地経度　x2  目的地緯度　y2　目的地経度*/
    double x1Rad, y1Rad, x2Rad, y2Rad; //ラジアン変換用
    double m,w,n,e; //途中計算用
    double dx,dy; //2点の緯度経度の差(ラジアン)
    double p; //2点の緯度の平均
    double rx = 6378137.000000000; //赤道半径(m)
    double ry = 6356752.314140356; //極半径
    double distance; //直線距離
    
  //ラジアン変換
  x1Rad = x1 * PI / 180.0;
  y1Rad = y1 * PI / 180.0;
  x2Rad = x2 * PI / 180.0;
  y2Rad = y2 * PI / 180.0;

  //2点の緯度の平均
  p = (x2Rad + x1Rad) / 2;

  //2点の緯度経度の差
  dx = x2Rad - x1Rad;
  dy = y2Rad - y1Rad;

  e = sqrt((pow(rx,2) - pow(ry,2)) / pow(rx,2)); //離心率
  w = sqrt(1 - pow(e,2) * pow(sin(p),2)); //子午線曲率半径
  m = (rx * ( 1 - pow(e,2)))/pow(w,3);
  n = rx / w; //卯酉線曲率半径
  distance = sqrt(pow((dx * m),2) + pow((dy * n * cos(p)),2));
  
  return (float)distance;
}

