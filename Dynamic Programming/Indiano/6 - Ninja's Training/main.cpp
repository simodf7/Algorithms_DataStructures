#include <iostream>
using namespace std;

int d[2][3] = {10, 50, 1,
5, 100, 11}; 

int used; 

int maximumPoints(int day,int used){

    if(day == 2){
        return 0; 
    }

    int points = -1; 
    for(int j=0; j<3; j++){
        if(used != j) points = max(points, d[day][j] + maximumPoints(day+1, j)); 
    }

    return points; 

}; 

int main(){

    cout << maximumPoints(0, -1); 

    return 1;
}