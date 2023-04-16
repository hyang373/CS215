#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <limits>
using namespace std;

struct Edge {
        Vertex* from;
        Vertex* to;
        int distance;
};

struct Vertex {
        string name;

        Color color;
        int discovery;
        Vertex* parent;

        int finish;
};

enum Color {
        WHITE, GREY, BLACK
};

class Graph
{
        public:
                // default constructor
                Graph();

                // to add an edge beween v and w to the graph
                void addEdge(Edge* edge);

                // implement BFS
                void BFS(Vertex* source);

        private:
                map<Vertex*, list<pair<Vertex*, int>>> adjList;


};

#endif   /* GRAPH_H */
