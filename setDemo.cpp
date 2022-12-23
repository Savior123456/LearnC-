//
// Created by �Ұ����ʶ� on 2022/10/24.
//

#include <iostream>

using namespace std;
#include <set>
#include <string>

class Person{
public:
    Person(string name,int age,int height){
        this->m_name = name;
        this->m_age = age;
        this->m_height = height;
    }

    string getName()const{
        return this->m_name;
    }
    int getAge()const{
        return this->m_age;
    }
    int getHeight()const{
        return this->m_height;
    }

public:
    string m_name;
    int m_age;
    int m_height;
};

class Compare
{
public:
    bool operator()(const Person& p1,const Person& p2) const//һ��Ҫ����Ϊ���������Ҳ�����Ҫ�޶�Ϊconst
    {
        if (p1.m_age == p2.m_age)
            return p1.m_height > p2.m_height;
        else
            return p1.m_age > p2.m_age;
    }
};

void printMySet(const set<Person,Compare> &s1){
    for(typename set<Person>::iterator it = s1.begin();it!=s1.end();it++){
        cout<<"����Ϊ��"<<(*it).getName()<<"���䣺"<<it->getAge()<<"���Ϊ��"<<it->getHeight()<<endl;
    }
}

void test01(){
    set<Person,Compare> s1;
    s1.insert(Person("����",10,175));
    s1.insert(Person("����",25,177));
    s1.insert(Person("����",60,185));
    s1.insert(Person("�ĸ�",10,173));

    printMySet(s1);
}
int main() {
    test01();
    //system("pause");
    return 0;
}