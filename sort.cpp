#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <iostream>

using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::cout;

#define vi vector<int>
#define findDuration(dur) std::chrono::duration_cast<std::chrono::milliseconds>(dur).count()
#define snapTime() std::chrono::high_resolution_clock::now()
#define For(i, init, n) for(int i = init; i < n; i++)

typedef long long ll;

void selectionSort(vi &elements);
void insertionSort(vi &elements);
void mergeSort(vi &elements);
void quickSort(vi &elements);
void hybridSort(vi &elements);


int main(int argc, char ** argv) {
    char sortingOperation = *argv[1];
    string inputFilePath = argv[2];
    string outputFilePath = argv[3];
    string runningTimeFilePath = argv[4];

    ifstream fin;
    ofstream fout;
    fin.open(inputFilePath);
    vector<int> elements; int e;
    while(fin >> e) {
        elements.push_back(e);
    }

    auto startTime = snapTime();
    switch(sortingOperation) {
        case '0':
            selectionSort(elements);
            break;
        case '1':
            insertionSort(elements);
            break;
        case '2':
            mergeSort(elements);
            break;
        case '3':
            quickSort(elements);
            break;
        case '4':
            hybridSort(elements);
    }
    auto endTime = snapTime();
    auto running_time = findDuration(endTime - startTime);

    fout.open(outputFilePath);
    for(int i = 0; i < elements.size(); i++) {
        fout << elements[i] << std::endl;
    }
    fout.close();

    fout.open(runningTimeFilePath);
    fout << running_time << std::endl;
    fout.close();
    fin.close();
}

void selectionSort(vi &elements) {
    int minimumElementIndex;
    For(i, 0, elements.size() - 1) {
        minimumElementIndex = i;
        For(j, i+1, elements.size()) {
            if(elements[j] < elements[minimumElementIndex]) {
                minimumElementIndex = j;
            }
        }
        if(minimumElementIndex != i) {
            int temp = elements[minimumElementIndex];
            elements[minimumElementIndex] = elements[i];
            elements[i] = temp;
        }
    }
}

void insertionSort(vi &elements) {
    cout << "This is insertion sort " << std::endl;
}

void mergeSort(vi &elements) {
    cout << "This is merge sort " << std::endl;
}

void quickSort(vi &elements) {
    cout << "This is quick sort" << std::endl;
}

void hybridSort(vi &elements) {
    cout << "This is hybrid sort" << std::endl;
}