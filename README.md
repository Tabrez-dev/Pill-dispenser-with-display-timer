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
8. Cardboard box
9. 0.96 inch i2c display

![WhatsApp Image 2021-10-03 at 5 10 40 PM](https://user-images.githubusercontent.com/75200693/135752211-f669fb75-571c-408b-a687-339e722f8b2d.jpeg)


## My Experience and Problems faced during the build:

My experience with the project was fruitful and exciting because I finally brought out my ideas into an actual working model successfully

The main problems faced while making the build was:

1. Finding the right material

2. Making the exact size hole for the tablet and tracking the trajectory of the funnel

3. Getting the code right for the display

The first problem was fixed by using a material known as foam board since the movement of cardboard was not smooth enough and it is easier to cut than cardboard.
The trajectory that the funnel would take with respect to the servo motor was calculated by trial and error. As the saying goes 

> test fast, fail fast and adjust fast.

> Fail faster succeed sooner.

There was an issue with printing comments onto the display. Make sure after every comment there should be an "oled.display();" command or else the comments will not come on the display. Also, download the correct library for your display. I had downloaded the Adafruit_SSD1306 library.



![pic1](https://user-images.githubusercontent.com/75200693/135752148-e090f6f0-3fda-48c8-a70f-c4aa8b0bdbab.jpeg)


![Capture](https://user-images.githubusercontent.com/75200693/135750978-80a4ad36-2a25-4de7-8492-4ca29de9a5aa.PNG)

![ezgif com-gif-maker (1)](https://user-images.githubusercontent.com/75200693/135755322-77c52c74-eff3-4127-85a6-421892dc44e6.gif)

## Circuit Design:
The project was done on a breadboard for simplicity. The connections are as follows:

1. *IR Sensor:* Output to pin D8, VCC and ground to 5 volt and GND pins respectively.

2. *Servo motor*: Data pin to D9, VCC and ground to 5 volt and GND pins respectively.

3. *0.96 inch i2c display:* VCC and GND to 5 volt and ground pins respectively. **SDA--->A4 and SCL--->A5**

## Future Scope and improvements:
This project can be extended to take in multiple tablets and make the plastic tube longer so that it will be easier to put the tablets from the top.
We can also add a timer to make an alarm at a particular time so that the patient does not forget to take his/her tablets or medication.
The system should be modified to accept different sizes of tablets.

## Please watch the video to understand the build and its working completely




