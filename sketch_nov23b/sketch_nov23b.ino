char input[12];
int count = 0;

// SETUP FUNCTION

void setup()

{

Serial.begin(9600); // START SERIAL AT BAUD RATE OF 9600 BITS/SEC

}

Now in Loop function, Read these 12 bytes if the Serial data is available.

I have used Serial.available() function to check whether Serial Data is available at the port or not. Now Print this Key on Serial Monitor. [ Do not print any text or extra data on Serial Monitor except RFID Key because I will tell you how to make a Windows Based Application for same.]

void loop()
{

if(Serial.available()) // CHECK FOR AVAILABILITY OF SERIAL DATA

{ count = 0; // Reset the counter to zero

while(Serial.available() && count < 12) {

input[count] = Serial.read(); // Read 1 Byte of data and store it in the input[] variable

count++; // increment counter delay(5); }

// PRINTING RFID TAG

for(int i=0;i<12;i++)

Serial.print(input[i]);

Serial.println();

}

}
