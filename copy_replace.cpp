//
// Created by 我爱林允儿 on 2022/11/4.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#include <string>

//函数原型：copy(iterator beg, iterator end, iterator dest);
// 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
// beg 开始迭代器
// end 结束迭代器
// dest 目标起始迭代器

class MyPrint{
public:
    void operator()(int val){
        cout<<val<<"  ";
    }
};

void test01(){
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }

    vector<int> v1;
    v1.resize(v.size());

    copy(v.begin(),v.end(),v1.begin());
    for_each(v1.begin(),v1.end(),MyPrint());

}

//函数原型：replace(iterator beg, iterator end, oldvalue, newvalue);
// 将区间内旧元素 替换成 新元素

//函数原型：replace_if(iterator beg, iterator end, _pred, newvalue);
// 按条件替换元素，满足条件的替换成指定元素
void test02(){
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    replace(v.begin(),v.end(),1,2000);
    for_each(v.begin(),v.end(),MyPrint());
}

void test03(){
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    replace(v.begin(),v.end(),1,2000);
    for_each(v.begin(),v.end(),MyPrint());
}

//函数原型：replace_if(iterator beg, iterator end, _pred, newvalue);
// 按条件替换元素，满足条件的替换成指定元素
// beg 开始迭代器
// end 结束迭代器
// _pred 谓词
// newvalue 替换的新元素
class MyReplace{
public:
    bool operator()(int val){
        return val>4;
    }
};

void test04(){
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    replace_if(v.begin(),v.end(),MyReplace(),25);
    for_each(v.begin(),v.end(),MyPrint());
}
//函数原型：swap(container c1, container c2);
// 互换两个容器的元素
void test05(){
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
        v2.push_back(i+100);
    }

    cout << "交换前： " << endl;
    for_each(v1.begin(), v1.end(), MyPrint());
    cout << endl;
    for_each(v2.begin(), v2.end(), MyPrint());
    cout << endl;

    cout << "交换后： " << endl;
    swap(v1, v2);
    for_each(v1.begin(), v1.end(), MyPrint());
    cout << endl;
    for_each(v2.begin(), v2.end(), MyPrint());
    cout << endl;
}
int main() {
    test05();
    //system("pause");
    return 0;
}