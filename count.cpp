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

    bool operator==(const Person &p1){
        if(this->m_age==p1.m_age && this->m_name==p1.m_name && this->m_id == p1.m_id){
            return true;
        }
        return false;
    }
};

void test01(){
    vector<int> v;
    for (int i = 0; i < 5; ++i) {
        v.push_back(5);
    }
    int result = count(v.begin(),v.end(),5);
    cout<<result<<endl;
}

void test02(){
    vector<Person> p;
    p.push_back(Person("xzx",2100400416,20));
    p.push_back(Person("xzx",2100400416,20));
    p.push_back(Person("xzx",2100400416,20));
    p.push_back(Person("xzx",2100400416,20));
    p.push_back(Person("xzx",2100400416,20));
    p.push_back(Person("cl",2000301810,19));
    p.push_back(Person("cl",2000301810,19));
    p.push_back(Person("cl",2000301810,19));
    p.push_back(Person("cl",2000301810,19));

    int result = count(p.begin(),p.end(),Person("xzx",2100400416,20));
    int result2 = count(p.begin(),p.end(),Person("cl",2000301810,19));

    cout<<result<<endl;
    cout<<result2<<endl;
}
int main() {
    test02();
    //system("pause");
    cout<<"sasaDADJKAH»˜∫πÀÆ";
    return 0;
}