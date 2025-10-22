// роздільна компіляція
// з кейсів операції перекинути у функції і закинути їх в окремий файл
// у інсерті лишня перевірка, вона повторюється у кейсі
// як ідея до вайл замінити на іф елс

#include <iostream> 
#include <string>
#include <list>

using namespace std;

template <typename T>
class Set {
private:
    list<T> elements; 

public:
    bool SEARCH(const T & element) const {
        for (const T& item : elements) {
            if (item == element) {
                return true;
            }
        }

        return false;
    }

    void INSERT(const T& element) {
        if (SEARCH(element) == true) {
            elements.push_back(element);
        }
    }

    void DELETE(const T& element) {
        elements.remove(element); 
    }

    void CLEAR() {
        elements.clear(); 
    }
};

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
    cout << "\n\n0 - FINISH WORK";
    cout << "\n\n---------------------------";

    do {
        cout << "\n\nYour choice: ";
        cin >> choice;

        if (choice == 1 || choice == 2 || choice == 3 || choice == 4) {
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
                if (intSet.SEARCH(b) == true) {
                    cout << "b prisutniu";
                }
                else {
                    intSet.INSERT(b);
                    cout << "Result: Done!";
                }
                break;
            }
            case 3: {
                cout << "Enter: element for delete: ";
                cin >> c;
                if (intSet.SEARCH(c) == true) {
                    intSet.DELETE(c);
                    cout << "delete done";
                }
                else {
                    cout << "Elemenya net";
                }
                
                break;
            }
            case 4: {
                intSet.CLEAR();
                cout << "Result:" << "Fucking Set";
                break;
            }
            }
        }
        else
            cout << "\n\nTry again... ";
    }
    while (choice != 0);
    cout << "\nError 404\n";

    return 0;
};
double time_not_found_avg = std::chrono::duration_cast<std::chrono::nanoseconds>(end_not_found - start_not_found).count() / 1000.0;
