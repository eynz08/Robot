// ---------- Pin Definitions ----------

// PWM output to TB6612FNG PWMA
const int pwmPin = 23;

// Direction pins
const int AIN1 = 26;
const int AIN2 = 27;

// Push buttons
const int CW_Button = 18;
const int CCW_Button = 19;


// ---------- Setup ----------

void setup() {

  // Attach hardware PWM to GPIO23
  ledcAttach(pwmPin, 1000, 8);

  // Set PWM duty cycle to 50%
  ledcWrite(pwmPin, 128);

  // Direction pins are outputs
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);

  // Buttons are inputs with internal pull-up resistors
  pinMode(CW_Button, INPUT_PULLUP);
  pinMode(CCW_Button, INPUT_PULLUP);

  // Motor starts stopped
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
}


// ---------- Main Loop ----------

void loop() {

  bool cw = digitalRead(CW_Button) == LOW;

  bool ccw = digitalRead(CCW_Button) == LOW;

  if (cw && !ccw) {

    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);

  }

  else if (ccw && !cw) {

    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);

  }

  else {

    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, LOW);

  }

}
