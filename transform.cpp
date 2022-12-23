//
// Created by 我爱林允儿 on 2022/11/3.
//

#include <iostream>
#include <algorithm>
using namespace std;
#include <string>
#include <vector>

class Transform{
public:
    int operator()(int val){
        return val+100;
    }
};
class print01{
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
    vector<int> vTarget;//目标容器
    vTarget.resize(v.size());
    transform(v.begin(),v.end(),vTarget.begin(),Transform());
    for_each(vTarget.begin(),vTarget.end(),print01());
}
int main() {
    test01();
    //system("pause");
    return 0;
}