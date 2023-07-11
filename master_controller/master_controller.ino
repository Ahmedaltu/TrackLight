#include <Wire.h>
#include <math.h>

#define SLAVE_ADDRESS_1 0x10  // I2C address of slave 1
#define SLAVE_ADDRESS_2 0x20  // I2C address of slave 2
float receivedData1;
float receivedData2;
float oldAngle= 0.0;
int transistorPin = 2;
int pin12=12;
unsigned long startTime;
void setup() {
  Serial.begin(115200);
  pinMode(transistorPin, OUTPUT);
  pinMode(pin12, OUTPUT);
  Wire.begin();
  Wire.onReceive(receiveData);
  startTime = millis() + 30000;  // Set the start time 20 seconds in the future

}

void loop() {
  unsigned long currentTime = millis();
  // Request data from Slave 1
  Wire.requestFrom(SLAVE_ADDRESS_1, sizeof(float));
  if (Wire.available()) {
    Wire.readBytes((uint8_t*)&receivedData1, sizeof(float));
    Serial.print("Received data from Slave 1: ");
    Serial.println(receivedData1);
  }
  delay(250);
  
  // Request data from Slave 2
  Wire.requestFrom(SLAVE_ADDRESS_2, sizeof(float));
  if (Wire.available()) {
    Wire.readBytes((uint8_t*)&receivedData2, sizeof(float));
    Serial.print("Received data from Slave 2: ");
    Serial.println(receivedData2);
  }
  
  //delay(250);
  if (currentTime >= startTime) {
    rfControl(receivedData1, receivedData2);
  }
}

void receiveData(int byteCount) {
  // This function is not used in the current implementation
}
void rfControl(float t1, float t2) {
  // This function is controlling the remote control and then control the ligth.
  t1 = t1 - 1.60;
  t2 = t2 - 1.10;
  float t3= 2.0;
  float numerator = t2 * t2 + t3 * t3 - t1 * t1;
  float denominator = 2 * t2 * t3;
  float cosValue = numerator / denominator;

  // Ensure cosValue is within the valid range [-1, 1] due to floating-point inaccuracies
  cosValue = max(min(cosValue, 1.0f), -1.0f);

  float angle = acos(cosValue);
  angle =(angle * 180.0 / M_PI) ;

  Serial.println(angle);
  if ((oldAngle - angle > 5) || (angle - oldAngle > 5)){
    if (angle > oldAngle){
      
      int delayTimeR = angle - oldAngle ;      
      Serial.print("angle > oldAngle: ");

      digitalWrite(transistorPin, HIGH);  // turn right
      delay(delayTimeR *25); 
      digitalWrite(transistorPin, LOW);
      delay(350);

    }
    if (oldAngle > angle){
      
      int delayTimeL = oldAngle - angle  ;
      Serial.print("oldAngle > angle: ");
   
      digitalWrite(pin12, HIGH);  // turn left
      delay((delayTimeL *25) +16); 
      digitalWrite(pin12, LOW);
      delay(350);
    }
    
  }
    
  oldAngle = angle;
  //delay(600);


}
