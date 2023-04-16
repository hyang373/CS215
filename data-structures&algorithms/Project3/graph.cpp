/* file: graph.cpp
 * course: cs 315
 * project: problem set 2
 * purpose: declaration of graph class
 * */

#include <iostream>
#include <map>
#include <list>
#include <utility>
#include <limits>
#include "graph.h"
using namespace std;

// default constructor
Graph::Graph()
{
        // do nothing
}

// to add an edge beween v and w to the graph
void Graph::addEdge(Edge* edge)
{
        adjList[edge->from].push_back({edge->to, edge->distance});
        adjList[edge->to].push_back({edge->from, edge->distance});
}

// implement BFS
void Graph::BFS(Vertex* source)
{
        const int INFINITY = std::numeric_limits<int>::max();
        // initialize all vertices as unvisited
        for(auto i = adjList.begin(); i != adjList.end(); i++){
                i->first->color = WHITE;
                i->first->discovery = INFINITY;
                i->first->parent = nullptr;
        }

        // set source vertex as visited and add to queue
        source->color = GRAY;
        source->discovery = 0;
        source->parent = nullptr;
        queue<Vertex*> q;
        q.push(source);

        // travers graph
        while(!q.empty()){
                auto u = q.front();
                q.pop();
                for(auto& adjV : adjList[u]){
                        Vertex* v = adjV.first;
                        if(v->color == WHITE){
                                v->color = GRAY;
                                v->discovery = u->discovery + 1;
                                v->parent = u;
                                q.push(v);
                        }
                }
                u->color = BLACK;
        }


}

void Graph::print_path(string from, string to)
{
        Vertex* fromV = nullptr;
        Vertex* toV = nullptr;

        // find the vertices with the given name
        for(auto p = adjList.begin(); p != adjList.end(); p++){
                if(p.first->name == from){
                        fromV = p.first;
                }
                if(p.first->name == to){
                        toV = p.first;
                }
        }

        if(toV == fromV){
                cout << fromV->name << endl;
        }
        else if(toV->parernt == nullptr){
                cout << "No path from " << from << " to " << to << " exists." << endl;
        }
        else{
                print_path(from, to->parent->name);
                cout << toV->name << endl;
        }
}
