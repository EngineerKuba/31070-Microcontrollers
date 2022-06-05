import processing.serial.*;
Serial myPort;
PImage logo;
int bg_color = 0;
void setup(){
 colorMode(HSB, 255);
 logo = loadImage("logo.png");
 size(170, 116);
 //println("Available serial ports: ");
 //println(Serial.list());
 myPort = new Serial(this, Serial.list()[0], 115200);
}
void draw(){
 if (myPort.available() > 0){
   bg_color = myPort.read();
   println(bg_color);
 }
 background(bg_color, 255, 255);
 image(logo, 0, 0);
}