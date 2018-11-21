/*
  Software serial multple serial test

 Receives from the hardware serial, sends to software serial.
 Receives from software serial, sends to hardware serial.

 The circuit:
 * RX is digital pin 10 (connect to TX of other device)
 * TX is digital pin 11 (connect to RX of other device)
 */
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  Serial.println("Connect to the Sigfox Breakout board...");
  Serial.println("AT$I=10 : get Device ID");
  Serial.println("AT$I=11 : get PAC");
  Serial.println("AT$T? : get Temperature");
  Serial.println("AT$V? : get Voltages");
  Serial.println("AT$P=unit : set Power mode (unit = 0:software reset 1:sleep 2:deep_sleep)");
  Serial.println("AT$TR=unit : set Transmit repeat (unit = 0..2)");
  Serial.println("AT$WR : save config");
  Serial.println("AT$SF=[payload] : SEND SIGFOX MESSAGE");
  Serial.print("Device ID : ");
  mySerial.print("AT$I=10\r");
}

void loop() { // run over and over
  if (mySerial.available()) {
    Serial.write(mySerial.read());
  }
  if (Serial.available()) {
    mySerial.write(Serial.read());
  }
}
