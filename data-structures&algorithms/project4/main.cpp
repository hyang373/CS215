#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cstring>
using namespace std;

void LCS(char *X, char *Y, int m, int n){
        /* "Construct the LCS Matrix and Compute LCS Length*/
        int table[m+1][n+1];

        for(int i = 0; i <= m; i++){
                for(int j = 0; j <= n; j++){
                        if((i==0)||(j==0)){
                                table[i][j] = 0;
                        }
                        else if(X[i-1] == Y[j-1]){
                                table[i][j] = table[i-1][j-1] +1;
                        }
                        else{
                                table[i][j] = max(table[i-1][j], table[i][j-1]);
                        }
                }
        }

        cout << "LCS Length: " << table[m][n] << endl;

        /* "Reconstruct the LCS PRINT-LCS"*/
        int index = table[m][n];
        char result[index+1];
        result[index] = '\0';

        int i = m;
        int j = n;

        while(i > 0 && j > 0){
                if(X[i-1]==Y[j-1]){
                        result[index - 1] = X[i-1];
                        i--;
                        j--;
                        index--;
                }
                else if(table[i-1][j] > table[i][j-1]){
                        i--;
                }
                else{
                        j--;
                }
        }
        cout << "S1 : " << X << "\nS2 : " << Y << endl;
        cout << "LCS: " << result << endl;

}

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

        string s1;
        string s2;
        int m;
        int n;
        int count = 0;

        string line= "";

        //import data from csv into 'data'
        // while its not the end of file
        while(getline(in_file, line)){
                // make sure that there is nothing in the vector
                string str;
                string tempString = "";
                stringstream inputString(line);

                // read each column data of a row
                getline(inputString, tempString);
                str = tempString;

                // turn string into an array of chars
                if(count == 0){
                        s1 = str;
                        m = str.length();
                }
                else if(count == 1){
                        s2 = str;
                        n = str.length();
                }

                count++;

        }

        in_file.close();

        // turn string to arr of char
        char *str1 = new char[m + 1];
        char *str2 = new char[n + 1];
        strcpy(str1, s1.c_str());
        strcpy(str2, s2.c_str());

        LCS(str1, str2, m, n);


}
