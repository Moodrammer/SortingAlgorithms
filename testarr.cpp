#include <fstream>
using namespace std;

int main() {
    ofstream fout("descending_arr.txt");
    int i = 500000;
    while(i > 0) {
        fout << i << endl;
        i--;
    }
}