#pragma once

#include <iostream>
#include <vector>
#include <cmath>

template <typename T>
class MinHeap
{

private:
    std::vector<T> nodes;
    int currentIndex;

public:
    std::vector<T> getNodes() const
    {
        return this->nodes;
    }
    MinHeap()
    {
        this->nodes = {-1};
        this->currentIndex = 0;
    };
    MinHeap(const std::vector<T> &n)
    {
        this->nodes = n;
        this->currentIndex = n.size();
    }
    MinHeap(const int &i)
    {
        this->nodes = std::vector<T>(i);
        this->currentIndex = 1;
    }
    int parent(int n)
    {
        return n / 2;
    }
    int leftChild(int n)
    {
        return n * 2;
    }
    int rightChild(int n)
    {
        return n * 2 + 1;
    }
    void swap(T &a, T &b)
    {
        T temp = a;
        a = b;
        b = temp;
        return;
    }

    T pop()
    {
        if (this->currentIndex == 1)
        {
            throw std::runtime_error("Empty heap!");
        };

        T returningData = this->nodes[1];

        T temp = this->nodes[this->currentIndex];
        this->nodes[1] = temp;
        this->nodes.pop_back();
        this->currentIndex--;
        this->heapifyDown(1);
        return returningData;
    }

    void push(T data)
    {

        this->nodes.push_back(data);
        this->currentIndex++;

        this->heapifyUp(this->currentIndex);
    };
    int size() const
    {
        return this->currentIndex;
    }

    void heapifyUp(int index)
    {
        if (index == 1)
            return;
        int parentIndex = this->parent(index);
        if (this->nodes[parentIndex] > this->nodes[index])
        {

            swap(this->nodes[parentIndex], this->nodes[index]);
            this->heapifyUp(parentIndex);
        };
    };

    void heapifyDown(int index)
    {
        int leftChildIndex = this->leftChild(index);
        int rightChildIndex = this->rightChild(index);
        int childIndex = ((this->nodes[leftChildIndex] > this->nodes[rightChildIndex])
                              ? rightChildIndex
                              : leftChildIndex);

        if (this->nodes[childIndex] < this->nodes[index])
        {
            swap(this->nodes[childIndex], this->nodes[index]);
            this->heapifyDown(childIndex);
        }
    }
};