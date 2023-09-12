void setup(){
  
 Serial.begin(9600);
}
void loop() {
  int mark=95;
  
    if(mark>90){
    Serial.print("choclate kitiya ");
  }
   else if (mark>60){
    Serial.print("chirik patti");
   }
   else
       Serial.print("eragiy podaiy");}
       
  
