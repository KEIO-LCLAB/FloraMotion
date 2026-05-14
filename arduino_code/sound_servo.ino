#include <Servo.h>      // Servoライブラリの読み込み
#include <MsTimer2.h> 

Servo myservo;          // Servoオブジェクトの宣言
const int SV_PIN = 5;   // サーボモーターをデジタルピン5に
int delay_c = 275;

// ポート指定用変数設定
int a0_in_port = A2;    // センサ デジタル情報入力
 
// 受信データ用変数設定
int a0_data;    // analogデータ用
// 電圧値変換用変数
float v_data;
 
void setup() {
  // put your setup code here, to run once:
  // シリアルモニタ通信速度設定
  myservo.attach(SV_PIN);  // サーボの割当
  delay_c = 275;
  Serial.begin(9600);  
}
 
void loop() {
  // put your main code here, to run repeatedly:
  // 音センサからの情報取得
  a0_data = analogRead(a0_in_port);   // アナログデータ
 
  // 受信データをシリアルモニタへ出力
  // 電圧表現に変換計算
  v_data = (float)a0_data / 1024.0f * 5.0f;
 
  // シリアルモニタへ出力
  //  Serial.println( a0_data ); 
  Serial.println( v_data );
  
  if (v_data > 4.0){ 
    for (int i=0;i<=1;i++) {
      myservo.write(20);
      delay(delay_c); 
      myservo.write(70); 
      delay(delay_c);
    }
  }
  
  delay(100);
}