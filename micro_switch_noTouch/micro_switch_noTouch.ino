#define IN_PIN 4 // ESP32 Pin D4
#define LED_PIN 2
#define SWTICH_PIN 5
int button_value = 0;
bool on_value = false;

void setup()
{
  Serial.begin(115200);
  delay(1000); // give me time to bring up serial monitor
  Serial.println("Micro Switch Test");
  pinMode(LED_PIN, OUTPUT);
  pinMode(SWTICH_PIN, OUTPUT);
  pinMode(IN_PIN, INPUT);
  digitalWrite (LED_PIN, LOW);
  digitalWrite (SWTICH_PIN, HIGH);
}

void loop()
{
    button_value = digitalRead(IN_PIN);
    Serial.println(button_value);  // get value
    if (button_value == HIGH )
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
    delay(500);
}
