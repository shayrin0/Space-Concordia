
#define sensorpin A0
int sensordata = 0;
char incomingData;

void setup() {
  Serial.begin(9600);
  pinMode(sensorpin, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite (LED_BUILTIN, LOW);
}


void loop() {
  while (Serial.available()) {
    incomingData = Serial.read();
    if (incomingData == '1') {
      digitalWrite (LED_BUILTIN, HIGH);
    }
    else if (incomingData == '0'){
      digitalWrite (LED_BUILTIN, LOW);
    }
    else if (incomingData == 'R'){
      sensordata = analogRead(sensorpin);
      Serial.println(sensordata);
    }
  }
}
