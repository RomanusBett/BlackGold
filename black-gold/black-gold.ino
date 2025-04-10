const int ledPin = 2;        
const int photodiodePin = 25; 
const int feedBackPin = 27;
float baseline = 0;        
bool oilDetected = false;   

void setup() {
    pinMode(ledPin, OUTPUT);
    pinMode(feedBackPin, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    int ambientLight = analogRead(photodiodePin);
    digitalWrite(ledPin, HIGH);  
    delay(10);
    int sensorReading = analogRead(photodiodePin);
    digitalWrite(ledPin, LOW);   
    delay(500);  


    if (ambientLight >= 700 || ambientLight <= 50) return;
    if (sensorReading >= 700 || sensorReading <= 50) return;

    int finalReading = sensorReading - ambientLight;
    baseline = 0.9 * baseline + 0.1 * finalReading;

    int threshold = baseline - 50; 

    if (!oilDetected && finalReading < threshold) {
        digitalWrite(feedBackPin, HIGH);
        delay(3000);
        oilDetected = true;
        Serial.println("🛢️ Oil Detected!");
        digitalWrite(feedBackPin, LOW);
        delay(2000);
    } else {
        Serial.println("✅ No Oil Detected.");
    }

    Serial.print("Ambient light: "); Serial.println(ambientLight);
    Serial.print("SensorReading: "); Serial.println(sensorReading);
    delay(1000); 
}
