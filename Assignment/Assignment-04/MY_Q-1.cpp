// Upload Time table data, holiday data and count how many day I can take a leave.

#include <bits/stdc++.h>
using namespace std;

class BunkCalc {
};

int bunkCount(map <string,int> DaysOfSub,int pt){
    string sub;
    double bunkDays;
    double reqDays;
    double alreadyBunked;
    
    cout << "\nEnter the name of Subject: ";
    cin.ignore();                
    getline(cin, sub);
    double totalLec = DaysOfSub[sub];

    reqDays = ceil((pt*totalLec)/100);
    bunkDays = totalLec - reqDays;
    
    cout << "\nYou should attend " << sub << " Lecture: " << reqDays << endl;

    cout << "\nEnter no of " << sub << " lecture you already bunked: ";
    cin >> alreadyBunked;
    bunkDays = bunkDays - alreadyBunked;

    cout << "\nYou can Bunk "<< sub << " Lecture: " << bunkDays ;

}

int main()
{
    cout << "Sem 03 : 21 Jul to 14 Nov (17 Weeks)" << endl;
    map <string,int> DaysOfSub = {{"DBMS",45},{"DBMS Lab",13},{"DMS",59},{"DLD",58},{"OOP",41},{"OOP Lab",15},{"DS",44},{"DS Lab",15}};

    double pt;
    cout << "\nEnter Percentage(%) of required Attendance: ";
    cin >> pt;   

    bunkCount(DaysOfSub,pt);

    return 0;
}

/*
Attendance required days = (percentage * Total Lecture) / 100
Bunk Allowed = Total Day - Attended Day

Total Lectures:  21Jul to 14Nov (17 weeks) {Except Holidays}
DBMS: 51-3-3 = 45
DBMS Lab: 17-1-1-1-1 = 13
DMS: 68-1-4-4 = 59
DLD: 68-1-1-4-4 = 58
OOP: 51-2-2-3-3 = 41
OOP Lab: 17-1-1 = 15
DS: 51-1-3-3 = 44
DS Lab: 17-1-1 = 15
*/

// import Lec Timetable
// import holidays list
// If you have already bunked then BunkDays