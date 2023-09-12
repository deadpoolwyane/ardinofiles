#define motorpin1 5
#define motorpin2 6
#define enablepin 9
int i;
void setup() {
  // put your setup code here, to run once:
Serial.begin (9600);
pinMode (motorpin1,OUTPUT);
pinMode (motorpin2,OUTPUT);
pinMode (enablepin,OUTPUT);

}

void loop() {
  
  // put your main code here, to run repeatedly:
//for (i=0;i<255;i++)
//{
 analogWrite (enablepin,255);
 digitalWrite (5,HIGH);
  digitalWrite (6,LOW);
  delay (3000); 
 //Serial.print ("maximam");
//}
//for (i=255;i>0;i--)
//{
  analogWrite (enablepin,100);
  digitalWrite (5,LOW);
  digitalWrite (6,HIGH);
  delay (3000);
  //Serial.print ("minimum");
//}
}
