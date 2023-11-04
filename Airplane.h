#include <iostream>
#include <vector>
using namespace std;

class Airplane {
private:
    int capacity;
    int velocity;
    string model;
    string pilotName;


public:
    Airplane(int capacity, int velocity, string model, string pilotName){
        this->capacity = capacity;
        this->velocity = velocity;
        this->model = model;
        this->pilotName = pilotName;
    }
    
    int getCapacity(){
        return this->capacity;
    }
    int getVelocity(){
        return this->velocity;
    }
    string getModel(){
        return this->model;
    }
    string getPilotName(){
        return this->pilotName;
    }

    void setCapacity(int capacity){
        this->capacity = capacity;
    }

    void setVelocity(int velocity){
        this->velocity = velocity;
    }

    void setModel(string model){
        this->model = model;
    }

    void setPilotName(string pilotName){
        this->pilotName = pilotName;
    }

    static vector<int> searchMatrix(vector< vector<Airplane> > airplaneMatrix,  string pilotName);
    static Airplane binarySearch(vector<Airplane> airplanes, int givenCapacity);
     void bubbleSort(vector<Airplane> &airplanes);

     void showAirplane(){
        cout << "Name: " << this->model << endl;
        cout << "Capaciy: " << this-> capacity << endl;
        cout << "Pilot Name: " << this->pilotName << endl;
        cout << "Velocity " << this->velocity << endl << endl;
         
    }
};
