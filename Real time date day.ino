#include <Wire.h>
#include <RTClib.h>
#include <LiquidCrystal_I2C.h>

// Initialize RTC and LCD
RTC_DS3231 rtc;
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Use 0x3F if 0x27 doesn't work

// Array of days
const char *daysOfWeek[] = {
  "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
};

// Flag to set RTC time manually once
bool setRTCtimeOnce = true;

void setup() {
  Wire.begin();
  lcd.init();
  lcd.backlight();

  // Check RTC
  if (!rtc.begin()) {
    lcd.print("RTC Not Found!");
    while (1);  // Stop execution
  }

  // Set RTC time manually (only run once)
  if (setRTCtimeOnce) {
    DateTime customTime(2025, 10, 7, 2, 24, 0); // YYYY, MM, DD, HH, MM, SS
    rtc.adjust(customTime);

    lcd.clear();
    lcd.print("RTC Time Set!");
    delay(2000);
    
    // Disable flag after first set
    setRTCtimeOnce = false;
  }

  lcd.clear();
}

void loop() {
  DateTime now = rtc.now();  // Get current RTC time

  // --- Line 1: Day + Time ---
  lcd.setCursor(0, 0);
  lcd.print("                ");  // Clear line
  lcd.setCursor(0, 0);

  lcd.print(daysOfWeek[now.dayOfTheWeek()]);
  lcd.print(" ");

  if (now.hour() < 10) lcd.print("0");
  lcd.print(now.hour());
  lcd.print(":");
  if (now.minute() < 10) lcd.print("0");
  lcd.print(now.minute());
  lcd.print(":");
  if (now.second() < 10) lcd.print("0");
  lcd.print(now.second());

  // --- Line 2: Date ---
  lcd.setCursor(0, 1);
  lcd.print("                ");  // Clear line
  lcd.setCursor(0, 1);

  if (now.day() < 10) lcd.print("0");
  lcd.print(now.day());
  lcd.print("/");
  if (now.month() < 10) lcd.print("0");
  lcd.print(now.month());
  lcd.print("/");
  lcd.print(now.year());

  delay(1000);  // Update every second
}
