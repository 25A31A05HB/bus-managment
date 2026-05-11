#include <iostream>
#include <string> // Added for string support
using namespace std;

struct Bus {
    int regNo;
    int busno;
    string name;
    string location;
    string route;
    Bus* next;
};

// Global head pointer
Bus* head = NULL;

// Insert at end
void insertBus(int reg, int busno, string name, string loc, string route) {
    Bus* newBus = new Bus{reg, busno, name, loc, route, NULL};

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

void loadBuses() {
    insertBus(0, 1, "None", "Kakinada", "Route-A");
    insertBus(0, 2, "None", "Kakinada", "Route-B");
    insertBus(0, 3, "None", "Pitapuram", "Route-C");
    insertBus(0, 4, "None", "Samarlakota", "Route-D");
    insertBus(0, 5, "None", "Rjy", "Route-E");
}

void addmember() {
    int reg, busno;
    string name;

    cout << "Enter Reg No: "; cin >> reg;
    cout << "Enter your name: "; cin >> name;
    cout << "Enter Bus no: "; cin >> busno;

    // FIX: Always start from head inside the function
    Bus* temp = head; 
    bool found = false;

    while (temp != NULL) {
        if (temp->busno == busno) {
            temp->regNo = reg;
            temp->name = name;
            found = true;
            break; 
        }
        temp = temp->next;
    }

    if (found) cout << "Member added to Bus successfully!\n";
    else cout << "\nInvalid bus number!\n";
}

void display() {
    Bus* temp = head;
    int ch; // FIX: Declare 'ch'

    if (temp == NULL) {
        cout << "No buses available\n";
        return;
    }

    cout << "\n--- Available Buses ---";
    while (temp != NULL) {
        cout << "\nBus No: " << temp->busno << " | Location: " << temp->location << " | Route: " << temp->route;
        temp = temp->next;
    }

    cout << "\n\nEnter bus number to view all stops: ";
    cin >> ch;
    switch (ch) {
        case 1: cout << "Stops: Gathicenter, Jagganaikpur, Balajicheruvu\n"; break;
        case 2: cout << "Stops: Sarpavaram, Srinagar, Main Road\n"; break;
        case 3: cout << "Stops: Simhadripuram, Municipal High School, Pitapuram Temple\n"; break;
        case 4: cout << "Stops: Jaggampeta, Ganapathinagar, Peddapuram\n"; break;
        case 5: cout << "Stops: RTC Colony, Lalachruvu, Divan Cheruvu\n"; break;
        default: cout << "Invalid bus number selection.\n";
    }
} // FIX: Added missing brace

void viewdetails() {
    int reg;
    cout << "Enter Reg No to search: ";
    cin >> reg;

    Bus* temp = head;
    while (temp != NULL) {
        if (temp->regNo == reg && reg != 0) { // Check reg != 0 so we don't find empty buses
            cout << "\nMember Found!\n";
            cout << "Name: " << temp->name << " | Bus No: " << temp->busno << " | Route: " << temp->route << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "No member found with that Registration Number.\n";
}

int main() {
    loadBuses();
    int choice;

    do {
        cout << "\n--- College Bus Management ---\n";
        cout << "1. View Buses & Stops\n2. Register Member to Bus\n3. View Member Details\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: display(); break;
            case 2: addmember(); break;
            case 3: viewdetails(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
