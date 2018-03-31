void RobotStatus(){
    Serial.println("Operation");
    Serial.print("北緯:");
    Serial.print(North_point,6);
    Serial.print(" 東経:");
    Serial.print(East_point,6);
    Serial.print(" 角度");
    Serial.print(diff);
    Serial.print(" 残り距離");
    Serial.print(dist,2);
    Serial.print(" 開始時間:");
    Serial.print(startTime);
    Serial.print(" 停止開始時間:");
    Serial.print(stopTime);
    Serial.print(" 現在時間:");
    Serial.print(nowTime);
    Serial.print(" 残り時間");
    Serial.print(stopTime - nowTime);
    Serial.print(" 目標ポイント:");
    Serial.println(Target_count);  
}
