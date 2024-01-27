#include <iostream>
#include <vector>
#include <math.h>
using namespace std; 

// A binary watch has 4 LEDs on the top to represent the hours (0-11), and 6 LEDs on the bottom to represent the minutes (0-59)
// Each LED represents a zero or one, with the least significant bit on the right.

// Given an integer turnedOn which represents the number of LEDs that are currently on (ignoring the PM), 
// return all possible times the watch could represent. You may return the answer in any order.

// Example 1:

// Input: turnedOn = 1
// Output: ["0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00"]

// Example 2:

// Input: turnedOn = 9
// Output: []

// 8  4  2  1
// 32 16 8  4  2  1

// NON FUNZIONA NEL SECONDO CASO


int turnedOn = 9;
int hour[4] = {0,0,0,0};
int minute[6] = {0,0,0,0,0,0};

void backtrack(vector<string>& t, int index){

    if(index == turnedOn){

        int minutes = 0; 
        int hours = 0; 

        for(int i=0; i<6; i++){
            if(minute[i] == 1){
                minutes += pow(2.0, i/1.0); 
            }
        }

        

        for(int i=0; i<4; i++){
            if(hour[i] == 1){
                hours += pow(2.0, i/1.0);
            }
        }

        if(minutes > 59){
            hours++; 
            minutes -= (60 - minutes); 
        }

        if(hours > 12){
            return; 
        }

        string s; 
        if(minutes < 10){
            s = to_string(hours) + ":0" +  to_string(minutes); 
        }else if(minutes == 0){
            s = to_string(hours) + ":00"; 
        }
        else{
            s = to_string(hours) + ":" +  to_string(minutes); 
        }

        t.push_back(s); 
        return; 
    }

   

    for(int i=0; i<6; i++){
        if(minute[i] != 1){
            minute[i] = 1;
            backtrack(t, index + 1); 
            minute[i] = 0; 
        }
    }

    for(int i=0; i<4; i++){
        if(hour[i] != 1){
            hour[i] = 1;
            backtrack(t, index + 1); 
            hour[i] = 0; 
        }
    }
}



int main(){

    vector<string> result; 
    backtrack(result, 0); 
    
    for(auto elem: result){
        cout << elem << endl; 
    }

    return 1; 
}