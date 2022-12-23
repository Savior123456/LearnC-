//
// Created by �Ұ����ʶ� on 2022/11/5.
//

#include <iostream>
#include <numeric>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>
//accumulate   ��������Ԫ���ۼ��ܺ�
//fill   �����������Ԫ��

//accumulate(iterator beg, iterator end, value);
// ��������Ԫ���ۼ��ܺ�
// beg ��ʼ������
// end ����������
// value ��ʼֵ
void test01(){
    vector<int> v;
    for (int i = 0; i <= 100; i++) {
        v.push_back(i);
    }

    int total = accumulate(v.begin(),v.end(),0);
    cout<<total<<endl;
}

//����ԭ�ͣ�fill(iterator beg, iterator end, value);
// �����������Ԫ��
// beg ��ʼ������
// end ����������
// value ����ֵ
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
    //���
    fill(v.begin(), v.end(), 100);

    for_each(v.begin(), v.end(), myPrint());
    cout << endl;
}
int main() {
    test02();
    //system("pause");
    return 0;
}