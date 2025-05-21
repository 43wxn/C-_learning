#include<iostream>
#include<vector>
#include <algorithm>
#include <iomanip>
int num;
class student{
    public:
        std::string name;
        std::string grade;
        //构造函数
        student()=default;
        student(std::string n,std::string g):name(n),grade(g){}
        //成员函数
        void show();
    //比较函数
        static bool compare(const student &a,const student &b){
            return a.grade>b.grade;
        }
};


void student::show(){
    std::cout << std::setw(15) << name << std::setw(5) << grade << std::endl;
}

int main(){
    std::cin>>num;
    std::vector<student> stu(num);
    //录入姓名和成绩
    for(int i=0;i<num;i++){
        std::string name,grade;
        std::cin>>name>>grade;
        stu[i]=student(name,grade);
    }
    std::sort(stu.begin(),stu.end(),student::compare);
    for(int i=0;i<num;i++){
        stu[i].show();
    }
    return 0;
}