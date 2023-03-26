/*
  BLE_Central_Device.ino

  This program uses the ArduinoBLE library to set-up an Arduino Nano 33 BLE Sense 
  as a central device and looks for a specified service and characteristic in a 
  peripheral device. If the specified service and characteristic is found in a 
  peripheral device, the last detected value of the on-board trashType
 sensor of 
  the Nano 33 BLE Sense, the APDS9960, is written in the specified characteristic. 

  The circuit:
  - Arduino Nano 33 BLE Sense. 

  This example code is in the public domain.
*/

#include <ArduinoBLE.h>
#include <Arduino_APDS9960.h>
#include <Arduino_LSM9DS1.h>

/* Includes ---------------------------------------------------------------- */
#include <trash1_inferencing.h>
#include <Arduino_OV767X.h>  //Click here to get the library: http://librarymanager/All#Arduino_OV767X

#include <stdint.h>
#include <stdlib.h>


static bool debug_nn = false;  // Set this to true to see e.g. features generated from the raw signal

const char* deviceServiceUuid = "19b10000-e8f2-537e-4f6c-d104768a1214";
const char* deviceServiceCharacteristicUuid = "19b10001-e8f2-537e-4f6c-d104768a1214";

int trashType = -1;
int oldtrashTypeValue = -1;

void setup() {
  Serial.begin(9600);
  while (!Serial)
    ;

  Serial.println("Started");

  if (!BLE.begin()) {
    Serial.println("* Starting Bluetooth® Low Energy module failed!");
    while (1)
      ;
  }

  BLE.setLocalName("Nano 33 BLE (Central)");
  BLE.advertise();

  Serial.println("Arduino Nano 33 BLE Sense (Central Device)");
  Serial.println(" ");
}

void loop() {

  // GLAS
  trashType = 0;
  delay(2000);
  connectToPeripheral(trashType);
  delay(7000);

  // KUNSTSTOFF
  trashType = 1;
  connectToPeripheral(trashType);
  delay(7000);

  // RESTMUELL
  trashType = 2;
  connectToPeripheral(trashType);
  delay(7000);

  // PAPPE
  trashType = 3;
  connectToPeripheral(trashType);
  delay(8000);
}

void connectToPeripheral(int trashType) {
  BLEDevice peripheral;
  Serial.println("HERE!");
  Serial.println("- Discovering peripheral device...");

  do {
    BLE.scanForUuid(deviceServiceUuid);
    peripheral = BLE.available();
  } while (!peripheral);

  if (peripheral) {
    Serial.println("* Peripheral device found!");
    Serial.print("* Device MAC address: ");
    Serial.println(peripheral.address());
    Serial.print("* Device name: ");
    Serial.println(peripheral.localName());
    Serial.print("* Advertised service UUID: ");
    Serial.println(peripheral.advertisedServiceUuid());
    Serial.println(" ");
    BLE.stopScan();
    controlPeripheral(peripheral, trashType);
  }
}

void controlPeripheral(BLEDevice peripheral, int trashType) {
  Serial.println("- Connecting to peripheral device...");

  if (peripheral.connect()) {
    Serial.println("* Connected to peripheral device!");
    Serial.println(" ");
  } else {
    Serial.println("* Connection to peripheral device failed!");
    Serial.println(" ");
    return;
  }

  Serial.println("- Discovering peripheral device attributes...");
  if (peripheral.discoverAttributes()) {
    Serial.println("* Peripheral device attributes discovered!");
    Serial.println(" ");
  } else {
    Serial.println("* Peripheral device attributes discovery failed!");
    Serial.println(" ");
    peripheral.disconnect();
    return;
  }

  BLECharacteristic trashTypeCharacteristic = peripheral.characteristic(deviceServiceCharacteristicUuid);

  if (!trashTypeCharacteristic) {
    Serial.println("* Peripheral device does not have trashType_type characteristic!");
    peripheral.disconnect();
    return;
  } else if (!trashTypeCharacteristic.canWrite()) {
    Serial.println("* Peripheral does not have a writable trashType_type characteristic!");
    peripheral.disconnect();
    return;
  }

  while (peripheral.connected()) {
    //trashType= 1;

    if (oldtrashTypeValue != trashType) {
      oldtrashTypeValue = trashType;
      // Serial.print("* Writing value to trashType_type characteristic: ");
      // Serial.println(trashType);
      trashTypeCharacteristic.writeValue((byte)trashType);
      Serial.println("* Writing value to trashType_type characteristic done!");
      // Serial.println(" ");
    }
    peripheral.disconnect();
  }
  Serial.println("- Peripheral device disconnected!");
}

// int trashDetection(){
//   String trash = 'glas';
//   int trashNo;
//   switch (trash) {
//       case glas:
//         Serial.println("glas detected");
//         trashNo = 0;
//         break;
//       case kunststoff:
//         Serial.println("kunststoff detected");
//         trashNo = 1;
//         break;
//       case restmuell: left
//         Serial.println("restmuell detected");
//         trashNo = 2;
//         break;
//       case pappe:
//         Serial.println("pappe detected");
//         trashNo = 3;
//         break;
//       default:
//         Serial.println("nothing detected");
//         trashNo = -1;
//         break;
//       }
//     }
//     Serial.println(trash);
//     Serial.println(trashNo);
//     return trashNo;
// }

// int trashTypeDetectection() {
//   if (APDS.trashTypeAvailable()) {
//     trashType
//    = APDS.readtrashType
//   ();

//     switch (trashType) {
//       case trashType_UP:
//         Serial.println("- UP trashType detected");
//         break;
//       case trashType_DOWN:
//         Serial.println("- DOWN trashType detected");
//         break;
//       case trashType_LEFT:
//         Serial.println("- LEFT trashTypedetected");
//         break;
//       case trashType_RIGHT:
//         Serial.println("- RIGHT trashType detected");
//         break;
//       default:
//         Serial.println("- No trashType detected");
//         break;
//       }
//     }
//     return trashType
//   ;
// }