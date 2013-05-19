// GSM Tasten
int switchOn = 13;
int switchNull = 12;

// Lichtschranke
int analogPin0 = 0;     
int analogPin1 = 1;
                       
int val0 = 0;
int val1 = 0;

void setup() {                
  Serial.begin(9600); // Serial Output
  pinMode(switchOn, OUTPUT);
  pinMode(switchNull, OUTPUT);
// GSM einschalten
  digitalWrite(switchOn, HIGH);   
  delay(3300);               // long press (Handy anschalten)
  digitalWrite(switchOn, LOW);    
  delay(34000);              // Bootzeit abwarten
// GSM Zeit"fehler" wegdrücken  
  digitalWrite(switchOn, HIGH);   
  delay(50);               // ggf. Zeitfehler wegdrücken
  digitalWrite(switchOn, LOW);  
}

void loop() {
  val0 = analogRead(analogPin0);    
  Serial.println("A0");
  Serial.println(val0);             
  val1 = analogRead(analogPin1);    
  Serial.println("A1");
  Serial.println(val1);             
//  delay(10000);  
// 
  if (val0 > val1) {
    digitalWrite(switchNull, HIGH);
    delay(50);
    digitalWrite(switchNull, LOW);
  } 
}

