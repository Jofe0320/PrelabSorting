#include "Airplane.h"

Airplane Airplane::binarySearch(vector<Airplane> airplanes, int givenCapacity){

    return binarySearchHelper(airplanes, givenCapacity, 0, airplanes.size() - 1);
}


Airplane binarySearchHelper(vector<Airplane> airplanes, int givenCapacity, int frontIndex, int backIndex){
    if(frontIndex < backIndex){
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