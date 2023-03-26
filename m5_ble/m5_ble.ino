/*
  BLE_Peripheral.ino

  This program uses the ArduinoBLE library to set-up an Arduino Nano 33 BLE 
  as a peripheral device and specifies a service and a characteristic. Depending 
  of the value of the specified characteristic, an on-board LED gets on. 

  The circuit:
  - Arduino Nano 33 BLE. 

  This example code is in the public domain.
*/

#include <ArduinoBLE.h>
#include <M5StickCPlus.h>
      
enum {
  NOTHING  = -1,
  GLAS    = 0,
  KUNSTSTOFF  = 1,
  RESTMUELL  = 2,
  PAPPE = 3
};

const char* deviceServiceUuid = "19b10000-e8f2-537e-4f6c-d104768a1214";
const char* deviceServiceCharacteristicUuid = "19b10001-e8f2-537e-4f6c-d104768a1214";

int gesture = -1;

BLEService gestureService(deviceServiceUuid); 
BLEByteCharacteristic gestureCharacteristic(deviceServiceCharacteristicUuid, BLERead | BLEWrite);


void setup() {
  Serial.begin(9600);
  while (!Serial);  
  
  // pinMode(LEDR, OUTPUT);
  // pinMode(LEDG, OUTPUT);
  // pinMode(LEDB, OUTPUT);
  // pinMode(LED_BUILTIN, OUTPUT);
  
  // digitalWrite(LEDR, HIGH);
  // digitalWrite(LEDG, HIGH);
  // digitalWrite(LEDB, HIGH);
  // digitalWrite(LED_BUILTIN, LOW);

  M5.begin();  // Initialize M5StickC PLus
  M5.Lcd.setTextSize(3);  // Set font size
  M5.Lcd.setRotation(3);  // Rotate the screen
  //M5.Lcd.print("Hello Kim");

  
  if (!BLE.begin()) {
    //Serial.println("BLow Energy module failed!");
    M5.Lcd.print("failed");
    while (1);
  } //else{
   // M5.Lcd.print("working");
  //}

  BLE.setLocalName("Arduino Nano 33 BLE (Peripheral)");
  BLE.setAdvertisedService(gestureService);
  gestureService.addCharacteristic(gestureCharacteristic);
  BLE.addService(gestureService);
  gestureCharacteristic.writeValue(-1);
  BLE.advertise();

  //Serial.println("Nano 33 BLE (Peripheral Device)");
  //Serial.println(" ");
}

void loop() {
  BLEDevice central = BLE.central();
  //Serial.println("Discovering central device...");
  delay(500);

  if (central) {
    // Serial.println("Connected to central device!");
    // Serial.print("Device MAC address: ");
    // Serial.println(central.address());
    // Serial.println(" ");

    while (central.connected()) {
      if (gestureCharacteristic.written()) {
         gesture = gestureCharacteristic.value();
         writeGesture(gesture);
       }
    }
    
    // Serial.println("Disconnected to central device!");
  }
}

void writeGesture(int gesture) {
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setCursor(0, 0);
   switch (gesture) {
      case GLAS:
        M5.Lcd.fillScreen(RED);
        M5.Lcd.setCursor(75, 50);
        M5.Lcd.print("GLAS");
        break;
      case KUNSTSTOFF:
        M5.Lcd.fillScreen(YELLOW);
        M5.Lcd.setCursor(25, 50);
        M5.Lcd.print("KUNSTSTOFF");
        break;
      case RESTMUELL:
        M5.Lcd.fillScreen(BLACK);
        M5.Lcd.setCursor(50, 50);
        M5.Lcd.print("RESTMUELL");
        break;
      case PAPPE:
        M5.Lcd.fillScreen(BLUE);
        M5.Lcd.setCursor(65, 50);
        M5.Lcd.print("PAPPE");
        break;
      default:
        M5.Lcd.fillScreen(BLACK);
        M5.Lcd.setCursor(0, 0);
        M5.Lcd.print("default");
        break;
    }      
}