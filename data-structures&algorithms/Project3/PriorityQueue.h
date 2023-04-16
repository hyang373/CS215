#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class PriorityQueue
{
        public:
                PriorityQueue();
                void insert(pair<string, int> info);
                pair<string, int> extractMin();
                void decreasekey(int element_index, pair<string, int> info);


        private:
                // a variable to store the data
                vector<pair<string to, int distance>> heap;
                void min_heapify(int index);
                int parent(int i);
                int Left(int i);
                int Right(int i);
                void swap(int index1, int index2);
}

#endif /* PRIORITYQUEUE_H */
