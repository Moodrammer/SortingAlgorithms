#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char ** argv) {
    string size = argv[1];
    ofstream fout("data/descending_arr_" + size + ".txt");
    int i; 
    cout << "Enter the size as an ingter " << endl;
    cin >> i; 
    while(i > 0) {
        fout << i << endl;
        i--;
    }
}