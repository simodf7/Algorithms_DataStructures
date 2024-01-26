#include <iostream>
#include <vector>


// non va
using namespace std;


float dist = 475.6;
float capacity = 11.9;
float num_miles_per_gallon = 27.4;
float cost_origin = 14.98;
int n_stations = 6;

vector<pair<float, float>> stations = {
    {102.0, 99.9},
    {220.0, 132.9},
    {256.3, 147.9},
    {275.0, 102.9},
    {277.6, 112.9},
    {381.8, 100.9}
};

float backtrack(int index, float c, float d)
{
    if (index == n_stations){
        return 0;
    }


    float gas_used = (1/num_miles_per_gallon) * (stations[index].first - d); 
    
    float cost_if_fuel = 10000; 

    if(c - gas_used <= capacity/2){
        cost_if_fuel = stations[index].second *(c-gas_used) + backtrack(index+1, capacity, stations[index].first); 
    }


    float cost_ifnot_fuel = backtrack(index+1, c-gas_used, stations[index].first);

    return min(cost_if_fuel, cost_ifnot_fuel);
   
}

int main(){
    cout << "Minimum cost: $" << cost_origin + backtrack(0, capacity, 0) << endl;

    return 0;
}
