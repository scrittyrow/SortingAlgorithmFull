
//DISPLAY 7.14 Two-Dimensional Array
//Reads 3 quiz scores for each student into the two-dimensional array grade (but
//the input code is not shown in this display). Computes the average score
//for each student and the average score for each quiz. Displays the quiz scores
//and the averages.
//#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
const int NUMBER_STUDENTS = 4, NUMBER_QUIZZES = 3;
//Precondition: Global constants NUMBER_STUDENTS and NUMBER_QUIZZES
//are the dimensions of the array grade. Each of the indexed variables
//grade[stNum-1, quizNum-1] contains the score for student stNum on quiz
//quizNum.
int loadArray(int grade[][NUMBER_QUIZZES]);
//int loadFromFile(int myGrade[][NUMBER_QUIZZES]);

void computeStAve(const int grade[][NUMBER_QUIZZES], double stAve[]);
//Precondition: Global constants NUMBER_STUDENTS and NUMBER_QUIZZES
//are the dimensions of the array grade. Each of the indexed variables
//grade[stNum-1, quizNum-1] contains the score for student stNum on quiz
//quizNum.
//Postcondition: Each stAve[stNum-1] contains the average for student
//number stu_num.


void computeQuizAve(const int grade[][NUMBER_QUIZZES], double quizAve[]);
//Precondition: Global constants NUMBER_STUDENTS and NUMBER_QUIZZES
//are the dimensions of the array grade. Each of the indexed variables
//grade[stNum-1, quizNum-1] contains the score for student stNum on quiz
//quizNum.
//Postcondition: Each quizAve[quizNum-1] contains the average for quiz number
//quizNum.


void display(const int grade[][NUMBER_QUIZZES],
    const double stAve[], const double quizAve[]);
//Precondition: Global constants NUMBER_STUDENTS and NUMBER_QUIZZES are the
//dimensions of the array grade. Each of the indexed variables grade[stNum-1,
//quizNum-1] contains the score for student stNum on quiz quizNum. Each
//stAve[stNum-1] contains the average for student stu_num. Each
//quizAve[quizNum -1] contains the average for quiz number quizNum.
//Postcondition: All the data in grade, stAve, and quizAve has been output.


int main()
{
    // int loadFromFile(int myGrade[][NUMBER_QUIZZES]);
    int loadArray(int grade[][NUMBER_QUIZZES]);
    //2 dimensional array to store the quiz grades
    int grade[NUMBER_STUDENTS][NUMBER_QUIZZES];
    //  int grade[NUMBER_STUDENTS][NUMBER_QUIZZES] =
      //{ { 10, 10, 10 },{2, 0, 1}, {8, 6, 9},{8, 4, 10} };
      //1 dimensional array to hold the averages for each student
    double stAve[NUMBER_STUDENTS];
    //1 dimensional array to hold the averages of each quiz
    double quizAve[NUMBER_QUIZZES];

    //The code for filling the array grade goes here, but is not shown.
    cout << "Total Number of Quizzes entered is " << loadArray(grade) << endl;
    /// cout << "Total Number of Quizzes entered is " << loadFromFile(grade) << endl;
    computeStAve(grade, stAve);
    computeQuizAve(grade, quizAve);
    display(grade, stAve, quizAve);
    return 0;
}

//load from file

/*int loadFromFile(int myGrade[][NUMBER_QUIZZES])
{
    using namespace std;
    ifstream fin;
    ofstream fout;
    fin.open("quizzes.txt");
    if (fin.fail())
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }
    for(int i=0;i<4;i++)
   {
       for(int j=0;j<3;j++)
       {
           fin>>grade[i][j];
           count++;
       }
   }
   return count;
}*/

//Load from keyboard

int loadArray(int grade[][NUMBER_QUIZZES])
{
    using namespace std;
    int count = 0; //count the entered quizzes
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "Enter quiz grade #" << j + 1 << " for student #" << i + 1 << " ";
            cin >> grade[i][j];
            count++;
        }
    }
    return count;
}
void computeStAve(const int grade[][NUMBER_QUIZZES], double stAve[])
{
    for (int stNum = 1; stNum <= NUMBER_STUDENTS; stNum++)//loop for all students (rows)
    {
        //Process one stNum:
        double sum = 0;
        for (int quizNum = 1; quizNum <= NUMBER_QUIZZES; quizNum++)//loop for 3 quizzes for each student (columns)
            sum = sum + grade[stNum - 1][quizNum - 1];//sum of all 3 quizzes for a student
        //sum contains the sum of the quiz scores for student number stNum.
        stAve[stNum - 1] = sum / NUMBER_QUIZZES;//after loop terminates, calculate the average
        //Average for student stNum is the value of stAve[stNum-1]
    }
}


void computeQuizAve(const int grade[][NUMBER_QUIZZES], double quizAve[])
{
    for (int quizNum = 1; quizNum <= NUMBER_QUIZZES; quizNum++)
    {//Process one quiz (for all students):
        double sum = 0;
        for (int stNum = 1; stNum <= NUMBER_STUDENTS; stNum++)
            sum = sum + grade[stNum - 1][quizNum - 1];
        //sum contains the sum of all student scores on quiz number quizNum.
        quizAve[quizNum - 1] = sum / NUMBER_STUDENTS;
        //Average for quiz quizNum is the value of quizAve[quizNum-1]
    }
}


//Uses iostream and iomanip:
void display(const int grade[][NUMBER_QUIZZES],
    const double stAve[], const double quizAve[])
{
    using namespace std;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);
    cout << setw(10) << "Student"
        << setw(5) << "Ave"
        << setw(15) << "Quizzes\n";
    for (int stNum = 1; stNum <= NUMBER_STUDENTS; stNum++)
    {
        //Display for one stNum:
        cout << setw(10) << stNum
            << setw(5) << stAve[stNum - 1] << " ";
        for (int quizNum = 1; quizNum <= NUMBER_QUIZZES; quizNum++)
            cout << setw(5) << grade[stNum - 1][quizNum - 1];
        cout << endl;
    }

    cout << "Quiz averages = ";
    for (int quizNum = 1; quizNum <= NUMBER_QUIZZES; quizNum++)
        cout << setw(5) << quizAve[quizNum - 1];
    cout << endl;
}

/*
Enter quiz grade #1 for student #1 10
Enter quiz grade #2 for student #1 10
Enter quiz grade #3 for student #1 10
Enter quiz grade #1 for student #2 2
Enter quiz grade #2 for student #2 0
Enter quiz grade #3 for student #2 1
Enter quiz grade #1 for student #3 8
Enter quiz grade #2 for student #3 6
Enter quiz grade #3 for student #3 9
Enter quiz grade #1 for student #4 8
Enter quiz grade #2 for student #4 4
Enter quiz grade #3 for student #4 10
Total Number of Quizzes entered is 12
Student  Ave       Quizzes
1 10.0    10   10   10
2  1.0     2    0    1
3  7.7     8    6    9
4  7.3     8    4   10
Quiz averages = 7.0  5.0  7
*/