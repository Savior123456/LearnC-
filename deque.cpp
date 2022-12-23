//
// Created by �Ұ����ʶ� on 2022/10/13.
//

#include <iostream>
using namespace std;
#include <deque>
#include <string>
#include <algorithm>

//ֻ��״̬�Ĵ�ӡ
template<class T>
void printDeque(const deque<T>&d1){
    for (typename deque<T>::const_iterator it = d1.begin();it!=d1.end();++it){
        cout<<*it<<" ";
    }
    cout<<endl;
}



void test01(){
    deque<int> d1;
    for (int i = 0; i < 10; ++i) {
        d1.push_front(i);//ͷ��
        d1.push_back(i);//β��
    }
    printDeque(d1);

    deque<int> d2(d1.begin(),d1.end());
    printDeque(d2);

    deque<int> d3(10,100);
    printDeque(d3);

    deque<int> d4(d3);
    printDeque(d4);
}

//deque�����ĸ�ֵ
void test02(){
    deque<int> d1;
    for (int i = 0; i < 10; ++i) {
        d1.push_front(i);//ͷ��
        d1.push_back(i);//β��
    }
    deque<int> d2 = d1;
    printDeque(d2);

    deque<int> d3 ;
    d3.assign(d1.begin(),d1.end());
    printDeque(d3);

    deque<int> d4;
    d4.assign(10,100);
    printDeque(d4);
}

//deque�Ĵ�С����  �� vector��������û�������ĸ��
void test03(){
    deque<int> d1;
    for (int i = 0; i < 10; ++i) {
        d1.push_front(i);//ͷ��
        d1.push_back(i);//β��
    }
    printDeque(d1);
    if(!d1.empty())
    cout<<"deque������Ϊ��"<<endl<<"deque�����Ĵ�СΪ�� "<<d1.size()<<endl;

    d1.resize(15);
    printDeque(d1);
    d1.resize(20);
    printDeque(d1);
    d1.resize(30,5);
    printDeque(d1);
}

//deque�����Ĳ����ɾ��
void test04(){
    deque<int> d1;
    for (int i = 0; i < 10; ++i) {
        d1.push_front(i);//ͷ��
        d1.push_back(i);//β��
    }
    printDeque(d1);

    d1.pop_back();//βɾ
    d1.pop_front();//ͷɾ
    printDeque(d1);

    //ָ��λ�ò���
    d1.insert(d1.begin(),1000);
    printDeque(d1);
    d1.insert(d1.begin(),2,38);//��ͷ����������38
    printDeque(d1);
    //cout<<*d1.begin()<<endl;

    //����������в���
    d1.insert(d1.begin(),d1.begin(),d1.end());
    printDeque(d1);

    //ɾ��
    //���յ�����ɾ��ָ��λ��
    deque<int>::iterator it = d1.begin();
    for(;it!=d1.end();it++){
        if(*it==7)
            d1.erase(it);
    }
    printDeque(d1);

    d1.erase(d1.begin(),d1.end());
    d1.clear();
}

//deque���������ݴ�ȡ
void test05(){
    deque<int> d1;
    for (int i = 0; i < 10; ++i) {
        d1.push_front(i);//ͷ��
        d1.push_back(i);//β��
    }
    printDeque(d1);

    cout<<"deque�����еĵ�һ������Ϊ�� "<<d1.front()<<endl;
    cout<<"deque�����е����һ������Ϊ�� "<<d1.back()<<endl;
    cout<<"deque�����еĵ�3������Ϊ�� "<<d1[2]<<endl;
    cout<<"deque�����еĵ�5������Ϊ�� "<<d1[4]<<endl;


}

//ֻҪ֧��������ʵĵ�������������������ʹ��sort�㷨��������
//deque����������
void test06(){
    deque<int> d1;
    for (int i = 0; i < 10; ++i) {
        d1.push_front(i);//ͷ��
        d1.push_back(i);//β��
    }
    printDeque(d1);

    sort(d1.begin(), d1.end());
    printDeque(d1);
}

int main() {

    test06();
    //system("pause");
    return 0;
}