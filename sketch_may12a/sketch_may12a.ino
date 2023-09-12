#define s_pin A0
#define led_pin1 7
#define led_pin2 8
void setup() {
 Serial.begin(9600);
 pinMode(A0,INPUT);
 pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
}

void loop(){
  int i=analogRead(A0);
  if(i<=50)
  {
    analogWrite(7,HIGH);
    delay(1000);
   }
  else
  (i>=100);
  {
    
    analogWrite(8,HIGH);
    delay(1000);
  }
  }
  
