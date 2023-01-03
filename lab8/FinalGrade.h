class FinalGrade 
{ 
  public: 
    // default constructor 
    FinalGrade(); 
 
    // constructor: give the initial value to the private data member: score  
    // from pass-in parameter in_score 
    FinalGrade(double in_score); 
 
    // set the private data member: score 
    // to pass-in parameter in_score 
    void setScore(double in_score); 
 
    // return the current value of the data member: score 
    double getScore() const; 
 
    // return the corresponding letter grade from score 
    // based on the grading policy in CS215 syllabus 
    char decideLetterGrade() const; 
 
    // print the score and letter grade in the format: (for example score is 88) 
    // Score: 88.00  Letter Grade: B 
    void print() const; 
 
  private: 
    double score;  // it represents the final score of a student 
};
