// Manage smart devices using base class pointers and virtual destructors.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class SmartDevice {
protected:
    string deviceId;

public:
    SmartDevice(const string& id) : deviceId(id) {
        cout << "SmartDevice constructor called: " << deviceId << endl;
    }

    virtual ~SmartDevice() {
        cout << "SmartDevice destructor called for " << deviceId << "." << endl;
    }

    virtual void connect() = 0;
    virtual void displayStatus() const = 0;
};

class SmartLight : public SmartDevice {
private:
    bool isOn;
    string* colorMode;

public:
    SmartLight(const string& id, bool state, const string& color)
        : SmartDevice(id), isOn(state) {
        colorMode = new string(color);
        cout << "SmartLight constructor called." << endl;
    }

    ~SmartLight() override {
        cout << "SmartLight destructor called for " << deviceId << "." << endl;
        if (colorMode) {
            cout << "Deallocating colorMode." << endl;
            delete colorMode;
        }
    }

    void connect() override {
        cout << "Smart Light " << deviceId << " connecting..." << endl;
    }

    void displayStatus() const override {
        cout << "Smart Light " << deviceId << " is "
             << (isOn ? "ON" : "OFF") << ". "
             << "Color Mode: " << *colorMode << "." << endl;
    }
};

class SmartSpeaker : public SmartDevice {
private:
    int volume;
    string currentSong;

public:
    SmartSpeaker(const string& id, int vol, const string& song)
        : SmartDevice(id), volume(vol), currentSong(song) {
        cout << "SmartSpeaker constructor called." << endl;
    }

    ~SmartSpeaker() override {
        cout << "SmartSpeaker destructor called for " << deviceId << "." << endl;
    }

    void connect() override {
        cout << "Smart Speaker " << deviceId << " connecting..." << endl;
    }

    void displayStatus() const override {
        cout << "Smart Speaker " << deviceId
             << " is at volume " << volume
             << ", playing: " << currentSong << "." << endl;
    }
};

int main()
{
    SmartLight* light1 = new SmartLight("Light001", true, "Warm White");
    SmartSpeaker* speaker1 = new SmartSpeaker("Speaker001", 75, "Bohemian Rhapsody"); 
    vector<SmartDevice*> devices;
    devices.push_back(light1);
    devices.push_back(speaker1);

    cout << "\n --- Connecting and Displaying Status ---" << endl;
    for (auto device : devices) {
        device->connect();
        device->displayStatus();
    }

    cout << "\n --- Deleting Devices ---" << endl;
    for (auto device : devices) {
        delete device;
    }
    devices.clear();
    return 0;
}