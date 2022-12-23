//
// Created by 我爱林允儿 on 2022/11/3.
//

#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;
#include <string>

template<class T>
void printVector(const vector<T> &v){
    for(typename vector<T>::const_iterator it = v.begin();it!=v.end();++it){
        cout<<(*it)<<' ';
    }
    cout<<endl;
}

template<class T>
void print01(T t){
    cout<<t<<' ';
}
void print02(int val){
    cout<<val<<' ';
}

class print03{
public:
    void operator()(int val){
        cout<<val<<' ';
    }
};
void test01(){
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    //printVector(v);
    //若使用for_each提供的函数不能使用泛型
    for_each(v.begin(),v.end(), print02);
    cout<<endl;
    for_each(v.begin(),v.end(), print03());
}
int main() {
    test01();
    //system("pause");
    return 0;
}