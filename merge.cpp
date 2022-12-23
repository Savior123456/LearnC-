//
// Created by 我爱林允儿 on 2022/11/4.
//

#include <iostream>
#include <algorithm>
using namespace std;
#include <vector>
#include <string>

class MyPrint{
public:
    void operator()(int val){
        cout << val << " ";
    }
};

void test01(){
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10 ; i++)
    {
        v1.push_back(i);
        v2.push_back(i + 1);
    }

    vector<int> vtarget;
    //目标容器需要提前开辟空间
    vtarget.resize(v1.size() + v2.size());
    //合并  需要两个有序序列
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vtarget.begin());
    for_each(vtarget.begin(), vtarget.end(), MyPrint());
    cout << endl;
    reverse(vtarget.begin(),vtarget.end());
    for_each(vtarget.begin(), vtarget.end(), MyPrint());
}
int main() {
    test01();
    //system("pause");
    return 0;
}