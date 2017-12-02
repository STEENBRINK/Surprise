//include libraries
#include <Wire.h>  
#include <LiquidCrystal_I2C.h>

//register lcd panel
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

//define the pins
#define PIN_2 2
#define PIN_3 3
#define PIN_4 4
#define PIN_5 5
#define PIN_6 6
#define PIN_9 9
#define PIN_10 10

//register variables
boolean wire = false;
boolean button_check = false;
boolean button_done = false;
boolean begun = false;
boolean done = false;

void setup() {
    // register lcd, sixteen characters across 2 lines
    lcd.begin(16,2); 
    lcd.backlight();

    //register pins
    pinMode(PIN_2, INPUT);
    pinMode(PIN_3, INPUT);
    pinMode(PIN_4, INPUT);
    pinMode(PIN_5, INPUT);
    pinMode(PIN_6, INPUT);
    pinMode(PIN_9, INPUT);
    pinMode(PIN_10, INPUT);

    //debug
    Serial.begin(9600);

    //print serial
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("To unlock press");
    lcd.setCursor(0,1);
    lcd.print("  start/reset");
    
}

void loop() {
    //Serial.println("wire " + String(wire));
    //Serial.println("button_check " + String(button_check));
    //Serial.println("button_done " + String(button_done));
    //Serial.println("begun " + String(begun));
    if(digitalRead(PIN_10)){
        while(digitalRead(PIN_10)){ int filler = 0; }          
        if(!begun){
            Serial.println("a");
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("Serial Number:");
            lcd.setCursor(0,1);
            lcd.print("937495");
            delay(2000);           
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("Unlock session");
            lcd.setCursor(0,1);
            lcd.print("started!");
            begun = true;
        }else{
            Serial.println("b");
            wire = false;
            button_check = false;
            button_done = false;
            begun = false;
            done = false;
            lcd.clear();                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
            lcd.setCursor(0,0);
            lcd.print("To unlock press");
            lcd.setCursor(0,1);
            lcd.print("  start/reset");
            delay(1000);
        }
    }
    if(begun){
        if(!wire){
            wireCut();
        }
        if(!button_done){
            buttonPressed();
        }
    }
    if(wire && !button_done){
        lcd.setCursor(0,0);
        lcd.print("Wire test done  ");
    }else if(button_done && !wire){
        lcd.setCursor(0,1);
        lcd.print("Button pressed  ");
    }else if(wire && button_done && !done){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Please complete");
        lcd.setCursor(0,1);
        lcd.print("the 2nd test!");
        delay(100);
        done = true;
    }
}

void wireCut(){
    if(!(digitalRead(PIN_2))){
        Serial.println("2 broken");
        wire = true;
        lcd.clear();
        lcd.print("Code 3 = 1");
        delay(2000);
        lcd.clear();
    }else if(!(digitalRead(PIN_3))){
        Serial.println("3 broken");
        wire = true;
        lcd.clear();
        lcd.print("Code 3 = 5");
        delay(2000);
        lcd.clear();
    }else if(!(digitalRead(PIN_4))){
        Serial.println("4 broken");
        wire = true;
        lcd.clear();
        lcd.print("Code 3 = 3");
        delay(2000);
        lcd.clear();
    }else if(!(digitalRead(PIN_5))){
        Serial.println("5 broken");
        wire = true;
        lcd.clear();
        lcd.print("Code 3 = 2");
        delay(2000);
        lcd.clear();
    }else if(!(digitalRead(PIN_6))){
        Serial.println("6 broken");
        wire = true;
        lcd.clear();
        lcd.print("Code 3 = 4");
        delay(2000);
        lcd.clear();
    }
}

void buttonPressed(){
    if(digitalRead(PIN_9)){
        Serial.println("Reading da 9 yo");
        for(int i = 0; i < 100; i++){ 
            delay(10); 
            if(!(digitalRead(PIN_9))){
                button_check = true;
                Serial.println("true");
                break;
            }
        }
        if(button_check){
            lcd.clear();
            lcd.print("Code 1 = 5");
        }else{
            lcd.clear();
            lcd.print("Code 1 = 3");
        }
        delay(2000);
        lcd.clear();
        button_done = true;
    }
}

