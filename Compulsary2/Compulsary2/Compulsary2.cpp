#include <iostream>
#include <math.h>
#include <algorithm>
#include <chrono>
#include <list>

using namespace std;


void PrintList(list<int> const list) {
    cout << "printed list: " << endl;
    for (auto const& i : list) { cout << i << endl; }
    cout << endl;
}

list<int> GenerateList(list<int>& MainList, int SizeToGen) {
    for (int i = 0; i < SizeToGen; i++) {
        int RandomValue = 1 + (rand() % (SizeToGen * 5));  //needs to be changed so it can generate numbers above 2^15, so that larger lists arent full of
        MainList.push_back(RandomValue);
    }

    return(MainList);
}

void QuickSort(list<int>& MainList) {
    list<int> Equal;
    list<int> Lesser;
    list<int> Greater;

    if (MainList.size() <= 1) {
        return;
    }
    else {
        auto Current = MainList.begin();
        auto Pivot = MainList.front();

        while (Current != MainList.end()) {
            if (*Current < Pivot) {
                Lesser.push_back(*Current);
            }
            else if (*Current > Pivot) {
                Greater.push_back(*Current);
            }
            else {
                Equal.push_back(*Current);
            }
            ++Current;
        }
    }
    QuickSort(Lesser);
    QuickSort(Greater);
    MainList.clear();
    MainList.splice(MainList.end(), Lesser);
    MainList.splice(MainList.end(), Equal);
    MainList.splice(MainList.end(), Greater);
}

void merge(list<int>& lst, list<int>& left, list<int>& right) {
    auto leftIt = left.begin();
    auto rightIt = right.begin();

    while (leftIt != left.end() && rightIt != right.end()) {
        if (*leftIt <= *rightIt) {
            lst.push_back(*leftIt);
            leftIt++;
        }
        else {
            lst.push_back(*rightIt);
            rightIt++;
        }
    }
    while (leftIt != left.end()) {
        lst.push_back(*leftIt);
        leftIt++;
    }

    while (rightIt != right.end()) {
        lst.push_back(*rightIt);
        rightIt++;
    }
}

void MergeSort(list<int>& MainList) {
    if (MainList.size() <= 1) {
        return;
    }

    // Split the list into two halves
    list<int> left;
    list<int> right;
    int mid = MainList.size() / 2;

    auto it = MainList.begin();
    for (int i = 0; i < mid; i++) {
        left.push_back(*it);
        it++;
    }

    while (it != MainList.end()) {
        right.push_back(*it);
        it++;
    }

    MergeSort(left);
    MergeSort(right);

    MainList.clear();
    merge(MainList, left, right);
}

void BubbleSort(std::list<int>& MainList) {
    bool swapped;
    do {
        swapped = false;
        auto Current = MainList.begin();
        auto Next = std::next(Current);
        while (Next != MainList.end()) {
            if (*Current > *Next) {
                std::iter_swap(Current, Next);
                swapped = true;
            }
            ++Current;
            ++Next;
        }
    } while (swapped);
}

int main()
{
    cout << "Select size of list to sort" << endl;
    int SizeToGen;
    cin >> SizeToGen;

    list<int> MainList;
    GenerateList(MainList, SizeToGen);

    //PrintList(MainList);

    cout << "Select Algorithm" << endl;
    cout << "Type 1 for Quick sort" << endl;
    cout << "Type 2 for Merge sort" << endl;
    cout << "Type 3 for Bubble sort" << endl;
    int AlgSelector;
    cin >> AlgSelector;

    auto start = chrono::high_resolution_clock::now();
    switch (AlgSelector) {
    case 1:
        cout << "Quick sort selected" << endl;
        QuickSort(MainList);
        break;
    case 2:
        cout << "Merge sort selected" << endl;
        MergeSort(MainList);
        break;
    case 3:
        cout << "Bubble sort selected" << endl;
        BubbleSort(MainList);
        break;
    default:
        cout << "Invalid input" << endl;
        break;
    }
    auto end = chrono::high_resolution_clock::now();

    PrintList(MainList);

    cout << "Time: " << chrono::duration_cast<chrono::milliseconds>((end)-(start)).count() << "ms" << endl;
}