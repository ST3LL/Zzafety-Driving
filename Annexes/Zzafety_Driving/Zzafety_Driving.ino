/**************************************************************************/
/*!
    @author   Estelle FIKET

    Code :
    - Récupération de données à partir d'un accéléromètre
    - Lorsque détection d'un inclinaison critique --> effet sonore (buzzer)
*/
/**************************************************************************/

#include <Wire.h>
#include <Adafruit_MMA8451.h>
#include <Adafruit_Sensor.h>
#include <BluetoothSerial.h>

Adafruit_MMA8451 mma = Adafruit_MMA8451(); //initialisation
//int d = 3;

void setup(void) 
{
  if (! mma.begin()) 
  {
    Serial.println("Couldnt start");
    while (1);
  }
  Serial.println("MMA8451 found!");
  
  mma.setRange(MMA8451_RANGE_2_G);
  
  Serial.print("Range = "); Serial.print(2 << mma.getRange());  
  Serial.println("G");

  pinMode(33, OUTPUT);
  //digitalWrite(33, HIGH); //stop son pour test
}


void loop() {
  int AX = 0;
  int AY = 0;
  int AZ = 0;
  
  // Read the 'raw' data in 14-bit counts
  mma.read();
  
  for(int i = 0; i< 1000; i++)
  {
    AX = mma.x;
    AY = mma.y;
    AZ = mma.z;
  }
  Serial.print("X:\t"); Serial.print(AX); 
  Serial.print("\tY:\t"); Serial.print(AY); 
  Serial.print("\tZ:\t"); Serial.print(AZ); 
  Serial.println();

  /* Get a new sensor event */ 
  sensors_event_t event; 
  mma.getEvent(&event);


  if ((-2500<AX) && (AX<1400) && (3000 < AY) && (AY < 5000))
  {
    Serial.print("Ok");
    digitalWrite(33, HIGH); // pas de bruit
    delay(1000);
  }
  else 
  {
    Serial.print("Wake up");
    delay(3000);
    digitalWrite(33, LOW); // bruit
    delay(1000);   
  }
  
       
  /* Get the orientation of the sensor */
  uint8_t o = mma.getOrientation();
  
  switch (o) {
    case MMA8451_PL_PUF: 
      Serial.println("Portrait Up Front");
      break;
    case MMA8451_PL_PUB: 
      Serial.println("Portrait Up Back");
      break;    
    case MMA8451_PL_PDF: 
      Serial.println("Portrait Down Front");
      break;
    case MMA8451_PL_PDB: 
      Serial.println("Portrait Down Back");
      break;
    case MMA8451_PL_LRF: 
      Serial.println("Landscape Right Front");
      break;
    case MMA8451_PL_LRB: 
      Serial.println("Landscape Right Back");
      break;
    case MMA8451_PL_LLF: 
      Serial.println("Landscape Left Front");
      break;
    case MMA8451_PL_LLB: 
      Serial.println("Landscape Left Back");
      break;
    }
  Serial.println();
  
  delay(100);
  
}
