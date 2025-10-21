#include <list>
#include <algorithm> // Знадобиться для std::find

template <typename T>
class MySet {
private:
    std::list<T> elements; // Ось тут ми використовуємо список для зберігання

public:
    // Тут ми будемо реалізовувати всі необхідні операції
};

bool SEARCH(const T& element) const {
    // std::find пробігає по списку від .begin() до .end()
    // і шукає 'element'. Якщо знаходить, повертає ітератор на нього,
    // інакше повертає .end().
    return std::find(elements.begin(), elements.end(), element) != elements.end();
}

void INSERT(const T& element) {
    // Якщо елемент *не* знайдено (SEARCH повертає false)
    if (!SEARCH(element)) {
        elements.push_back(element); // Додаємо в кінець списку
    }
}

void DELETE(const T& element) {
    // std::list::remove знаходить *всі* входження 'element' і видаляє їх.
    // Оскільки у нас множина, там має бути не більше одного.
    elements.remove(element);
}

void CLEAR() {
    elements.clear();
}

MySet<T> UNION(const MySet<T>& other) const {
    MySet<T> result = *this; // 1. Копіюємо всі елементи з першої множини (this)

    // 2. Додаємо всі елементи з другої множини (other)
    for (const T& element : other.elements) {
        result.INSERT(element); // Наш INSERT сам подбає про дублікати
    }
    return result;
}

MySet<T> INTERSECTION(const MySet<T>& other) const {
    MySet<T> result;
    // Пробігаємо по елементах першої множини
    for (const T& element : this->elements) {
        // Якщо елемент є і в другій множині
        if (other.SEARCH(element)) {
            result.INSERT(element); // Додаємо його до результату
        }
    }
    return result;
}

MySet<T> SETDIFFERENCE(const MySet<T>& other) const {
    MySet<T> result;
    // Пробігаємо по елементах першої множини (this)
    for (const T& element : this->elements) {
        // Якщо елемента *немає* в другій множині
        if (!other.SEARCH(element)) {
            result.INSERT(element); // Додаємо його до результату
        }
    }
    return result;
}

MySet<T> SYM_DIFFERENCE(const MySet<T>& other) const {
    MySet<T> uni = this->UNION(other);
    MySet<T> inter = this->INTERSECTION(other);
    return uni.SETDIFFERENCE(inter);
}

bool ISSUBSET(const MySet<T>& other) const {
    // Пробігаємо по елементах `this`
    for (const T& element : this->elements) {
        // Якщо ми знайшли хоча б один елемент,
        // якого *немає* в 'other', то це не підмножина
        if (!other.SEARCH(element)) {
            return false;
        }
    }
    // Якщо цикл завершився, значить всі елементи на місці
    return true;
}

#include <chrono>
#include <vector>
#include <random> // Для генерації даних

// ... (припустимо, у вас є згенерована MySet<int> setN розміром N)
// ... (і згенерований std::vector<int> elementsToFind, яких НЕМАЄ в setN)

// Випадок 1: Елемент є
auto start_found = std::chrono::high_resolution_clock::now();
for (int i = 0; i < 1000; ++i) {
    int element = /* взяти випадковий елемент, що ТОЧНО є в setN */;
    setN.SEARCH(element);
}
auto end_found = std::chrono::high_resolution_clock::now();
double time_found_avg = std::chrono::duration_cast<std::chrono::nanoseconds>(end_found - start_found).count() / 1000.0;

// Випадок 2: Елемента немає
auto start_not_found = std::chrono::high_resolution_clock::now();
for (int i = 0; i < 1000; ++i) {
    int element = /* взяти випадковий елемент, якого НЕМАЄ в setN */;
    setN.SEARCH(element);
}
auto end_not_found = std::chrono::high_resolution_clock::now();
double time_not_found_avg = std::chrono::duration_cast<std::chrono::nanoseconds>(end_not_found - start_not_found).count() / 1000.0;
