// C++ code
//
void setup()
{
  pinMode(13, OUTPUT); //set port 13 to output
  pinMode(12, OUTPUT); //set port 12 to output
  pinMode(11, OUTPUT); //set port 11 to output
  pinMode(10, OUTPUT); //set port 10 to output
  pinMode(9, OUTPUT); //set port 9 to output
  pinMode(8, OUTPUT); //set port 8 to output
}

void loop()
{
  first_in_first_out(); //calling the function.
}

void first_in_first_out(){
  int time[6] = {5000, 3000, 4000, 1000, 5000, 3000};
  //an array of time in milliseconds to be used in delay function.
  int count = 0; //used to identifies the element of time array.
  for (int i=13; i>=8; i--){
  	digitalWrite(i, HIGH); //Turn the LED On
    delay(time[count]); //Delay.
    digitalWrite(i, LOW); //Turn the LED Off
    count++; //Increment count.
  }
}