#include <OneWire.h>
OneWire ds(8);

#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3); // RX, TX
String val = "";
String phone = "";
String text = "";

void setup() {
  delay(2000);
  Serial.begin(9600);
  Serial.println("GSM tester v1.0");
  mySerial.begin(9600);
  mySerial.println("AT+CLIP=1");
  delay(100);
  mySerial.println("AT+CMGF=1");
  delay(100);
  mySerial.println("AT+CSCS=\"GSM\"");
  delay(100);
}

void tempread() {
  byte data[2];
  ds.reset();
  ds.write(0xCC);
  ds.write(0x44);
  delay(1000);
  ds.reset();
  ds.write(0xCC);
  ds.write(0xBE);
  data[0] = ds.read();
  data[1] = ds.read();
  float temperature = ((data[1] << 8) | data[0]) * 0.0625;
}

void sms(String text, String phone) {
  Serial.println("SMS send started");
  mySerial.println("AT+CMGS=\"" + phone + "\"");
  delay(500);
  mySerial.print(text);
  delay(500);
  mySerial.print((char)26);
  delay(500);
  Serial.println("SMS send complete");
  delay(2000);
}

void loop() {
  tempread();
  String phone = "7958370573";
  if (tempread == 22) {
    String text = "Temperature is 22C";
    sms(text, phone);
  } else if (tempread == 23) {
    String text = "Temperature is 23C";
    sms(text, phone);
  } else {
    String text = "WARNING! Temperature is tempread()";
    sms(text, phone);
  }
}
