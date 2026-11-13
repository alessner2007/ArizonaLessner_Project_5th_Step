//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                          //
// Final project for CLC's CIT 141                                                                          //
// Starter Code: Solution to Exercise 8.15                                                                  //
// Step 1: Lower the number of comparisons from 16,250 to 1,600                                             //
// Step 2: Modify your solution to display number of comparisons done in the selection sort (10/26/26)      // 
// Step 3: Modify your program to randomly generate 50 ints and store them in the array list (10/28/26)     //    
// Step 4: Count Swaps (in addition to comparisons performed in selectionSort) (11/09/26)                  //
// Step 5: Time the sort function with different array sizes                                                //
// Author; Arizona Lessner                                                                                  //
// Date: 10/21/2026                                                                                         //
//                                                                                                          //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
   10 17 23 65 34 6 18 27 35 110 75 25 100 24 19 67 45 88 70 96 41 36 72 150 125 25 77
   200 90 166 139 55 31 8 29 119 126 137 34 62 135 121 108 197 45 35 24 1 16 43
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <chrono>

using namespace std;

struct sortStats
{
    int comparisons;
    int swaps;
};

sortStats selectionSort(int list[], int length);
bool arraySorted(int list[], int length);
void timeSelectionSort(int length);

int main()
{
    const int LIST_SIZE = 50;

    int list[LIST_SIZE];

    // Generate random integers
    srand(time(0));

    for (int i = 0; i < LIST_SIZE; i++)
        list[i] = rand() % 100 + 1;

    //
    // Variable used to count # of time if statement is performed
    // when the number of ints is 50
    //
    int count = 0;

    for (int i = 0; i < LIST_SIZE; i++)
    {
        for (int j = i + 1; j < LIST_SIZE; j++)
        {
            count++;
        }
    }

    cout << "Number of times the if-statement was performed with 50 ints: "
         << count * 16 << endl;

    cout << "Array list is in ascending order? "
         << boolalpha << arraySorted(list, LIST_SIZE) << endl;

    // call the sorting algorithm
    sortStats result = selectionSort(list, LIST_SIZE);

    cout << "Array list is in ascending order? "
         << arraySorted(list, LIST_SIZE) << endl;

    cout << "Comparisons performed in selection sort "
         << result.comparisons << endl;

    cout << "Swaps performed in selection sort "
         << result.swaps << endl;

    // Step 5: Time the sort function

    cout << endl;
    cout << "Selection Sort Timing Results" << endl;

    timeSelectionSort(50);
    timeSelectionSort(500);
    timeSelectionSort(5000);
    timeSelectionSort(50000);
    timeSelectionSort(500000);

    return 0;
}

// Selection sort function
sortStats selectionSort(int list[], int length)
{
    sortStats result;
    result.comparisons = 0;
    result.swaps = 0;

    for (int i = 0; i < length - 1; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            result.comparisons++;

            if (list[i] > list[j])
            {
                swap(list[i], list[j]);
                result.swaps++;
            }
        }
    }

    return result;
}

// This function is used to check if the array is in ascending order
bool arraySorted(int list[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        if (list[i] > list[i + 1])
            return false;
    }

    return true;
}

// Step 5: Function used to time selection sort
void timeSelectionSort(int length)
{
    int* list = new int[length];

    // Generate random integers
    for (int i = 0; i < length; i++)
        list[i] = rand() % 100 + 1;

    // Start timing
    auto start = chrono::high_resolution_clock::now();

    // Call selection sort
    selectionSort(list, length);

    // Stop timing
    auto stop = chrono::high_resolution_clock::now();

    // Calculate elapsed time
    chrono::duration<double> elapsed = stop - start;

    cout << "Time to sort " << length << " ints: "
         << elapsed.count() << " seconds" << endl;

    delete[] list;
}