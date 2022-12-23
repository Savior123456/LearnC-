//
// Created by 我爱林允儿 on 2022/10/28.
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
    map<int,string> m2(m1);//拷贝构造
    printMap(m2);
    map<int,string> m3;
    m3 = m2;
    printMap(m3);
}

//map容器的大小和互换
void test02(){
    map<int,string> m1;
    map<int,string> m2;
    m1.insert(pair<int,string>(1,"xzx"));
    m1.insert(pair<int,string>(2,"cl"));
    m1.insert(pair<int,string>(3,"qqq"));
    //m1.insert(pair<int,string>(3,"qqq"));
    cout<<"map容器的大小为："<<m1.size()<<endl;
    cout<<"map容器是否为空："<<m2.empty()<<endl;//0为非空 1为空
    printMap(m1);
    cout<<"====================="<<endl;
    m1.swap(m2);
    printMap(m1);

}

//map集合插入和删除
void test03(){
    map<int,string> m1;
    m1.insert(pair<int,string>(1,"xzx"));
    m1.insert(pair<int,string>(2,"cl"));
    m1.insert(pair<int,string>(3,"qqq"));
    m1.insert(make_pair(4,"ccc"));
    m1.insert(map<int,string>::value_type(5,"aaa"));
    m1[6] = "zzz";//不建议使用中括号插入
    printMap(m1);

    m1.erase(m1.begin());
    cout<<"=================="<<endl;
    printMap(m1);
    cout<<"=================="<<endl;
    m1.erase(4);//按照key删除
    printMap(m1);
    cout<<"=================="<<endl;
    //m1.clear();与m1.erase(m1.begin(),m1.end());功能相同

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

//map容器查找和统计
void test04(){
    map<int,string> m1;
    m1.insert(pair<int,string>(1,"xzx"));
    m1.insert(pair<int,string>(2,"cl"));
    m1.insert(pair<int,string>(3,"qqq"));
    m1.insert(make_pair(4,"ccc"));

    //multimap可以插入重复key的键值对,count可以统计key值出现的次数
    map<int,string>::iterator pos = m1.find(4);
    if(pos!=m1.end()){
        cout<<"找到了元素"<<endl;
    } else{
        cout<<"未找到元素"<<endl;
    }
}

//改变map容器的插入次序
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