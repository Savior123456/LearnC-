//
// Created by �Ұ����ʶ� on 2022/10/18.
//

#include <iostream>

using namespace std;
#include <queue>
#include <string>
//��ջ�෴���Ƚ��ȳ�
//ջ���Ƚ����

class Person{
public:

    Person(string name,int age){
        this->m_Age = age;
        this->m_Name = name;
    }
    int m_Age;
    string m_Name;
};

void test01(){
    queue<Person> q;

    Person p1("��ɮ",30);
    Person p2("�����",500);
    Person p3("��˽�",3000);
    Person p4("ɳɮ",200);

    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);

    //ֻҪ���в�Ϊ�գ��鿴��ͷ���鿴��β������

    while(!q.empty()){
        cout<<"��ǰ��ͷԪ��   ----    ������"<<q.front().m_Name<<"���䣺"<<q.front().m_Age<<endl;
        q.pop();
    }

    cout<<"��ǰqueue��������"<<q.size()<<"��Ԫ�أ�"<<endl;

}
int main() {
    test01();
    //system("pause");
    return 0;
}