#include<iostream>
#include<fstream>
using namespace std;

int main() {
    int rollNo[100];
    string name[100];
    float marks[100];
    int count = 0;
    int choice, searchRoll;

    // Load data from file
    ifstream infile("students.txt");
    while(infile >> rollNo[count] >> name[count] >> marks[count]) {
        count++;
    }
    infile.close();

    while(true) {
        cout << "\n\n===== STUDENT MANAGEMENT SYSTEM =====";
        cout << "\n1. Add Student";
        cout << "\n2. Display Students";
        cout << "\n3. Search Student";
        cout << "\n4. Save Records";
        cout << "\n5. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
                cout << "\nEnter Roll Number: ";
                cin >> rollNo[count];

                cout << "Enter Name: ";
                cin >> name[count];

                cout << "Enter Marks: ";
                cin >> marks[count];

                count++;
                cout << "Student Added Successfully!";
                break;

            case 2:
                if(count == 0) {
                    cout << "\nNo Records Found!";
                }
                else {
                    for(int i = 0; i < count; i++) {
                        cout << "\n\nRoll Number: " << rollNo[i];
                        cout << "\nName: " << name[i];
                        cout << "\nMarks: " << marks[i];
                        cout << "\nPercentage: " << marks[i] << "%";

                        if(marks[i] >= 90)
                            cout << "\nGrade: A";
                        else if(marks[i] >= 75)
                            cout << "\nGrade: B";
                        else if(marks[i] >= 50)
                            cout << "\nGrade: C";
                        else
                            cout << "\nGrade: Fail";

                        cout << "\n----------------------";
                    }
                }
                break;

            case 3:
                cout << "\nEnter Roll Number to Search: ";
                cin >> searchRoll;

                bool found;
                found = false;

                for(int i = 0; i < count; i++) {
                    if(rollNo[i] == searchRoll) {
                        cout << "\nStudent Found!";
                        cout << "\nRoll Number: " << rollNo[i];
                        cout << "\nName: " << name[i];
                        cout << "\nMarks: " << marks[i];
                        found = true;
                    }
                }

                if(found == false)
                    cout << "\nStudent Not Found!";
                break;

            case 4: {
                ofstream outfile("students.txt");

                for(int i = 0; i < count; i++) {
                    outfile << rollNo[i] << " "
                            << name[i] << " "
                            << marks[i] << endl;
                }

                outfile.close();
                cout << "\nRecords Saved Successfully!";
                break;
            }

            case 5: {
                ofstream outfile("students.txt");

                for(int i = 0; i < count; i++) {
                    outfile << rollNo[i] << " "
                            << name[i] << " "
                            << marks[i] << endl;
                }

                outfile.close();

                cout << "\nData Saved. Exiting Program...";
                return 0;
            }

            default:
                cout << "\nInvalid Choice!";
        }
    }

    return 0;
}