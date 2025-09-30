/* [Star-Problem]
1. Design a problem statement to demonstrate the following:
    a. Access Specifiers
    b. Constructors and Destructors
    c. Deep and Shallow Copy
    d. use of new and delete keywords
2. Write the pseudocode and list the library files needed, classes involved and significance of dynamic allocation for the project optimization.
3. Implement the project as designed in the previous two steps.
*/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Song {
private:    
    int songID;
    char* songName;
    char* songType;
    char* artistName;
    bool isShallow;

public:
    // Parameterized Constructor   
    Song(int songID, const char* songName, const char* songType, const char* artistName) {
        this->songID = songID;
        this->songName = new char[strlen(songName) + 1];
        strcpy(this->songName, songName);
        this->songType = new char[strlen(songType) + 1];
        strcpy(this->songType, songType);
        this->artistName = new char[strlen(artistName) + 1];
        strcpy(this->artistName, artistName);
        isShallow = false; // own the memory
        cout << "\n-> Song Added: " << this->songID << " - " << this->songName << endl;
    }

    // Deep Copy Constructor
    Song(const Song& obj) {
        songID = obj.songID;
        songName = new char[strlen(obj.songName) + 1];
        strcpy(songName, obj.songName);
        songType = new char[strlen(obj.songType) + 1];
        strcpy(songType, obj.songType);
        artistName = new char[strlen(obj.artistName) + 1];
        strcpy(artistName, obj.artistName);
        isShallow = false; // own the memory
        cout << "\n-> Deep copy constructor called for: " << songID << " - " << songName << endl;
    }

    // Shallow Copy Constructor
    Song(Song& obj, bool shallow) {
        if (shallow) {
            songID = obj.songID;
            songName = obj.songName;
            songType = obj.songType;
            artistName = obj.artistName;
            isShallow = true; // not own the memory
            cout << "\n-> Shallow copy constructor called for: " << songID << " - " << songName << endl;
        }
    }

    // Destructor
    ~Song() {
        cout << "Deleting Song: " << songID << " - " << songName << endl;
        if (!isShallow) { // only delete if we own the memory
            delete[] songName;
            delete[] songType;
            delete[] artistName;
        }
    }

    void setSongType(const char* newType) {
        if (!isShallow) {
            delete[] songType;
            songType = new char[strlen(newType) + 1];
            strcpy(songType, newType);
        } else {
            // Shallow copy shares memory — changing type will affect original
            strcpy(songType, newType);  // Directly modify shared memory
        }
    }

    void display(const char* copyType = "") const {
        cout << "Song ID: " << songID << " | Name: " << songName << " | Type: " << songType << " | Artist: " << artistName;
        if (strlen(copyType) > 0) {
            cout << "  (" << copyType << ")";
        }
        cout << endl;
    }
};

class Playlist {
private:
    Song* songs[10];
    string copyType[10];
    int count;

public:
    Playlist() { count = 0; }

    void addSong(Song* s, string type = "") {
        if (count < 10) {
            songs[count] = s;
            copyType[count] = type;
            count++;
        } else {
            cout << "Playlist is full!" << endl;
        }
    }

    void showSongs() const {
        cout << "\n----- Playlist Songs -----\n";
        for (int i = 0; i < count; i++) {
            songs[i]->display(copyType[i].c_str());
        }
    }
};

int main() {
    int id;
    char name[100], type[100], artist[100];

    cout << "Enter Song 1 Details:\n";
    cout << "Song ID: ";
    cin >> id;
    cin.ignore();
    cout << "Song Name: ";
    cin.getline(name, 100);
    cout << "Song Type: ";
    cin.getline(type, 100);
    cout << "Artist Name: ";
    cin.getline(artist, 100);

    Song s1(id, name, type, artist);
    Playlist playlist;
    playlist.addSong(&s1, "Original Song");
    playlist.showSongs();

    // Shallow copy
    Song s2(s1, true);
    cout << "Enter new type for Shallow Copied song: ";
    char shallowType[100];
    cin.getline(shallowType, 100);
    s2.setSongType(shallowType); // will also affect s1

    // Deep copy
    Song s3 = s1;
    // Change copied song's type
    cout << "Enter new type for Deep Copied song: ";
    char newType[100];
    cin.getline(newType, 100);
    s3.setSongType(newType);

    // Playlist
    playlist.addSong(&s2, "Shallow Copied Song");
    playlist.addSong(&s3, "Deep Copied Song");
    
    cout << "\n:::: After Shallow & Deep Coping ::::" << endl;
    playlist.showSongs();
    cout << endl;

    return 0;
}