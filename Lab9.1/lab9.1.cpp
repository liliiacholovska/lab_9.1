#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

enum Specialization { CS, IT, ME, PHI, TECH };
string specializationNames[] = { "Computer Science", "IT", "Maths and Economics", "Physics and Informatics", "Technology" };

union Grade {
    int programming; 
    int numerical_methods; 
    int pedagogy; 
};

struct Student {
    string surname;
    int course;
    Specialization specialization;
    int physics_grade;
    int math_grade;
    Grade additional_grade;
};

void Create(Student* students, const int N);
void CalculateProgrammingGrades(const Student* students, const int N, int& count5, int& count4, int& count3);
double CalculateInterest(const Student* students, const int N);
void Print(const Student* students, const int N);

int main() {
    int N;
    cout << "Enter the number of students: ";
    cin >> N;

    Student* students = new Student[N];
    Create(students, N);

    cout << "\nStudents' table:\n";
    Print(students, N);

    int count5 = 0, count4 = 0, count3 = 0;
    CalculateProgrammingGrades(students, N, count5, count4, count3);
    cout << "Number of '5' grades in additional subjects: " << count5 << endl;
    cout << "Number of '4' grades in additional subjects: " << count4 << endl;
    cout << "Number of '3' grades in additional subjects: " << count3 << endl;

    double percentage = CalculateInterest(students, N);
    cout << "Percentage of students with grades '4' or '5' in Physics and Mathematics: " << percentage << "%" << endl;

    delete[] students;
    return 0;
}

void Create(Student* students, const int N) {
    for (int i = 0; i < N; ++i) {
        cout << "Student #" << i + 1 << ":\n";
        cout << "Surname: ";
        cin >> students[i].surname;
        cout << "Course: ";
        cin >> students[i].course;
        cout << "Specialization (0 - Computer Science, 1 - Informatics, 2 - Maths and Economics, 3 - Physics and Informatics, 4 - Technology): ";
        int specialization;
        cin >> specialization;
        students[i].specialization = static_cast<Specialization>(specialization);
        cout << "Grade in Physics: ";
        cin >> students[i].physics_grade;
        cout << "Grade in Maths: ";
        cin >> students[i].math_grade;

        switch (students[i].specialization) {
        case CS:
            cout << "Programming grade: ";
            cin >> students[i].additional_grade.programming;
            break;
        case IT:
            cout << "Numerical methods grade: ";
            cin >> students[i].additional_grade.numerical_methods;
            break;
        default:
            cout << "Pedagogy grade: ";
            cin >> students[i].additional_grade.pedagogy;
            break;
        }
        cout << endl;
    }
}

void Print(const Student* students, const int N) {
    cout << "========================================================================================================" << endl;
    cout << "| # | Surname       | Course | Specialization               | Physics | Mathematics | Additional Grade |" << endl;
    cout << "--------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < N; ++i) {
        cout << "| " << setw(1) << right << i + 1 << " | ";
        cout << setw(13) << left << students[i].surname << " | ";
        cout << setw(6) << right << students[i].course << " | ";

        switch (students[i].specialization) {
        case CS:
            cout << setw(28) << left << "Computer Science" << " | ";
            cout << setw(7) << right << students[i].physics_grade << " | ";
            cout << setw(11) << right << students[i].math_grade << " | ";
            cout << setw(16) << right << students[i].additional_grade.programming << " |" << endl;
            break;
        case IT:
            cout << setw(28) << left << "Informatics" << " | ";
            cout << setw(7) << right << students[i].physics_grade << " | ";
            cout << setw(11) << right << students[i].math_grade << " | ";
            cout << setw(16) << right << students[i].additional_grade.numerical_methods << " |" << endl;
            break;
        case ME:
            cout << setw(28) << left << "Maths and Economics" << " | ";
            cout << setw(7) << right << students[i].physics_grade << " | ";
            cout << setw(11) << right << students[i].math_grade << " | ";
            cout << setw(16) << right << students[i].additional_grade.pedagogy << " |" << endl;
            break;
        case PHI:
            cout << setw(28) << left << "Physics and Informatics" << " | ";
            cout << setw(7) << right << students[i].physics_grade << " | ";
            cout << setw(11) << right << students[i].math_grade << " | ";
            cout << setw(16) << right << students[i].additional_grade.numerical_methods << " |" << endl;
            break;
        case TECH:
            cout << setw(28) << left << "Technology" << " | ";
            cout << setw(7) << right << students[i].physics_grade << " | ";
            cout << setw(11) << right << students[i].math_grade << " | ";
            cout << setw(16) << right << students[i].additional_grade.pedagogy << " |" << endl;
            break;
        }
    }
    cout << "===================================================================================================================================" << endl;
}

void CalculateProgrammingGrades(const Student* students, const int N, int& count5, int& count4, int& count3) {
    count5 = count4 = count3 = 0; 
    for (int i = 0; i < N; ++i) {
        if (students[i].specialization == CS) { 
            int grade = students[i].additional_grade.programming;
            switch (grade) {
            case 5: ++count5; break;
            case 4: ++count4; break;
            case 3: ++count3; break;
            }
        }
    }
}

double CalculateInterest(const Student* students, const int N) {
    int count = 0;
    for (int i = 0; i < N; ++i) {
        if (students[i].physics_grade >= 4 && students[i].math_grade >= 4) {
            ++count;
        }
    }
    return static_cast<double>(count) / N * 100; 
}