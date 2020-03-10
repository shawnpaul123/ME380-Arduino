#include <Servo.h>             //Servo library

/*include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(); 

*/

//!1-Have a for loop that create a mid function by divinding the two and storing the value
	// set all servos to mid value after calibration

//function headers
void motor(int[], int);
void updateArray(int[]);

//Initialize all servos
Servo servo1;
Servo servo2; 
Servo servo3; 
Servo servo4; 
Servo servo5; 
Servo servo6; 
//distances
int distanceThreshold = 350;
int cm = 0;
int inches = 0;
int size = 6;
//arrays for ServoMins, ServoMids,ServoMaxs
int ServoMins[] = {0,0,0,0,0,0};
int ServoMids[] = {0,0,0,0,0,0};
int ServoMaxs[] = {180,180,180,180,180,180};
int arrPosition[] = {50,50,50,50,50,50};



void updateArray(int arrPos[], int size)
{
  for(int i = 0; i < size; i++)
  {
    arrPosition[i] = arrPos[i];
  }
}

void midArray(int size)
{ int i = 0;
  //int ServoMaxs[] = {180,180,180,180,180,180};
  //int ServoMins[] = {0,0,0,0,0,0};
  for( i = 0; i < size; i++)
  {
    ServoMids[i] = (ServoMaxs[i] +  ServoMins[i])/2.0;
   // Serial.print(ServoMids[i]);
  }
}

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  
/*
  for (int i = 0; i<sizeof ServoMins/sizeof ServoMins[0]; i++) {
    	ServoMids[i] = (ServoMins[i] + ServoMaxs[i])/2.0 ;  
  }*/
  //Serial.println(ServoMids);
  int servoPin1 = 8;
  int servoPin2 = 9;
  int servoPin3 = 10;
  int servoPin4 = 11;
  int servoPin5 = 12;
  int servoPin6 = 13;
  
  
  
  
  
  
  Serial.begin(9600);//need this for debugger
  pinMode(2, OUTPUT);//we removed this
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  
  servo1.attach(servoPin1); 
  servo2.attach(servoPin2); 
  servo3.attach(servoPin3); 
  servo4.attach(servoPin4); 
  servo5.attach(servoPin5); 
  servo6.attach(servoPin6); 
  
  

 //remove Serial.println("ServoMids");
  //	Serial.println(ServoMids[5]);
 // pwm.setPWMFreq(50); // set sero Frequency [Hz]
 // for (int i = 0; i < 16; i++) pwm.setPWM(i, 0, 0); // Set all pins to 'off', motors can freely move

}

void loop()
{
  // set threshold distance to activate LEDs
  distanceThreshold = 350;
  // measure the ping time in cm
  cm = 0.01723 * readUltrasonicDistance(7, 7);
  cm = 0;
  int check = 0;
  // convert to inches by dividing by 2.54
  inches = (cm / 2.54);
  /*
  Serial.print(cm);
  Serial.print("cm, ");
  Serial.print(inches);
  Serial.println("in");
  */
  //if just testing the motor
  //declare random cm value
  //refer off one array for positions
  
  // 5 if statements with array number so that you have 4 positions for each \
  //servo and one stationary position
  midArray(size);
  
  if (cm == check) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    int arrPos[] = {10,20,30,40,50,60};
    updateArray(arrPos, size);
    Serial.print("if statement1 works");
    
  }
  else if (cm <= distanceThreshold && cm > distanceThreshold - 100) {
    
    //distance threshold is 350 
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    int arrPos[] = {20,20,20,20,20,20};
    updateArray(arrPos, size);
    Serial.print("works");
  }
  else if (cm <= distanceThreshold - 100 && cm > distanceThreshold - 250) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    int arrPos[] = {30,30,30,30,30,30};
    updateArray(arrPos, size);
    Serial.print("works");
  }
  else if (cm <= distanceThreshold - 250 && cm > distanceThreshold - 350) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    int arrPos[] = {40,40,40,40,40,40};
    updateArray(arrPos, size);
    Serial.print("works");
  }
  else if (cm <= distanceThreshold - 350) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    int arrPos[] = {50,50,50,50,50,50};
    updateArray(arrPos, size);
    Serial.print("works");
    
    
  }
  
  delay(100); // Wait for 100 millisecond(s)
  //int servoNum[6] = {1,2,3,4,5,6};
  motor(arrPosition,size);
  Serial.print("now in motor");
     
    
  }
  


void motor(int arr[], int size){
  Serial.println(sizeof arr);
  for (int i=1; i<size; i++) {
    int a = arr[i];
    int servoNum = i;
    Serial.println(a);
    Serial.println("servoAngle");
    Serial.println(servoNum);
    Serial.println("servoNum");
    if (servoNum == 1){
      servo1.write(a);
      Serial.println(a);
    }
    else if (servoNum == 2){
      servo2.write(a);
      Serial.println(a);
    }
    else if (servoNum == 3){
      servo3.write(a);
      Serial.println(a);
    }
    else if (servoNum == 4){
      servo4.write(a);
      Serial.println(a);
    }
    else if (servoNum == 5){
      servo5.write(a);
      Serial.println(a);
    }
    else if (servoNum == 6){
      servo6.write(a);
      Serial.println(a);
    }
    
    
    
      
    
      
    }
  
}