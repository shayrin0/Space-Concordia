

int totalChannels = 8;

int addressA = 8;
int addressB = 9;
int addressC = 10;
int outputpin = 13;

int A = 0;      //Address pin A
int B = 0;      //Address pin B
int C = 0;      //Address pin C

int Vo;
float R1 = 10000;
float logR2, R2, T;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;


void setup() {
  Serial.begin(9600);
  // Prepare address pins for output
  pinMode(addressA, OUTPUT);
  pinMode(addressB, OUTPUT);
  pinMode(addressC, OUTPUT);
  // Prepare write/output pin 
//  pinMode(outputpin, OUTPUT);/
  pinMode(A0, INPUT);
}

void loop() {
  int reading;
  double tempReadings;
  //Select each pin and read value
//  for(int i=0; i<totalChannels; /i++){
//    A = bitRead(i,0); //Take first bit from binary value of i channel.
//    B = bitRead(i,1); //Take second bit from binary value of i channel.
//    C = bitRead(i,2); //Take third bit from value of i channel.

    //Write address to mux
    digitalWrite(addressA, A);
    digitalWrite(addressB, B);
    digitalWrite(addressC, C);

  
 
//  reading = analogRead(A0);
// 
//  Serial.print("Analog reading "); 
//  Serial.println(reading);
 
 
  Vo = analogRead(A0);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  T = T - 273.15;
//  T = (T * 9.0)/ 5.0 + 32.0; /

  Serial.print("Temperature: "); 
  Serial.print(T);
  Serial.println(" C"); 


//   Serial.print(" value: ");
//   Serial.println(analogRead(A0));
//   Serial.println(tempReadings);

    //Write value
//    digitalWrite(outputpin, 1);
    //Set delay to 1000 and then to 1 to see difference
    delay(1000);
//  }/
  
}
