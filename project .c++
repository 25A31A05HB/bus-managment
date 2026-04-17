#include <iostream>
using namespace std;

struct Bus {
    int regNo;
    string name;
    string location;
    string route;
    Bus* next;
};

Bus* head = NULL;

// Insert at end
void insertBus(int reg, string name, string loc, string route) {
    Bus* newBus = new Bus{reg, name, loc, route, NULL};

    if (head == NULL) {
        head = newBus;
        return;
    }

    Bus* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newBus;
}

// Auto add 5 buses
void loadBuses() {
    insertBus(3,  "ClgBus1", "Campus", "Route-A");
    insertBus(8,  "ClgBus2", "City", "Route-B");
    insertBus(12, "ClgBus3", "Town", "Route-C");
    insertBus(78, "ClgBus4", "Village", "Route-D");
    insertBus(35, "ClgBus5", "Highway", "Route-E");
}

// Add manually
void addBus() {
    int reg;
    string name, loc, route;

    cout << "Enter Reg No: ";
    cin >> reg;
    cout << "Enter Bus Name: ";
    cin >> name;
    cout << "Enter Location: ";
    cin >> loc;
    cout << "Enter Route: ";
    cin >> route;

    insertBus(reg, name, loc, route);
    cout << "Bus added successfully!\n";
}

// Display buses
void display() {
    Bus* temp = head;

    if (temp == NULL) {
        cout << "No buses available\n";
        return;
    }

    cout << "\n--- Bus List ---\n";
    while (temp != NULL) {
        cout << "\nReg No: " << temp->regNo;
        cout << "\nName: " << temp->name;
        cout << "\nLocation: " << temp->location;
        cout << "\nRoute: " << temp->route << endl;

        temp = temp->next;
    }
}

// Search
void searchBus() {
    int reg;
    cout << "Enter Reg No to search: ";
    cin >> reg;

    Bus* temp = head;

    while (temp != NULL) {
        if (temp->regNo == reg) {
            cout << "\nBus Found!\n";
            cout << temp->name << " | " << temp->location 
                 << " | " << temp->route << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Bus not found!\n";
}

// Main
int main() {
    loadBuses(); // auto insert

    int choice;

    do {
        cout << "\n--- College Bus Management ---\n";
        cout << "1. View Buses\n2. Add Bus\n3. Search Bus\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: display(); break;
            case 2: addBus(); break;
            case 3: searchBus(); break;
        }

    } while (choice != 4);

    return 0;
}
