/*
 * Arduino Frequency Counter
 *
 * 
 * by Niyas Thalappil
 * 
 * www.youtube.com/c/NiyasThalappil
 * NiyazThalappil@gmail.com
 *
 */

#include <LiquidCrystal.h>
LiquidCrystal lcd(4, 6, 10, 11, 12, 13);

const int pulsePin = 8;               

int pulseHigh;                         
int pulseLow;                            
float pulseTotal;                       
float frequency;                        
void setup()
{
    pinMode(pulsePin,INPUT);             
    lcd.begin(16, 2);                     
    lcd.setCursor(0,0);                   
    lcd.print("Arduino Powered");         
    lcd.setCursor(0,1);                  
    lcd.print("  Freq Counter  ");        
    delay(2000);                         
}

void loop()
{
    lcd.setCursor(0,0);                   
    lcd.print("Frequency is    ");      
    lcd.setCursor(0,1);                  
    lcd.print("                ");        
    pulseHigh = pulseIn(pulsePin,HIGH);  
    pulseLow = pulseIn(pulsePin,LOW);   
    pulseTotal = pulseHigh + pulseLow;    
    frequency=1000000/pulseTotal;        
    lcd.setCursor(0,1);                 
    lcd.print(frequency);                
    lcd.print(" Hz");                   
    delay(500);                         
}
