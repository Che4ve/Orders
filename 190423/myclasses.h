#include <iostream>

using namespace std;

#define DEFAULT_SIZE 20
 // Define the Set class
class Set {
private:
    // Array to store elements
    int* elements;
     // Number of elements in the set
    int count;
    // Maximum size of the array
    int size;
 public:
    // Constructors
    Set() {
        elements = new int[DEFAULT_SIZE];
        count = 0;
        size = DEFAULT_SIZE;
    }
    Set(int size) {
        elements = new int[size];
        count = 0;
        this->size = size;
    }
    Set(int* arr, int size) {
        elements = new int[size];
        count = 0;
        this->size = size;
        for (int i = 0; i < size; i++) {
            add(arr[i]);
        }
    }
     // Destructor
    ~Set() {
        delete[] elements;
    }
     // Add an element to the set
    void add(int x) {
        if (count < size) {
            if (!contains(x)) {
                elements[count++] = x;
            }
        } else {
            cout << "Error: Set is already full." << endl;
        }
    }
     // Remove an element from the set
    void remove(int x) {
        if (!is_empty()) {
            for (int i = 0; i < count; i++) {
                if (elements[i] == x) {
                    for (int j = i; j < count - 1; j++) {
                        elements[j] = elements[j + 1];
                    }
                    count--;
                    break;
                }
            }
        } else {
            cout << "Error: Set is already empty." << endl;
        }
    }
     // Check if an element is present in the set
    bool contains(int x) {
        for (int i = 0; i < count; i++) {
            if (elements[i] == x) {
                return true;
            }
        }
        return false;
    }
     // Print the elements of the set
    void print() {
        for (int i = 0; i < count; i++) {
            cout << "[" << elements[i] << "] ";
        }
        cout << "- size: " << count << endl;
    }
     // Check if the set is empty
    bool is_empty() {
        return count == 0;
    }
};

class PolynomialSet : public Set {
public:
    // Constructors
    PolynomialSet() : Set() {}
    PolynomialSet(int size) : Set(size) {}
    PolynomialSet(int* arr, int size) : Set(arr, size) {}

    // Method to add two polynomials and store the result in the set
    void add_polynomials(int* p1, int* p2, int degree) {
        int* result = new int[degree + 1];
        for (int i = 0; i <= degree; i++) {
            result[i] = p1[i] + p2[i];
        }
        cout << "The result was transformed to a set" << endl;
        Set::add(*result);
    }

    // Method to subtract two polynomials and store the result in the set
    void subtract_polynomials(int* p1, int* p2, int degree) {
        int* result = new int[degree + 1];
        for (int i = 0; i <= degree; i++) {
            result[i] = p1[i] - p2[i];
        }
        cout << "The result was transformed to a set" << endl;
        Set::add(*result);
    }
};