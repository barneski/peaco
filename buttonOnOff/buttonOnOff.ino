// This program responds to button S3 on the Romeo microcontroller.  
// When S3 is pressed initially, the LED turns (and stays) on.  When
// the button is pressed again, the LED turns off.

int ledPin = 13;
char start_msg[15] = {"Start Loop "};
int adc_key_val[5] = {30, 150, 360, 535, 760};
int NUM_KEYS = 5;
int adc_key_in;
int key = -1;
int ledOn = false;
boolean lastButton = LOW;
boolean currentButton;

  

void setup() {
  // Set ledPin as an output and print a start message
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  
  Serial.println(start_msg);
}

void loop() {
  // Get the state of the current button
  currentButton = digRead();
  
  // If button is pressed (currentButton == HIGH) and button was previously
  // off, switch the led state from on to off or off to on
  if (currentButton == HIGH and lastButton == LOW) {
    ledOn = !ledOn;
  }
  
  // set the new lastButton and make the led switch
  lastButton = currentButton;
  digitalWrite(ledPin, ledOn);
}

boolean digRead() {
  // takes in an analog reading of pin 7 to determine
  // if button 3 has been pressed.  Returns True if button has not
  // been pressed and False if it has been
  adc_key_in = analogRead(7);
  key = get_key(adc_key_in);
  if (key == 3) {
    delay(50);  // debounce
    adc_key_in = analogRead(7);
    key = get_key(adc_key_in);
  }
  return (key == 3);
}

int get_key(unsigned int input) {
  // Takes an ADC value and converts it to a button
  // number between 1 and NUM_KEYS
  int k;
  for (k = 0; k < NUM_KEYS; k++)
  {
    if (input < adc_key_val[k])
    {  
      return k;  
    }
  }
  if (k >= NUM_KEYS)
    k = -1;     // No valid key pressed
  return k;
}

