#include<Servo.h>
#include<Wire.h>

Servo motor;
Servo servo;

float North_point = 0.0;           //現在の北緯x1
float East_point = 0.0;            //現在の東経y1

//座標生成用
float xa = 35.79254412;
float ya = 140.11037894;
float xb = 35.79225169;
float yb = 140.11037521;
float theta;

float Tnorth_pointArray[6]; //目標の北緯x2
float Teast_pointArray[6]; //目標の東経y2
int Target_count = 0;

//モータ、サーボ上下限制御
int const motormax = 50;
int const motormin = 20;
int const servomax = 70;
int const servomin = -70;

//タイマー、ゴール用フラグ
boolean startTimeFlag = false;
boolean stopTimerFlag = false;
boolean endFlag = false;

//タイマー
unsigned long startTime = 0;
unsigned long stopTime = 0;
unsigned long nowTime = 0;

int diff = 0;
float dist = 0.0;

int compassAddress = 0x42 >> 1; //0x21

void setup() {
  Serial.begin(115200);
  //Serial.begin(9600);
  MotorSetup();
  ServoSetup();
  DigitalcompassSetup();
  PointGeneration(xa, ya, xb, yb, Direction(xa, ya, xb, yb));
  //PointStatus();
  
}

void loop() {
  RobotStatus();
  GpsReceive();
  if(North_point != 0.000000 && East_point != 0.000000 && !endFlag){
    //StartStopTimer();
    dist = Distance( North_point , East_point , Tnorth_pointArray[ Target_count ] , Teast_pointArray[ Target_count ]);
    PDegDistControl( DigitalcompassDirect() , Direction( North_point , East_point , Tnorth_pointArray[ Target_count ] , Teast_pointArray[ Target_count ]) , dist , 2);
    PointChange(Distance( North_point , East_point , Tnorth_pointArray[ Target_count ] , Teast_pointArray[ Target_count ]));
  }else{
    motor.writeMicroseconds(1500);
    servo.writeMicroseconds(1500);
  }
}
