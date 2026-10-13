#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
using namespace std;

class Student {
private:
    int id;
    string name;
    float grade;
public:
    Student(int id = 0, string name = "", float grade = 0) : id(id), name(name), grade(grade) {}

    int getId() const { return id; }
    string getName() const { return name; }
    float getGrade() const { return grade; }

    void setId(int new_id) { id = new_id; }
    void setName(const string& new_name) { name = new_name; }
    void setGrade(float new_grade) { grade = new_grade; }

    void setStudent(int s_id, string s_name, float s_grade) {
        id = s_id;
        name = s_name;
        grade = s_grade;
    }

};

Student* findStudent(vector<Student>& s, int searchId) {
    for (auto& student : s) {
        if(student.getId() == searchId) {
            return &student;
        }
    }
    return nullptr;
}

const Student* findStudent(const vector<Student>& s, int searchId) {
    for (const auto& student : s) {
        if(student.getId() == searchId) {
            return &student;
        }
    }
    return nullptr;
}

void displayStudent(const Student& s) {
    cout << "ID: " << s.getId() << "\t" << "Name: " << s.getName() << "\t" << "Grade: " << s.getGrade() << endl;
}

void viewStudentMark(const vector<Student>& s, int searchId) {
    const Student* student = findStudent(s, searchId);
    if (student != nullptr) displayStudent(*student);
    else { cout << "Cannot find the student with ID " << searchId << "." << "\nPlease use the right format and try again"; }
}

 void displayAllStudents(vector <Student>& student) {
    for (const auto& s : student) {
        cout << "┌------------------------------------┐\n";
        cout << "| ID    : " << s.getId() << "\n";
        cout << "| Name  : " << s.getName() << "\n";
        cout << "| Grade : " << fixed << setprecision(2) << s.getGrade() << "\n";
        cout << "└------------------------------------┘\n";
    }
}

int main() {
    fstream file("sample.csv", ios::in | ios::out | ios::app);

    if(!file) {
        cout << "Error opening file" << endl;
        return 0;
    }

    vector<Student> students;
    string line;
    int currentId;
    while(getline(file, line)) {
        stringstream ss(line);

        string idStr, name, gradeStr;

        getline(ss, idStr, ',');
        getline(ss, name, ',');
        getline(ss, gradeStr, ',');

        int id = stoi(idStr);
        int grade = stof(gradeStr);

        students.push_back(Student(stoi(idStr), name, stof(gradeStr)));
        currentId = id;
    }

    int choice;
    do {
            system("clear");
            cout << " ------------------------------------------------ " << endl;
            cout << "|        STUDENT RECORD MANAGEMENT SYSTEM        |" << endl;
            cout << " ------------------------------------------------ " << endl;
            cout << endl;
            cout << "[Select an option below]\n\n";
            cout << "1. Add New Students" << endl;
            cout << "2. Student View Marks" << endl;
            cout << "3. Update Student Marks" << endl;
            cout << "4. View All Student Marks" << endl;
            cout << "5. Calculate Average GPA" << endl;
            cout << "6. Exit" << endl;
            cout << "Enter option: ";
            cin >> choice;
            system("clear");

            switch (choice) {
                case 1:
                    {
                        int new_id = currentId + 1;
                        string new_name, new_gradeStr;

                        cout << " --------------------- " << endl;
                        cout << "|   Add New Student   |" << endl;
                        cout << " --------------------- " << endl;
                        cout << endl;
                        cout << "Enter name and grade (John, 85): ";

                        string line;
                        cin.ignore();
                        getline(cin, line);

                        stringstream ss(line);
                        getline(ss, new_name, ',');
                        getline(ss, new_gradeStr);

                        float new_grade = stof(new_gradeStr);
                        file.clear();

                        file.seekp(0, ios::end);

                        file << new_id << "," << new_name << "," << new_grade << "\n";
                        file.flush();

                        students.push_back(Student(new_id, new_name, new_grade));
                        currentId = new_id;
                        break;
                    }
                case 2:
                    {
                        cout << " ------------------------ " << endl;
                        cout << "|  View Student Records  |" << endl;
                        cout << " ------------------------ " << endl;
                        cout << endl;
                        cout << "ID format: 1001, 1002, 1003, etc." << endl;
                        cout << "\nEnter Student's ID: ";
                        int searchId;
                        cin >> searchId;
                        cout << endl;
                        viewStudentMark(students, searchId);

                        string input;
                        cout << "Press Enter to continue...";

                        cin.ignore();
                        getline(cin, input);

                        if(input.empty()) break;
                    }
                case 3:
                    {
                        ofstream outFile("temp.csv", ios::app);

                        if(!outFile) {
                            cout << "Error Opening inFile or outFile!" << endl;
                            return 0;
                        }

                        cout << " -------------------------- " << endl;
                        cout << "|   Update Student Marks   |" << endl;
                        cout << " -------------------------- " << endl;
                        cout << endl;
                        cout << "Enter student ID:";


                        int target_id;
                        cin >> target_id;
                        Student* s = findStudent(students, target_id);

                        if (s != nullptr) {
                            displayStudent(*s);
                            cout << endl;
                            cout << "Enter new grade: ";
                            float new_grade;
                            cin >> new_grade;

                            s->setGrade(new_grade);

                            for (Student st : students) {
                                outFile << st.getId() << "," << st.getName() << "," << st.getGrade() << "\n";
                            }
                            remove("sample.csv");
                            rename("temp.csv", "sample.csv");

                            string input;
                            cout << "Press Enter to continue...";

                            cin.ignore();
                            getline(cin, input);

                            if(input.empty()) break;
                        }
                        else {
                            cout << "Cannot find the ID" << endl;

                            file.close();
                            return 0;
                        }
                        break;
                    }
                case 4:
                    {
                        cout << " ---------------------------------- " << endl;
                        cout << "|   Display All Students Records   |" << endl;
                        cout << " ---------------------------------- " << endl;
                        cout << endl;
                        displayAllStudents(students);

                        cout << endl;
                        cout << endl;

                        string input;
                        cout << "Enter to continue...";
                        cin.ignore();

                        getline(cin, input);
                        system("clear");
                        if(input.empty()) break;
                    }
                case 6:
                    cout << "Exiting..." << endl;
                    system("clear");
                    return 0;
        }
    }while(choice != 0);
    file.close();
    return 0;
}
