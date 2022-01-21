////#include <IRremote.hpp>
//////#define r 3
//////#define g 5
//////#define b 6+
////void setup() {
////// pinMode(r , OUTPUT);
////// pinMode(g , OUTPUT);
////// pinMode(b , OUTPUT);
//// Serial.begin(9600);     
//// myReceiver.enableIRIn(); 
////}    
////     
////     
////void loop()     
////{     
////if (myReceiver.decode(&result))// Returns 0 if no data ready, 1 if data ready.     
////{
//// myReceiver.decode(&result);
////    
////  Serial.println(result.value, HEX); 
//////  delay(1000);//prints the value a a button press     
////  
////  myReceiver.resume();
////}
////
////}     
//
//
//#include <IRremote.h>
//decode_results result;     
//IRrecv myReceiver(4);
//IRsend mySender(3);
//const byte IR_RECEIVE_PIN = 4;
//
//void setup()
//{
//  myReceiver.enableIRIn();
//   Serial.begin(9600);
//   Serial.println("IR Receive test");
////   IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
//}
//
//void loop()
//{
////   mySender.sendNEC(0, 32);
//  
//   if (myReceiver.decode(&result), HEX)
//   {
//    int value = result.value ;
////    if(value ==10)
//      Serial.println( value, HEX);
//
//   }
//      myReceiver.resume();
////     myReceiver.enableIRIn();
//
//}

/*
AUTHOR: Hazim Bitar (techbitar)
DATE: Aug 29, 2013
LICENSE: Public domain (use at your own risk)
CONTACT: techbitar at gmail dot com (techbitar.com)
*/
 
#include <SoftwareSerial.h>
 
SoftwareSerial BTSerial(10, 11);   // RX | TX
 
void setup() 
{
  pinMode(9, OUTPUT);    /* this pin will pull the HC-05 
                            pin 34 (KEY pin) HIGH to switch module to AT mode */
 
  digitalWrite(9, HIGH); 
  Serial.begin(9600);
  Serial.println("Enter AT commands:");
  BTSerial.begin(38400);  // HC-05 default speed in AT 
                          // command mode
}
 
void loop()
{
  // Keep reading from HC-05 and send to Arduino 
  // Serial Monitor
  if (BTSerial.available())
    Serial.write(BTSerial.read());
 
  // Keep reading from Arduino Serial Monitor 
  //  and send to HC-05
  if (Serial.available())
    BTSerial.write(Serial.read());
}
