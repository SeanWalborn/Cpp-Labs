/* 
Lab: 11 Problem 03 
Name: Sean Walborn 
ID: 10763229
Submission Date: 10/07/25
*/

#include <iostream>
#include <iomanip>

using namespace std;

class Student{
    public: 
        // constructors
        Student();
        Student(string n, int g);

        // setters
        void setName(string n);
        void setGrade(int g);

        // getters
        string getName();
        int getGrade();

        //operators


    private:
        string name;
        int grade;

};

class HS_Student : public Student{
    public:
        //constructors
        HS_Student();
        HS_Student(string n, int s, int e, int m);

        //setters
        void setEnglishScore(int e);
        void setMathScore(int m);
        
        //getters
        int getEnglishScore ();
        int getMathScore();

    private:
        int englishScore;
        int mathScore;
};

// helper funcitons
HS_Student englishHighScore(HS_Student, HS_Student);
HS_Student mathHighScore(HS_Student, HS_Student);

int main(){
    HS_Student alice("Alice Smith", 9, 80, 90);
    HS_Student paul("Paul Bauer", 10, 88, 85);
    HS_Student highMathScore;
    HS_Student highEnglishScore;
    
    // finidng math and english high scores
    highMathScore = mathHighScore(alice, paul);
    highEnglishScore = englishHighScore(alice, paul);


    cout << "Person with the higher english score : "<< highEnglishScore.getName() << endl;
    cout << "Person with the higher math score    : " << highMathScore.getName() << endl;
    
}

// student functions defined
Student :: Student() : name("empty"), grade(0){}
Student :: Student(string n, int g) : name(n), grade(g) {}

void Student :: setName(string n){
    name = n;
}
void Student :: setGrade(int g){
    grade = g;
}

string Student :: getName(){
    return name;
}
int Student :: getGrade(){
    return grade;
}


// HS_Student functions defined
HS_Student :: HS_Student(): Student(), mathScore(0), englishScore(0){}
HS_Student :: HS_Student(string n, int g, int e, int m) : Student(n, g), englishScore(e), mathScore(m){}

void HS_Student :: setEnglishScore(int e){
    englishScore = e;
}
void HS_Student :: setMathScore(int m){
    mathScore = m;
}

int HS_Student :: getEnglishScore(){
    return englishScore;
}
int HS_Student :: getMathScore(){
    return mathScore;
}


// helper funcions
HS_Student englishHighScore(HS_Student s1, HS_Student s2){
    if (s1.getEnglishScore()> s2.getEnglishScore()){
        return s1;
    }else{
        return s2;
    }
}
HS_Student mathHighScore(HS_Student s1, HS_Student s2){
    if (s1.getMathScore() > s2.getMathScore()){
        return s1;
    }else{
        return s2;
    }
}
