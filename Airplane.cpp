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


int main(){

    Airplane a1 = Airplane(140, 200, "Airbus A380", "Nikola Jokic" );
    Airplane a2 = Airplane(150, 250, "Airbus A321", "Jimmy Butler");
    Airplane a3 = Airplane(160, 300, "Boeing 747-400", "Damian Lillard");
    Airplane a4 = Airplane(170, 260, "Boeing 757", "Wesley Matthews");
    Airplane a5 = Airplane(180, 300, "Cessna 172", "Jamal Murray");
    Airplane a6 = Airplane(190, 240, "Airbus A319", "Devin Booker");
    Airplane a7 = Airplane(200, 300, "Embraer 190", "Kevin Durant");
    Airplane a8 = Airplane(210, 400, "Boeing 707", "LeBron James");
    
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
}