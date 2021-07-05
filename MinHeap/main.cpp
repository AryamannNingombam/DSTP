#include <iostream>
#include <vector>
#include "MinHeap.h"

using namespace std;

template <typename T>
ostream &operator<<(ostream &os, const MinHeap<T> &t)
{
    vector<T> nodes = t.getNodes();
    for (int i = 1; i < t.size() + 1; i++)
    {
        os << nodes[i] << ' ';
    }

    return os;
}

int main()
{
    int size;
    cout << "Enter the size of the heap : ";
    cin >> size;
    MinHeap newHeap = MinHeap<int>();
    int temp;
    cout << "Enter the elements : ";
    for (int i = 0; i < size; i++)
    {
        cin >> temp;
        newHeap.push(temp);
     }

    cout << "Size of the heap : " << newHeap << '\n';
    cout << "Displaying the elements : " << newHeap << '\n';

    int numberToInsert;
    cout << "Enter the number to insert : ";
    cin >> numberToInsert;
    newHeap.push(numberToInsert);
    cout << "Entering....\n";
    cout << "Size of the heap : " << newHeap.size() << '\n';
    cout << "Displaying the elements : " << newHeap << '\n';

    cout << "Popping the min element...\n";
    temp = newHeap.pop();
    cout << "Popped element : " << temp << '\n';

    cout << "Size of the heap : " << newHeap << '\n';
    cout << "Displaying the elements : " << newHeap << '\n';

    return 0;
}