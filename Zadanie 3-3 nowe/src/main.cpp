#include <LiquidCrystal.h>
#include <stdio.h>

// Inicjalizacja obiektu klasy LiquidCrystal: RS, E, DB4, DB5, DB6, DB7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
char rxBuff[32];
int ValueA = 0, ValueB = 0;
char operation[16];


void setup() {
    lcd.begin(16, 2); //Ustawienie liczby kolumn i wierszy
    lcd.print("Jakub Serafin"); //Komunikat powitalny  
    Serial.begin(9600);
}

void loop() {  
    Serial.readBytesUntil('\r', rxBuff, sizeof(rxBuff) - 1);

    sscanf(rxBuff, "%d%s%d", ValueA, operation, ValueB);

    // Odczyt wartości i ich konwersja
    lcd.setCursor(0, 0); //W pierwszym wierszu jest wpisany tekst
    lcd.print(rxBuff);
    lcd.setCursor(0, 1);
  
  if (strcmp(operation, "+")) {
    lcd.print(ValueA + ValueB);
  } else if (strcmp(operation, "-")) {
     lcd.print(ValueA - ValueB);
  } else {
     lcd.print("Brak obslugi ");
  }
  delay(4000);

    // Wykonanie obliczeń i wyświetlenie wyniku
} 