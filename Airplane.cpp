#include "Airplane.h"

Airplane binarySearchHelper(vector<Airplane> airplanes, int givenCapacity, int frontIndex, int backIndex){
    if(frontIndex > backIndex){
        return Airplane(250, 450, "Boeing 777", "Anthony Edwards"); // Airplane(int capacity, int velocity, string model, string pilotName);
    }

    int middleIndex = (frontIndex + backIndex) / 2;
    if(airplanes[middleIndex].getCapacity() == givenCapacity){
        return airplanes[middleIndex];
    }
    else if(airplanes[middleIndex].getCapacity() > givenCapacity){ 
        // search to the left
        return binarySearchHelper(airplanes, givenCapacity, frontIndex, middleIndex - 1);
    }
    else{
        return binarySearchHelper(airplanes, givenCapacity, middleIndex + 1, backIndex);
    }
}

Airplane Airplane::binarySearch(vector<Airplane> airplanes, int givenCapacity){

    return binarySearchHelper(airplanes, givenCapacity, 0, airplanes.size() - 1);
}


vector<int> Airplane::searchMatrix(vector< vector<Airplane> > airplaneMatrix, string pilotName){
        // you cannot assume that it's a square matrix

        for(int row = 0; row < airplaneMatrix.size(); row++)
        {
            for(int col = 0; col < airplaneMatrix[row].size(); col++){
                Airplane currentAirplane = airplaneMatrix[row][col];
                if(pilotName == currentAirplane.getPilotName()){
                    return vector<int>{row, col};
                }
            }
        }

        return vector<int>{-1, -1};
    
}

void Airplane::insertionSort(vector<Airplane> &airplanes){
    for (int i = 1; i < airplanes.size(); ++i) {
        Airplane temp = airplanes[i];
        int j = i - 1;

        while (j >= 0 && airplanes[j].getCapacity() > temp.getCapacity()) {
            airplanes[j + 1] = airplanes[j];
            j = j - 1;
        }

        airplanes[j + 1] = temp;
    }
}

int main(){

    Airplane a1 = Airplane(140, 200, "Airbus A380", "Nikola Jokic" );
    Airplane a2 = Airplane(150, 250, "Airbus A321", "Jimmy Butler");
    Airplane a3 = Airplane(160, 300, "Boeing 747-400", "Damian Lillard");
    Airplane a4 = Airplane(170, 260, "Boeing 757", "Wesley Matthews");
    Airplane a5 = Airplane(180, 300, "Cessna 172", "Jamal Murray");
    Airplane a6 = Airplane(190, 240, "Airbus A319", "Devin Booker");
    Airplane a7 = Airplane(200, 300, "Embraer 190", "Kevin Durant");
    Airplane a8 = Airplane(210, 400, "Boeing 707", "LeBron James");
    Airplane a9 = Airplane(220, 450, "Random Plane Name", "Tyrese Haliburton");
    Airplane a10 = Airplane(230, 500, "Douglas DC-3", "Robert Oppenheimer");
    
    
    vector<Airplane> test1 = {a1, a2, a3, a4, a5, a6, a7, a8};
    vector<Airplane> test2 = {a4, a5};
    vector<Airplane> empty = {};
    Airplane::binarySearch(test1, 140).showAirplane(); // Nikola Jokic
    Airplane::binarySearch(test2, 180).showAirplane(); // Jamal Murray
    Airplane::binarySearch(test1, 150).showAirplane();  // Jimmy Butler
    Airplane::binarySearch(test1, 200).showAirplane();  // Kevin Durant
    Airplane::binarySearch(empty, 900).showAirplane();   // Anthony Edwards
    Airplane::binarySearch(test1, 800).showAirplane(); // Anthony Edwards
    Airplane::binarySearch(test1, 210).showAirplane(); // LeBron James

    test1 = {a8, a5, a4, a2, a6, a3, a7, a1};
    test2 = {a5, a4};
    empty = {};

    cout << "Before Sorting: " << endl;
    for (Airplane& plane : test1) {
        plane.showAirplane();
    }

    Airplane::insertionSort(test1);

    cout << "\nAfter Sorting: " << endl;
    for (Airplane& plane : test1) {
        plane.showAirplane();
    }

    cout << "Before Sorting: " << endl;
    for (Airplane& plane : test2) {
        plane.showAirplane();
    }

    Airplane::insertionSort(test2);

    cout << "\nAfter Sorting: " << endl;
    for (Airplane& plane : test2) {
        plane.showAirplane();
    }

    return 0;
}

