//
// Created by 我爱林允儿 on 2022/10/19.
//

#include <iostream>
using namespace std;
#include <string>
#include<list>
#include <algorithm>

bool MyCompare(int v1,int v2){
    return v1>v2;
}

template<class T>
void printList(const list<T>&l){
    for (typename list<T>::const_iterator it = l.begin();it!=l.end();it++) {
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test01(){
    list<int> l;
    for (int i = 0; i < 5; ++i) {
        l.push_back(i);
    }

    printList(l);

    list<int> l1 = l;
    printList(l1);

    list<int> l2(l1.begin(),l1.end());
    printList(l2);
}

//list容器的赋值和交换
void test02(){
    list<int> l;
    for (int i = 0; i < 5; ++i) {
        l.push_back(i);
    }
    printList(l);

    list<int> l1;
    l1.assign(l1.begin(),l1.end());

    list<int> l2;
    l2.assign(10,100);
}

//交换
void test03(){
    list<int> l;
    for (int i = 0; i < 5; ++i) {
        l.push_back(i);
    }

    list<int> l1;

    l1.assign(10,25);
    printList(l);
    printList(l1);

    l.swap(l1);
    printList(l);
    printList(l1);

    //cout<<l.size()<<endl;
}

//list大小操作
void test04(){
    list<int> l;
    for (int i = 0; i < 5; ++i) {
        l.push_back(i);
    }
    printList(l);

    cout<<l.max_size()<<endl;
    cout<<l.size()<<endl;

    l.resize(20,2);
    cout<<l.max_size()<<endl;
    cout<<l.size()<<endl;

    //判断容器是否为空  0为非空
    cout<<l.empty()<<endl;

}

//list容器的插入和删除操作
void test05(){
    list<int> l;
    for (int i = 0; i < 5; ++i) {
        l.push_back(i);//往list集合尾部添加一个元素
    }

    printList(l);
    l.pop_back();//往list集合尾部删除一个元素
    l.push_front(20);//往list集合头部添加一个元素
    l.pop_front();//往list集合头部删除一个元素

    list<int>::iterator it = l.begin();
    l.insert(++it,10);//利用迭代器，在指定位置插入数据
    printList(l);
    l.erase(it);//利用迭代器，在指定位置删除数据
    printList(l);

    l.remove(10);//移除与指定元素相同的元素
    printList(l);

    l.clear();//清空list集合
}

//list数据的存取
//list容器不能使用中括号和at的方式读取数据，因为list容器是链表的数据结构，不是连续的地址
void test06(){
    list<int> l;
    for (int i = 0; i < 5; ++i) {
        l.push_back(i);//往list集合尾部添加一个元素
    }

    printList(l);

    cout<<"list的第一个元素为："<<l.front()<<endl<<"list的最后一个元素为："<<l.back()<<endl;
}

//list容器的反转和排序
void test07(){
    list<int> l;
    for (int i = 0; i < 5; ++i) {
        l.push_back(i);//往list集合尾部添加一个元素
    }
    printList(l);
    l.reverse();
    printList(l);


    list<int>::iterator  it = l.begin();
    it++;
    l.insert(it,10);
    l.sort();//list容器的方法，不是标准容器都可以使用的那个
    printList(l);
    l.sort(MyCompare);//降序
    printList(l);
}

int main() {
    test07();
    //system("pause");
    return 0;
}