#include <Servo.h>      // Servoライブラリの読み込み

// 土壌センサのピン
const int SENSER_PIN = A2;
int jadge = 0;
Servo myservo;          // Servoオブジェクトの宣言
const int SV_PIN = 5;   // サーボモーターをデジタルピン5に
int delay_c = 275;

const int SW_W_PIN = 4;   // 白スイッチをデジタルピン4に
int switch_w_status = 1;  // 白スイッチの初期状態Low

void setup() {
  myservo.attach(SV_PIN);  // サーボの割当
  Serial.begin(9600);  
  pinMode(SW_W_PIN,INPUT);
}

void loop() {

  // 土壌センサの値を読み取る
  int senser_val;
  senser_val = analogRead( SENSER_PIN );
  Serial.println(senser_val);


  if (senser_val < 900){
    jadge = 1;
  }

  if (senser_val > 900 && jadge == 1){ 
    for (int i=0;i<=3;i++) {
      myservo.write(20);
      delay(delay_c); 
      myservo.write(70); 
      delay(delay_c);
    }
  }
  
  switch_w_status = digitalRead(SW_W_PIN);
  if (switch_w_status == HIGH){
    jadge = 0;
  }

  delay(5000);
}