#include<iostream>
#include<fstream>
#include<windows.h>
#include<sstream>

using namespace std;

class Airline {
private:
    string Flight, Des, Dep;
    int Seats;

public:
    Airline(string flight, string des, string dep, int seats) {
        Flight = flight;
        Des = des;
        Dep = dep;
        Seats = seats;
    }

    string getFlight() {
        return Flight;
    }

    string getDes() {
        return Des;
    }

    string getDep() {
        return Dep;
    }

    int getSeats() {
        return Seats;
    }

    void update(string flight) {
        ifstream in("D:/Flight.txt");
        ofstream out("D:/Flight_Temp.txt");

        string line;
        while (getline(in, line)) {
            int pos = line.find(flight);
            if (pos != string::npos) {
                int current = Seats - 1;
                Seats = current;
                stringstream ss;
                ss << current;
                string strCurrent = ss.str();

                int seatsPos = line.find_last_of(':');
                line.replace(seatsPos + 2, string::npos, strCurrent);
            }
            out << line << endl;
        }

        out.close();
        in.close();
        remove("D:/Flight.txt");
        rename("D:/Flight_Temp.txt", "D:/Flight.txt");
        cout << "Seat Reserved Successfully!" << endl;
    }

    static void display() {
        ifstream in("D:/Flight.txt");
        if (!in) {
            cout << "Error : File Can't Open!" << endl;
            return;
        }

        string line;
        while (getline(in, line)) {
            cout << line << endl;
        }
        in.close();
    }
};

int main() {
    Airline flight1("F001", "Sydney", "Canada", 200);
    Airline flight2("F002", "Sydney", "Mumbai", 90);
    Airline flight3("F003", "Sydney", "Qatar", 2);

    ofstream out("D:/Flight.txt");
    if (!out) {
        cout << "Error : File can't open!" << endl;
    } else {
        out << flight1.getFlight() << " : " << flight1.getDes() << " : " << flight1.getDep() << " : " << flight1.getSeats() << endl;
        out << flight2.getFlight() << " : " << flight2.getDes() << " : " << flight2.getDep() << " : " << flight2.getSeats() << endl;
        out << flight3.getFlight() << " : " << flight3.getDes() << " : " << flight3.getDep() << " : " << flight3.getSeats() << endl;
        out.close();
        cout << "Data Saved Successfully!" << endl;
    }

    bool exitFlag = false;
    while (!exitFlag) {
        system("cls");
        cout << "\t Welcome to Airline Management System" << endl;
        cout << "\t ************************************" << endl;
        cout << "\t 1. Reserve a Seat." << endl;
        cout << "\t 2. Exit." << endl;
        cout << "\t Enter Your Choice : ";

        int val;
        cin >> val;

        if (val == 1) {
            system("cls");
            Airline::display();

            string flight;
            cout << "Enter Flight No : ";
            cin >> flight;

            if (flight == flight1.getFlight() && flight1.getSeats() > 0) {
                flight1.update(flight);
            } else if (flight == flight1.getFlight()) {
                cout << "Sorry, Seats Not Available!" << endl;
            }

            if (flight == flight2.getFlight() && flight2.getSeats() > 0) {
                flight2.update(flight);
            } else if (flight == flight2.getFlight()) {
                cout << "Sorry, Seats Not Available!" << endl;
            }

            if (flight == flight3.getFlight() && flight3.getSeats() > 0) {
                flight3.update(flight);
            } else if (flight == flight3.getFlight()) {
                cout << "Sorry, Seats Not Available!" << endl;
            }

            Sleep(3000);
        } else if (val == 2) {
            system("cls");
            exitFlag = true;
            cout << "Good Luck!" << endl;
            Sleep(2000);
        }
    }

    return 0;
}

