topse// Set all the pin numbers that read the digital signals. For example "inPin1" will be the pin number on the microcontroller that expects a signal when "outPin1" sends a digital signal.
#define inPin1 20
#define inPin2 21
#define inPin3 5
#define inPin4 6
#define inPin5 9
#define inPin6 10

// Set all the pin numbers that send digital output signals.
#define outPin1 11
#define outPin2 12
#define outPin3 13
#define outPin4 14
#define outPin5 15
#define outPin6 16

// Set all the pin numbers that light up an LED when an input is detected correctly for a corresponding output
#define LEDpin1 1
#define LEDpin2 0
#define LEDpin3 22
#define LEDpin4 23
#define LEDpin5 24
#define LEDpin6 19

// This time delay is in milliseconds and allows time for each pulldown resistor to drain the input pins. Increasing the timedelay is also a good way of increasing battery life
#define timedelay 20

// Sets the mode of each pin
void setup() {
  pinMode(outPin1, OUTPUT);
  pinMode(inPin1, INPUT);
  pinMode(LEDpin1, OUTPUT);
  pinMode(outPin2, OUTPUT);
  pinMode(inPin2, INPUT);
  pinMode(LEDpin2, OUTPUT);
  pinMode(outPin3, OUTPUT);
  pinMode(inPin3, INPUT);
  pinMode(LEDpin3, OUTPUT);
  pinMode(outPin4, OUTPUT);
  pinMode(inPin4, INPUT);
  pinMode(LEDpin4, OUTPUT);
  pinMode(outPin5, OUTPUT);
  pinMode(inPin5, INPUT);
  pinMode(LEDpin5, OUTPUT);
  pinMode(outPin6, OUTPUT);
  pinMode(inPin6, INPUT);
  pinMode(LEDpin6, OUTPUT);
}

// This section is what is ran continuously during operation. The outPin sends a digital signal. The inPin reads that signal. If the signal is read correctly, then the LEDpin will turn on.
void loop() {
  checkPin(outPin1, inPin1, LEDpin1);
  checkPin(outPin2, inPin2, LEDpin2);
  checkPin(outPin3, inPin3, LEDpin3);
  checkPin(outPin4, inPin4, LEDpin4);
  checkPin(outPin5, inPin5, LEDpin5);
  checkPin(outPin6, inPin6, LEDpin6);
}

// Function sets the outpin high, then waits for the specified time delay. The voltage on the inPin is read. The outpin is then set to low. If that inPin is high, then the LEDpin is set to high.
void checkPin(int outpin, int inpin, int ledpin){
  int result;
  digitalWrite(outpin, HIGH);
  delay(timedelay);
  result = digitalRead(inpin);
  digitalWrite(outpin, LOW);
  digitalWrite(ledpin, result);
  delay(timedelay);
}
