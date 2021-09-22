#include <Arduino.h>
#include <LiquidCrystal.h>


// Inicjalizacja obiektu klasy LiquidCrystal: RS, E, DB4, DB5, DB6, DB7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
    lcd.begin(16, 2); //Ustawienie liczby kolumn i wierszy
    lcd.print("Serafin"); //Komunikat powitalny  
}

void loop() {  
    lcd.setCursor(0, 1); // Przesunięcie kursora do początku drugiego wiersza
    lcd.print(millis() / 1000); //Wyświetlenie liczby sekund od uruchomienia
    delay(500); // Odczekanie w celu uniknięcia zbyt częstego odświeżania zawartości wyświetlacza
} 