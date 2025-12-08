// COMSC-210 | Final 1 | Arkhip Finski
// IDE used: Visual Studio
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <random>
#include <chrono>
using namespace std;

const int MIN_TRF = 1, MAX_TRF = 35;
const int SIM_MIN = 2, SIM_MAX = 5;

void outputAll(const map<string,int>& );
void findMax(const map<string, int>& );
int randomValue(int, int);
void findRange();

int main(){
    srand(time(0));
    ifstream inputFile("210-final-1-FA25.txt");
    string src, dest;
    map<string, int> traffic;

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
    outputAll(traffic);

    findMax(traffic);

    int sim = randomValue(SIM_MIN, SIM_MAX);

    cout << "Test" << endl;
    for(int i = 0; i < 10; i++){
        cout << sim << endl;
    }
    

    return 0;
}

void outputAll(const map<string, int>& t){
    cout << "All airport traffic counts:" << endl;
    for(auto it = t.begin(); it != t.end(); ++it){
        cout << it->first << " " << it->second << endl;
    }
}

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
    return rand()%s_max + s_min;  

}