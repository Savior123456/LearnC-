//
// Created by �Ұ����ʶ� on 2022/11/4.
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
    cout<<endl<<"�����"<<endl;
    sort(v.begin(),v.end());//��С��������
    for_each(v.begin(),v.end(), MyPrint);
    cout<<endl;

    //�Ӵ�С����
    sort(v.begin(),v.end(),greater<int>());
    for_each(v.begin(),v.end(), MyPrint);
    cout<<endl;
    //random_shuffleָ����Χ�ڵ�Ԫ�������������
    random_shuffle(v.begin(),v.end());
    for_each(v.begin(),v.end(), MyPrint);
}

int main() {
    test01();
    //system("pause");
    return 0;
}