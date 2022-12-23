//
// Created by 我爱林允儿 on 2022/10/18.
//

#include <iostream>

using namespace std;
#include <stack>
#include <string>

template<class T>
void printStack( stack<T> &stk){

    int num = stk.size();

    //判断栈是否为空  stk.empty()
    for (int i = 0; i < num; ++i) {
        cout<<stk.top()<<endl;
        stk.pop();
    }

}

void test01(){
    stack<int> stk;
    for (int i = 0; i < 5; ++i) {
        stk.push(i);
    }

    printStack(stk);

}
int main() {
    test01();
    //system("pause");
    return 0;
}