#include <U8glib.h>
#define INTERVAL_LCD 20  
unsigned long lcd_time = millis(); 
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE); //…Ë÷√OLED–Õ∫≈ 
#define setFont_L u8g.setFont(u8g_font_7x13)

#define sensor1 A0
#define sensor2 A2
#define fan1 0
#define fan2 1
void setup() {
  Serial.begin(9600);
  pinMode(sensor1,INPUT);
  pinMode(sensor2,INPUT);
  pinMode(fan1,OUTPUT);
  pinMode(fan2,OUTPUT);
  // put your setup code here, to run once:
}

float a,b,sn,sb;
void loop() {
  digitalWrite(fan1,LOW);
  a=analogRead(sensor1);
  b=analogRead(sensor2);
  sn=b-a;
  Serial.println(a);
  Serial.println(b);
  Serial.println(sn);
  if (sn<50)
  { 
    digitalWrite(fan2,HIGH);
    u8g.firstPage();
    do{
    setFont_L;
    u8g.setPrintPos(0, 10);
    u8g.println("cool complete");
    }while( u8g.nextPage() );
    sb=0;
   }
  if (sn>=50) 
  {
   if (sb==0) sb=sn;
   digitalWrite(fan2,HIGH);
   u8g.firstPage();
   do{
   setFont_L;
   u8g.setPrintPos(0, 10);
   u8g.println("cooling");
   u8g.setPrintPos(0, 30);
   u8g.print("completeness");
   u8g.setPrintPos(85,30);
   u8g.print( int(100-(sn/sb)*100));
   u8g.print("%");
   }while( u8g.nextPage() );
  }
  delay(100);
}