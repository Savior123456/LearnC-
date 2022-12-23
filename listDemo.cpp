//
// Created by �Ұ����ʶ� on 2022/10/22.
//

#include <iostream>
#include <list>
using namespace std;



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
private:
    string m_name;
    int m_age;
    int m_height;
};
#include <string>


bool MyCompare(Person &p1,Person &p2){
    if(p1.getAge()!=p2.getAge()){
        return p1.getAge()<p2.getAge();
    } else{
        return p1.getHeight()<p2.getHeight();
    }
}

void printList( list<Person> &l){
    for (list<Person>::iterator it = l.begin();it!=l.end();it++ ){
        cout<<"������"<<(*it).getName()<<" ���䣺"<<(*it).getAge()<<" ��ߣ�"<<(*it).getHeight()<<endl;
    }
}

void test01(){
    list<Person> l;
    l.push_back(Person("����",50,175));
    l.push_back(Person("����",40,175));
    l.push_back(Person("����",60,145));
    l.push_back(Person("����",50,155));
    l.push_back(Person("��",83,195));

    printList(l);
    cout<<"================================="<<endl;
    l.sort(MyCompare);
    printList(l);
}
int main() {
    test01();
    //system("pause");
    return 0;
}