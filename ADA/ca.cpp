// you have employees with their salaries. Write a C++ program using Merge Sort to sort the employees based on their salaries in decending order.
#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Employee {
    string name;
    double salary;
};
void merge(vector<Employee>& employees, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<Employee> L(n1);
    vector<Employee> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = employees[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = employees[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i].salary >= R[j].salary) {
            employees[k] = L[i];
            i++;
        } else {
            employees[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        employees[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        employees[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(vector<Employee>& employees, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(employees, left, mid);
        mergeSort(employees, mid + 1, right);
        merge(employees, left, mid, right);
    }
}
int main() {
    vector<Employee> employees = {
        {"Kartik kala", 70000},
        {"Surya", 50000},
        {"Ravi", 60000},
        {"Seema kumari", 80000},
        {"Tajindar", 55000}
    };
    int n = employees.size();
    mergeSort(employees, 0, n - 1);
    cout << "Employees sorted by salary in descending order:\n";
    for (const auto& emp : employees) {
        cout << emp.name << ": Rs" << emp.salary << endl;
    }
    return 0;
}
