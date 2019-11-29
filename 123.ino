int raw = 0;
float temp = 0;
float t = 0;

void setup() {
  Serial.begin(9600);
  pinMode( A0, INPUT );
}

float temperature() {
  raw = analogRead(A0);
  temp = ( raw/1023.0 ) *5.0*1000/10;
  return temp;
}

void loop() {
  t = temperature();
  Serial.println(t);
  delay(1000);
  int result[5] = {t};
  Serial.println(result[5]);
}
