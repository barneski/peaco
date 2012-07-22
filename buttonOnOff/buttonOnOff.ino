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
  
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  
  Serial.println(start_msg);
}

void loop() {
  currentButton = digRead();
  if (currentButton == HIGH and lastButton == LOW) {
    ledOn = !ledOn;
  }
  lastButton = currentButton;
  digitalWrite(ledPin, ledOn);
}

boolean digRead() {
  adc_key_in = analogRead(7);
  key = get_key(adc_key_in);
  if (key == 3) {
    delay(50);
    adc_key_in = analogRead(7);
    key = get_key(adc_key_in);
  }
  return (key == 3);
}

int get_key(unsigned int input)
{   
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

