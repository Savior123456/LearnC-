//
// Created by 我爱林允儿 on 2022/11/3.
//

#include <iostream>
#include <algorithm>
using namespace std;
#include <string>
#include <vector>
//find 查找指定的元素，找得到返回迭代器，找不到返回end()

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
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }

    vector<int>::iterator it = std::find(v.begin(), v.end(),11);
    if(it==v.end()){
        cout<<"未找到"<<endl;
    } else{
        cout<<"找到了"<<endl;
    }
}

void test02(){
    vector<Person> p;
    p.push_back(Person("xzx",2100400416,20));
    p.push_back(Person("cl",2000301810,19));
    Person p1("xzx",2100400416,20);
    vector<Person>::iterator it = std::find(p.begin(), p.end(),Person("xx",11,1));
    if(it==p.end()){
        cout<<"未找到"<<endl;
    } else{
        cout<<"找到了"<<endl;
    }
}
int main() {
    test02();
    //system("pause");
    return 0;
}