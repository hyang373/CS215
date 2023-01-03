/* 
 * Course: CS215-001
 * Project: Final Grade Determination -- Define class FinalGrade
 * Purpose: Provide the declaration of the class named FinalGrade
 *
 * Author: Helen Yang
 */

#include "FinalGrade.h"
#include <iomanip>
#include <iostream>
using namespace std;

// default constructor
FinalGrade::FinalGrade() {
	score = 0;
}

// constructor: give the initial value to the private data member score 
// to pass-in parameter in_score
FinalGrade::FinalGrade(double in_score) {
	score = in_score;
}

// set the private data member: score
// to pass-in parameter in_score
void FinalGrade::setScore(double in_score) {
	score = in_score;
}

// return the value of the data member: score
double FinalGrade::getScore() const {
	return score;
}

// return the corresponding letter grade from score
// based on the grading policy in CS216 syllabus
char FinalGrade::decideLetterGrade() const {
	if (score >= 90)
		return 'A';
	else if (score >= 80)
		return 'B';
	else if(score >= 70)
		return 'C';
	else if (score >= 60)
		return 'D';
	else
		return 'E';
}


// print the score and letter grade in the format: (for example)
// Score: 88.00        Letter Grade: B
void FinalGrade::print() const {
	cout << "Score: " << setprecision(2) << score << "        Letter Grade: " << decideLetterGrade() << endl;
}
