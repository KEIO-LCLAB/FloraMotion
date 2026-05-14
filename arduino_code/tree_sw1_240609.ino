// Arduino入門編⑧ Servoライブラリを使いサーボモーターを動かす
// https://burariweb.info

#include <Servo.h>      // Servoライブラリの読み込み
#include <MsTimer2.h> 

Servo myservo;          // Servoオブジェクトの宣言
const int SV_PIN = 5;   // サーボモーターをデジタルピン5に
const int SW_B_PIN = 8;   // 青スイッチをデジタルピン8に
const int SW_Y_PIN = 7;   // 黄スイッチをデジタルピン7に
const int SW_W_PIN = 4;   // 白スイッチをデジタルピン4に
int switch_b_status = 1;  // 青スイッチの初期状態Low
int switch_y_status = 1;  // 黄スイッチの初期状態Low
int switch_w_status = 1;  // 白スイッチの初期状態Low
int delay_c = 350;

void setup(){
  myservo.attach(SV_PIN);  // サーボの割当
  pinMode(SW_B_PIN,INPUT);
  pinMode(SW_Y_PIN,INPUT);
  pinMode(SW_W_PIN,INPUT);
}

void loop(){
  switch_b_status = digitalRead(SW_B_PIN);
  switch_y_status = digitalRead(SW_Y_PIN);
  switch_w_status = digitalRead(SW_W_PIN);

  if (switch_w_status == HIGH){
    delay_c += 25;
  }
  if (switch_y_status == HIGH){
    delay_c -= 25;
  }
  if (switch_b_status == HIGH){
    delay_c = 350;
  }

  myservo.write(70);
  delay(delay_c); 
  myservo.write(110); 
  delay(delay_c);
  
}