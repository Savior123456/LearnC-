//
// Created by 我爱林允儿 on 2022/11/5.
//

#include <iostream>

using namespace std;
#include <algorithm>
#include <vector>
#include <string>

//函数原型：set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
// 求两个集合的交集
// 注意:两个集合必须是有序序列
// beg1 容器1开始迭代器
// end1 容器1结束迭代器
// beg2 容器2开始迭代器
// end2 容器2结束迭代器
// dest 目标容器开始迭代器
class MyPrint
{
public:
    void operator()(int val)
    {
        cout << val << " ";
    }
};
void test01(){
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i+5);
    }

    v3.resize(min(v1.size(),v2.size()));
//返回目标容器的最后一个元素的迭代器地址
    vector<int>::iterator itEnd =
            set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());

    for_each(v3.begin(), itEnd, MyPrint());
    cout << endl;
}

//set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
// 求两个集合的并集
// 注意:两个集合必须是有序序列
// beg1 容器1开始迭代器
// end1 容器1结束迭代器
// beg2 容器2开始迭代器
// end2 容器2结束迭代器
// dest 目标容器开始迭代器

void test02(){
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i+5);
    }
    v3.resize(v1.size()+v2.size());
    vector<int>::iterator it = std::set_union(v1.begin(), v1.end(),v2.begin(),v2.end(),v3.begin());
    for_each(v3.begin(),it,MyPrint());
}

//函数原型：set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
// 求两个集合的差集
// 注意:两个集合必须是有序序列
// beg1 容器1开始迭代器
// end1 容器1结束迭代器
// beg2 容器2开始迭代器
// end2 容器2结束迭代器
// dest 目标容器开始迭代器
void test03(){
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i+5);
    }
    v3.resize(max(v1.size(),v2.size()));
    vector<int>::iterator it = std::set_difference(v2.begin(), v2.end(),v1.begin(),v1.end(),v3.begin());
    for_each(v3.begin(),it,MyPrint());
}
int main() {
    test03();
    //system("pause");
    return 0;
}