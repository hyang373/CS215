/* 
 * Course: CS215-001
 * Project: Gradebook Determination -- Define class Gradebook
 * Purpose: Provide the declaration of the class named Gradebook
 *
 * Author: Helen Yang
*/

#include "Gradebook.h"
#include "FinalGrade.h"
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;


// default constructor
Gradebook::Gradebook(){
    vector<FinalGrade> scores;
}

// return the size of the  current vector: scores,
// which represents current gradebook
int Gradebook::getSize() const{
    return scores.size();
}

// insert a FinalGrade object, newFG, 
// into the end of the current gradebook
void Gradebook::insert(FinalGrade newFG){
    scores.push_back(newFG);
}

// return a FinalGrade object, 
// which holds the maximum score in the current gradebook
FinalGrade Gradebook::getMax() const{
    FinalGrade FG;

    double maxScore = 0;
	//maxScore = scores[0].getScore();
	for (int i = 0; i < scores.size(); i++)
	{
		if (scores[i].getScore() > maxScore) {
			maxScore = scores[i].getScore();
            FG = scores[i];
		}
	}

    return FG;
}

// return a FinalGrade object, 
// which holds the minimum score in the current gradebook
FinalGrade Gradebook::getMin() const{
    FinalGrade FG;

    double minScore = 0;
	minScore = scores[0].getScore();
	for (int i = 0; i < scores.size(); i++)
	{
		if (scores[i].getScore() < minScore) {
			minScore = scores[i].getScore();
            FG = scores[i];
		}
	}

    return FG;
}

// return the average score among all scores in the current gradebook
double Gradebook::getAverage() const{
    double avg_score = 0;
	double sum = 0;
	for (int i = 0; i < scores.size(); i++)
	{
		sum = sum + scores[i].getScore();
	}
	avg_score = sum / scores.size();
	return avg_score;
}

// For each FinalGrade object in the current gradebook, 
// its score will be increased by the given value 
// If the score reaches MAX_SCORE, it does not go beyond
void Gradebook::incrementScore(double value){
    for(int i = 0; i < scores.size(); i++)
    {
        if (scores[i].getScore() + value > MAX_SCORE)
        {
            scores[i] = MAX_SCORE;

        } 
        else
        {
            scores[i] = scores[i].getScore() + value;
        }
    }

}

// print the FinalGrade objects in the current gradebook
void Gradebook::print() const{
    for(int i = 0; i < scores.size(); i++)
    {
        scores[i].print();
    }
}
