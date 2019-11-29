int raw = 0;
float temp = 0;
float t = 0;
float result[5];

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
  float result[5] = {t, t, t, t, t};
  float x2result = ((result[1] + result[2] + result[3] + result[4] + result[5]) / 5);
  Serial.println(x2result);
}
