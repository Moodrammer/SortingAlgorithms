#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main(int argc, char ** argv) {
    string operation = argv[1];
    string size = argv[2];
    int numSwaps;
    cout << "Enter the number of Swaps " << endl;
    cin >> numSwaps;
    string filepath = "SortedFiles/sorted_data_";
    filepath += operation;
    filepath += "_";
    filepath += size;
    filepath += ".txt";
    ifstream fin(filepath);
    vector<long long> elmnts;
    long long el;
    while(fin >> el) {
        elmnts.push_back(el);
    }
    fin.close();
    int randomNum1, randomNum2;
    srand(time(NULL));
    int j;
    while(numSwaps--) {
        randomNum1 = rand() % elmnts.size();
        if(randomNum1 - 1 >= 0) j = randomNum1 - 1;
        else j = randomNum1 + 1;
        swap(elmnts[randomNum1], elmnts[j]);
    }
    filepath = "SortedFiles/nsorted_data_" + operation + "_" + size + ".txt";
    ofstream fout(filepath);
    
    for(int i = 0; i < elmnts.size(); i++) {
        fout << elmnts[i] << endl;
    }

    fout.close();



}