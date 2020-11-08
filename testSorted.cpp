#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char ** argv) {
    string inputFilePath = argv[1];

    ifstream fin;
    fin.open(inputFilePath);
    int element1, element2;
    fin >> element1;
    bool good = true;
    int cnt = 1;
    while(fin >> element2) {
        cnt++;
        // cout << element2 << " " << element1 << endl;
        if(element2 - element1 < 0) {
            good = false;
            break;
        }
        element1 = element2;
    }

    cout << "The number of elements is : " << cnt << endl;
    if(good)
        cout << inputFilePath << " is sorted" << endl;
    else
        cout << inputFilePath << " is not sorted" << endl;
}