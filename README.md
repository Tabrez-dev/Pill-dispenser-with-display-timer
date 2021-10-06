# Pill-dispenser-with-display-timer
Automatic pill dispenser using an IR sensor and a display screen with a timer indicating the time of pill last taken.
## Intention behind this project:
To dispense pills inside pill holder automatically when IR sensor is activated.
## Story behind the build:
One of my close relatives is suffering from a disease that makes it difficult to take his medication since his hands have become weak and vibrate uncontrollably. To add to the difficulty the tablets are very small. This was a problem that piqued my interest and I made this project to make his life a little bit easier.

After some research, I noticed that this problem is faced by many people. But all the automatic tablet dispensers are quite expensive in the market as of date. This will also reduce the effort of caretakers to give tablets as they can be loaded once and used multiple times until the tablets get depleted from the dispenser.

## Components and Materials Required:
1. Arduino Nano/Uno
2. PCB/Breadboard
3. Connecting wires
4. Power bank or 9-volt battery
5. Long plastic tube and/or a funnel to hold the tube
6. Infrared Sensor
7. Hot glue gun for hacking things together
8. Cardboard box and **foam board**
9. 0.96 inch i2c display

![WhatsApp Image 2021-10-03 at 5 10 40 PM](https://user-images.githubusercontent.com/75200693/135752211-f669fb75-571c-408b-a687-339e722f8b2d.jpeg)

## Code
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
 
## My Experience and Problems faced during the build:

My experience with the project was fruitful and exciting because I finally brought out my ideas into an actual working model successfully

The main problems faced while making the build was:

1. Finding the right material

2. Making the exact size hole for the tablet and tracking the trajectory of the funnel

3. Getting the code right for the display

The first problem was fixed by using a material known as foam board for the mechanical part of the build since the movement of cardboard was not smooth enough the tablet was not coming out of the funnel and into the cup smoothly. Also it is easier to cut than cardboard.

second, The trajectory that the funnel would take with respect to the servo motor was a difficult to find out. I did it by trial and error. As the saying goes 

> test fast, fail fast and adjust fast.

> Fail faster succeed sooner.

Third,There was an issue with printing comments onto the display. Make sure after every comment there should be an "oled.display();" command or else the comments will not come on the display. Also, download the correct library for your display. I had downloaded the Adafruit_SSD1306 library.



![pic1](https://user-images.githubusercontent.com/75200693/135752148-e090f6f0-3fda-48c8-a70f-c4aa8b0bdbab.jpeg)


![ezgif com-gif-maker (1)](https://user-images.githubusercontent.com/75200693/135755322-77c52c74-eff3-4127-85a6-421892dc44e6.gif)

![Capture](https://user-images.githubusercontent.com/75200693/135750978-80a4ad36-2a25-4de7-8492-4ca29de9a5aa.PNG)

## Circuit Design:
The project was done on a breadboard for simplicity. The connections are as follows for Arduino Nano:

1. *IR Sensor:* Output to pin D8, VCC and ground to 5 volt and GND pins respectively.

2. *Servo motor*: Data pin to D9, VCC and ground to 5 volt and GND pins respectively.

3. *0.96 inch i2c display:* VCC and GND to 5 volt and ground pins respectively. **SDA--->A4 and SCL--->A5**

![WhatsApp Image 2021-10-01 at 11 27 49 AM](https://user-images.githubusercontent.com/75200693/136192545-afbe4a29-18cd-4e00-b8b6-1379c316a627.jpeg)

![WhatsApp Image 2021-10-01 at 11 25 35 AM](https://user-images.githubusercontent.com/75200693/136192720-87b711e7-7dcb-4569-ba1b-d10a616bb07a.jpeg)

![WhatsApp Image 2021-10-01 at 11 25 47 AM](https://user-images.githubusercontent.com/75200693/136192746-ef2d0f37-adce-4e92-8aab-63f13c87bfe7.jpeg)


## Future Scope and improvements:
This project can be extended to take in multiple tablets and make the plastic tube longer so that it will be easier to put the tablets from the top.
We can also add a timer to set an alarm at a particular time so that the patient does not forget to take his/her tablets or medication.
The system should be modified to accept different sizes of tablets.

## Please watch the video to understand the build and its working completely

https://youtu.be/ZzsbktEgxVU
