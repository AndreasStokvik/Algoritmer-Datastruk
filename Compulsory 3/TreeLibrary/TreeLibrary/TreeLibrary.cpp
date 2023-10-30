#include <iostream>

#include "Tree.h"

using namespace std;

int main()
{
    Tree a;
    for (int i = 1; i <= 10; ++i) {
        int r = rand() % 100;
        a.Insert(r);
        cout << r << " ";
    }
    cout << endl;
    cout << a << endl;
    cout << endl;

    // CLEARING THE TREE
    /*a.Clear();cout << a << endl;*/

    int SpecifiedNumber = 78; // Number to erase/find
    
    // ERASING SPECIFIED NUMBER 
    /*try {
        a.Erase(SpecifiedNumber);
        cout << "Erased 78" << endl;}
    catch (exception e)
    {
        cout << "Failed to erase " << SpecifiedNumber << endl;
        // Fails to erase without complaining
    } 
    cout << a << endl;
    */

    // FINDING SPECIFIED NUMBER
    /*bool b = a.Find(SpecifiedNumber);
    if (b == true) {
        cout << "Found " << SpecifiedNumber << endl;
    }
    else {
        cout << "Didn't Find " << SpecifiedNumber << endl;
    }
    cout << a << endl;
    */
}