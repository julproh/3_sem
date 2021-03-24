#include <iostream>
#include <vector>
#include <string>

struct Student;
struct Lesson{
    std::string name_;
    int number_;
    std::vector<Student*> student;
    Lesson(std::string name, int number):name_(name), number_(number) {};
};
struct Student{
    std::string name_;
    int number_;
    std::vector<Lesson*> lesson;
    Student(std::string name, int number):
            name_(name), number_(number) {};
};
std::ostream& operator<<(std::ostream& out, const Lesson& l){
    out<<" "<<l.number_<<" is "<<l.name_<<std::endl;
    return out;
}
void init(std::vector<Lesson>&,std::vector<Student>&);
int main() {
    std::vector<Lesson> lessons;
    std::vector<Student> students;
    lessons.emplace_back(Lesson("Physics", 1));
    lessons.emplace_back(Lesson("IT", 2));
    lessons.emplace_back(Lesson("Math", 3));
    students.emplace_back(Student("Jack", 1));
    students.emplace_back(Student("Max", 2));
    students.emplace_back(Student("Bob", 1));


    init(lessons, students);
    if(!students[1].lesson.empty())
        std::cout<<*(students[1].lesson[0])<<std::endl;
    for(auto & student : students) {
        std::cout<<"Lessons of "<<student.name_<<":"<<std::endl;
        for(auto & v : student.lesson){
            std::cout<<*v <<std::endl;
        }
    }
    //std:: cout << *students[0].lesson[1] << std::endl;
    return 0;
}
void init(std::vector<Lesson> & lessons,  std::vector<Student> &students) {
    for (auto &v1: students) {
        for (int i = 0; i < v1.number_; i++) {
            std::string name;
            std::cout << "Enter lesson for " << v1.name_ << std::endl;
            getline(std::cin, name);
            for (auto &v2: lessons) {
                if (name == v2.name_){
                    v1.lesson.push_back(&v2);
                    v2.student.push_back(&v1);
                    break;
                }
            }
        }
    }
}
