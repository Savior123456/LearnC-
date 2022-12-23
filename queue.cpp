//
// Created by 我爱林允儿 on 2022/10/18.
//

#include <iostream>

using namespace std;
#include <queue>
#include <string>
//对栈相反，先进先出
//栈是先进后出

class Person{
public:

    Person(string name,int age){
        this->m_Age = age;
        this->m_Name = name;
    }
    int m_Age;
    string m_Name;
};

void test01(){
    queue<Person> q;

    Person p1("唐僧",30);
    Person p2("孙悟空",500);
    Person p3("猪八戒",3000);
    Person p4("沙僧",200);

    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);

    //只要队列不为空，查看队头，查看队尾，出队

    while(!q.empty()){
        cout<<"当前队头元素   ----    姓名："<<q.front().m_Name<<"年龄："<<q.front().m_Age<<endl;
        q.pop();
    }

    cout<<"当前queue容器还有"<<q.size()<<"个元素！"<<endl;

}
int main() {
    test01();
    //system("pause");
    return 0;
}