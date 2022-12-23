//
// Created by �Ұ����ʶ� on 2022/10/28.
//

#include <iostream>
#include<map>
using namespace std;

#include <string>

class MyCompare{
public:
    bool operator()(int v1,int v2){
        return v1>v2;
    }
};

template<typename T , typename K>
void printMap(map<T,K> &m1){
    for(typename map<T,K>::iterator it = m1.begin();it!=m1.end();it++){
        cout<<"KEY = "<<(*it).first<<"  value = "<<it->second<<endl;
    }
}

template<typename T , typename K>
void printMap(map<T,K,MyCompare> &m1){
    for(typename map<T,K>::iterator it = m1.begin();it!=m1.end();it++){
        cout<<"KEY = "<<(*it).first<<"  value = "<<it->second<<endl;
    }
}

void test01(){
    map<int,string> m1;
    m1.insert(pair<int,string>(1,"xzx"));
    m1.insert(pair<int,string>(2,"cl"));
    m1.insert(pair<int,string>(3,"qqq"));
    //printMap(m1);
    map<int,string> m2(m1);//��������
    printMap(m2);
    map<int,string> m3;
    m3 = m2;
    printMap(m3);
}

//map�����Ĵ�С�ͻ���
void test02(){
    map<int,string> m1;
    map<int,string> m2;
    m1.insert(pair<int,string>(1,"xzx"));
    m1.insert(pair<int,string>(2,"cl"));
    m1.insert(pair<int,string>(3,"qqq"));
    //m1.insert(pair<int,string>(3,"qqq"));
    cout<<"map�����Ĵ�СΪ��"<<m1.size()<<endl;
    cout<<"map�����Ƿ�Ϊ�գ�"<<m2.empty()<<endl;//0Ϊ�ǿ� 1Ϊ��
    printMap(m1);
    cout<<"====================="<<endl;
    m1.swap(m2);
    printMap(m1);

}

//map���ϲ����ɾ��
void test03(){
    map<int,string> m1;
    m1.insert(pair<int,string>(1,"xzx"));
    m1.insert(pair<int,string>(2,"cl"));
    m1.insert(pair<int,string>(3,"qqq"));
    m1.insert(make_pair(4,"ccc"));
    m1.insert(map<int,string>::value_type(5,"aaa"));
    m1[6] = "zzz";//������ʹ�������Ų���
    printMap(m1);

    m1.erase(m1.begin());
    cout<<"=================="<<endl;
    printMap(m1);
    cout<<"=================="<<endl;
    m1.erase(4);//����keyɾ��
    printMap(m1);
    cout<<"=================="<<endl;
    //m1.clear();��m1.erase(m1.begin(),m1.end());������ͬ

    m1.insert(pair<int,string>(1,"xzx"));
    m1.insert(pair<int,string>(2,"cl"));
    m1.insert(pair<int,string>(3,"qqq"));
    m1.insert(make_pair(4,"ccc"));
    printMap(m1);
    cout<<"=================="<<endl;
    map<int,string>::iterator it1 ;
    map<int,string>::iterator it2 ;
    for(map<int,string>::iterator it=m1.begin();it!=m1.end();it++){
        if((*it).first == 3){
            it1 = it;
        }
        if((*it).first == 5){
            it2 = it;
        }
    }

    m1.erase(it1,it2);
    printMap(m1);
}

//map�������Һ�ͳ��
void test04(){
    map<int,string> m1;
    m1.insert(pair<int,string>(1,"xzx"));
    m1.insert(pair<int,string>(2,"cl"));
    m1.insert(pair<int,string>(3,"qqq"));
    m1.insert(make_pair(4,"ccc"));

    //multimap���Բ����ظ�key�ļ�ֵ��,count����ͳ��keyֵ���ֵĴ���
    map<int,string>::iterator pos = m1.find(4);
    if(pos!=m1.end()){
        cout<<"�ҵ���Ԫ��"<<endl;
    } else{
        cout<<"δ�ҵ�Ԫ��"<<endl;
    }
}

//�ı�map�����Ĳ������
void test05(){
    map<int,string,MyCompare> m1;
    m1.insert(pair<int,string>(1,"xzx"));
    m1.insert(pair<int,string>(2,"cl"));
    m1.insert(pair<int,string>(3,"qqq"));
    m1.insert(make_pair(4,"ccc"));
    printMap(m1);
}
int main() {
    test05();
    //system("pause");
    return 0;
}