
// ── Motor Driver Pins ──────────────────────────────────
int in1 = 2;
int in2 = 4;
int in3 = 7;
int in4 = 8;

int enA = 9;
int enB = 10;

// ── IR Sensor Pins ─────────────────────────────────────

int left_IR  = 11;
int right_IR = 12;

// ── Speed ──────────────────────────────────────────────
int motorSpeed = 77;

// IR sensor logic:
// LOW  == WHITE surface detected (off the line)
// HIGH == BLACK surface detected (on the line)

void setup() {
  Serial.begin(9600);

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(left_IR,  INPUT);
  pinMode(right_IR, INPUT);


}

void loop() {
  int leftVal  = digitalRead(left_IR);
  int rightVal = digitalRead(right_IR);

  if (leftVal == LOW && rightVal == LOW) {
    moveForward();
  }
  else if (leftVal == HIGH && rightVal == LOW) {
    moveLeft();
  }
  else if (leftVal == LOW && rightVal == HIGH) {
    moveRight();
  }
  else if (leftVal == HIGH && rightVal == HIGH) {
    stop();
  }

  Serial.print("L:"); Serial.print(leftVal);
  Serial.print(" R:"); Serial.println(rightVal);
}

void moveForward() {
  analogWrite(enA, motorSpeed);   // speed set here 
  analogWrite(enB, motorSpeed);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void moveRight() {
  analogWrite(enA, motorSpeed);
  analogWrite(enB, motorSpeed);
  // Right motor reverse
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  // Left motor forward
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void moveLeft() {
  analogWrite(enA, motorSpeed);
  analogWrite(enB, motorSpeed);
  // Right motor forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // Left motor reverse
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void stop() {
  //write 0 to enable pins so motors fully stop
  analogWrite(enA, 0);
  analogWrite(enB, 0);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
