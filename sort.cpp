#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::cout;
using std::swap;

typedef long long ll;

#define vi vector<ll>
#define findDuration(dur) std::chrono::duration_cast<std::chrono::milliseconds>(dur).count()
#define snapTime() std::chrono::high_resolution_clock::now()
#define For(i, init, n) for(int i = init; i < n; i++)


// algorithms
void selectionSort(vi &elements);
void insertionSort(vi &elements);
void mergeArrays(int l, int r, int m, vi &elements);
void mergeSort(int l, int r, vi &elements);
int quickPartition(int l, int r, vi &elements);
void quickSort(int l, int r, vi &elements);
void hybridSort(vi &elements);



int main(int argc, char ** argv) {
    char sortingOperation = *argv[1];
    string inputFilePath = argv[2];
    string outputFilePath = argv[3];
    string runningTimeFilePath = argv[4];

    ifstream fin;
    ofstream fout;
    fin.open(inputFilePath);
    vi elements; ll e;
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
            mergeSort(0, elements.size() - 1, elements);
            break;
        case '3':
            quickSort(0, elements.size() - 1, elements);
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


// --------------------------------------- Selection Sort --------------------------------------
void selectionSort(vi &elements) {
    int minimumElementIndex;
    For(i, 0, elements.size() - 1) {
        minimumElementIndex = i;
        For(j, i+1, elements.size()) {
            if(elements[j] < elements[minimumElementIndex]) {
                minimumElementIndex = j;
            }
        }

        swap(elements[minimumElementIndex], elements[i]);
    }
}

// --------------------------------------- Insertion Sort --------------------------------------
//stable
void insertionSort(vi &elements) {
    For(i, 1, elements.size()) {
        ll curr = elements[i];
        int j = i-1;
        while(j >= 0 && curr < elements[j]) {
            elements[j+1] = elements[j];
            j--;
        }
        elements[j+1] = curr;
    }
}


// ------------------------------------------ Merge Sort ----------------------------------------
void mergeArrays(int l, int r, int m, vi &elements) {
    int leftSize = m - l + 1;
    int rightSize = r - m;

    vi left(leftSize);
    vi right(rightSize);

    For(i, 0, leftSize) left[i] = elements[l + i];
    For(i, 0, rightSize) right[i] = elements[m + i + 1];

    left.push_back(INT64_MAX);
    right.push_back(INT64_MAX);

    int leftindex = 0, rightindex = 0;

    For(i, l, r+1) {
        if(left[leftindex] <= right[rightindex]) {
            elements[i] = left[leftindex];
            leftindex++;
        }
        else {
            elements[i] = right[rightindex];
            rightindex++;
        }
    }
}

void mergeSort(int l, int r, vi &elements) {
    if(l >= r) {
        return;
    }

    int m = l + (r - l) / 2;
    mergeSort(l, m, elements);
    mergeSort(m+1, r, elements);
    mergeArrays(l, r, m, elements);
}

// --------------------------------------- Quick Sort ------------------------------------------
int quickPartition(int l, int r, vi &elements) {
    int randIndex = l + (std::rand() % (r - l + 1));
    swap(elements[r], elements[randIndex]);
    ll pivot = elements[r];

    int lastSmallestOrEqualIndex = l-1;
    For(i, l, r) {
        if(elements[i] <= pivot) {
            lastSmallestOrEqualIndex++;
            swap(elements[lastSmallestOrEqualIndex], elements[i]);
        }
    }

    swap(elements[lastSmallestOrEqualIndex + 1], elements[r]);
    return lastSmallestOrEqualIndex+1;
}

void quickSort(int l, int r, vi &elements) {
    if(l >= r) 
        return;

    int pivotLocation = quickPartition(l, r, elements);
    quickSort(l, pivotLocation-1, elements);
    quickSort(pivotLocation+1, r, elements);
}

// ---------------------------------------- Hybrid Sort ----------------------------------------
void hybridSort(vi &elements) {
    int cntSwaps = 0;
    For(i, 1, elements.size()) {
        ll curr = elements[i];
        int j = i-1;
        while(j >= 0 && curr < elements[j]) {
            elements[j+1] = elements[j];
            j--;
            cntSwaps ++;
        }
        elements[j+1] = curr;
        if(cntSwaps >= elements.size() / 10) {
            quickSort(0, elements.size() - 1, elements);
            return;
        }
    }
}