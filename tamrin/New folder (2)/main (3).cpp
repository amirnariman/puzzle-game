#include <stdio.h>
#include <iostream>
#include <limits>
#define LESSON_MAX 6
#define TEACHER_MAX 4
#define STUDENT_MAX 5

using namespace std;

int getUserInt() {
    int choice;
    cin >> choice;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return choice;
}

string getUserString(string str) {
    string res;
    cout << str;
    cin >> res;
    return res;
}

class Teacher {
   public:
    string id;
    string name;
    string password;

    Teacher() {
        id = "";
        name = "";
    }
    Teacher(string id, string name, string password) {
        this->id = id;
        this->name = name;
        this->password = password;
    }
};

class Lesson {
   public:
    string id;
    string title;
    Teacher teacher;
    uint16_t count_of_units;

    Lesson() {
        id = "";
        title = "";
        count_of_units = 0;
    }

    Lesson(string id, string title, Teacher teacher, uint16_t count_of_units) {
        this->id = id;
        this->title = title;
        this->teacher = teacher;
        this->count_of_units = count_of_units;
    }
};

class Student {
   public:
    string id;
    string name;
    string password;
    Lesson lessons[LESSON_MAX];
    float grade;

    Student() {
        id = "";
        name = "";
        password = "";
    }

    Student(string id, string name, string password, float grade) {
        this->id = id;
        this->name = name;
        this->password = password;
        this->grade = grade;
    }
};

void printLessons(Lesson lessons[]) {
    cout << endl;
    printf("%-10s", "ID");
    printf("%-20s", "TITLE");
    printf("%-20s", "TEACHER");
    printf("%10s", "UNITS");
    cout << endl;
    for (int i = 0; i < LESSON_MAX; i++) {
        if (lessons[i].count_of_units == 0) continue;
        printf("%-10s", lessons[i].id.c_str());
        printf("%-20s", lessons[i].title.c_str());
        printf("%-20s", lessons[i].teacher.name.c_str());
        printf("%10d", lessons[i].count_of_units);
        cout << endl;
    }
}

class Database {
   public:
    Student students[STUDENT_MAX];
    Teacher teachers[TEACHER_MAX];
    Lesson lessons[LESSON_MAX];

    Database() {
        students[0] = Student("0920", "Mohammad", "123", 15.6);
        students[1] = Student("4001020", "Ali", "1234", 12.3);
        students[2] = Student("4001232", "Kamal", "2562", 12.3);
        students[3] = Student("4006325", "Reza", "7895", 16.3);
        students[4] = Student("9962200", "Poya", "0254", 19.0);
        teachers[0] = Teacher("0923", "Moeiny", "123");
        teachers[1] = Teacher("0912", "Radmanesh", "145");
        teachers[2] = Teacher("0963", "Zarei", "698");
        teachers[3] = Teacher("0958", "Kiani", "258");
        lessons[0] = Lesson("0", "Dini", teachers[0], 2);
        lessons[1] = Lesson("1", "Design Algorithm", teachers[2], 3);
        lessons[2] = Lesson("2", "Data Structure", teachers[2], 3);
        lessons[3] = Lesson("3", "Circut", teachers[3], 3);
        lessons[4] = Lesson("4", "Persian", teachers[0], 2);
        lessons[5] = Lesson("5", "English", teachers[1], 2);
    }

    int loginStudent(string id, string password) {
        for (int i = 0; i < STUDENT_MAX; i++)
            if (students[i].id == id && students[i].password == password)
                return i;
        return -1;
    }

};

class StudentCms {
   private:
    Database db;
    int student_index;
    bool is_authenticate = false;

    void menu() {
        cout << "\n1.Course Selection" << endl;
        cout << "2.Show Profile" << endl;
        cout << "3.Exit" << endl;
    }

    void login() {
        cout << "\n------------ LOGIN ------------\n";
        string id, password;
        id = getUserString("id = ");
        password = getUserString("password = ");
        student_index = db.loginStudent(id, password);
        cout << "------------------------------\n";
        if (student_index != -1) {
            is_authenticate = true;
            cout << "\nWelcome " << db.students[student_index].name << endl;
        } else
            cout << "\nError: Login failed" << endl;
    }

    void doAction(uint16_t choice) {
        switch (choice) {
            case 1:
                courceSelection();
                break;
            case 2:
                showProfile();
                break;
            default:
                cout << "\nError: Your choice is incorrect" << endl;
                break;
        }
    }

   public:
    StudentCms(Database db) { this->db = db; }

    void courceSelection() {
        printLessons(db.lessons);
        cout << "\nWrite - to end" << endl;
        int units = 0;
        for (int i = 0; i < LESSON_MAX; i++) {
            if (units >= 24) break;
            string id = getUserString("id = ");
            if (id == "-") {
                if (units < 15)
                    cout << "Error: You must select atleast 15\n";
                else
                    break;
            }
            for (int j = 0; j < LESSON_MAX; j++)
                if (db.lessons[j].id == id) {
                    db.students[student_index].lessons[i] = db.lessons[j];
                    units += db.lessons[i].count_of_units;
                    break;
                }
        }
    }

    void showProfile() {
        printLessons(db.students[student_index].lessons);
        cout << "\nName = " << db.students[student_index].name << endl;
        cout << "Grade = " << db.students[student_index].grade << endl;
    }

    void run() {
        if (is_authenticate) {
            menu();
            cout << "\nWhat is your choice? ";
            uint16_t choice = getUserInt();
            if (choice != 3) {
                doAction(choice);
                run();
            }
        } else {
            login();
            run();
        }
    }
};

class ManagerCms {
    Database db;
    bool is_authenticate = false;

    void menu() {
        cout << "\n1.Show Teachers" << endl;
        cout << "2.Show Lessons" << endl;
        cout << "3.Show Students" << endl;
        cout << "4.Exit" << endl;
    }

    void login() {
        cout << "\n------------ LOGIN ------------\n";
        string id, password;
        id = getUserString("id = ");
        password = getUserString("password = ");
        cout << "------------------------------\n";
        if (id == "123" && password == "123") {
            is_authenticate = true;
        } else
            cout << "\nError: Login failed" << endl;
    }

    void doAction(uint16_t choice) {
        switch (choice) {
            case 1:
                showTeachers();
                break;
            case 2:
                showLessons();
                break;
            case 3:
                showStudents();
                break;
            default:
                cout << "\nError: Your choice is incorrect" << endl;
                break;
        }
    }

   public:
    ManagerCms(Database db) { this->db = db; }

    void showTeachers() {
        cout << endl;
        printf("%-10s", "ID");
        printf("%20s", "NAME");
        cout << endl;
        for (int i = 0; i < TEACHER_MAX; i++) {
            printf("%-10s", db.teachers[i].id.c_str());
            printf("%20s", db.teachers[i].name.c_str());
            cout << endl;
        }
    }

    void showLessons() {
        printLessons(db.lessons);
    }

    void showStudents() {
        cout << endl;
        printf("%-10s", "ID");
        printf("%-20s", "NAME");
        printf("%10s", "GRADE");
        cout << endl;
        for (int i = 0; i < STUDENT_MAX; i++) {
            printf("%-10s", db.students[i].id.c_str());
            printf("%-20s", db.students[i].name.c_str());
            printf("%10f", db.students[i].grade);
            cout << endl;
        }
    }


    void run() {
        if (is_authenticate) {
            menu();
            cout << "\nWhat is your choice? ";
            uint16_t choice = getUserInt();
            if (choice != 4) {
                doAction(choice);
                run();
            }
        } else {
            login();
            run();
        }
    }
};

int main() {
    Database db;
    cout << "Welcome to the UCMS" << endl;
    while (true) {
        cout << "\n1.Student\n2.Manager\n3.Exit" << endl;
        cout << "\nWhat is your job? ";
        uint16_t job = getUserInt();
        if (job == 1)
            StudentCms(db).run();
        else if (job == 2)
            ManagerCms(db).run();
        else if (job == 3)
            return 0;
        else
            cout << "\nError: Job is incorrect" << endl;
    }
    return 0;
}
