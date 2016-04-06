#include <Servo.h>
int joyX = A0 , joyY = A1;
int X, Y;
String outputFormat;
int portServoDer = 9, portServoIzq = 10;
Servo servoDer, servoIzq;

void setup() {
  Serial.begin(9600);
  servoDer.attach(portServoDer);
  servoIzq.attach(portServoIzq);
  arm();
}

void loop() {
 X = analogRead(A0);
 Y = analogRead(A1);
  formatInput(&X, &Y);

  X = map(X, 523, 1023, 60, 150);
  Y = map(Y, 513, 1023, 60, 150);
  
  outputFormat = "X: ";
  outputFormat.concat(X);
  outputFormat.concat("\tY: ");
  outputFormat.concat(Y);
  Serial.println(outputFormat);

  servoDer.write(X);
  servoIzq.write(Y);
  
  delay(100);
}

void formatInput( int* X, int* Y){
  if(*X <= 523){
    *X = 522;
  }
  if(*Y <= 514){
    *Y = 513;
  }
}
void arm(){                                                                   // Funcion del armado del ESC
 servoDer.write(10);
 servoIzq.write(10);
 delay(100);
 servoDer.write(40);
 servoIzq.write(40);
 delay(100);
}

