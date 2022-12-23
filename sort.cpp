//
// Created by 我爱林允儿 on 2022/11/4.
//

#include <iostream>

using namespace std;
#include <algorithm>
#include <vector>
#include <string>

void MyPrint(int val){
    cout<<val<<"  ";
}
void test01(){
    vector<int> v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(50);
    v.push_back(20);
    v.push_back(40);
    for_each(v.begin(),v.end(), MyPrint);
    cout<<endl<<"排序后"<<endl;
    sort(v.begin(),v.end());//从小到大排序
    for_each(v.begin(),v.end(), MyPrint);
    cout<<endl;

    //从大到小排序
    sort(v.begin(),v.end(),greater<int>());
    for_each(v.begin(),v.end(), MyPrint);
    cout<<endl;
    //random_shuffle指定范围内的元素随机调整次序
    random_shuffle(v.begin(),v.end());
    for_each(v.begin(),v.end(), MyPrint);
}

int main() {
    test01();
    //system("pause");
    return 0;
}