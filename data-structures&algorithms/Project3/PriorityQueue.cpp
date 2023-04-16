/* File : PriorityQueue.cpp
 * Author : Helen Yang
 * Date : 04/14/2023
 */

#include <iostream>
#include <vector>
#include <stdexcept>
#include "PriorityQueue.h"
using namespace std;

PriorityQueue::PriorityQueue()
{
        // do nothing
}

void PriorityQueue::insert(pair<string,int> info)
{
        heap.push_back(info);
        int index = heap.size() - 1;
        // increase key
        while((index > 0) && (heap[index].second < heap[parent(index)].second)){
                swap(index, parent(index));
                index = parent(index);
        }
}

// helper functions: "int parent(int index);" and "void swap(pair1, pair2);"

pair<string, int> PriorityQueue::extractMin()
{
        if(heap.size() < 1){
                throw std::runtime_error("heap underflow");
        }
        pair<string, int> min = heap[0];
        heap.pop_back();
        min_heapify(0);
        return min;


}

void PriorityQueue::decreasekey(int element_index, pair<string, int> info)
{
        heap[element_index] = info;
        int index = element_index;
        while ((index > 0) && (heap[index].second < heap[parent(index)].second)){
                swap(index, parent(index));
                index = parent(index);
    }
}

/*private:
     vector<pair<string to, int distance>> heap;
*/

void PriorityQueue::min_heapify(int index)
{
        int left_index = Left(index);
        int right_index = Right(index);
        int smallest;
        if((left_index <= heap.size())&&(heap[left_index].second < heap[index].second)){
                smallest = left_index;
        }
        else{
                smallest = index;
        }
        if((right_index <= heap.size())&&(heap[right_index].second < heap[smallest].second)){
                smallest = right_index;
        }
        if(smallest != index){
                swap(index, smallest);
                min_heapify(smallest);
        }
}
// helper functions : "int Left(int i)", "int Right(int i)", "swap(pair1, pair2)"
// "int parent(int index);" and "void swap(pair1, pair2);
int PriorityQueue::parent(int i)
{
        return (i-1)/2;
}

int PriorityQueue::Left(int i)
{
        return (2*i)+1;
}
int PriorityQueue::Right(int i)
{
        return (2*i)+2;
}
void PriorityQueue::swap(int index1 , int index2)
{
        pair<string, int> temp = heap[index1];
        heap[index1] = heap[index2];
        heap[index2] = temp;
}
