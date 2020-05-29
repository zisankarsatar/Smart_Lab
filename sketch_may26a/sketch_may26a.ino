#include <LiquidCrystal.h>
//bayrak pinlerini ayarlamak için
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//sensör, buton ve led pinleri
int hareketSensor = 8;
int gasSensor     = 9;
int buttonPin     = 6;
int ledRed        = 13;
int ledGreen      = 10;
int tetik         = 7; 

//gaz, buton ve sistem kapatma durumu
boolean gasStat    = 0;
boolean buttonStat = 0;
boolean systemFlag = 0;
boolean hareketSensorValue = 0; 


void setup() {
  lcd.begin(16,2);
  
  //giriş ve çıkış pin atamalrı
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(tetik, OUTPUT);
  pinMode(gasSensor, INPUT);
  pinMode(hareketSensor, INPUT);
  pinMode(buttonPin, INPUT);
  digitalWrite(ledRed, LOW);
  digitalWrite(ledGreen, LOW);
  lcd.print("sistem baslatildi.....");

}

void loop() {
  //pinleri aldık
  gasStat = digitalRead(gasSensor);
  delay(50);
  buttonStat = digitalRead(buttonPin);
  delay(50);
  hareketSensorValue= digitalRead(hareketSensor);
  delay(100);

  if(hareketSensorValue==1)
  {
    digitalWrite(tetik, HIGH);
    //alt satır sağa
    lcd.setCursor(0,1);
    lcd.print("hareket var!!");
  }else{
    digitalWrite(tetik, LOW);
  };

  
  //gaz durumu 1 sistem 0 ise 
  if(gasStat == 1 && systemFlag == 0){
    //buton 1 ise sistem 1 yapıp işlemi durduracak
    if(buttonStat == 1){
      systemFlag = 1;
    }
    //gaz olduğuna dair kırmızı led yanar
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledRed, HIGH);
    lcd.setCursor(0,1);
    lcd.print("Gass!!");
    }else{
      //gaz olmadığında yeşil led yanacak/      
      if(gasStat == 0){
        systemFlag = 0;
      }
    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledRed, LOW);
    lcd.setCursor(0,1);
    lcd.print("Normall!!");      
 };
}
