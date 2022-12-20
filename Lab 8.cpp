/*
Data takes the form:
AAAA 1000.00 5
BBBB 2250.00 8
etc.
*/

#include <iostream>
#include <fstream>
using namespace std;

//structure with 3 data types
struct houseHolds {
    string ID;
    double income;
    int familySize;
};

void data2Array(ifstream& inData, houseHolds array[], int& numLines);
void avgHigher(houseHolds array[], int numLines);
double lowPoverty(houseHolds array[], int numLines);
void sortArray(houseHolds array[], houseHolds sortedArray[], int numLines);
double median(houseHolds sortedArray[], int numLines);
int main()
{
    ifstream inData;
    bool start = true;
    char userChoice = 'z';
    houseHolds array[50];
    houseHolds sortedArray[50];
    int numLines = 0;
    //Calling function to put data into arrays before opening menu
    data2Array(inData, array, numLines);
    //Calling function to create a sorted copy of the same array
    sortArray(array, sortedArray, numLines);


    while (start == true) {


        while (userChoice != 'a' && userChoice != 'A' && userChoice != 'b' && userChoice != 'B' && userChoice != 'c' && userChoice != 'C' && userChoice != 'd' && userChoice != 'D' && userChoice != 'e' && userChoice != 'E' && userChoice != 'f' && userChoice != 'F') {
            cout << "\n------------------------------------\nEnter an option: \nA: Print data \nB: Calculate average \nC: Determine percentage below poverty line \nD: Print data sorted by household income \nE: Calculate median household income \nF: Quit";
            cout << endl;
            cin >> userChoice;
            if (!cin) {
                cin.clear();
                cin.ignore(200, '\n');
            }
        }
        if (userChoice == 'a' || userChoice == 'A') {
            cout << "ID\tIncome\tFamily Size\n";
            for (int i = 0; i < numLines; i++) {
                cout << array[i].ID << "\t" << array[i].income << "\t" << array[i].familySize << endl;
            }
            userChoice = 'z';
        }
        else if (userChoice == 'b' || userChoice == 'B') {
            avgHigher(array, numLines);
            userChoice = 'z';
        }
        else if (userChoice == 'c' || userChoice == 'C') {
            cout << "\nPercentage of households below the poverty level: " << lowPoverty(array, numLines) << '%' << endl;
            userChoice = 'z';
        }
        else if (userChoice == 'd' || userChoice == 'D') {
            cout << "\nSorted:\nID\tIncome\tFamily Size\n";
            for (int i = 0; i < numLines; i++) {
                cout << sortedArray[i].ID << "\t" << sortedArray[i].income << "\t" << sortedArray[i].familySize << endl;
                userChoice = 'z';
            }
        }
        else if (userChoice == 'e' || userChoice == 'E') {
            cout << "\nMedian Income: $" << median(sortedArray, numLines) << endl;
            userChoice = 'z';
        }
        else if (userChoice == 'f' || userChoice == 'F') {
            cout << "Good bye.";
            start = false;
        }
    }
    return(0);
}



void data2Array(ifstream& inData, houseHolds array[], int& numLines) {
    inData.open("Data.txt");
    while (!inData.eof()) {
        inData >> array[numLines].ID;
        inData >> array[numLines].income;
        inData >> array[numLines].familySize;
        numLines++;
    }


}

void avgHigher(houseHolds array[], int numLines) {
    double avg = 0;
    for (int i = 0; i < numLines; i++) {
        avg += array[i].income;
    }
    avg = avg / numLines;
    cout << endl << "Average income: " << avg << endl;

    cout << "\nHouses with income higher than the average:\nID\tIncome\n";
    for (int i = 0; i < numLines; i++) {
        if (array[i].income > avg) {
            cout << array[i].ID << "\t" << array[i].income << endl;
        }
    }
}

double lowPoverty(houseHolds array[], int numLines) {
    double underPov = 0;
    for (int i = 0; i < numLines; i++) {
        if (array[i].income < (8000 + (500 * (array[i].familySize) - 2))) {
            underPov++;
        }
    }
    underPov = (underPov / numLines) * 100;
    return underPov;
}

void sortArray(houseHolds array[], houseHolds sortedArray[], int numLines) {
    int swap;
    houseHolds temp;
    //setting the sorted array equal to the regular array
    for (int i = 0; i < numLines; i++) {
        sortedArray[i] = array[i];
    }
    //Bubble sorting the sorted array
    do
    {
        swap = 0;
        for (int count = 0; count < numLines - 1; count++) {
            if (sortedArray[count].income > sortedArray[count + 1].income) {
                temp = sortedArray[count];
                sortedArray[count] = sortedArray[count + 1];
                sortedArray[count + 1] = temp;
                swap = 1;
            }
        }
    } while (swap != 0);
}

double median(houseHolds sortedArray[], int numLines) {
    double median;
    if (numLines % 2 == 0) {
        median = (sortedArray[(numLines - 1) / 2].income + sortedArray[numLines / 2].income) / 2.0;
    }
    else {
        median = sortedArray[numLines / 2].income;
    }
    return(median);
}