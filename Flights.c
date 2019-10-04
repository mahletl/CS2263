/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main() {
 int hours;
 int minutes;
 int desiredTime;
 int dTime=-1;
 int aTime=-1;
 int * departureTime;
 int * arrivalTime;
 

departureTime = &dTime;
arrivalTime = &aTime;

 printf("Enter a 24 hour time:");   
 int a = scanf("%d:%d", &hours, &minutes);
        if ( (a!=2)) {
             printf("Invalid input");
        return -1;
        }
        desiredTime = hours * 60 + minutes;
        if(desiredTime > 1400 || desiredTime < 0) {
            printf("Invalid input");
            return -1;   
        }
        
findClosetFlight(desiredTime,departureTime, arrivalTime );

printf("The closest departureTime is: %d, arriving at: %d", *departureTime, *arrivalTime); 

}


 void findClosetFlight(int desiredTime, int * departureTime, int * arrivalTime){
    
     
FILE *f = fopen("flights.dat", r);
if (f==NULL) {
    printf("Empty file!");
    return -1;
}

int hour;
int min;
int flightArray[999];
int count = 0;
int flightArrayClockFormat[999];

    while(!feof(f)) {
       int b = fscanf(f, "%d:%d",&hour, &min);
            if ( b < 2) {
             printf("Invalid input");
            return -1;
            }
            
            if (hour <= 9) {
                flightArray[count] = hour*60+min;//converts time to minutes for calcuations below
                flightArrayClockFormat[count] = hour *100 + min; // maintains the formatting
            }
            else if (hour>=10) {
                flightArray[count] = hour*60+min;
                flightArrayClockFormat[count] = hour * 1000 + min; //maintaisn the formatting
            } 
                        count++;
    
    } //end of while  
    
    int closestTime=flightArray[0];
    int closestTimeCompare=flightArray[0];
    int indexTracker;
    for (int i=0; i < count; i=i+2) { // in this case, departure times are every even number and arrival times are every odd number of the index
        if (desiredTime <= flightArray[i]) { //if the flight hasn't left yet, check if it's the closest flight 
            closestTimeCompare = flightArray[i]-desiredTime;
                if (closestTimeCompare < closestTime) {
                    closestTime = closestTimeCompare;
                    indexTracker = i; //track where in the array the closet time is
                }
        }
    }

    * departureTime = flightArrayClockFormat[indexTracker]; // departure time 
    * arrivalTime = flightArrayClockFormat[indexTracker+1]; //arival time
    
}// end of method
 
 
 
 



