/* Problem Set 3
 * Course: Algorithms and Analysis
 * Due: April 11th, 2023
 * Author: Helen Yang
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <queue>
#include "graph.h"
#include "PriorityQueue.h"
using namespace std;

int main(int argc, char* argv[])
{
        if(argc != 3){
                cout << "Usage: " << argv[0] << " <file_name1> "<< "<file_name2> "<<endl;
                return 1;
        }

        // ask user which file is the edges and which is the vertices data
        int file_edges;
        int file_vertices;

        do{
                cout << "Which file contain vertices data (list of name of cities)?" << endl;
                cout << "If its the 1st file, enter 1. If its the 2nd file, enter 2." << endl;
                cin >> file_vertices;
        }while((file_vertices != 1) && (file_vertices != 2));

        if(file_vertices == 1){
                file_edges = 2;
        }
        else{
                file_edges = 1;
        }

        /**************************************************************************************/
        // obtain the vertices data
        // file pointer
        ifstream vertices_file;

        // opens the csv file
        vertices_file.open(argv[file_vertices]);

        // check whether the input file can be open successfully or not
        if(!vertices_file.good()){
                cout << "Warning: cannot open file named " << argv[vertices_file] << "!" << endl;
                return 2;
        }

        // declare a variable to store the data from csv #1
        vector<string> cities;

        string line= "";

        // import data from csv into 'cities'
        // while its not the end of file
        while(getline(vertices_file, line)){
                string v;
                string tempString = "";
                stringstream inputString(line);

                // read each data
                getline(inputString, tempString);
                v = tempString;

                // insert number into data
                cities.push_back(v);

        }
        vertices_file.close();
        /**************************************************************************/
        // obtain the weighted edges
        // file pointer
        ifstream edges_file;

        // opens the csv file
        edges_file.open(argv[file_edges]);

        // check whether the input file can be open successfully or not
        if(!edges_file.good()){
                cout << "Warning: cannot open file named " << argv[file_edges] << "!" << endl;
                return 2;
        }

        // declare a variable to store the data
        Graph g;

        string line= "";

        // import data from csv into 'cities'
        // while its not the end of file
        while(getline(vertices_file, line)){
                Edge* info;
                string tempString = "";
                stringstream inputString(line);

                // read each data
                getline(inputString, tempString, ',');
                info->from->name = tempString;

                tempString = ""; // clear tempString
                getline(inputString, tempString, ',');
                info->to->name = tempString;

                tempString = "";
                getline(inputString, tempString);
                info->distance = atoi(tempString.c_str());

                // insert number into data
                g.addEdge(info);

        }
        edges_file.close();
        /************************** BFS ******************************/
        // implement the PRINT-PATH method
        // print out shortest path from "Arad to Sibiu", "Arad to Craiova", "Arad to Bucharest"
        string from = "Arad";
        g.BFS(from);

        string to = "Sibiu";
        g.print_path(from,to);

        to = "Craiova";
        g.print_path(from, to);

        to = "Bucharest";
        g.print_path(from, to);

        /********************* Dikstra **********************************/

}
