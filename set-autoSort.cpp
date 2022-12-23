//
// Created by 我爱林允儿 on 2022/10/24.
//

#include <iostream>

using namespace std;
#include <set>
#include <string>

//set容器不允许插入重复数据，multiset允许插入重复数据
//插入时会自动排序

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

    //set的拷贝构造
    set<int> s4(s1);

    set<Person> s3;
    for (int i = 0; i < 5; ++i) {
        s1.insert(i);
    }
    printSet(s1);
}

//set容器的大小与交换
void test02(){
    set<int> s1;
    for (int i = 0; i < 5; ++i) {
        s1.insert(i);
    }

    cout<<"s1的大小为："<<s1.size()<<endl;
    set<int> s2;
    s2.swap(s1);
    cout<<"s1的大小为："<<s1.size()<<endl;
    cout<<"s2的大小为："<<s2.size()<<endl;
}

//set容器的插入与删除
void test03(){
    set<int> s1;
    for (int i = 0; i < 5; ++i) {
        s1.insert(i);//插入，只能通过尾插
    }

    set<int>::iterator it = s1.begin();
    set<int>::iterator it1 = s1.end();
    it++;
    it1--;
    cout<<*it1<<endl;
    printSet(s1);
    s1.erase(it,it1);//通过迭代器，删除中间的元素，包括it元素，不包括it1
    printSet(s1);

    s1.erase(10);//删除set容器中的指定值
}

//set容器的查找与统计
void test04(){
    set<int> s1;
    for (int i = 0; i < 5; ++i) {
        s1.insert(i);//插入，只能通过尾插
    }

    set<int>::iterator it1 = s1.find(10);//s1.find(10);查找set容器中是否有10，没有的话则返回set.end();

    cout<<*it1<<endl;

    s1.count(10);//统计10出现的个数

}


//pair对组的创建
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
//改变set容器默认的排序规则
void test06(){
    set<int,MyCompare> s1;
    for (int i = 0; i < 5; ++i) {
        s1.insert(i);//插入，只能通过尾插
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