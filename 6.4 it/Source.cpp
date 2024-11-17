#include <iostream>
#include <vector>
#include <cmath>
#include <Windows.h>
using namespace std;

// ������� ��� ��������� ������
vector<int> createArray(int n) {
    vector<int> array(n);
    cout << "������ " << n << " �������� ������:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    return array;
}

// ������� ��� ��������� ������
void printArray(const vector<int>& array) {
    for (int i = 0; i < array.size(); i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

// ������� ��� ������ ���������� �� ������� �������� ������
int findMinAbsElement(const vector<int>& array) {
    int minAbs = abs(array[0]);
    for (int i = 1; i < array.size(); i++) {
        if (abs(array[i]) < minAbs) {
            minAbs = abs(array[i]);
        }
    }
    return minAbs;
}

// ������� ��� ���������� ���� ������ �������� ���� ������� ���������
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

// ������� ��� ������������ �������� ������: ���� �� �������, ������ � ����
void transformArray(std::vector<int>& arr) {
    std::vector<int> evenElements;
    std::vector<int> oddElements;

    // ������� �������� �� ������� �� ��������� ���������
    for (int i = 0; i < arr.size(); ++i) {
        if (i % 2 == 0) {
            evenElements.push_back(arr[i]); // ���� �������
        }
        else {
            oddElements.push_back(arr[i]);  // ������ �������
        }
    }

    // �������� ���� �������� � ����� �������� ������
    int index = 0;
    for (int i = 0; i < evenElements.size(); ++i) {
        arr[index++] = evenElements[i];
    }

    // �������� ������ �������� � ����� �������� ������
    for (int i = 0; i < oddElements.size(); ++i) {
        arr[index++] = oddElements[i];
    }
}




int main() {
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251); 
    int n;
    cout << "������ ������� �������� � �����: ";
    cin >> n;

    // ��������� ������
    vector<int> array = createArray(n);

    // ��������� ����������� ������
    cout << "���������� �����: ";
    printArray(array);

    // ����������� ���������� �� ������� ��������
    int minAbsElement = findMinAbsElement(array);
    cout << "̳�������� �� ������� �������: " << minAbsElement << endl;

    // ���������� ���� ������ �������� ���� ������� ����
    int sumModules = sumAfterFirstZero(array);
    cout << "���� ������ �������� ���� ������� ����: " << sumModules << endl;

    // ������������ ������
    transformArray(array);

    // ��������� ������������� ������
    cout << "������������ �����: ";
    printArray(array);

    return 0;
}
