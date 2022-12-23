//
// Created by �Ұ����ʶ� on 2022/11/4.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#include <string>

//����ԭ�ͣ�copy(iterator beg, iterator end, iterator dest);
// ��ֵ����Ԫ�أ��ҵ�����ָ��λ�õ��������Ҳ������ؽ���������λ��
// beg ��ʼ������
// end ����������
// dest Ŀ����ʼ������

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

//����ԭ�ͣ�replace(iterator beg, iterator end, oldvalue, newvalue);
// �������ھ�Ԫ�� �滻�� ��Ԫ��

//����ԭ�ͣ�replace_if(iterator beg, iterator end, _pred, newvalue);
// �������滻Ԫ�أ������������滻��ָ��Ԫ��
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

//����ԭ�ͣ�replace_if(iterator beg, iterator end, _pred, newvalue);
// �������滻Ԫ�أ������������滻��ָ��Ԫ��
// beg ��ʼ������
// end ����������
// _pred ν��
// newvalue �滻����Ԫ��
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
//����ԭ�ͣ�swap(container c1, container c2);
// ��������������Ԫ��
void test05(){
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
        v2.push_back(i+100);
    }

    cout << "����ǰ�� " << endl;
    for_each(v1.begin(), v1.end(), MyPrint());
    cout << endl;
    for_each(v2.begin(), v2.end(), MyPrint());
    cout << endl;

    cout << "������ " << endl;
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