#define ECHOPIN 10
#define TRIGPIN 9
int pulseResult = 0;
int updatedDistance = 0;
int fullBinAt = 40;  // <=== Change this value to Update distance sensor. 
int buzzerPin = 12;   

void setup() {
  // SetUp for distanceSensor
  Serial.begin(9600);
  pinMode(ECHOPIN, INPUT_PULLUP);
  pinMode(TRIGPIN, OUTPUT);
  digitalWrite(ECHOPIN, HIGH);

  // SetUp for Bin State Lights
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  
  // SetUp the Buzzer
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Set Green light ON 
  digitalWrite(1, HIGH);
  
  // Read sensor and update value of 'updatedDistance' variable
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(15);
  digitalWrite(TRIGPIN, LOW);

  // Update distance base on EchoPin.
  pulseResult = pulseIn(ECHOPIN, HIGH, 26000);
  updatedDistance = pulseResult/58;

  // Loggin the updatedDistance
  Serial.println(updatedDistance);
  Serial.print(" cm");
  


  // Based on the distance choose Lights setUp for this Loop. 
  if(updatedDistance >= fullBinAt){
      digitalWrite(3, LOW);
      
      digitalWrite(2, HIGH);
      tone(buzzerPin, 150);
      delay(300);
      digitalWrite(2, LOW);
      noTone(buzzerPin);
      delay(200);
    
      digitalWrite(2, HIGH);
      tone(buzzerPin, 180);
      delay(200);
      digitalWrite(2, LOW);
      noTone(buzzerPin);
      delay(500);
    
    } else {
      digitalWrite(2, LOW);
      
      digitalWrite(3, HIGH);
      tone(buzzerPin, 659);
      delay(200);
      
      digitalWrite(3, LOW);
      noTone(buzzerPin);
      delay(200);
      }

}
