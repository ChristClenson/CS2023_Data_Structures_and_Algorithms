#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

// partition function to divide the array into two halves
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// recursive quick sort function to sort the array
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
double findMedian(int arr[], int n) {
    quickSort(arr, 0, n-1);
    if (n % 2 == 0)
        return (double)(arr[n/2] + arr[n/2 - 1])/2;
    else
        return (double)arr[n/2];
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    
    // To get the input from the user
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    //To generate the random array
    /*
   for (int i = 0; i < n; i++) {
        arr[i] = rand() % 101 - 50; // generate a random number between 0 and 99
    }
   
    cout << "The random array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    */
   

    for (int i = 0; i < n; i++) {
        double median = findMedian(arr, i+1); 

        cout << "Sorted :" << " ";

        for (int j = 0; j <= i; j++) {
            cout << arr[j] << ", ";
        }

        cout << endl;

        cout << "The median : " << fixed << setprecision(1) << median << endl; 
    }
    return 0;
}
