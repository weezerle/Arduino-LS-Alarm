// GSM Tasten
int switchOn = 13;
int switchCall = 12;

// Lichtschranke
int analogPin0 = 0;     
int analogPin1 = 1;

// Status LED
int ledLS = 9;
int ledSetup = 10;

// LS Sensoren                       
int val0 = 0;
int val1 = 0;

void setup() {
//  Serial.begin(9600); // Serial Output (LS Signalausgabe)
  pinMode(switchOn, OUTPUT);
  pinMode(switchCall, OUTPUT);
  pinMode(ledLS, OUTPUT);
  pinMode(ledSetup, OUTPUT);

// LED-Test
  digitalWrite(ledSetup, HIGH);
  delay(500);               // 0,5sec break
  digitalWrite(ledSetup, LOW); 
  delay(500);               // 0,5sec break
  digitalWrite(ledLS, HIGH); 
  delay(500);               // 0,5sec break
  digitalWrite(ledLS, LOW); 
// Testlauf LEDs

// GSM einschalten
  digitalWrite(switchOn, HIGH);   
  delay(3000);               // long press (Handy anschalten)
  digitalWrite(switchOn, LOW);    
  delay(30000);              // Bootzeit abwarten
// Ggf. Bildschirm Reaktivieren  
//  digitalWrite(switchOn, HIGH);   
//  delay(50);               
//  digitalWrite(switchOn, LOW); 
//  delay(160);
  digitalWrite(ledSetup, HIGH); 
}

void loop() {
  val0 = analogRead(analogPin0);    
//  Serial.println("A0"); (LS Signalausgabe)
//  Serial.println(val0);             
  val1 = analogRead(analogPin1);    
//  Serial.println("A1"); (LS Signalausgabe)
//  Serial.println(val1);             
//  delay(10000);  
// 
  if (val0 > val1) {
    digitalWrite(ledSetup, LOW);  
    digitalWrite(ledLS, HIGH);
  // Ggf. Bildschirm Reaktivieren  
    digitalWrite(switchOn, HIGH);   
    delay(80);               
    digitalWrite(switchOn, LOW);
    delay(160);  
  // Last Call starten
    digitalWrite(switchCall, HIGH);
    delay(80);          
    digitalWrite(switchCall, LOW);    
    delay(160);
    digitalWrite(switchCall, HIGH);
    delay(80);          
    digitalWrite(switchCall, LOW);    
    delay(15000); // Wartezeit
  // Call abbrechen
    digitalWrite(switchOn, HIGH);   
    delay(80);               
    digitalWrite(switchOn, LOW);
    delay(160);
    digitalWrite(ledLS, LOW);
    digitalWrite(ledSetup, HIGH);  
  } 
}
