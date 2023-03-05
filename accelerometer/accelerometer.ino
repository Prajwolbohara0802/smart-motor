int xaxis=A2;
int yaxis=A0;
int zaxis=A1;


void setup() {
  // put your setup code here, to run once:
pinMode(xaxis,INPUT);
pinMode(yaxis,INPUT);
pinMode(zaxis,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your ma9in code here, to run repeatedly:
int x=analogRead(xaxis);
int y=analogRead(yaxis);
int z=analogRead(zaxis);
Serial.println("value of xaxis");
Serial.println(x);
delay(1000);
Serial.println("value of yaxis");
Serial.println(y);
delay(1000);

Serial.println("value of zaxis");
Serial.println(z);
delay(1000);
}
