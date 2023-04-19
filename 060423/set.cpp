#include <iostream>
using namespace std;
 // Define the default size of the set
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
 // Menu to create a set
void creation_menu() {
    cout << "\t1. Create an empty set of default size (20)" << endl;
    cout << "\t2. Create an empty set with specified size" << endl;
    cout << "\t3. Create a set from an array" << endl;
    cout << "\t0. Exit" << endl;
}
 // Menu to perform operations on the set
void option_menu() {
    cout << "\t    1. Add an element to the set" << endl;
    cout << "\t    2. Remove an element from the set" << endl;
    cout << "\t    3. Print the set" << endl;
    cout << "\t    4. Build a new set" << endl;
    cout << "\t    0. Exit" << endl;
}
 int main() {
    // Pointer to a Set object
    Set* s = nullptr;
     // Variables to store user choices
    int create_choice;
    int action_choice;
    do {
    cout << "How would you prefer to create a set?\n";
    creation_menu();
    cin >> create_choice;
     switch (create_choice) {
        case 1: {
            // Create an empty set
            s = new Set();
            cout << "Empty set created." << endl;
            break;
        }
        case 2: {
            // Create a set with a given size
            int size;
            cout << "Enter the size: ";
            cin >> size;
            s = new Set(size);
            cout << "Set with size (" << size << ") created." << endl;
            break;
        }
        case 3: {
            // Create a set from an array
            int size;
            cout << "Enter the size of array: ";
            cin >> size;
            int* arr = new int[size];
            cout << "Enter the elements: ";
            for (int i = 0; i < size; i++) {
                cin >> arr[i];
            }
            s = new Set(arr, size);
            delete[] arr;
            cout << "Set created from array." << endl;
            break;
        }
        case 0: {
            // Exit program
            if (s) {
                delete s;
            }
            cout << "Goodbye!" << endl;
            return 0;
        }
        default: {
            // Invalid choice
            cout << "Invalid choice. Try again." << endl;
            break;
        }
    }
     do {
        // Ask user what action they would like to perform
        option_menu();
        cin >> action_choice;
        switch (action_choice) {
            case 1: {
                // Add an element to the set
                int x;
                cout << "Enter the element: ";
                cin >> x;
                s->add(x);
                cout << "Done." << endl;
                break;
            }
            case 2: {
                // Remove an element from the set
                int x;
                cout << "Enter the element: ";
                cin >> x;
                s->remove(x);
                cout << "Done." << endl;
                break;
            }
            case 3: {
                // Print the set
                if (!s->is_empty()) {
                    cout << "The set contains: ";
                    s->print();
                    break;
                }
                else {
                    cout << "The set is empty\n";
                    break;
                }
            }
            case 4: {
                // Go back to creation menu
                action_choice = 4;
                break;
            }
            case 0: {
                // Exit program
                if (s) {
                    delete s;
                }
                cout << "Goodbye!" << endl;
                return 0;
            }
            default: {
                // Invalid choice
                cout << "Invalid choice. Try again." << endl;
                break;
            }
            }
        } while (action_choice != 4);
    } while (create_choice != 0);
    return 0;
}