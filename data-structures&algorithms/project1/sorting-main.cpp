/*
 * Project: Programming Assignment 1
 * Course: CS 315 - 001
 * Due: Febrary 14, 2023 11:59 PM
 * Author: Helen Yang
 * Purpose:
 *
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

void insertion_sort(vector<vector<int>>& test);
void merge_sort(vector<vector<int>>& test, int begin, int end);
void merge(vector<vector<int>>& test, int begin, int end, int middle);
void quick_sort(vector<vector<int>>& test, int p, int r);
int partition(vector<vector<int>>& test, int p, int r);

int NUM_COMPARE = 0;

int main(int argc, char* argv[]){

        if(argc != 2){
                cout << "Usage: " << argv[0] << " <file_name> "<< endl;
                return 1;
        }

        // file pointer
        ifstream in_file;

        // opens the csv file
        in_file.open(argv[1]);

        // check whether the input file can be open successfully or not
        if(!in_file.good()){
                cout << "Warning: cannot open file named " << argv[1] << "!" << endl;
                return 2;
        }

        // declare a variable to store the data from csv in
        // [row 1, row 2, row 3, .... , row n]
        vector<vector<int>> data;

        // create a variable for data in the rows
        vector<int> row;
        string line= "";

        //import data from csv into 'data'
        // while its not the end of file
        while(getline(in_file, line)){
                // make sure that there is nothing in the vector
                row.clear();
                int number_1;
                int number_2;
                string tempString = "";
                //line = "";

                stringstream inputString(line);

                // read each column data of a row
                // column 1 value = number_1
                // column 2 value = number_2
                getline(inputString, tempString, ',');
                number_1 = atoi(tempString.c_str());

                tempString = ""; // clear tempString
                getline(inputString, tempString);
                number_2 = atoi(tempString.c_str());

                //obtain the individual datas and insert it into the vector 'row'
                row.push_back(number_1);
                row.push_back(number_2);

                // insert row into data
                data.push_back(row);

        }

        in_file.close();

        // sort vector<vector<int>>
        // ask what sorting algo do they want to use?
        string input;
        while(true){
                do{
                        // continue asking
                        cout << "Which sorting algorithm would you like to use to sort " << argv[1] << "?" << endl;
                        cout << "('quicksort', 'insertion_sort', or 'merge_sort')" << endl;
                        cout << "Enter 'Q' or 'q' to exit the program." << endl;
                        cin >> input;
                        cout << endl;
                }while((input != "quicksort") && (input != "insertion_sort") && (input != "merge_sort") && (input != "q") && (input != "Q"));


                if((input == "Q") || (input == "q")){
                        return 0;
                }
                // print the before sorted version
                cout << "Before Sorted: " << endl;
                for(int i = 0; i < data.size(); i++){
                        cout << data[i][0] << ", " << data[i][1] << endl;
                }
                cout << endl;

                if(input == "quicksort"){
                        NUM_COMPARE = 0;
                        int end = data.size() - 1;
                        quick_sort(data, 0, end);
                }
                else if(input == "insertion_sort"){
                        NUM_COMPARE = 0;
                        insertion_sort(data);
                }
                else{
                        NUM_COMPARE = 0;
                        // merge sort
                        int end = data.size() - 1;
                        merge_sort(data, 0, end);
                }

                // print data
                cout << "After sorted with " << input << " algorithm." << endl;
                for(int i = 0; i < data.size(); i++){
                        cout << data[i][0] << ", " << data[i][1] << endl;
                }

                cout << endl;
                cout << argv[1] << " is now sorted using " << input << "." << endl;
                cout << "There was: " << NUM_COMPARE << " comparasions." << endl;
                cout << endl;

        }

}

void insertion_sort(vector<vector<int>>& test){
        int i;
        vector<int> key;
        int col_pos = 1;

        // go through data
        for(int j = 1; j < test.size(); j++){
                key = test[j];
                i = j - 1;
                while((i > 0) && (test[i][col_pos] > key[col_pos]) || ((test[i][col_pos] == key[col_pos]) && (test[i][0] > key[0]))){
                        test[i+1] = test[i];
                        i = i - 1;
                        NUM_COMPARE++;
                }
                NUM_COMPARE++;
                test[i+1] = key;
        }
}
void merge_sort(vector<vector<int>>& test, int begin, int end){
        if(begin < end){
                int middle = floor((begin+end)/2);
                merge_sort(test, begin, middle);
                merge_sort(test, middle + 1, end);
                merge(test, begin, end, middle);
        }
}
void merge(vector<vector<int>>& test, int begin, int end, int middle){
        int i = 0, j = 0, n1, n2;
        int col_pos = 1;

        // create auxiliary vectors
        vector<vector<int>> left;
        vector<vector<int>> right;

        n1 = middle - begin + 1;
        n2 = end - middle;

        left.resize(n1);
        right.resize(n2);

        // populate aux vectors
        for(i = 0; i < n1; i++){
                left[i] = test[begin + i];
        }
        for(j = 0; j < n2; j++){
                right[j] = test[middle + j +1];
        }

        i = 0;
        j = 0;

        // merge vectors back together
        for(int k = begin; k <= end; k++){
                if(i < n1 && j < n2){
                        if(left[i][col_pos] < right[j][col_pos]){
                                test[k] = left[i];
                                i = i + 1;
                                NUM_COMPARE++;
                        }
                        else if(left[i][col_pos] == right[j][col_pos]){
                                // values are the same
                                // then check value in column 1
                                if(left[i][0] < right[j][0]){
                                        test[k] = left[i];
                                        i = i + 1;
                                        NUM_COMPARE++;
                                }
                                else{
                                        test[k] = right[j];
                                        j = j + 1;
                                        NUM_COMPARE++;
                                }
                        }
                        else{
                                test[k] = right[j];
                                j = j + 1;
                                NUM_COMPARE++;
                        }
                }
                else if(i < n1){
                        // merge remaining elements of left vector
                        test[k] = left[i];
                        i = i+ 1;
                        NUM_COMPARE++;
                }
                else{
                        // copy remaining elements of right vector
                        test[k] = right[j];
                        j = j + 1;
                        NUM_COMPARE++;
                }
        }
}
void quick_sort(vector<vector<int>>& test, int p, int r){
        if(p < r){
                //NUM_COMPARE++;
                int q = partition(test, p, r);
                quick_sort(test, p, q - 1);
                quick_sort(test, q + 1, r);
        }
}
int partition(vector<vector<int>>& test, int p, int r){
        vector<int> x = test[r];
        int i = p - 1;
        int col_pos = 1;
        for(int j = p; j < r; j++){
                NUM_COMPARE++;
                if(test[j][col_pos] < x[col_pos]){
                        i = i + 1;
                        // swap test[i] and test[j]
                        vector<int> temp = test[i];
                        test[i] = test[j];
                        test[j] = temp;
                }
                else if(test[j][col_pos] == x[col_pos]){
                        NUM_COMPARE++;
                        if(test[j][0] < x[0]){
                                i = i + 1;
                                // swap test[i] and test[j]
                                vector<int> temp = test[i];
                                test[i] = test[j];
                                test[j] = temp;
                        }
                }
        }
        vector<int> temp = test[i+1];
        test[i+1] = test[r];
        test[r] = temp;
        return i + 1;

}
