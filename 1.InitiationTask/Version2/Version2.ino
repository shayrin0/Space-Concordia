
char operation;

void setup() {
    Serial.begin(9600); // Serial Port at 9600 baud
}


void loop() {
    // Check if characters available in the buffer
    if (Serial.available() > 0) {
        operation = Serial.read();
        Serial.println("cmd = " + String(operation));
    }
}
