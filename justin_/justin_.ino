#define s_pin A0//defining the A0 pin s_pin
#define Green_led D0
#define Red_led D2

int water_value;

void setup(){
  Serial.begin(115200);
  pinMode(s_pin,INPUT);
  pinMode(D0,OUTPUT);
  pinMode(Red_led,OUTPUT);
}
void loop(){
  water_value=analogRead(s_pin);
  Serial.print("Water Value = ");
  Serial.println(water_value);
  delay(1000);
  if(water_value<50){
    digitalWrite(Green_led,HIGH);
    digitalWrite(Red_led,LOW);
    
   
  }
   
  else{
    digitalWrite(Green_led,LOW);
    digitalWrite(Red_led,HIGH);
    
  }
  }
  
    
    
  
  
