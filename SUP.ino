// assign each component to a pin
int buton = 12;
int led_r = 8;  // if its too hot red led light up
int led_y = 9;  // if its too dark yellow led light up
int led_g = 10;  // if theres too much moisture led green light up
int sen_ldr = A0; // sensor of light dependent resistor
int sen_temp = A1; // sensor of temperature


// sensor value
int sv_temp = 0;
int sv_ldr = 0;

#include <LiquidCrystal.h>
const int rs = 13, en = 11, d4 = 7, d5 = 6, d6 = 5, d7 = 4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);  // set up for lcd display

#include<CapacitiveSensor.h>
CapacitiveSensor capSensor = CapacitiveSensor(3, 2);  // set up for moisture sensor

// refrence value
int ref_temp = 25;  // reference value to temp
int ref_ldr = 70; // reference value to ldr
int ref_mstr = 1000;  // reference to moisture sensor

// lable modes
int crt_dis = 0;  //whats currently being displayed (1 = temp, 2 = light, 3 = moisture)
int buton_stat = 0; // what the stat of button

int rled_r; // read LED of Red
int rled_y; // read LED of Yellow
int rled_g; // read LED of Green



void setup()
{
  pinMode(led_r, OUTPUT);
  pinMode(led_y, OUTPUT);
  pinMode(led_g, OUTPUT);
  pinMode(buton, INPUT);
  Serial.begin(9600);
  lcd.begin(6, 2);
  lcd.clear();
  lcd.print("Press Button to ");
  lcd.setCursor(5, 2);
  lcd.print("Start");
  delay(500);
}



void loop()
{
  // reading the value in sensors
  sv_temp = analogRead(sen_temp);
  sv_ldr = analogRead(sen_ldr);
  buton_stat = digitalRead(buton);
  long sv_mstr = capSensor.capacitiveSensor(30);  // moisture sensor


  // intput to tempreture
  float vol = ( sv_temp / 1024.0 ) * 5.0;
  float temp = ( vol - .5) * 100;


  // what to display in the serial monintor
  Serial.print("Temp = ");
  Serial.println(temp);
  Serial.print("Light = ");
  Serial.println(sv_ldr);
  Serial.print("Mosture = ");
  Serial.println(sv_mstr);

  // what heppen if button is pressed
  if (buton_stat == HIGH)
  {
    crt_dis ++;
    delay (500);
    Serial.println ("button is High");
  } else {
    Serial.println ("button is Low");
  }


  // What to display in the top row of lcd
  if (crt_dis == 1)
  {
    lcd.clear();
    lcd.print ("Temp: ");
    lcd.print (temp);
    Serial.println ("LCD = Temp");
  }
  if (crt_dis == 2)
  {
    lcd.clear();
    lcd.print ("Light: ");
    lcd.print (sv_ldr);
    Serial.println ("LCD = Light");
  }
  if (crt_dis == 3)
  {
    lcd.clear();
    lcd.print ("Moist: ");
    lcd.print (sv_mstr);
    Serial.println ("LCD = Mousture");
  }
  if (crt_dis >= 4)
  {
    crt_dis = 1;
  }

  Serial.print ("Current display = ");
  Serial.println (crt_dis);

  // When does LED lights up
  if (temp > ref_temp)
  {
    digitalWrite(led_r, HIGH);
  } else {
    digitalWrite(led_r, LOW);
  }
  if (sv_ldr < ref_ldr)
  {
    digitalWrite(led_y, HIGH);
  } else {
    digitalWrite(led_y, LOW);
  }
  if (sv_mstr > ref_mstr)
  {
    digitalWrite(led_g, HIGH);
  } else {
    digitalWrite(led_g, LOW);
  }


 // Read Value of LED (weather if its on or not 
  rled_r = digitalRead(led_r);
  rled_g = digitalRead(led_g);
  rled_y = digitalRead(led_y);
  Serial.print ("LED RED = ");
  Serial.println (rled_r);
  Serial.print ("LED Yellow = ");
  Serial.println (rled_y);
  Serial.print ("LED Green = ");
  Serial.println (rled_g);

  
 // when deos lcd display "led on" or "led off"
  if (rled_r == HIGH and rled_y == HIGH and rled_g == HIGH)
  {
    lcd.setCursor(0,2);
    lcd.print("all LED is ON");
    Serial.print("LCD Dis (all LED ON)");
  } else if (rled_y == HIGH and rled_g == HIGH)
  {
  lcd.setCursor(0, 2);
  lcd.print("Y & G LED Is On");
  Serial.print("LCD Dis (Yellow and Green LED ON)");
  } else if (rled_y == HIGH and rled_r == HIGH)
  {
    lcd.setCursor(0, 2);
    lcd.print("Y & R LED is On");
    Serial.print("LCD Dis (Yellow and Red LED ON)");
  } else if (rled_g == HIGH and rled_r == HIGH)
  {
    lcd.setCursor(0, 2);
    lcd.print("G & R LED is On");
    Serial.print("LCD Dis (Yellow and Red LED ON)");
  } else if (rled_r == HIGH)
  {
    lcd.setCursor(0, 2);
    lcd.print("Red LED is On");
    Serial.print("LCD Dis (Red LED ON)");
  } else if (rled_g == HIGH)
  {
    lcd.setCursor(0, 2);
    lcd.print("Green LED is On");
    Serial.print("LCD Dis (Green LED ON)");
  } else if (rled_y == HIGH)
  {
    lcd.setCursor(0, 2);
    lcd.print("Yellow LED is On");
    Serial.print("LCD Dis (Yellow LED ON)");
  }

   
  // Enter 2 Blanks to consol to show time line
  Serial.println();
  Serial.println();

}
