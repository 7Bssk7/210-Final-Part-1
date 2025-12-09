// COMSC-210 | Final 1 | Arkhip Finski
// IDE used: Visual Studio
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <random>
using namespace std;

// Constants for possible traffic values
const int MIN_TRF = 1, MAX_TRF = 35;
// Constants fpr the number of random simulations
const int SIM_MIN = 0, SIM_MAX = 3;

// Function prototypes
void outputAll(const map<string,int>& );
void findMax(const map<string, int>& );
int randomValue(int, int);
void findRange(const map<string, int>&, int, int);

int main(){
    srand(time(0));
    ifstream inputFile("210-final-1-FA25.txt");
    string src, dest;
    map<string, int> traffic;

    // Read file line by line,  reading first aitport code into src and second airport code into dest
    while(inputFile >> src >> dest){
        // If airport in src not yet in map, initialize with 0(count)
        if(traffic.find(src) == traffic.end()){
            traffic[src] = 0;
        }
        // If airport in dest not yet in map, initialize with 0(count)
        if(traffic.find(dest) == traffic.end()){
            traffic[dest] = 0;
        }
        // Increment traffic counts for both airports that we read from the file
        traffic[src] += 1;
        traffic[dest] += 1;

    }
    // Milestone 1: Read all airport from the file and outputs all airport traffic counts
    outputAll(traffic);

    // Milestone 2: Find and output busiest airport(s)
    findMax(traffic);

    // Milestone 3: Outputs all airports in the ranges
    int sim = randomValue(SIM_MIN, SIM_MAX);
    // TEST 
    // findRange(traffic, 5, 8);

    // Ensures function is called with at least two different ranges
    findRange(traffic, 3, 10);
    findRange(traffic, 8, 15);
    // Runs a simulation with a random ranges
    for(int i = 0; i < sim; ++i){
        int trf_min = randomValue(MIN_TRF, MAX_TRF);
        int trf_max = randomValue(trf_min, MAX_TRF);
        findRange(traffic, trf_min, trf_max);
    }

    return 0;
}

//This function outputs all airports and their traffic counts stored in the map
//arguments: constant reference to a map, (const map<string,int>& t)
//returns: nothing. It's a void function, outputs all of the airports and their traffic counts
void outputAll(const map<string, int>& t){
    cout << "All airport traffic counts:" << endl;
    for(auto it = t.begin(); it != t.end(); ++it){
        cout << it->first << " " << it->second << endl;
    }
}

//This function finds and outputs the busiest airport(s) with the maximum traffic count
//arguments: constant reference to a map, (const map<string,int>& t)
//returns: nothing. It's a void function, outputs the busiest airport(s) with the maximum traffic count
void findMax(const map<string, int>& t){
    int maxTrf = 0;
    for(auto it = t.begin(); it != t.end(); ++it){
        if(it->second > maxTrf){
            maxTrf = it->second;
        }
    }

    cout << "\nBusiest airport(s) with count "<< maxTrf << " :" << endl;
    for(auto it = t.begin(); it != t.end(); ++it){
        if(it->second == maxTrf){
            cout << it->first << " " << it->second << endl;
        }
    }
}

int randomValue(int s_min, int s_max){
    return s_min + rand()% (s_max - s_min + 1);  
}

void findRange(const map<string, int>& t, int r_min, int r_max){
    int count = 0;
    cout << "\nAirports with traffic in range [" << r_min << ", " << r_max << "]:" << endl;
    for(auto it = t.begin(); it != t.end(); ++it){
        if((it->second >= r_min) && (it->second <= r_max)){
            cout << it->first << " " << it->second << endl;
            count += 1;
        }
    }
    if(count == 0){
        cout << "Not a single airport falls in this traffic range" << endl;
    }
}