// C++ code
//Shortest Job Scheduling associates with each process the length of the process next CPU burst.

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
  shortest_job(); //calling the function.
}

void shortest_job(){
  int pin[6] = {13, 12, 11, 10, 9, 8};
  int time[6] = {5000, 2000, 4000, 1000, 7000, 3000};
  //an array of time in milliseconds to be used in delay function.
  //index 0 or the P1 has a time of 5 seconds.
  //index 1 or the P2 has a time of 2 seconds.
  //index 2 or the P3 has a time of 4 seconds.
  //index 3 or the P4 has a time of 1 second.
  //index 4 or the P5 has a time of 7 seconds.
  //index 5 or the P6 has a time of 3 seconds.
  
  //with the given burst time, the first to be executed is the P4 followed by P2, P6, P3, P1 and lastly P5.
  
  int temp; //temporary value used in swapping.
  
  for (int i=0; i<6; i++){
    for (int j=0; j<6; j++){
      if (time[i] < time[j]){
      	temp = time[i];
        time[i] = time[j];
        time[j] = temp;
        
        temp = pin[i];
        pin[i] = pin[j];
        pin[j] = temp;
      }
    }
  } //after executing this loop, the time array as well as pin array will be sorted in ascending.
  
  int count = 0; //used to identifies the element of time array.
  while (count != 6){
  	digitalWrite(pin[count], HIGH);
    delay(time[count]);
    digitalWrite(pin[count], LOW);
    count++;
  } //executes shortest job scheduling.
}