#include <iostream>
using namespace std;

template <class T>
class Sorting
{
private:
    static T *Partition(T *start, T *end);

public:
    static void printArray(T *start, T *end)
    {
        int size = end - start;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }

    static void insertionSort(T *start, T *end);

    static void hybridQuickSort(T *start, T *end, int min_size);
};

template <class T>
T *Sorting<T>::Partition(T *start, T *end)
{
    // pivot (Element to be placed at right position)
    int i= 1;
    int j = end - start;
    T pivot = *start;
    T temp;

    while (i <= j)
    {
        while (start[i] <= pivot)
            i++;
        while (start[j] > pivot)
            j--;
        if (i <= j)
        {
            temp = start[i];
            start[i] = start[j];
            start[j] = temp;
            i++;
            j--;
        }
    }
    start[0] = start[j];
    start[j] = pivot;

    cout << "Quick sort: ";
    printArray(start, end);
    return &start[j];
}

template <class T>
void Sorting<T>::insertionSort(T *start, T *end)
{
    int n = end - start;
    int idx;
    T temp;
    for (int i = 1; i < n; i++)
    {
        idx = i;
        temp = start[idx];
        while (temp < start[idx - 1] && idx > 0)
        {
            start[idx] = start[idx - 1];
            idx--;
        }
        start[idx] = temp;
        cout << "Insertion sort: ";
        printArray(start, end);
    }
}

template <class T>
void Sorting<T>::hybridQuickSort(T *start, T *end, int min_size)
{
    if (end - start > 1)
    {
    if (end - start < min_size)
    {
        insertionSort(start, end);
    }
    else
    {
        if (start < end)
        {
            /* pi is partitioning index, arr[pi] is now
           at right place */
            T *pi = Partition(start, end);

            hybridQuickSort(start, pi - 1, min_size);  // Before pi
            hybridQuickSort(pi + 1, end, min_size); // After pi
        }
    }
}
}

int main()
{

   int array[] = {1, -10, 6, 4, 7, 8, 5, 3};
int min_size = 4;
Sorting<int>::hybridQuickSort(&array[0], &array[8], min_size);
Sorting<int>::printArray(&array[0], &array[8]);

    return 0;
}