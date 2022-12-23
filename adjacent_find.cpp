//
// Created by �Ұ����ʶ� on 2022/11/3.
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

ostream& operator<<(ostream& os,Person &p){
    cout<<"name��"<<p.getName()<<"  "<<"age��"<<p.getAge()<<"  "<<"id��"<<p.getId();
    return os;
}
//adjacent_find�ᳯ�������ظ�Ԫ�أ�����ҵ����򷵻ص�һ��λ�õĵ�����
//binary_search����ָ��Ԫ���Ƿ����  ���ֲ��ң�ֻ�ܲ�����˳�������,�������Ͳ�һ��׼ȷ��

void test01(){
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    vector<int>::iterator it;
    for (it = v.begin();it!=v.end();++it) {
        if((*it)==4){
            break;
        }
    }
    v.insert(it,4);
    v.push_back(9);
    vector<int>::iterator it2 = adjacent_find(v.begin(),v.end());
    if(it2 != v.end()){
        cout<<"�ҵ��ˣ�����Ԫ�ص�ֵΪ��"<<(*it2)<<endl;
    } else{
        cout<<"δ�ҵ�"<<endl;
    }
}

void test02(){
    vector<Person> p;
    p.push_back(Person("xzx",2100400416,20));
    p.push_back(Person("xzx",2100400416,20));
    p.push_back(Person("cl",2000301810,19));
    vector<Person>::iterator it = adjacent_find(p.begin(),p.end());
    if(it != p.end()){
        cout<<"�ҵ��ˣ�"<<endl<<"����Ԫ�ص�ֵΪ��"<<(*it)<<endl;
    } else{
        cout<<"δ�ҵ�"<<endl;
    }
}

void test03(){
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    bool temp = binary_search(v.begin(),v.end(),5);
    cout<<temp<<endl;
}
int main() {
    test03();
    //system("pause");
    return 0;
}