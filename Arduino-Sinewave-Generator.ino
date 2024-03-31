// C++ code
//
const byte f = 50;
float t;
const float fs = 500.0;
int samples[500];
const int pwnPin = 11;
const int pwnPin2 = 10;

void setup() {
  Serial.begin(9600);
  pinMode(pwnPin, OUTPUT);
  pinMode(pwnPin2, OUTPUT);

  for (int i = 0; i < 500; i++) {
    t = i/fs;
    samples[i] = (int) 127 * (1 + sin(2*PI*f*t));
  }
}

void loop() {
  for (int i = 0; i < 500; i++) {
    analogWrite(pwnPin, samples[i]);
    analogWrite(pwnPin2, samples[i]);
    Serial.println(samples[i]);
    delay(2);
  }
}
