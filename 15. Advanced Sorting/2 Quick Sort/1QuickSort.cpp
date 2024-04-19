// QUICK SORT

#include <iostream>
#include <algorithm>
using namespace std;
int partition(int arr[], int si, int ei)
{
    int pivotElement = arr[(si+ei)/2];
    int count = 0;
    for (int i = si; i <=ei; i++){
        if(i==(si+ei)/2) continue;
        if (arr[i] <= pivotElement) count++;
    }
    int pivotIdx = count + si;
    swap(arr[(si+ei)/2], arr[pivotIdx]);
    int i = si, j = ei;
    while (i < pivotIdx && j > pivotIdx) // ye wala section ye make sure krta hai hai ki pivot se left se usse chhote number rahe and pivot se right usse bade numb rahe
    {
        if (arr[i] <= pivotElement)   
            i++;
        if (arr[j] > pivotElement)
            j--;
        else if (arr[i] > pivotElement && arr[j] <= pivotElement)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return pivotIdx;
}

void quicksort(int arr[], int si, int ei)  
{
    // si= starting idx and ei= ending idx
    if (si >= ei)
        return; // base case
    int pi = partition(arr, si, ei); //ye pivot element nikalta hai                                      

    // 4,1,3,2,5,7,6,3,4
    quicksort(arr, si, pi - 1);
    quicksort(arr, pi + 1, ei);
}
int main()
{
    int arr[] = {5, 1, 8, 2, 7, 6, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    quicksort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}