//
// Created by �Ұ����ʶ� on 2022/10/19.
//

#include <iostream>
using namespace std;
#include <string>
#include<list>
#include <algorithm>

bool MyCompare(int v1,int v2){
    return v1>v2;
}

template<class T>
void printList(const list<T>&l){
    for (typename list<T>::const_iterator it = l.begin();it!=l.end();it++) {
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test01(){
    list<int> l;
    for (int i = 0; i < 5; ++i) {
        l.push_back(i);
    }

    printList(l);

    list<int> l1 = l;
    printList(l1);

    list<int> l2(l1.begin(),l1.end());
    printList(l2);
}

//list�����ĸ�ֵ�ͽ���
void test02(){
    list<int> l;
    for (int i = 0; i < 5; ++i) {
        l.push_back(i);
    }
    printList(l);

    list<int> l1;
    l1.assign(l1.begin(),l1.end());

    list<int> l2;
    l2.assign(10,100);
}

//����
void test03(){
    list<int> l;
    for (int i = 0; i < 5; ++i) {
        l.push_back(i);
    }

    list<int> l1;

    l1.assign(10,25);
    printList(l);
    printList(l1);

    l.swap(l1);
    printList(l);
    printList(l1);

    //cout<<l.size()<<endl;
}

//list��С����
void test04(){
    list<int> l;
    for (int i = 0; i < 5; ++i) {
        l.push_back(i);
    }
    printList(l);

    cout<<l.max_size()<<endl;
    cout<<l.size()<<endl;

    l.resize(20,2);
    cout<<l.max_size()<<endl;
    cout<<l.size()<<endl;

    //�ж������Ƿ�Ϊ��  0Ϊ�ǿ�
    cout<<l.empty()<<endl;

}

//list�����Ĳ����ɾ������
void test05(){
    list<int> l;
    for (int i = 0; i < 5; ++i) {
        l.push_back(i);//��list����β�����һ��Ԫ��
    }

    printList(l);
    l.pop_back();//��list����β��ɾ��һ��Ԫ��
    l.push_front(20);//��list����ͷ�����һ��Ԫ��
    l.pop_front();//��list����ͷ��ɾ��һ��Ԫ��

    list<int>::iterator it = l.begin();
    l.insert(++it,10);//���õ���������ָ��λ�ò�������
    printList(l);
    l.erase(it);//���õ���������ָ��λ��ɾ������
    printList(l);

    l.remove(10);//�Ƴ���ָ��Ԫ����ͬ��Ԫ��
    printList(l);

    l.clear();//���list����
}

//list���ݵĴ�ȡ
//list��������ʹ�������ź�at�ķ�ʽ��ȡ���ݣ���Ϊlist��������������ݽṹ�����������ĵ�ַ
void test06(){
    list<int> l;
    for (int i = 0; i < 5; ++i) {
        l.push_back(i);//��list����β�����һ��Ԫ��
    }

    printList(l);

    cout<<"list�ĵ�һ��Ԫ��Ϊ��"<<l.front()<<endl<<"list�����һ��Ԫ��Ϊ��"<<l.back()<<endl;
}

//list�����ķ�ת������
void test07(){
    list<int> l;
    for (int i = 0; i < 5; ++i) {
        l.push_back(i);//��list����β�����һ��Ԫ��
    }
    printList(l);
    l.reverse();
    printList(l);


    list<int>::iterator  it = l.begin();
    it++;
    l.insert(it,10);
    l.sort();//list�����ķ��������Ǳ�׼����������ʹ�õ��Ǹ�
    printList(l);
    l.sort(MyCompare);//����
    printList(l);
}

int main() {
    test07();
    //system("pause");
    return 0;
}