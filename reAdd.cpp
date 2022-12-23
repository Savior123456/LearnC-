//
// Created by 我爱林允儿 on 2022/9/22.
//
#include <iostream>
using namespace std;
//运算符重载
//重载传入的参数必须是引用
class Person
{
public:
    int m_A;
    int m_B;

    Person(int a,int b){
        this->m_A=a;
        this->m_B=b;
    }
    Person(){
    }

    /*Person operator+(Person &p){
        Person temp;
        temp.m_A=this->m_A+p.m_A;
        temp.m_B=this->m_B+p.m_B;
        return temp;
    }*/

    Person operator-(Person &p){
        Person temp;
        temp.m_A=this->m_A-p.m_A;
        temp.m_B=this->m_B-p.m_B;
        return temp;
    }

    Person operator*(Person &p){
        Person temp;
        temp.m_A=this->m_A*p.m_A;
        temp.m_B=this->m_B*p.m_B;
        return temp;
    }

    Person operator/(Person &p){
        Person temp;
        temp.m_A=this->m_A/(double )p.m_A;
        temp.m_B=this->m_B/(double)p.m_B;
        return temp;
    }
};

Person operator+(Person &p1,Person &p2){
    Person temp;
    temp.m_A=p1.m_A+p2.m_A;
    temp.m_B=p1.m_B+p2.m_B;
    return temp;
}

void test01(){
    Person p1(10,20);
    Person p2(30,40);
    Person p3 = p1+p2;
    cout<<"p3的a值为："<<p3.m_A<<endl;
    cout<<"p3的b值为："<<p3.m_B<<endl;
}

void test02(){
    Person p1(10,20);
    Person p2(30,40);
    Person p3 = p1-p2;
    cout<<"p3的a值为："<<p3.m_A<<endl;
    cout<<"p3的b值为："<<p3.m_B<<endl;
}

void test03(){
    Person p1(10,20);
    Person p2(30,40);
    Person p3 = p1*p2;
    cout<<"p3的a值为："<<p3.m_A<<endl;
    cout<<"p3的b值为："<<p3.m_B<<endl;
}
void test04(){
    Person p1(10,20);
    Person p2(30,40);
    Person p3 = p1/p2;
    cout<<"p3的a值为："<<p3.m_A<<endl;
    cout<<"p3的b值为："<<p3.m_B<<endl;
}

int main(){
    test01();
    test02();
    test03();
    test04();

    Person person ;
    Person person1(10,20) ;
    Person person2(20,30) ;
    person= operator+(person1,person2);

    cout<<"------------"<<endl;
    cout<<person.m_A<<"--------"<<person.m_B<<endl;

}
