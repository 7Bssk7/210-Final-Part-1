// COMSC-210 | Final 1 | Arkhip Finski
// IDE used: Visual Studio
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <random>
using namespace std;

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

    return 0;
}

