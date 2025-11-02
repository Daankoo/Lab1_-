#include <iostream> 
#include <string>
#include <list>

using namespace std;

#include "stranger.h"

int main() {

    cout << boolalpha;

    Set<int> setA;
    Set<int> setB;
    Set<int> setRes;

    Set<int>* activeSet = &setA;
    char activeSetName = 'A';

    int choice, value;

    cout << "\nSELECT AN OPERATION (Working on Set " << activeSetName << ")";
    cout << "\n---------------------------";
    cout << "\n 1 - SEARCH (in active set)";
    cout << "\n 2 - INSERT (to active set)";
    cout << "\n 3 - DELETE (from active set)";
    cout << "\n 4 - CLEAR (active set)";
    cout << "\n 5 - PRINT (active set)";
    cout << "\n\n--- Binary Operations ---";
    cout << "\n 6 - A UNION B (result in C)";
    cout << "\n 7 - A INTERSECTION B (result in C)";
    cout << "\n 8 - A SETDIFFERENCE B (result in C)";
    cout << "\n 9 - A ISSUBSET B?";
    cout << "\n 10 - A SYM_DIFFERENCE B (result in C)";
    cout << "\n\n--- Management ---";
    cout << "\n 11 - PRINT Set C (result)";
    cout << "\n 12 - SWITCH active set (A <-> B)";
    cout << "\n\n 0 - FINISH WORK";
    cout << "\n---------------------------";

    do {
        cout << "\n\nYour choice (Active Set: " << activeSetName << "): ";
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "Enter element to search: "; 
            cin >> value;
            cout << "Result: " << (*activeSet).SEARCH(value);
            break;
        }
        case 2: {
            cout << "Enter element to insert: "; 
            cin >> value;
            (*activeSet).INSERT(value);
            cout << "Done.";
            break;
        }
        case 3: {
            cout << "Enter element to delete: "; cin >> value;
            (*activeSet).DELETE(value);
            cout << "Done.";
            break;
        }
        case 4: {
            (*activeSet).CLEAR();
            cout << "Set " << activeSetName << " cleared.";
            break;
        }
        case 5: {
            cout << "Printing Set " << activeSetName << ":" << endl;
            (*activeSet).PRINT();
            break;
        }
        case 6: { 
            setRes = setA.UNION(setB);
            cout << "A UNION B saved to Set C.";
            break;
        }
        case 7: { 
            setRes = setA.INTERSECTION(setB);
            cout << "A INTERSECTION B saved to Set C.";
            break;
        }
        case 8: { 
            setRes = setA.SETDIFFERENCE(setB);
            cout << "A - B saved to Set C.";
            break;
        }
        case 9: { 
            bool isSubset = setA.ISSUBSET(setB);
            cout << "Is Set A a subset of Set B? -> " << isSubset;
            break;
        }
        case 10: { 
            setRes = setA.SYM_DIFFERENCE(setB);
            cout << "A SYM_DIFFERENCE B saved to Set C.";
            break;
        }
        case 11: {
            cout << "Printing Set C (Result):" << endl;
            setRes.PRINT();
            break;
        }
        case 12: { 
            if (activeSetName == 'A') {
                activeSet = &setB;
                activeSetName = 'B';
            }
            else {
                activeSet = &setA;
                activeSetName = 'A';
            }
            cout << "Active set switched. Now working on Set " << activeSetName;
            break;
        }

        default: {
            if (choice != 0) {
                cout << "\nTry again... ";
            }
            break;
        }
        }
    } while (choice != 0);

    cout << "\nError 404\n";
    return 0;
};
