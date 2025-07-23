int buttonPin = 2;
int counter = 0;
bool lastState = HIGH;
bool currentState;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // Internal pull-up resistor
  Serial.begin(9600);
}

void loop() {
  currentState = digitalRead(buttonPin);

  // Detect button press (LOW state)
  if (lastState == HIGH && currentState == LOW) {
    counter++;
    Serial.print("Button Pressed. Count = ");
    Serial.println(counter);
    delay(200); // debounce delay
  }

  lastState = currentState;
}
