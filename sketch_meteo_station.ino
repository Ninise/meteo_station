//Libraries

#include <LiquidCrystal.h>
#include <DHT.h>

//Constants
#define DHTPIN 2     // Coonected pin for DHT11
#define DHTTYPE DHT11   // DHT 11 
DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor for normal 16mhz Arduino

// Numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

//Variables
int chk;
float hum;  //Stores humidity value
float temp; //Stores temperature value

void setup()
{
  Serial.begin(9600);
	dht.begin();

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Temp & Humidity");

}

void loop()
{
    
    //Read data and store it to variables hum and temp
    hum = dht.readHumidity();
    temp= dht.readTemperature();
   
    String result = String(temp) + (char)223 + "C " + String(hum) + "%";

    lcd.setCursor(0, 1);

    lcd.print(result);

    delay(2000); //Delay 2 sec.
}


   
