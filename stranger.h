#pragma once
#include <iostream> 
#include <string>
#include <list>

using namespace std;

template <typename T>
class Set {
private:
    list<T> elements;

public:
    bool SEARCH(const T& element) const {
        for (const T& item : elements) {
            if (item == element) {
                return true;
            }
        }
        return false;
    }

    void INSERT(const T& element) {
        if (SEARCH(element) == false) {
            elements.push_back(element);
            cout << "Result: Done!";
        }
        else
            cout << "The element already exists";
    }

    void DELETE(const T& element) {
        if (SEARCH(element) == false) {
            cout << "No element";
        }
        else {
            elements.remove(element);
            cout << "Element remove";
        }
    }

    void CLEAR() {
        elements.clear();
        cout << "Result:" << "Fucking Set";
    }

    void PRINT() const {
        if (elements.empty()) {
            cout << "Set is empty" << endl;
            return;
        }
        cout << "Elements in set: ";
        for (const T& item : elements) {
            cout << item << " ";
        }
    }
};