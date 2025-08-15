/*
Track the Champions

Typical Platform Categories:
•	LeetCode → "Design" problems (e.g., Design Underground System, Design Parking System)
•	GFG → OOP in C++, Class & Objects, Static Data Members
•	Codeforces / AtCoder → Simulation with class-based constraints in Div. 3 / Beginner contests

You are building a programming contest score tracker. Each participant’s score changes as they solve problems. The system should:
1.	Track the highest score among all participants at any time.
2.	Track the total number of participants created so far.

You must implement a Participant class with:
•	Static data members:
o	highestScore — stores the maximum score achieved so far by any participant.
o	totalParticipants — stores the number of participants created.
•	Static member function:
o	getCompetitionStats() — returns both highestScore and totalParticipants.
•	Non-static members:
o	name (string) and score (int).
•	Member function:
o	updateScore(int points) — increases the participant’s score and updates highestScore if needed.

Input Format:
•	First line: Integer N — number of participants.
•	Next N lines: Participant names (initial score = 0).
•	Next line: Integer Q — number of score updates.
•	Next Q lines: name points — increase that participant’s score by points.
*/

#include <bits/stdc++.h>
using namespace std;

class Participant
{
public:
    // Non-static members
    string name;
    int score;

    // Static members
    static int highestScore;
    static int totalParticipants;

    // Default Constructor
    Participant(){
        name = "";
        score = 0;
    }

    // Parameterized Constructor
    Participant(string n) {
        name = n;
        score = 0;
        totalParticipants++;
    }

    // Member function
    void updateScore(int points) {
        score += points;
        if (score>highestScore) {
            highestScore = score;
        }
    }

    // Static member function
    static pair<int,int> getCompetitionStats() {
        return {highestScore,totalParticipants};
    }
};

// Definition of Static members
int Participant::highestScore = 0;
int Participant::totalParticipants = 0;

int main()
{
    int num;
    cout << "Enter the number of Participant: ";
    cin >> num;

    // Input Participant Name
    Participant participants[100]; 
    cout << "Enter Participants Name: " << endl;
    for (int i = 0;i < num;i++) {
        string name;
        cin >> name;
        participants[i] = Participant(name);
    }

    // Score Update
    int scoreUpdate;
    cout<<"Enter the number of score updates: ";
    cin >> scoreUpdate;

    while(scoreUpdate--) {
        string name;
        int points;
        cout << "Enter Name and Score (separated by space): ";
        cin >> name >> points;

        // Find all participant by name and update score
        for (int i = 0;i < num;i++) {
            if (participants[i].name == name) {
                participants[i].updateScore(points);
                break;
            }
        }
    }

    auto stats = Participant::getCompetitionStats();
    cout << "\nHighest Score: " << stats.first << "\n";  // Print Highest Score

    // Display names of participant(s) with highest score
    cout << "Participant(s) with highest score: ";
    for (int i = 0; i < num; i++) {
        if (participants[i].score == Participant::highestScore) {
            cout << participants[i].name << "  ";
        }
    }

    cout << "\nTotal Participants: " << stats.second << "\n";  // Total participant count

    return 0;
}