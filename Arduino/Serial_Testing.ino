int LED1 = 2;
int LED2 = 3;
int LED3 = 4;
int LED4 = 5;
int sig;


void setup() {

Serial.begin(9600);

pinMode(LED1, OUTPUT);
pinMode(LED2, OUTPUT);
pinMode(LED3, OUTPUT);
pinMode(LED4, OUTPUT);


}

void loop() {

if (Serial.available()){
  sig = Serial.read();
  Serial.print("Recieved a point");
}

if (sig == 'C'){
  digitalWrite(LED1,HIGH); 
  digitalWrite(LED2,LOW);
  //pitch up
}

if (sig == 'F'){
  digitalWrite(LED2,HIGH);
  digitalWrite(LED1,LOW); 
  //pitch down
}

if (sig == 'G'){
  digitalWrite(LED3,HIGH);
  digitalWrite(LED4,LOW);
  //roll left
}

if (sig == 'H'){
  digitalWrite(LED4,HIGH);
  digitalWrite(LED3,LOW);
  //roll right
}

delay(20);

}
