#include <iostream> 
#include <string>
#include <list>

using namespace std;

#include "stranger.h"

int main() {

    cout << boolalpha;

    Set<int> intSet;

    int choice, a, b, c;

    cout << "\nSELECT AN OPERATION...";
    cout << "\n---------------------------";
    cout << "\n\n1 - SEARCH";
    cout << "\n2 - INSERT";
    cout << "\n3 - DELETE";
    cout << "\n4 - CLEAR";
    cout << "\n5 - PRINT SET";
    cout << "\n\n0 - FINISH WORK";
    cout << "\n\n---------------------------";

    do {
        cout << "\n\nYour choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "Enter: element for search: ";
            cin >> a;
            cout << "Result:" << intSet.SEARCH(a);
            break;
        }
        case 2: {
            cout << "Enter: element for insert: ";
            cin >> b;
            intSet.INSERT(b);
            break;
        }
        case 3: {
            cout << "Enter: element for delete: ";
            cin >> c;
            intSet.DELETE(c);
            break;
        }
        case 4: {
            intSet.CLEAR();
            break;
        }
        case 5: {
            intSet.PRINT();
            break;
        }
        default: {
            if (choice != 0) {
                cout << "\n\nTry again... ";
            }
            break;
        }
        }
    }
    while (choice != 0);
    cout << "\nError 404\n";

    return 0;
};