#include <iostream>
using namespace std;

enum{Not_found = -1};

// binary search
int binarySearch(int* tab, const int SIZE, const int key)
{
    int left = 0, right = SIZE - 1;
    int middle = 0;
    while(left < right){

        middle = (left + right) / 2;

        if(tab[middle] > key)  // if the sought value is smaller than the array's value
            right = middle - 1; // decrease array`s right border by one
        else if(tab[middle] < key) // if the sought value is greater than the array's value
            left = middle + 1; // increment array`s left border by one
        else return middle; // this is working when we found the sought value
    }

    return Not_found;
}

int main()
{
    const int _size = 10;
    int tab[_size];
    for(int i=0; i<_size; i++)
        tab[i] = i+1;

    cout << binarySearch(tab, _size, 5) << endl;

    return 0;
}
