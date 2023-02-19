#include <SPFD5408_Adafruit_GFX.h>    //--> Core graphics library
#include <SPFD5408_Adafruit_TFTLCD.h> //--> Hardware-specific library
#include <SPFD5408_TouchScreen.h>
#include <Servo.h>
//----------------------------------------

//----------------------------------------
#if defined(__SAM3X8E__)
    #undef __FlashStringHelper::F(string_literal)
    #define F(string_literal) string_literal
#endif

//----------------------------------------Pin configuration and initialization for Touchscreen
#define YP A1 //--> must be an analog pin, use "An" notation!
#define XM A2 //--> must be an analog pin, use "An" notation!
#define YM 7  //--> can be a digital pin
#define XP 6  //--> can be a digital pin

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0

// optional
#define LCD_RESET A4

Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define BLACKM  0x18E3

#define TS_MAXX 919
#define TS_MAXY 865
#define TS_MINX 145
#define TS_MINY 82

#define MINPRESSURE 10
#define MAXPRESSURE 1000



int BtnGreenX = 30;
int BtnGreenY = 30;
int BtnRedX = 200;
int BtnRedY = 30;
int pin=10;

Servo servo_pin;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
tft.reset();
  tft.begin(0x9341); 
  tft.setRotation(1);
  tft.fillScreen(WHITE);
 
  //DrawButtonGreen(BtnGreenX,BtnGreenY);
  //DrawButtonRed(BtnRedX, BtnRedY);

 // tft.setTextSize(3);
 // tft.setTextColor(BLUE, WHITE);
  //tft.setCursor(100, 160);
  //tft.print("Angle:180");
  pinMode(13, OUTPUT);  

  servo();
   pot();
}
void pot(){
  pinMode(A5,INPUT);
}
void servo(){
  pinMode(pin,OUTPUT);
  servo_pin.attach(pin,500,2500);
}

/*void loop() {
 
  digitalWrite(13, HIGH);
  TSPoint p = ts.getPoint();
  digitalWrite(13, LOW);

  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
  

  p.x = map(p.x, TS_MINX, TS_MAXX, 0,tft.height());
  p.y = map(p.y, TS_MINY, TS_MAXY, 0, tft.width());
  
  int y_set_rotatoon_135 = map(p.x, 0, 240, 0, tft.height());
  int x_set_rotatoon_135 = map(tft.width() - p.y, 0, 320, 0, tft.width());

}*/
void loop(){
   int a=2;
 int potvalue;
  potvalue=analogRead(A5);
  int read=map(potvalue,0,1023,0,9);
  Serial.println("pot value=");
  Serial.println(potvalue);
 delay(100);
      
tft.fillRect(10, 80, map(potvalue,0,1023,0,300), 20, BLACKM);

  delay(1000);

tft.fillRect(10, 80, map(potvalue,0,1023,0,300), 20, WHITE);


  
 
  tft.setTextSize(3);
 tft.setTextColor(BLUE, WHITE);
  tft.setCursor(100, 160);
  tft.print("pot value=");
  tft.setCursor(100, 190);
    tft.print(read);
}



  /*if (p.z > MINPRESSURE && p.z < MAXPRESSURE) {
    
    if (x_set_rotatoon_135 > BtnGreenX && x_set_rotatoon_135 < (BtnGreenX+84) && y_set_rotatoon_135 > BtnGreenY && y_set_rotatoon_135 < (BtnGreenY+84)) {
      tft.setTextSize(3);
      tft.setTextColor(BLUE, WHITE);
      tft.setCursor(100, 160);
      tft.print("Angle:180");
        servo_pin.write(180);
   
      
      DrawButtonGreenPress(BtnGreenX, BtnGreenY);
      delay(100);
      DrawButtonGreen(BtnGreenX,BtnGreenY);
    }
    

   
    if (x_set_rotatoon_135 > BtnRedX && x_set_rotatoon_135 < (BtnRedX+84) && y_set_rotatoon_135 > BtnRedY && y_set_rotatoon_135 < (BtnRedY+84)) {
      tft.setTextSize(3);
      tft.setTextColor(BLUE, WHITE);
      tft.setCursor(100, 160);
      tft.print("Angle: 90");

     servo_pin.write(90);
  
      DrawButtonRedPress(BtnRedX, BtnRedY);
      delay(100);
      DrawButtonRed(BtnRedX, BtnRedY);
    }
   
  }

}
void DrawButtonGreen(int xp, int yp) {
  tft.fillRoundRect(xp, yp, 84, 84, 10, BLACKM);
  tft.fillRoundRect(xp+2, yp+2, 80, 80, 10, GREEN);
  tft.setCursor(xp+18, yp+32);
  tft.setTextSize(3);
  tft.setTextColor(WHITE);
  tft.println("180");
}

void DrawButtonGreenPress(int xp, int yp) {
  tft.fillRoundRect(xp, yp, 84, 84, 10, BLACKM);
}

void DrawButtonRed(int xp, int yp) {
  tft.fillRoundRect(xp, yp, 84, 84, 10, BLACKM);
  tft.fillRoundRect(xp+2, yp+2, 80, 80, 10, RED);
  tft.setCursor(xp+18, yp+35);
  tft.setTextSize(3);
  tft.setTextColor(WHITE);
  tft.println("90");
}

void DrawButtonRedPress(int xp, int yp) {
  tft.fillRoundRect(xp, yp, 84, 84, 10, BLACKM);
}*/

