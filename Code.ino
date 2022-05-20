#include <SPI.h>  
 #include <MFRC522.h>  
 #include "LiquidCrystal.h"  
 #include <Servo.h>
 Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;
 const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 8, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); 
 #define SS_PIN 10  
 #define RST_PIN 9  
 #define LED_G A3 //define green LED pin  
 #define LED_R A4 //define red LED pin  
 #define BUZZER A5 //buzzer pin  
 MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance.  
 void setup()   
 {  
  Serial.begin(9600);  // Initiate a serial communication  
  SPI.begin();   // Initiate SPI bus  
  mfrc522.PCD_Init();  // Initiate MFRC522  
  lcd.begin(16,2); // Turn on the blacklight and print a message.   
    
  pinMode(BUZZER, OUTPUT);  
  
   myservo.attach(3);  


   pinMode(A3, OUTPUT); // Green
   pinMode(A4, OUTPUT); // Red
 }  
 void loop()   
 {  
  // Look for new cards  
  if ( ! mfrc522.PICC_IsNewCardPresent())   
  {    
  lcd.setCursor(3,0);  
  lcd.print("SHOW YOUR");  
  lcd.setCursor(4,1);  
  lcd.print("ID CARD");   
  return;  
  }  
  else{  
    lcd.clear();  
  }  
  // Select one of the cards  
  if ( ! mfrc522.PICC_ReadCardSerial())   
  {  
   return;  
  }  
  //Show UID on serial monitor  
  Serial.print("UID tag :");  
  String content= "";  
  byte letter;  
  for (byte i = 0; i < mfrc522.uid.size; i++)   
  {  
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");  
    Serial.print(mfrc522.uid.uidByte[i], HEX);  
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));  
    content.concat(String(mfrc522.uid.uidByte[i], HEX));  
  }  
  Serial.println();  
  content.toUpperCase();   
  if (content.substring(1) == "B1 B7 09 1B") //change here the UID of the card/cards that you want to give access  
  {  
   lcd.print("STUDENT 01");  
   lcd.setCursor(0,1);  
   lcd.print("PRESENT");  

  
   lcd.clear();  
   digitalWrite(A3, HIGH);
   digitalWrite(A4, LOW);
       open(); 
   delay(3000);
   digitalWrite(A3, LOW);
  }  
  else if (content.substring(1) == "B3 D7 D8 9A") //change here the UID of the card/cards that you want to give access  
  {  
   lcd.print("STUDENT 02");  
   lcd.setCursor(0,1);  
   lcd.print("PRESENT");  

   lcd.clear();  
   digitalWrite(A3, HIGH);
   digitalWrite(A4, LOW);
     open();
   delay(3000);
   digitalWrite(A3, LOW);
  }  
  else if (content.substring(1) == "91 69 3E 43") //change here the UID of the card/cards that you want to give access  
  {  
   lcd.print("STUDENT 03");  
   lcd.setCursor(0,1);  
   lcd.print("PRESENT");
   open();  
   digitalWrite(LED_G, HIGH);  
   tone(BUZZER, 500);  
   delay(300);  
   noTone(BUZZER);  
   delay(300);  
   digitalWrite(LED_G, LOW);  
   lcd.clear(); 
   digitalWrite(A3, HIGH);
   digitalWrite(A4, LOW); 
   delay(3000);
   digitalWrite(A3, LOW);
  }  
  else  {  
   lcd.print("UNAUTHORIZE");  
   lcd.setCursor(0,1);  
   lcd.print("ACCESS"); 
   digitalWrite(A3, LOW);
   digitalWrite(A4, HIGH);    
   digitalWrite(BUZZER,HIGH); // active the buzzer
  delay(1000);              // delay of 3000 millisecond = 3s
  digitalWrite(BUZZER,LOW); // deactivat the buzzer
     delay(2000);
     digitalWrite(A4, LOW);  
     
   lcd.clear(); 
   
  }  
 }
 void open() {
  pos=0;
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
 }
