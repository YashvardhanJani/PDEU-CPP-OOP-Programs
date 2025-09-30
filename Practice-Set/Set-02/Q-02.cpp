/* [Star-Problem]
Bus Reservation Tracker 
Domain: Transport Management 
Objective: Use constructors to auto-generate seat numbers, destructor to free resources. 
Problem Statement: 
Create a class Passenger with: passengerName, seatNumber, and destination. 
Use a static counter in the constructor to auto-assign seat numbers. 
When a passenger cancels (object goes out of scope), print "Seat <seatNumber> canceled." 
Use array or vector to simulate passenger list. 
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Passenger {
private:
    string passengerName;
    string destination;
    int seatNumber;
    static int seatCounter;   // shared across all passengers

public:
    // Constructor
    Passenger(string name, string dest) {
        passengerName = name;
        destination = dest;
        seatNumber = ++seatCounter; // assign and increment
        cout << "Passenger " << passengerName 
             << " booked seat " << seatNumber 
             << " for " << destination << "." << endl;
    }

    // Destructor
    ~Passenger() {
        cout << "Seat " << seatNumber << " canceled for " << passengerName << "." << endl;
    }

    // Display passenger details
    void display() const {
        cout << "Name: " << passengerName
             << ", Seat: " << seatNumber
             << ", Destination: " << destination << endl;
    }

    // Getter for passenger name
    string getName() const {
        return passengerName;
    }
};

// Initialize static variable
int Passenger::seatCounter = 0;

int main() {
    vector<Passenger*> passengers;
    int choice;

    while (true) {
        cout << "\n=== Bus Reservation Menu ===\n";
        cout << "1. Book Ticket\n";
        cout << "2. Cancel Ticket by Name\n";
        cout << "3. Show Passenger List\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string name, dest;
            cout << "Enter Passenger Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Destination: ";
            getline(cin, dest);
            passengers.push_back(new Passenger(name, dest));

        } else if (choice == 2) {
            string name;
            cout << "Enter Passenger Name to Cancel: ";
            cin.ignore();
            getline(cin, name);

            bool found = false;
            for (auto it = passengers.begin(); it != passengers.end(); ++it) {
                if ((*it)->getName() == name) {
                    delete *it;                  // calls destructor
                    passengers.erase(it);        // remove from list
                    found = true;
                    cout << "Ticket canceled successfully.\n";
                    break;
                }
            }
            if (!found) {
                cout << "Passenger not found!\n";
            }

        } else if (choice == 3) {
            if (passengers.empty()) {
                cout << "No passengers booked.\n";
            } else {
                cout << "\n--- Passenger List ---\n";
                for (auto p : passengers) {
                    p->display();
                }
            }

        } else if (choice == 4) {
            cout << "Exiting... canceling all remaining tickets.\n";
            for (auto p : passengers) {
                delete p;  // free all passengers
            }
            passengers.clear();
            break;

        } else {
            cout << "Invalid choice! Try again.\n";
        }
    }
    return 0;
}