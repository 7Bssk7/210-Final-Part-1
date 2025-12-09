// COMSC-210 | Final 1 | Arkhip Finski
// IDE used: Visual Studio
#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

// Constants for possible traffic values 
const int MIN_TRF = 1, MAX_TRF = 35; 
// Constants fpr the number of random simulations const 
int SIM_MIN = 0, SIM_MAX = 3; 
// Function prototypes 
int randomValue(int, int); 
void findRange(const map<string, int>&, int, int);

int main(){
    srand(time(0));
    ifstream inputFile("210-final-1-FA25.txt");
    string src, dest;
    map<string, int> traffic;

    if(!inputFile){
        cout << "Failed to open the file!" << endl;
        return 1;
    }


    while(inputFile >> src >> dest){

        if(traffic.find(src) == traffic.end()){
            traffic[src] = 0;
        }

        if(traffic.find(dest) == traffic.end()){
            traffic[dest] = 0;
        }

        traffic[src] += 1;
        traffic[dest] += 1;

    }

    // Milestone 1
    cout << "All airport traffic counts:" << endl;
    for(auto it = traffic.begin(); it != traffic.end(); ++it){
        cout << it->first << " " << it->second << endl;
    }


    // Milestone 2
    int maxTrf = 0;
    for(auto it = traffic.begin(); it != traffic.end(); ++it){
        if(it->second > maxTrf){
            maxTrf = it->second;
        }
    }

    cout << "\nBusiest airport(s) with count "<< maxTrf << " :" << endl;
    for(auto it = traffic.begin(); it != traffic.end(); ++it){
        if(it->second == maxTrf){
            cout << it->first << " " << it->second << endl;
        }
    }

    // Milestone 3
    int count = 0;
    cout << "\nAirports with traffic in range [" << 3 << ", " << 10 << "]:" << endl;
    for(auto it = traffic.begin(); it != traffic.end(); ++it){
        if((it->second >= 3) && (it->second <= 10)){
            cout << it->first << " " << it->second << endl;
            count += 1;
        }
    }
    if(count == 0){
        cout << "Not a single airport falls in this traffic range" << endl;
    }
    count = 0;

    cout << "\nAirports with traffic in range [" << 8 << ", " << 15 << "]:" << endl;
    for(auto it = traffic.begin(); it != traffic.end(); ++it){
        if((it->second >= 8) && (it->second <= 15)){
            cout << it->first << " " << it->second << endl;
            count += 1;
        }
    }
    if(count == 0){
        cout << "Not a single airport falls in this traffic range" << endl;
    }

    
    int sim = randomValue(SIM_MIN, SIM_MAX);  
    for(int i = 0; i < sim; ++i){ 
        int trf_min = randomValue(MIN_TRF, MAX_TRF); 
        int trf_max = randomValue(trf_min, MAX_TRF); 
        findRange(traffic, trf_min, trf_max); 
    }

    // Milestone 4
    return 0;
}


int randomValue(int s_min, int s_max){ 
    return s_min + rand()% (s_max - s_min + 1); 
} 

void findRange(const map<string, int>& t, int r_min, int r_max){
    int count = 0; 
    cout << "\nAirports with traffic in range [" << r_min << ", " << r_max << "]:" << endl; 
    for(auto it = t.begin(); it != t.end(); ++it){ 
        if((it->second >= r_min) && (it->second <= r_max)){
             cout << it->first << " " << it->second << endl; count += 1; }
        } 
        if(count == 0){ cout << "Not a single airport falls in this traffic range" << endl; } 
}
