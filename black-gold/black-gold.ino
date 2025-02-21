const int LED_PIN = 2;
const int photodiodePin = 25;


void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);

}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  int lightValue = analogRead(photodiodePin);
  Serial.print("Light Intensity: ");
  Serial.println(lightValue);
  digitalWrite(LED_PIN, LOW);
  delay(1000);
}
