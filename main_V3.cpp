#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


struct Slot {
    string name;
    string email;
    string designation;
    string date;
    string time;
};

void loadSlotData(const string& filename, vector<Slot>& slots) {
    ifstream inFile(filename);
    if (inFile.is_open()) {
        Slot temp;
        while (getline(inFile, temp.name)) {
            getline(inFile, temp.email);
            getline(inFile, temp.designation);
            getline(inFile, temp.date);
            getline(inFile, temp.time);
            slots.push_back(temp);
        }
        inFile.close();
    }
}


void saveSlotData(const string& filename, const vector<Slot>& slots) {
    ofstream outFile(filename, ios::trunc); // Overwrite the file
    for (const auto& slot : slots) {
        outFile << slot.name << endl;
        outFile << slot.email << endl;
        outFile << slot.designation << endl;
        outFile << slot.date << endl;
        outFile << slot.time << endl;
        outFile << endl;
    }
    outFile.close();
}


void displaySlots(const vector<Slot>& slots) {
    if (slots.empty()) {
        cout << "No slots booked yet." << endl;
        return;
    }
    cout << "\nBooked Slots:" << endl;
    for (const auto& slot : slots) {
        cout << "Name: " << slot.name << ", Email: " << slot.email
             << ", Designation: " << slot.designation << ", Date: " << slot.date
             << ", Time: " << slot.time << endl;
    }
}

int main() {
    int n;
   

    const string filename = "slots.txt";
    vector<Slot> slots;

    // Load existing bookings
    loadSlotData(filename, slots);

    // Display existing bookings
    cout << "Current Slot Bookings:" << endl;
    displaySlots(slots);

     cout<<"Enter Number of slots You want to book: ";
    cin>>n;

    for(int i=0;i<n;i++){

    // Add a new booking
    Slot newSlot;
    cout << "\nEnter details for new slot booking:" << endl;
    cout << "Enter Name: ";
    cin.ignore(); // Clear input buffer
    getline(cin, newSlot.name);
    cout << "Enter Email: ";
    getline(cin, newSlot.email);
    cout << "Enter Designation: ";
    getline(cin, newSlot.designation);
    cout << "Enter Date (YYYY-MM-DD): ";
    getline(cin, newSlot.date);
    cout << "Enter Time (HH:MM): ";
    getline(cin, newSlot.time);
    

    // Add new booking to the list
    slots.push_back(newSlot);

    }

    // Save updated bookings to the file
    saveSlotData(filename, slots);

    // Display updated bookings
    cout << "\nUpdated Slot Bookings:" << endl;
    displaySlots(slots);

    return 0;
}
