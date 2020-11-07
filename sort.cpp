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

typedef long long ll;

#define vi vector<ll>
#define findDuration(dur) std::chrono::duration_cast<std::chrono::milliseconds>(dur).count()
#define snapTime() std::chrono::high_resolution_clock::now()
#define For(i, init, n) for(int i = init; i < n; i++)

void selectionSort(vi &elements);
void insertionSort(vi &elements);
vi mergeArrays(vi &left, vi &right);
vi mergeSort(int l, int r, vi &elements);
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
            elements = mergeSort(0, elements.size() - 1, elements);
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
        if(minimumElementIndex != i) {
            ll temp = elements[minimumElementIndex];
            elements[minimumElementIndex] = elements[i];
            elements[i] = temp;
        }
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
vi mergeArrays(vi &left, vi &right) {
    int leftSize = left.size();
    int rightSize = right.size();

    vi res(leftSize + rightSize);

    left.push_back(INT64_MAX);
    right.push_back(INT64_MAX);

    int leftindex = 0, rightindex = 0;

    For(i, 0, res.size()) {
        if(left[leftindex] < right[rightindex]) {
            res[i] = left[leftindex];
            leftindex++;
        }
        else {
            res[i] = right[rightindex];
            rightindex++;
        }
    }

    return res;
}

vi mergeSort(int l, int r, vi &elements) {
    if(l >= r) {
        vi element(1);
        element[0] = elements[l];
        return element;
    }

    int m = l + (r - l) / 2;
    vi left = mergeSort(l, m, elements);
    vi right = mergeSort(m+1, r, elements);
    vi res = mergeArrays(left, right);
    return res;
}

// --------------------------------------- Quick Sort ------------------------------------------
void quickSort(vi &elements) {
    cout << "This is quick sort" << std::endl;
}

// ---------------------------------------- Hybrid Sort ----------------------------------------
void hybridSort(vi &elements) {
    cout << "This is hybrid sort" << std::endl;
}