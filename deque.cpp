//
// Created by 我爱林允儿 on 2022/10/13.
//

#include <iostream>
using namespace std;
#include <deque>
#include <string>
#include <algorithm>

//只读状态的打印
template<class T>
void printDeque(const deque<T>&d1){
    for (typename deque<T>::const_iterator it = d1.begin();it!=d1.end();++it){
        cout<<*it<<" ";
    }
    cout<<endl;
}



void test01(){
    deque<int> d1;
    for (int i = 0; i < 10; ++i) {
        d1.push_front(i);//头插
        d1.push_back(i);//尾插
    }
    printDeque(d1);

    deque<int> d2(d1.begin(),d1.end());
    printDeque(d2);

    deque<int> d3(10,100);
    printDeque(d3);

    deque<int> d4(d3);
    printDeque(d4);
}

//deque容器的赋值
void test02(){
    deque<int> d1;
    for (int i = 0; i < 10; ++i) {
        d1.push_front(i);//头插
        d1.push_back(i);//尾插
    }
    deque<int> d2 = d1;
    printDeque(d2);

    deque<int> d3 ;
    d3.assign(d1.begin(),d1.end());
    printDeque(d3);

    deque<int> d4;
    d4.assign(10,100);
    printDeque(d4);
}

//deque的大小操作  与 vector容器区别：没有容量的概念。
void test03(){
    deque<int> d1;
    for (int i = 0; i < 10; ++i) {
        d1.push_front(i);//头插
        d1.push_back(i);//尾插
    }
    printDeque(d1);
    if(!d1.empty())
    cout<<"deque容器不为空"<<endl<<"deque容器的大小为： "<<d1.size()<<endl;

    d1.resize(15);
    printDeque(d1);
    d1.resize(20);
    printDeque(d1);
    d1.resize(30,5);
    printDeque(d1);
}

//deque容器的插入和删除
void test04(){
    deque<int> d1;
    for (int i = 0; i < 10; ++i) {
        d1.push_front(i);//头插
        d1.push_back(i);//尾插
    }
    printDeque(d1);

    d1.pop_back();//尾删
    d1.pop_front();//头删
    printDeque(d1);

    //指定位置插入
    d1.insert(d1.begin(),1000);
    printDeque(d1);
    d1.insert(d1.begin(),2,38);//在头部插入两个38
    printDeque(d1);
    //cout<<*d1.begin()<<endl;

    //按照区间进行插入
    d1.insert(d1.begin(),d1.begin(),d1.end());
    printDeque(d1);

    //删除
    //按照迭代器删除指定位置
    deque<int>::iterator it = d1.begin();
    for(;it!=d1.end();it++){
        if(*it==7)
            d1.erase(it);
    }
    printDeque(d1);

    d1.erase(d1.begin(),d1.end());
    d1.clear();
}

//deque容器的数据存取
void test05(){
    deque<int> d1;
    for (int i = 0; i < 10; ++i) {
        d1.push_front(i);//头插
        d1.push_back(i);//尾插
    }
    printDeque(d1);

    cout<<"deque容器中的第一个数据为： "<<d1.front()<<endl;
    cout<<"deque容器中的最后一个数据为： "<<d1.back()<<endl;
    cout<<"deque容器中的第3个数据为： "<<d1[2]<<endl;
    cout<<"deque容器中的第5个数据为： "<<d1[4]<<endl;


}

//只要支持随机访问的迭代器的容器，都可以使用sort算法进行排序
//deque容器的排序
void test06(){
    deque<int> d1;
    for (int i = 0; i < 10; ++i) {
        d1.push_front(i);//头插
        d1.push_back(i);//尾插
    }
    printDeque(d1);

    sort(d1.begin(), d1.end());
    printDeque(d1);
}

int main() {

    test06();
    //system("pause");
    return 0;
}