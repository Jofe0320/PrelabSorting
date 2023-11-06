#include "Airplane.h"

Airplane binarySearchHelper(vector<Airplane> airplanes, int givenCapacity, int frontIndex, int backIndex)
{
    if (frontIndex > backIndex)
    {
        return Airplane(250, 450, "Boeing 777", "Anthony Edwards"); // Airplane(int capacity, int velocity, string model, string pilotName);
    }

    int middleIndex = (frontIndex + backIndex) / 2;
    if (airplanes[middleIndex].getCapacity() == givenCapacity)
    {
        return airplanes[middleIndex];
    }
    else if (airplanes[middleIndex].getCapacity() > givenCapacity)
    {
        // search to the left
        return binarySearchHelper(airplanes, givenCapacity, frontIndex, middleIndex - 1);
    }
    else
    {
        return binarySearchHelper(airplanes, givenCapacity, middleIndex + 1, backIndex);
    }
}

Airplane Airplane::binarySearch(vector<Airplane> airplanes, int givenCapacity)
{

    return binarySearchHelper(airplanes, givenCapacity, 0, airplanes.size() - 1);
}

/**
 *  Implement the searchMatrix function where you are given a matrix (you cannot assume that it's a square Matrix!)
 *  and you must search for a given pilotName and return a vector of two integers
 *  where the first integer is the row Index and the second integer is the column Index.
 *
 *  The following example is assuming we are searching through a matrix of INTEGERS (in the exercise we are searching through
 *  a vector of Airplanes)
 *
 *  matrix = [ [1, 2, 3, 4],
 *              [5, 6],
 *              [7, 8, 9, 10, 11]
 *            ]
 *
 *  if we search for the integer 7 then the funciton should return a vector with the integers: { 2, 0 }
 *
 */
vector<int> Airplane::searchMatrix(vector<vector<Airplane>> airplaneMatrix, string pilotName)
{
    // you cannot assume that it's a square matrix

    for (int row = 0; row < airplaneMatrix.size(); row++)
    {
        for (int col = 0; col < airplaneMatrix[row].size(); col++)
        {
            Airplane currentAirplane = airplaneMatrix[row][col];
            if (pilotName == currentAirplane.getPilotName())
            {
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

int main()
{

    Airplane a1 = Airplane(140, 200, "Airbus A380", "Nikola Jokic");
    Airplane a2 = Airplane(150, 250, "Airbus A321", "Jimmy Butler");
    Airplane a3 = Airplane(160, 300, "Boeing 747-400", "Damian Lillard");
    Airplane a4 = Airplane(170, 260, "Boeing 757", "Wesley Matthews");
    Airplane a5 = Airplane(180, 300, "Cessna 172", "Jamal Murray");
    Airplane a6 = Airplane(190, 240, "Airbus A319", "Devin Booker");
    Airplane a7 = Airplane(200, 300, "Embraer 190", "Kevin Durant");
    Airplane a8 = Airplane(210, 400, "Boeing 707", "LeBron James");
    Airplane a9 = Airplane(220, 450, "Random Plane Name", "Tyrese Haliburton");
    Airplane a10 = Airplane(230, 500, "Douglas DC-3", "Robert Oppenheimer");

    // testCases searchMatrix
    vector<vector<Airplane>> matrix1 = {{a1, a2, a3, a4},
                                        {a5, a6},
                                        {a8, a9, a10},
                                        {}, // empty vector
                                        {a7}};

    showIntVector(Airplane::searchMatrix(matrix1, "LeBron James")); // {2, 0}
    showIntVector(Airplane::searchMatrix(matrix1, "Kevin Durant")); // {4, 0}
    showIntVector(Airplane::searchMatrix(matrix1, "Jamal Murray")); // 
    showIntVector(Airplane::searchMatrix(matrix1, "Tobias Harris")); // not found! {-1, -1}

    // testCases Binary Search

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