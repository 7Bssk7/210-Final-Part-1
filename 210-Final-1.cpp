// COMSC-210 | Final 1 | Arkhip Finski
// IDE used: Visual Studio
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main(){
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

    }



    return 0;
}