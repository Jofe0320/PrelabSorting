#include <iostream>
using namespace std;

class Airplane {
private:
    int capacity;
    int velocity;
    string model;
    string pilotName;


public:
    Airplane(int capacity, int velocity, string model, string pilotName);
    
    int getCapacity();
    int getVelocity();
    string getModel();
    string getPilotName();

    void setCapacity(int capacity);
    void setVelocity(int velocity);
    void setModel(string model);
    void setPilotName(string pilotName);

    Airplane binarySearch(vector<Airplane> airplanes, int givenCapacity);
    void bubbleSort(vector<Airplane> &airplanes);
};
