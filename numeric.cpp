//
// Created by 我爱林允儿 on 2022/11/5.
//

#include <iostream>
#include <numeric>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>
//accumulate   计算容器元素累计总和
//fill   向容器中添加元素

//accumulate(iterator beg, iterator end, value);
// 计算容器元素累计总和
// beg 开始迭代器
// end 结束迭代器
// value 起始值
void test01(){
    vector<int> v;
    for (int i = 0; i <= 100; i++) {
        v.push_back(i);
    }

    int total = accumulate(v.begin(),v.end(),0);
    cout<<total<<endl;
}

//函数原型：fill(iterator beg, iterator end, value);
// 向容器中填充元素
// beg 开始迭代器
// end 结束迭代器
// value 填充的值
class myPrint
{
public:
    void operator()(int val)
    {
        cout << val << " ";
    }
};

void test02(){
    vector<int> v;
    v.resize(10);
    //填充
    fill(v.begin(), v.end(), 100);

    for_each(v.begin(), v.end(), myPrint());
    cout << endl;
}
int main() {
    test02();
    //system("pause");
    return 0;
}