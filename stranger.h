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
        }
    }

    void DELETE(const T& element) {
        if (SEARCH(element) == true) 
            elements.remove(element);
    }

    void CLEAR() {
        elements.clear();
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

    Set<T> UNION(const Set<T>& other) const {
        Set<T> result; 

        for (const T& item : this->elements) {
            result.INSERT(item);
        }
        for (const T& item : other.elements) {
            result.INSERT(item);
        }
        return result; 
    }

    Set<T> INTERSECTION(const Set<T>& other) const {
        Set<T> result;

        for (const T& item : elements) {
            if (other.SEARCH(item)) {
                result.INSERT(item);
            }
        }
        return result;
    }

    Set<T> SETDIFFERENCE(const Set<T>& other) const {
        Set<T> result;

        for (const T& item : elements) {
            if (!other.SEARCH(item)) {
                result.INSERT(item);
            }
        }
        return result;
    }

    bool ISSUBSET(const Set<T>& other) const {
        for (const T& item : elements) {
            if (!other.SEARCH(item)) {
                return false;
            }
        }
        return true;
    }

    Set<T> SYM_DIFFERENCE(const Set<T>& other) const {
        Set<T> uni = UNION(other);
        Set<T> inter = INTERSECTION(other);

        return uni.SETDIFFERENCE(inter);
    }
};
