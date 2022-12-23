//
// Created by �Ұ����ʶ� on 2022/10/24.
//

#include <iostream>

using namespace std;
#include <set>
#include <string>

//set��������������ظ����ݣ�multiset��������ظ�����
//����ʱ���Զ�����

class Person{
public:
    Person(string name,int age,int height){
        this->m_name = name;
        this->m_age = age;
        this->m_height = height;
    }

    string getName(){
        return this->m_name;
    }
    int getAge(){
        return this->m_age;
    }
    int getHeight(){
        return this->m_height;
    }
private:
    string m_name;
    int m_age;
    int m_height;
};

template<class T>
void printSet(set<T> &s1){
//    int temp = s1.size();
//    for (int i = 0; i < temp; ++i) {
//        cout<<"no";
//    }
//    cout<<endl;
    for (typename set<T>::iterator it = s1.begin();it!=s1.end();it++){
        cout<<*it<<' ';
    }
    cout<<endl;
}

void printSet(set<Person> &s1){
    cout<<"yes"<<endl;
}

void test01(){
    set<int> s1;
    multiset<int> s2;

    //set�Ŀ�������
    set<int> s4(s1);

    set<Person> s3;
    for (int i = 0; i < 5; ++i) {
        s1.insert(i);
    }
    printSet(s1);
}

//set�����Ĵ�С�뽻��
void test02(){
    set<int> s1;
    for (int i = 0; i < 5; ++i) {
        s1.insert(i);
    }

    cout<<"s1�Ĵ�СΪ��"<<s1.size()<<endl;
    set<int> s2;
    s2.swap(s1);
    cout<<"s1�Ĵ�СΪ��"<<s1.size()<<endl;
    cout<<"s2�Ĵ�СΪ��"<<s2.size()<<endl;
}

//set�����Ĳ�����ɾ��
void test03(){
    set<int> s1;
    for (int i = 0; i < 5; ++i) {
        s1.insert(i);//���룬ֻ��ͨ��β��
    }

    set<int>::iterator it = s1.begin();
    set<int>::iterator it1 = s1.end();
    it++;
    it1--;
    cout<<*it1<<endl;
    printSet(s1);
    s1.erase(it,it1);//ͨ����������ɾ���м��Ԫ�أ�����itԪ�أ�������it1
    printSet(s1);

    s1.erase(10);//ɾ��set�����е�ָ��ֵ
}

//set�����Ĳ�����ͳ��
void test04(){
    set<int> s1;
    for (int i = 0; i < 5; ++i) {
        s1.insert(i);//���룬ֻ��ͨ��β��
    }

    set<int>::iterator it1 = s1.find(10);//s1.find(10);����set�������Ƿ���10��û�еĻ��򷵻�set.end();

    cout<<*it1<<endl;

    s1.count(10);//ͳ��10���ֵĸ���

}


//pair����Ĵ���
void test05(){
        pair<int,int> p (10,20);
        pair<int,int> p1 = make_pair(20,50);
        cout<<p.first<<endl<<p.second<<endl;
}

class MyCompare{
public:
            bool operator()(int v1,int v2){
                return v1>v2;
            }
        };
//�ı�set����Ĭ�ϵ��������
void test06(){
    set<int,MyCompare> s1;
    for (int i = 0; i < 5; ++i) {
        s1.insert(i);//���룬ֻ��ͨ��β��
    }

    for (typename set<int>::iterator it = s1.begin();it!=s1.end();it++){
        cout<<*it<<' ';
    }
    cout<<endl;

}
int main() {
    test06();
    //system("pause");
    return 0;
}