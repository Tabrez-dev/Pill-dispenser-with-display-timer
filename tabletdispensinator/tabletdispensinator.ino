
#include <Wire.h>  //  Include I2C library
#include<Adafruit_GFX.h>   //  include Graphical Library
#include<Adafruit_SSD1306.h>  // Oled library
#include <Servo.h>
Adafruit_SSD1306 oled(128, 64, &Wire, 4); 
Servo servo; 
int pos; 
int Signal = 8; 
int servopin = 9;

int val=0;//transition indicator
int old_val=0;//stores previous status
unsigned long TimeNow= 0;//store current time
unsigned long TimeThen=0;//previous time 
int count=0;//state


void setup() { 
   
    pinMode(Signal, INPUT); 
    servo.attach(servopin);
    servo.write(0);         //close cap on power on
    delay(1000);
    servo.detach();
    oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // SSD1306_SWITCHCAPPVCC is generate 3.3volt internaly,  0x3c is I2c slave(oled) address
  oled.clearDisplay();  // Celar display function
     } 
void loop() {
  
  oled.setTextSize(1);    // first we have to decide font size
 oled.setTextColor(WHITE);     //we have to decide back ground color
 oled.setCursor(1,1);    //then set print location or printing cursor
  oled.println(("PILL DISPENSER"));   // print conmmand 
   oled.display();  // oled display command
 oled.invertDisplay(true);

  servo.write(0);
    int buttonState = digitalRead(Signal);
     delay(50); 
    if (buttonState == 1) 
    {
       
      oled.setCursor(1,15); 
      
  
      oled.println(("DISPENSING..."));
      oled.display(); 
      delay(1000);
      
      delay(50);
      servo.attach(servopin);
      servo.write(100);
      delay(3000);       //wait 5 seconds
      servo.write(0);    
      delay(1000);
      servo.detach();
      
      oled.setCursor(1,25);
      oled.println("Ready!...");
      oled.display(); 
      delay(500);
      count=1;
    
      
    } 
    delay(100);
    oled.setCursor(1,20);
    
    if(count==1)
    {
      oled.clearDisplay();
      count=0;//transistion
      delay(50);
      

      TimeNow= millis()-TimeThen;//when removed,time lapsed
      TimeThen= millis(); //capture last time when pill is dispensed
      if(TimeNow/1000<60)//seconds
      {
        oled.setCursor(1,40);
        oled.println(TimeNow/1000);
        oled.println(" seconds ago");
        
      }

      if((TimeNow/1000>60) && (TimeNow/1000<3600))//minutes
      {
        oled.setCursor(1,40);
        oled.println(TimeNow/60000);
        oled.println(" minutes ago");
        
      }

      if((TimeNow/3600000) && (TimeNow/1000 <86400))//hours
      {
        oled.setCursor(1,40);
        oled.println(TimeNow/3600000);
        oled.println(" hours ago");
       
      }
    oled.display();    
    }
    
         
  }
