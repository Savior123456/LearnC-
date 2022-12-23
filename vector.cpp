//
// Created by 我爱林允儿 on 2022/10/13.
//
#include <iostream>
using namespace std;
#include <vector>
#include <string>

template<typename T>
void printVector(vector<T> &vector1){
    for(typename vector<T>::iterator it = vector1.begin();it!=vector1.end();it++){
        cout<<*it<<" ";
    }
    puts(" ");
}

void test01(){
    vector<int> v1;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }
   // printVector(v1);
    vector<int> v2(v1.begin(),v1.end());
    printVector(v2);
    vector<int> v3(10,100);//尾插十个一百
    vector<int> v4(v3);//拷贝构造
}

//vector赋值
void test02(){
    vector<int> v1;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }
    //printVector(v1);
    vector<int> v2 = v1;
    printVector(v2);

    vector<int> v3;
    v3.assign(v1.begin(),v1.end());//左闭右开
    printVector(v3);

    //n个element方式赋值
    vector<int> v4;
    v4.assign(10,100);
    printVector(v4);
}

//vector容器的容量和大小
void test03(){
    vector<int> v1;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }
    printVector(v1);

    if(v1.empty()!=NULL){//如果为真则表示容器为空
        cout<<"v1容器为空"<<endl;
    } else{
        cout<<"v1容器不为空"<<endl;
        cout<<"v1容器的容量为： "<<v1.capacity()<<endl;
        cout<<"v1容器的大小为： "<<v1.size()<<endl;
    }

    //重新指定大小
    cout<<"==================================="<<endl;
    //v1.resize(20);
    //利用重载版本，指定填充数字是啥，默认为0，如果指定大小比原来短，则删除超出部分
    v1.resize(20,100);
    cout<<"v1容器的容量为： "<<v1.capacity()<<endl;
    cout<<"v1容器的大小为： "<<v1.size()<<endl;
    printVector(v1);
}

//vector容器的插入和删除
void test04(){
    vector<int> v1;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }
    printVector(v1);
    v1.pop_back();//尾删
    v1.insert(v1.begin(),100);//第一个参数是迭代器，插入位置，插入数值
    printVector(v1);
    v1.insert(v1.begin(),2,50);//插入2个50，在头部
    v1.erase(v1.begin());//删除一个位置的数据
    v1.erase(v1.begin(),v1.end());//清除两个迭代器中间的数据，左闭右开
    printVector(v1);
    v1.clear();//清空
}

//vector容器的数据存取
void test05(){
    vector<int> v1;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }
   // printVector(v1);
    //输出每个元素
    for(int i = 0;i < v1.size();i++){
        cout<<v1[i]<<  "========"  <<v1.at(i)<<endl;
    }

    cout<<"第一个元素为： "<<v1.front()<<endl;
    cout<<"最后一个元素为： "<<v1.back()<<endl;
}

//vector容器的互换
void test06(){
    vector<int> v1;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }
    vector<int> v2;
    for (int i = 10; i >0 ; --i) {
        v2.push_back(i);
    }
    cout<<"=======互换前======="<<endl;
    printVector(v1);
    printVector(v2);
    cout<<"==================="<<endl;
    cout<<"=======互换后======="<<endl;
    v1.swap(v2);
    printVector(v1);
    printVector(v2);
    cout<<"==================="<<endl;

}

//利用swap巧妙减缓resize之后占用内存过多问题
void test07(){
    vector<int> v1;
    for (int i = 0; i < 10000; ++i) {
        v1.push_back(i);
    }

    cout<<"v1容器的容量为： "<<v1.capacity()<<endl;
    cout<<"v1容器的大小为： "<<v1.size()<<endl;

    v1.resize(20);

    cout<<"v1容器的容量为： "<<v1.capacity()<<endl;///容量不变，大小变化，内存空间浪费
    cout<<"v1容器的大小为： "<<v1.size()<<endl;

    //解决办法

    vector<int>(v1).swap(v1);
    cout<<"v1容器的容量为： "<<v1.capacity()<<endl;
    cout<<"v1容器的大小为： "<<v1.size()<<endl;
}

//vector预留空间reserve
void test08(){
    vector<int> v1;
    int *p=NULL;
    int num = 0;
    v1.reserve(10);
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
        if(p!=&v1[0]){
            num++;
            p=&v1[0];
        }
    }
    cout<<"vector分配了几次空间 num = "<<num<<endl;
    cout<<"v1容器的容量为： "<<v1.capacity()<<endl;
    cout<<"v1容器的大小为： "<<v1.size()<<endl;
}
int main(){
    test08();
    //system("pause");
    return 0;
}
