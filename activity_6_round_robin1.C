// C++ code
//Round Robin

/*
Process Id	Arrival Time	Burst Time
P1			0000mm			5000mm
P2			1000mm			3000mm
P3			2000mm			1000mm
P4			3000mm			2000mm
P5			4000mm			3000mm
P6			5000mm			4000mm
Time Quantum = 2000 milliseconds 
*/


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
  round_robin(); //calling the function.
}

void round_robin(){
  int time_quantum = 2000;
  int burst_time[6] = {5000, 3000, 1000, 2000, 3000, 4000};
  int pin[6] = {13, 12, 11, 10, 9, 8};
  int ready_queue[6];
  int arrival_time[6] = {0, 5000, 2000, 3000, 6000, 5000};
  int time = 0;
  
  int temp;
  for (int i=0; i<6; i++){
    for (int j=0; j<6; j++){
      if (arrival_time[i] < arrival_time[j]){
      	temp = arrival_time[i];
        arrival_time[i] = arrival_time[j];
        arrival_time[j] = temp;
        
        temp = burst_time[i];
        burst_time[i] = burst_time[j];
        burst_time[j] = temp;
        
        temp = pin[i];
        pin[i] = pin[j];
        pin[j] = temp;
      }
    }
  }
  
  for (int i=0; i<6; i++){
  	digitalWrite(pin[i], HIGH);
    delay(time_quantum);
    digitalWrite(pin[i], LOW);
    burst_time[i] = burst_time[i] - time_quantum;
  
  }
  
}