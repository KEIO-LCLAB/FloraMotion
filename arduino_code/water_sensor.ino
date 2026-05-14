

// 土壌センサのピン
const int SENSER_PIN = A2;

void setup() {
  Serial.begin(9600);  
}

void loop() {

  // 土壌センサの値を読み取る
  int senser_val;
  senser_val = analogRead( SENSER_PIN );
  Serial.println(senser_val);
  delay(1000);
}