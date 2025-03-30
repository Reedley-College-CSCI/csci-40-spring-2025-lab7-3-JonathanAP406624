
//Jonathan Acosta

#include <iostream>
#include <fstream>
using namespace std;



// TODO: Step 1 - Define the struct TemperatureRecord
// It should contain two integer fields: day and temperature.
struct TemperatureRecord {
    int day;
    int temperature;

};


// Constants
const int MAX_DAYS = 31;

// Function Prototypes
void readTemperatures(TemperatureRecord tempDay [], int& size); // TODO: Fix the parameters
void printTemperatures(const TemperatureRecord tempDay[], int size);
TemperatureRecord findMin(const TemperatureRecord tempDay[], int size);
TemperatureRecord findMax(const TemperatureRecord tempDay[], int size);
double findAverage(const TemperatureRecord tempDay[], int size);

int main() {
    // TODO: Step 2 - Declare an array of TemperatureRecord structs (MAX_DAYS size)
    TemperatureRecord tempDays[MAX_DAYS]{};
    
    
    int size = 0;  // Actual number of records read

    // TODO: Step 3 - Call readTemperatures() to load data from file
    readTemperatures(tempDays, size);


    // TODO: Step 4 - Print the temperatures
    printTemperatures(tempDays, size);

    // TODO: Step 5 - Compute and display min, max, and average temperature
    TemperatureRecord minTemp = findMin(tempDays, size);
    TemperatureRecord maxTemp = findMax(tempDays, size);
    double avgTemp = findAverage(tempDays, size);

    cout << "Minimum Temperature was on Day " << minTemp.day << ": " << minTemp.temperature << " F" << endl;
    cout << "Maximum Temperature was on Day " << maxTemp.day << ": " << maxTemp.temperature << " F" << endl;
    cout << "Average Temperature for all: " << avgTemp << " F" << endl;

    return 0;
}

// TODO: Step 6 - Implement readTemperatures()
// Read from "temps.txt" and store data in the array
void readTemperatures(TemperatureRecord tempDay[], int& size) {

    fstream tempFS;
    tempFS.open("temps.txt");

    if (!tempFS) {  
        cout << "Error: Unable to open temps.txt" << endl;
        return;
    }

    while (size < MAX_DAYS && tempFS >> tempDay[size].day >> tempDay[size].temperature) {
        size++;
       
    }
    tempFS.close();
}

// TODO: Step 7 - Implement printTemperatures()
// Print all stored temperatures in a formatted table
void printTemperatures(const TemperatureRecord tempDay[], int size) {
    cout << "Day         Temperature" << endl;
    cout << "**************************" << endl;

    for (int i = 0; i < size; ++i) {
        cout << tempDay[i].day << "         " << tempDay[i].temperature << " F" << endl;

    }

}

// TODO: Step 8 - Implement findMin()
// Return the TemperatureRecord with the lowest temperature
TemperatureRecord findMin(const TemperatureRecord tempDay[], int size) {
    TemperatureRecord minRecord = tempDay[0];
    for (int i = 1; i < size; i++) {
        if (tempDay[i].temperature < minRecord.temperature) {
            minRecord = tempDay[i];
        }
    }
    return minRecord;
}

// TODO: Step 9 - Implement findMax()
// Return the TemperatureRecord with the highest temperature
TemperatureRecord findMax(const TemperatureRecord tempDay[], int size) {
    TemperatureRecord maxRecord = tempDay[0];
    for (int i = 1; i < size; i++) {
        if (tempDay[i].temperature > maxRecord.temperature) {
            maxRecord = tempDay[i];
        }
    }
    return maxRecord;
}

// TODO: Step 10 - Implement findAverage()
// Compute and return the average temperature
double findAverage(const TemperatureRecord tempDay[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += tempDay[i].temperature;
    }
    return (double)sum / size;
}
