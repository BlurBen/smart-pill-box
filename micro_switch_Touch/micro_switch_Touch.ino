#define TOUTCH_PIN T0 // ESP32 Pin D4
#define LED_PIN 2
#define SWTICH_PIN 5
int touch_value = 100;
bool on_value = false;

void setup()
{
  Serial.begin(115200);
  delay(1000); // give me time to bring up serial monitor
  Serial.println("Micro Switch Test");
  pinMode(LED_PIN, OUTPUT);
  pinMode(SWTICH_PIN, OUTPUT);
  digitalWrite (LED_PIN, LOW);
  digitalWrite (SWTICH_PIN, HIGH);
}

void loop()
{
  touch_value = touchRead(TOUTCH_PIN);
  Serial.println(touch_value);  // get value using T0
  if (touch_value < 5)
  {
    switch (on_value)
    {
      case false:
        on_value = true;
        break;
      case true:
        on_value = false;
        break;
    }
  }
  if (on_value == true)
  {
    digitalWrite (LED_PIN, HIGH);
  }
  else
  {
    digitalWrite (LED_PIN, LOW);
  }
  delay(1000);
}
