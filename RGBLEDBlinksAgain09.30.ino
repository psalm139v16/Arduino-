// 1. We define all variables here at the top so the loop can use them
int RledPin = 3;
int GledPin = 4;
int BledPin = 5;
int buttonPin = 2; // Make sure your button is on digital pin 2

int buttonState = 0;  
int ledcolor = 0;
bool ButtonPressed = false; 

// This is the line that was missing or broken!
String currentcolor = "led"; 

void setup() {
  pinMode(RledPin, OUTPUT);
  pinMode(GledPin, OUTPUT);
  pinMode(BledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600); 
}

void loop() {
  buttonState = digitalRead(buttonPin);
  
  
  Serial.print("Current Color: ");
  Serial.println(currentcolor);

  // When button is pressed down
  if (buttonState == LOW && !ButtonPressed) {
    ledcolor = ledcolor + 1;
    ButtonPressed = true; 
  }
  
  // When button is released
  if (buttonState == HIGH && ButtonPressed) {
    ButtonPressed = false; 
  }

  // Loop back to mode 0 if it goes over 7
  if (ledcolor >= 8) {
    ledcolor = 0;
  }

  // --- LED COLOR MODES ---
  if (ledcolor == 0){
    currentcolor = "LED off";
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
  }
  else if (ledcolor == 1){
    currentcolor = "LED off";
    digitalWrite(RledPin, LOW);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
  }
  else if (ledcolor == 2){
    currentcolor = "red";
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, LOW); 
    digitalWrite(BledPin, HIGH);
  }
  else if (ledcolor == 3){
    currentcolor = "green";
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, LOW);
  }
  else if (ledcolor == 4){
    currentcolor = "blue"; 
    digitalWrite(RledPin, LOW);
    digitalWrite(GledPin, LOW);
    digitalWrite(BledPin, HIGH);
  }
  else if (ledcolor == 5){
    currentcolor = "yellow"; 
    digitalWrite(RledPin, LOW);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, LOW);
  }
  else if (ledcolor == 6){
    currentcolor = "purple"; 
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, LOW);
    digitalWrite(BledPin, LOW);
  }
  else if (ledcolor == 7){
    currentcolor = "White"; 
    digitalWrite(RledPin, LOW);
    digitalWrite(GledPin, LOW);
    digitalWrite(BledPin, LOW);
  }
  else if(ledcolor == 8){
    ledcolor =0;
  }
 
}
