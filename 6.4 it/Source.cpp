#include <iostream>
#include <vector>
#include <cmath>
#include <Windows.h>
using namespace std;

// Функція для створення масиву
vector<int> createArray(int n) {
    vector<int> array(n);
    cout << "Введіть " << n << " елементів масиву:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    return array;
}

// Функція для виведення масиву
void printArray(const vector<int>& array) {
    for (int i = 0; i < array.size(); i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

// Функція для пошуку мінімального за модулем елемента масиву
int findMinAbsElement(const vector<int>& array) {
    int minAbs = abs(array[0]);
    for (int i = 1; i < array.size(); i++) {
        if (abs(array[i]) < minAbs) {
            minAbs = abs(array[i]);
        }
    }
    return minAbs;
}

// Функція для обчислення суми модулів елементів після першого нульового
int sumAfterFirstZero(const vector<int>& array) {
    int sum = 0;
    bool zeroFound = false;

    for (int i = 0; i < array.size(); i++) {
        if (zeroFound) {
            sum += abs(array[i]);
        }
        if (array[i] == 0) {
            zeroFound = true;
        }
    }

    return sum;
}

// Функція для перестановки елементів масиву: парні на початку, непарні в кінці
void transformArray(std::vector<int>& arr) {
    std::vector<int> evenElements;
    std::vector<int> oddElements;

    // Розподіл елементів за парними та непарними індексами
    for (int i = 0; i < arr.size(); ++i) {
        if (i % 2 == 0) {
            evenElements.push_back(arr[i]); // Парні індекси
        }
        else {
            oddElements.push_back(arr[i]);  // Непарні індекси
        }
    }

    // Зберігаємо парні елементи в першу половину масиву
    int index = 0;
    for (int i = 0; i < evenElements.size(); ++i) {
        arr[index++] = evenElements[i];
    }

    // Зберігаємо непарні елементи в другу половину масиву
    for (int i = 0; i < oddElements.size(); ++i) {
        arr[index++] = oddElements[i];
    }
}




int main() {
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251); 
    int n;
    cout << "Введіть кількість елементів у масиві: ";
    cin >> n;

    // Створення масиву
    vector<int> array = createArray(n);

    // Виведення початкового масиву
    cout << "Початковий масив: ";
    printArray(array);

    // Знаходження мінімального за модулем елемента
    int minAbsElement = findMinAbsElement(array);
    cout << "Мінімальний за модулем елемент: " << minAbsElement << endl;

    // Обчислення суми модулів елементів після першого нуля
    int sumModules = sumAfterFirstZero(array);
    cout << "Сума модулів елементів після першого нуля: " << sumModules << endl;

    // Перетворення масиву
    transformArray(array);

    // Виведення перетвореного масиву
    cout << "Перетворений масив: ";
    printArray(array);

    return 0;
}
