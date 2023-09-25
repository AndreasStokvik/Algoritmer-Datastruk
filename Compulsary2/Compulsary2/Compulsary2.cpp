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

void QuickSort(list<int>& MainList)
{
    if (MainList.size() > 2) {
        list<int> Lesser, Equal, Greater;

        auto pivot = MainList.front();
        auto compare = MainList.begin();
        
        while (compare != MainList.end()) {
            if (*compare < pivot) {
                Lesser.push_back(*compare);
            }
            else if (*compare == pivot) {
                Equal.push_back(*compare);
            }
            else {
                Greater.push_back(*compare);
            }
            ++compare;
        }
        MainList.clear();
        QuickSort(Lesser);
        MainList.splice(MainList.end(), Lesser);
        MainList.splice(MainList.end(), Equal);
        QuickSort(Greater);
        MainList.splice(MainList.end(), Greater);
    }
    else return;
}

void Merge(list<int>& MainList, list<int>& left, list<int>& right)
{
    auto leftIt = left.begin();
    auto rightIt = right.begin();

    while (leftIt != left.end() && rightIt != right.end()) {
        if (*leftIt <= *rightIt) {
            MainList.push_back(*leftIt);
            leftIt++;
        }
        else {
            MainList.push_back(*rightIt);
            rightIt++;
        }
    }
    while (leftIt != left.end()) {
        MainList.push_back(*leftIt);
        leftIt++;
    }

    while (rightIt != right.end()) {
        MainList.push_back(*rightIt);
        rightIt++;
    }
}

void MergeSort(list<int>& MainList)
{
    if (MainList.size() <= 1) {
        return;
    }

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
    Merge(MainList, left, right);
}

void BubbleSort(list<int>& MainList)
{
    bool swapped;
    do {
        swapped = false;
        auto Current = MainList.begin();
        auto Next = next(Current);
        while (Next != MainList.end()) {
            if (*Current > *Next) {
                iter_swap(Current, Next);
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

    // Declare these in case user selects quicksort
    auto MainListLow = MainList.begin();
    advance(MainListLow, distance(MainList.begin(), MainList.end()) / 2); // Find the middle element as the pivot
    auto MainListHigh = prev(MainList.end());

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