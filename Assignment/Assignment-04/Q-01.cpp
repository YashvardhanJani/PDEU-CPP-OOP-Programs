/* [Star-Problem]
Create a Bunk-Calculator using concept of OOP. 
-> Import timetable & holidays list.

Input from user:
-> Sem starting & ending date
-> Subject name
-> Required attendance percentage
-> Number of lectures already bunked

Output contains:
-> Total lectures of that subject (Holiday excluded)
-> Already bunked lectures
-> Number of lectures still you can bunk
*/

#include <bits/stdc++.h>
#include <chrono>
#include <ctime>
#include <iomanip>
using namespace std;

// ------------------- CSV Reader -------------------
class CSVReader {
private:
    static vector<string> split(const string& s, char delimiter) {
        vector<string> tokens;
        string token;
        stringstream ss(s);
        while (getline(ss, token, delimiter))
            tokens.push_back(token);
        return tokens;
    }

public:
    static map<string, vector<string>> readTimetable(const string& filename) {
        ifstream file(filename);
        map<string, vector<string>> timetable;
        string line;

        if (!file.is_open()) {
            cerr << "Error: Cannot open " << filename << endl;
            return timetable;
        }

        // Ignore header
        if (getline(file, line)) {}

        while (getline(file, line)) {
            vector<string> row = split(line, ',');
            if (row.empty()) continue;

            string day = row[0];
            for (int i = 1; i < (int)row.size(); i++) {
                timetable[day].push_back(row[i]);
            }
        }
        return timetable;
    }

    static set<string> readHolidays(const string& filename) {
        ifstream file(filename);
        string line;
        set<string> holidays;

        if (!file.is_open()) {
            cerr << "Error: Cannot open " << filename << endl;
            return holidays;
        }

        while (getline(file, line)) {
            if (!line.empty())
                holidays.insert(line);
        }
        return holidays;
    }
};

// ------------------- Date Utilities -------------------
class DateUtils {
public:
    static chrono::system_clock::time_point parseDate(const string& dateStr) {
        tm tm_date = {};
        istringstream ss(dateStr);
        ss >> get_time(&tm_date, "%d-%m-%Y");

        if (ss.fail()) {
            throw runtime_error("Date parsing failed for " + dateStr + ". Use DD-MM-YYYY format.");
        }

        return chrono::system_clock::from_time_t(mktime(&tm_date));
    }

    static string toString(chrono::system_clock::time_point tp) {
        time_t tt = chrono::system_clock::to_time_t(tp);
        tm local_tm = *localtime(&tt);
        char buffer[11];
        strftime(buffer, sizeof(buffer), "%d-%m-%Y", &local_tm);
        return string(buffer);
    }

    static string getDayOfWeek(chrono::system_clock::time_point tp) {
        time_t tt = chrono::system_clock::to_time_t(tp);
        tm local_tm = *localtime(&tt);
        static const char* days[] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
        return days[local_tm.tm_wday];
    }
};

// ------------------- Bunk Calculator -------------------
class BunkCalculator {
private:
    map<string, vector<string>> timetable;
    set<string> holidays;

    string subject;
    double requiredPercent;
    int alreadyBunked;
    chrono::system_clock::time_point startDate, endDate;

    int countTotalLectures() {
        int total = 0;
        for (auto day = startDate; day <= endDate; day += chrono::hours(24)) {
            string dStr = DateUtils::toString(day);
            if (holidays.count(dStr)) continue; // skip holiday
            string weekday = DateUtils::getDayOfWeek(day);
            if (timetable.count(weekday)) {
                for (auto &lec : timetable[weekday]) {
                    if (lec == subject) total++;
                }
            }
        }
        return total;
    }    

public:
    BunkCalculator(const map<string, vector<string>>& t,
                   const set<string>& h,
                   const string& subj,
                   double percent,
                   int bunked,
                   chrono::system_clock::time_point start,
                   chrono::system_clock::time_point end)
        : timetable(t), holidays(h), subject(subj),
          requiredPercent(percent), alreadyBunked(bunked),
          startDate(start), endDate(end) {}

    void calculate() {
        int totalLectures = countTotalLectures();

        int minPresent = ceil((requiredPercent / 100.0) * totalLectures);
        int maxBunkAllowed = totalLectures - minPresent;
        int remainingBunk = maxBunkAllowed - alreadyBunked;

        cout << "\nTotal lectures of " << subject << "(Holiday excluded): " << totalLectures << endl;
        cout << "Already bunked: " << alreadyBunked << endl;
        cout << "You can bunk " << max(0, remainingBunk)
             << " more lectures and still maintain "
             << requiredPercent << "% attendance.\n\n";
    }
};

// ------------------- MAIN -------------------
int main() {
    try {
        // Load data
        auto timetable = CSVReader::readTimetable("timetable.csv");
        auto holidays = CSVReader::readHolidays("holidays.csv");

        // Inputs
        string startStr, endStr, subject;
        double requiredPercent;
        int alreadyBunked;

        cout << "Enter semester start date (DD-MM-YYYY): ";
        cin >> startStr;
        cout << "Enter semester end date (DD-MM-YYYY): ";
        cin >> endStr;
        cout << "[Subjects: DMS, DLD, DBMS, OOP, DS, DBMSLab, OOPLab, DSLab]" << endl;
        cout << "Enter subject name: ";
        cin >> subject;
        cout << "Enter required attendance percentage: ";
        cin >> requiredPercent;
        cout << "Enter number of lectures already bunked: ";
        cin >> alreadyBunked;

        auto start = DateUtils::parseDate(startStr);
        auto end   = DateUtils::parseDate(endStr);

        // Create object & calculate
        BunkCalculator bc(timetable, holidays, subject,
                          requiredPercent, alreadyBunked,
                          start, end);
        bc.calculate();

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}