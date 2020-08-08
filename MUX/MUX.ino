

#define addressA 8
#define addressB 9
#define addressC 10
#define outputpin 13

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
  
  pinMode(A0, INPUT);
}

void loop() {
  
  //Write address to mux
  digitalWrite(addressA, A);
  digitalWrite(addressB, B);
  digitalWrite(addressC, C);

 
  Vo = analogRead(A0);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  T = T - 273.15;
  //  T = (T * 9.0)/ 5.0 + 32.0; 

  Serial.print("Temperature: "); 
  Serial.print(T);
  Serial.println(" C"); 
  delay(1000);
  
}
