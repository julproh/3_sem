#include <iostream> 
#include <vector>
#include <string>

using namespace std;

struct Student
{
    Student ():name("None"),surname("None"), form(0),lesson()  {
        cout << "Emptystudenis constructed" << endl;}
    Student (string _name, string _surname, int _form, vector<struct Lesson*> _lesson ) {
        name = _name;
        surname = _surname;
        form = _form;
        lesson = _lesson;
        //cout << name <<" is constructed" << endl;
    }
    ~Student () {
        //cout << name << " " << surname << " is destructed" << endl;
    }
    string name;
    string surname;
    int form;
    vector<struct Lesson*> lesson;
};

struct Lesson
{
    Lesson ():name("None"), days({}),teacher_name("None"),teacher_secondname("None"), student({})  {
        cout << "Empty lesson is constructed" << endl;}
    Lesson (string _name,vector<string> _days,int _number, string _teacher_name, string _teacher_secondname,  vector<struct Student*> _student) {
        name = _name;
        days = _days;
        number = _number;
        teacher_name  = _teacher_name;
        teacher_secondname = _teacher_secondname;
        student  = _student;
    }
    ~Lesson () {
       // cout << name << " is destructed" << endl;
    }
    string name;
    vector<string> days;
    int number;
    string teacher_name;
    string teacher_secondname;
    vector<struct Student*> student;
};

void print_student (vector<Student> &students, vector<Lesson> &lessons);
void print_lesson (vector<Student> &students, vector<Lesson> &lessons);

int main () {
    Lesson math("Math", {"Monday", "Wednesday"}, 2, "Olga", "Ivanovna", {}),
    russian("Russian", {"Tusday", "Sunday"},1, "Ivan", "Petrovich", {}),
    art ("Art",{"Thursday"}, 3,"Anna", "Vasilievna", {}),
    PE ("PE", {"Monday", "Friday"}, 5, "Petr", "Alekseevich", {}),
    english("English", {"Monday", "Saturday"}, 3, "Evgenia", "Olegovna", {});
    vector <Lesson> lessons = {art, english, math, PE, russian};
    
    Student IP1("Ivan", "Petrov", 1, {&math, &russian,&PE}), AW3("Andrew", "Wolf", 3, {&math, &russian, &PE, &english}), 
    SP4("Sarra", "Petrova", 4, {&math, &russian, &PE, &english, &art}), AM4("Anna", "Monova", 4, {&math, &russian, &PE, &english, &art});
    vector<Student> students = {IP1, AW3, SP4, AM4 };
    
    for (auto i : lessons) {
        for (auto j : students) {
            for (auto k : j.lesson){
                if((*k).name == i.name){
                    i.student.push_back(&j);
                }
            }
        }
    }
    print_student (students, lessons);
    cout << endl;
    print_lesson (students, lessons);
    return 0;
}

void print_student (vector<Student> &students, vector<Lesson> &lessons) {
    int t = 0;
    cout << "Предметы какого студента Вы хотите узнать: " << endl;
    for (auto i: students) {
        t++;
        cout << t << ')' << i.name << " " << i.surname << endl;
    }
    cout << "Введите номер: ";
    cin >> t;
    cout << students[t-1].name << ' ' << students[t-1].surname << endl
    << "учится в " << students[t-1].form << " классе" << endl << "Предметы: " << endl;
    for (auto i : students[t-1].lesson) {
        cout << (*i).name << endl; 
    }
 }

 void print_lesson (vector<Student> &students, vector<Lesson> &lessons)  {
    int t = 0;
    cout << "Предметы: " << endl;
    for (auto i: lessons) {
        t++;
        cout << t << ')' << i.name << " "<< endl;
    }
    cout << "Введите номер, учеников которого хотите узнать: ";
    cin >> t;
    cout << lessons[t-1].name << endl << "проходит на " << lessons[t-1].number << " уроке" << endl
    << "проходит по: ";
    for (auto i : lessons[t-1].days) {
        cout << i << endl; 
    }
    cout << "учитель: " << lessons[t-1].teacher_name << ' ' << lessons[t-1].teacher_secondname << endl;
 }