//RTC library link: https://github.com/jcw/rtclib
//LCD I2C library link: http://www.dfrobot.com/wiki/index.php/I2C/TWI_LCD1602_Module_(Gadgeteer_Compatible)_(SKU:_DFR0063)

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <RTClib.h>

#if defined(ARDUINO) && ARDUINO >= 100
#define printByte(args)  write(args);
#else
#define printByte(args)  print(args,BYTE);
#endif

uint8_t clock[8] = {0x0,0xe,0x15,0x17,0x11,0xe,0x0};


RTC_DS1307 RTC;
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.print("Initialising...");
    lcd.createChar(2, clock);
  Wire.begin();
   RTC.begin();
   
   // following line sets the RTC to the date & time this sketch was compiled
    //RTC.adjust(DateTime(__DATE__, __TIME__));
}

void loop()
{
  lcd.clear();
   DateTime now = RTC.now();
   lcd.printByte(2);
   lcd.print(" ");
  lcd.print(now.hour(), DEC);
    lcd.print(':');
    lcd.print(now.minute(), DEC);
    lcd.print(':');
    lcd.print(now.second(), DEC);
   lcd.setCursor(0, 1);
   lcd.print(now.day(), DEC);
    lcd.print('/');
    lcd.print(now.month(), DEC);
    lcd.print('/');
    lcd.print(now.year(), DEC);
    lcd.print(' ');
  delay(1000);
}
