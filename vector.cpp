//
// Created by �Ұ����ʶ� on 2022/10/13.
//
#include <iostream>
using namespace std;
#include <vector>
#include <string>

template<typename T>
void printVector(vector<T> &vector1){
    for(typename vector<T>::iterator it = vector1.begin();it!=vector1.end();it++){
        cout<<*it<<" ";
    }
    puts(" ");
}

void test01(){
    vector<int> v1;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }
   // printVector(v1);
    vector<int> v2(v1.begin(),v1.end());
    printVector(v2);
    vector<int> v3(10,100);//β��ʮ��һ��
    vector<int> v4(v3);//��������
}

//vector��ֵ
void test02(){
    vector<int> v1;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }
    //printVector(v1);
    vector<int> v2 = v1;
    printVector(v2);

    vector<int> v3;
    v3.assign(v1.begin(),v1.end());//����ҿ�
    printVector(v3);

    //n��element��ʽ��ֵ
    vector<int> v4;
    v4.assign(10,100);
    printVector(v4);
}

//vector�����������ʹ�С
void test03(){
    vector<int> v1;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }
    printVector(v1);

    if(v1.empty()!=NULL){//���Ϊ�����ʾ����Ϊ��
        cout<<"v1����Ϊ��"<<endl;
    } else{
        cout<<"v1������Ϊ��"<<endl;
        cout<<"v1����������Ϊ�� "<<v1.capacity()<<endl;
        cout<<"v1�����Ĵ�СΪ�� "<<v1.size()<<endl;
    }

    //����ָ����С
    cout<<"==================================="<<endl;
    //v1.resize(20);
    //�������ذ汾��ָ�����������ɶ��Ĭ��Ϊ0�����ָ����С��ԭ���̣���ɾ����������
    v1.resize(20,100);
    cout<<"v1����������Ϊ�� "<<v1.capacity()<<endl;
    cout<<"v1�����Ĵ�СΪ�� "<<v1.size()<<endl;
    printVector(v1);
}

//vector�����Ĳ����ɾ��
void test04(){
    vector<int> v1;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }
    printVector(v1);
    v1.pop_back();//βɾ
    v1.insert(v1.begin(),100);//��һ�������ǵ�����������λ�ã�������ֵ
    printVector(v1);
    v1.insert(v1.begin(),2,50);//����2��50����ͷ��
    v1.erase(v1.begin());//ɾ��һ��λ�õ�����
    v1.erase(v1.begin(),v1.end());//��������������м�����ݣ�����ҿ�
    printVector(v1);
    v1.clear();//���
}

//vector���������ݴ�ȡ
void test05(){
    vector<int> v1;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }
   // printVector(v1);
    //���ÿ��Ԫ��
    for(int i = 0;i < v1.size();i++){
        cout<<v1[i]<<  "========"  <<v1.at(i)<<endl;
    }

    cout<<"��һ��Ԫ��Ϊ�� "<<v1.front()<<endl;
    cout<<"���һ��Ԫ��Ϊ�� "<<v1.back()<<endl;
}

//vector�����Ļ���
void test06(){
    vector<int> v1;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }
    vector<int> v2;
    for (int i = 10; i >0 ; --i) {
        v2.push_back(i);
    }
    cout<<"=======����ǰ======="<<endl;
    printVector(v1);
    printVector(v2);
    cout<<"==================="<<endl;
    cout<<"=======������======="<<endl;
    v1.swap(v2);
    printVector(v1);
    printVector(v2);
    cout<<"==================="<<endl;

}

//����swap�������resize֮��ռ���ڴ��������
void test07(){
    vector<int> v1;
    for (int i = 0; i < 10000; ++i) {
        v1.push_back(i);
    }

    cout<<"v1����������Ϊ�� "<<v1.capacity()<<endl;
    cout<<"v1�����Ĵ�СΪ�� "<<v1.size()<<endl;

    v1.resize(20);

    cout<<"v1����������Ϊ�� "<<v1.capacity()<<endl;///�������䣬��С�仯���ڴ�ռ��˷�
    cout<<"v1�����Ĵ�СΪ�� "<<v1.size()<<endl;

    //����취

    vector<int>(v1).swap(v1);
    cout<<"v1����������Ϊ�� "<<v1.capacity()<<endl;
    cout<<"v1�����Ĵ�СΪ�� "<<v1.size()<<endl;
}

//vectorԤ���ռ�reserve
void test08(){
    vector<int> v1;
    int *p=NULL;
    int num = 0;
    v1.reserve(10);
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
        if(p!=&v1[0]){
            num++;
            p=&v1[0];
        }
    }
    cout<<"vector�����˼��οռ� num = "<<num<<endl;
    cout<<"v1����������Ϊ�� "<<v1.capacity()<<endl;
    cout<<"v1�����Ĵ�СΪ�� "<<v1.size()<<endl;
}
int main(){
    test08();
    //system("pause");
    return 0;
}
