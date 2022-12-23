//
// Created by �Ұ����ʶ� on 2022/11/5.
//

#include <iostream>

using namespace std;
#include <algorithm>
#include <vector>
#include <string>

//����ԭ�ͣ�set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
// ���������ϵĽ���
// ע��:�������ϱ�������������
// beg1 ����1��ʼ������
// end1 ����1����������
// beg2 ����2��ʼ������
// end2 ����2����������
// dest Ŀ��������ʼ������
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
//����Ŀ�����������һ��Ԫ�صĵ�������ַ
    vector<int>::iterator itEnd =
            set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());

    for_each(v3.begin(), itEnd, MyPrint());
    cout << endl;
}

//set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
// ���������ϵĲ���
// ע��:�������ϱ�������������
// beg1 ����1��ʼ������
// end1 ����1����������
// beg2 ����2��ʼ������
// end2 ����2����������
// dest Ŀ��������ʼ������

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

//����ԭ�ͣ�set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
// ���������ϵĲ
// ע��:�������ϱ�������������
// beg1 ����1��ʼ������
// end1 ����1����������
// beg2 ����2��ʼ������
// end2 ����2����������
// dest Ŀ��������ʼ������
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