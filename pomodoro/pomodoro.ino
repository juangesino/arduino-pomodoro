
// Set RGB LED pins (common anode).
int redPin = 11;
int greenPin = 10;
int bluePin = 9;

// Set variables for periods of time.
// Set focus time to 10 minutes.
float focus = 10;
// Set short break to 20% of focus time.
float sbreak = focus * 0.2;
// Set long break to 80% of focus time.
float lbreak = focus * 0.8;

// Initialize the pomodoro counter.
int pomodoros = 0;

void setup() {
  // Set pins for RGB LED.
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}
 
void loop() {
  // We start with a period of focus.
  startFocus();
  // Keep focus on for as many minutes as focus variable indicates.
  delay(focus * 60000);
  // After focus period, add one to pomodoro counter.
  pomodoros = pomodoros + 1;
  
  // Check to see if we have reached 4 pomodoros.
  if (pomodoros >=4) {
    // If we have reached 4 pomodoros, reset counter.
    pomodoros = 0;
    // Start long break period.
    startLongBreak();
    // Keep long break on for as many minutes as focus variable indicates.
    delay(lbreak * 60000);
  } else {
    // Start short break period.
    startShortBreak();
    // Keep short break on for as many minutes as focus variable indicates.
    delay(sbreak * 60000);
  }
  
}

// Function for focus period.
// This function runs every time a focus period starts.
void startFocus() {
  // Set the LED to Red.
  setRed();
}

// Function for long break period.
// This function runs every time a long break starts.
void startLongBreak() {
  // Set the LED to Blue.
  setBlue();
}

// Function for short break period.
// This function runs every time a short break starts.
void startShortBreak() {
  // Set the LED to Green.
  setGreen();
}

// Simple function to control RGB LED.
void setColor(int red, int green, int blue) {
  // Subtract 255 beacuse using common anode.
  red = 255 - red;
  green = 255 - green;
  blue = 255 - blue;
  // Write values to pins.
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}

// Start functions to set colors on LED.
// Function to set LED to Red.
void setRed() {
 setColor(255, 0, 0); 
}
// Function to set LED to Green.
void setGreen() {
 setColor(0, 255, 0); 
}
// Function to set LED to Blue.
void setBlue() {
  setColor(0, 0, 255);
}
