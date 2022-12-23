//
// Created by Œ“∞Æ¡÷‘ ∂˘ on 2022/11/3.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#include <string>

class Person{
private:
    string m_name;
    int m_id;
    int m_age;
public:
    Person(){}
    Person(string name,int id,int age){
        this->m_name = name;
        this->m_id = id;
        this->m_age = age;
    }
    string getName(){
        return this->m_name;
    }

    int getAge(){
        return this->m_age;
    }

    int getId(){
        return this->m_id;
    }

    void setName(string name){
        this->m_name = name;
    }

    void setAge(int age){
        this->m_age = age;
    }

    void setId(int id){
        this->m_id = id;
    }

//    bool operator==(const Person &p1){
//        if(this->m_age==p1.m_age && this->m_name==p1.m_name && this->m_id == p1.m_id){
//            return true;
//        }
//        return false;
//    }
};

ostream& operator<<(ostream& os, Person &p){
    cout<<"name: "<<p.getName()<<"  "<<"age: "<<p.getAge()<<"  "<<"id: "<<p.getId();
    return os;
}

class GreaterFour{
public:
    bool operator()(int val){
        return val>3;
    }

    bool operator()(Person &p){
        if(p.getName()=="xzx" && p.getAge()>25){
            return 1;
        }
        return 0;
    }
};
void test01(){
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    int result = count_if(v.begin(),v.end(),GreaterFour());
    cout<<result<<endl;
}

void test02(){
    vector<Person> p;
    p.push_back(Person("xzx",2100400416,23));
    p.push_back(Person("xzx",2100400416,20));
    p.push_back(Person("xzx",2100400416,27));
    p.push_back(Person("xzx",2100400416,17));
    p.push_back(Person("xzx",2100400416,23));
    p.push_back(Person("xzx",2100400416,12));

    vector<Person>::iterator it = find_if(p.begin(),p.end(),GreaterFour());
    cout<<(*it)<<endl;
}

int main() {
    test02();
    //system("pause");
    return 0;
}