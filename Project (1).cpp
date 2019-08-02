// Imaad Ullah Afridi
// Email: imaad3358@gmail.com
// Simple Quizz Grading

 
#include <iostream>
#include <conio.h>
#include <string>
#include <stdlib.h>
#include <fstream>
using namespace std;

int main ()
{
	system("color FD");
	system("cls");
	cout<<"\n\n\n\n\n\n\n";
	cout<<"*******************************************************************************\n\n\n";
	cout << "\t\t\tWelcome to the Project of BCS 1st Semester: ";
	cout<<"\n\n\n*******************************************************************************";
	getch();
	int checker = 0;
	int enteredroll;
	char correctname[80];
	int correctroll;
	system("cls");
	while (checker == 0){
	cout << "Enter the student Roll Number: ";
	cin >> enteredroll;
	
	ifstream studentfile ("student.txt");
		while (!studentfile.eof())
		{
		studentfile >> correctroll >> correctname;
		if (correctroll == enteredroll)
		{
			cout << "\n\nYou have successfully Logged in.\n\nProceeding to the test.\n";
			studentfile.close();
			checker = 1;
			break;
		}
		}
	if (correctroll != enteredroll)
	{
		cout << "\nYou have entered a wrong roll number.\nPlease try again.\n\n";
		continue;
	
	}
	getch ();
	}
	system("cls");
	cout << "Press any key to continue.";
	getch();
	
	ifstream questionsfile ("test.txt");
	ofstream resultfile ("result.txt" , ios::app);
	resultfile << "Roll No. " << enteredroll << ". Name: " << correctname << " Test Obt. Marks: " ;
	system("cls");
	cout << "\n\n\nFor true press T and for false press F.\n\n\n";
	
	char cq[250];
	char enteredanswer[10];
	for(int i = 0; i < 10; i++)
	{
		questionsfile.getline (cq, 250);
		cout << endl << cq << endl;
		enteredanswer[i] = getche();
	
	}
	questionsfile.close();
	
	ifstream keyfile("key.txt");
	char correctkey[12];
	keyfile >> correctkey;
	keyfile.close();
	int obtmarks = 0;
	for (int i = 0; i < 10; i++)
	{
		if (correctkey[i] == enteredanswer[i])
		obtmarks += 2;
		else
		obtmarks--;
	}
	
	resultfile << obtmarks;
	
	float per;
	char grade;// = 'B';
	per = (obtmarks/20.0);
	per *= 100;
	
	if (per > 90)
		grade = 'A';
		
	else if (per > 80)
		grade = 'B';
	
	else if (per > 60)
		grade = 'C';
	
	else if (per > 40)
		grade = 'D';
	
	else
		grade = 'F';
	
	resultfile << grade << endl;
	resultfile.close();
	system("cls");
	cout << "\n\n\n\n\n\n\t\t\t\t   Your result\n";
	cout<<"\n\n*******************************************************************************\n\n";
	
	cout << "Roll No. "<<correctroll << " \tName: " << correctname << " " << "\tMarks: " << obtmarks <<"\tPercent: " << per << "\t Grade: " <<grade;
    cout<<"\n\n*******************************************************************************\n\n\n";
	getch();
	return 0;
}
