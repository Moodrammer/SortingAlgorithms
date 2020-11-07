#include <fstream>
using namespace std;

int main() {
    ofstream fout("descending_arr.txt");
    int i = 500000;
    while(--i) {
        fout << i << endl;
    }
}