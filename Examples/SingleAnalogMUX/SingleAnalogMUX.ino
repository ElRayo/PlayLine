#include <QTRSensors.h>

// This example is designed for use with eight analog MUX QTR sensors. These
// reflectance sensors should be connected to analog pin A0. The
// sensors' emitter control pin (CTRL or LEDON) can  be required connected to
// digital pin 7, 
// setEmitterPin(7).
// This library uses analog MUX, each strip have eigth Anlog input and only Analog (OUT)
// The control of MUX:
// - Three selectors (A, B, C)
// - One enable (ENA)
// - ONE LED On (LED)
// - VCC 5/3v (VCC) It can be 5VDC or 3.3 VDC, 5VDC (default), solder the jump over the borad -> 3.3VDC
// - GND (VCC)
/*
 * PINOUT
 * +-----+-----+-----+-----+
 * | OUT |  A  |  B  |  C  |
 * +-----+-----+-----+-----+
 * | GND | LED | ENA | VCC |
 * +-----+-----+-----+-----+
 */

QTRSensors qtr;

//Set the sensors and the number of sensors
const uint8_t SensorCount = 8;
uint16_t sensorValues[SensorCount];

void setup()
{
  // configure the serial port
  Serial.begin(9600);
  //Set the sensor as type Analog MUX 
  qtr.setTypeAnalogMUX();
  //Warning, SET ONLY ONE INPUT PIN
  qtr.setSensorPins((const uint8_t[]){A0}, SensorCount);
  qtr.setEmitterPin(7);
  //Set the control pins "Selectors and Enables"
  qtr.setSelectorPins((const uint8_t[]){2, 3, 4}, 3);
  qtr.setEnablePins((const uint8_t[]){5}, 1);
  delay(1000);
}

void loop()
{
  // read raw sensor values
  qtr.read(sensorValues);

  // print the sensor values as numbers from 0 to 1023, where 0 means maximum
  // reflectance and 1023 means minimum reflectance
  for (uint8_t i = 0; i < SensorCount; i++)
  {
    Serial.print(sensorValues[i]);
    Serial.print('\t');
  }
  Serial.println();

  delay(250);

  
}
