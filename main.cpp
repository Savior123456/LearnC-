#include <iostream>
#include <string>
using namespace std;

class Phone
{
    friend class Person;
private:
    string m_PhoneName;
};
class Person
{
public:

    Person(){}

    Person(string name,string phone){
        this->m_Name=name;
        m_Phone.m_PhoneName=phone;
    }

    string getPhoneName(){
        return m_Phone.m_PhoneName;
    }
    string getName(){
        return this->m_Name;
    }

    void setName(string name){
        this->m_Name=name;
    }
private:
    string m_Name;
    Phone m_Phone;
public:
    static string m_Age;
};

string Person::m_Age = "19";

void test(){
    Person person("����","123456");
    cout<<"�ҵ������ǣ�"<<person.getName()<<endl<<"�ҵ��ֻ������ǣ�"<<person.getPhoneName()<<endl<<"�ҵ�����Ϊ��"<<Person::m_Age<<endl;
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    test();
    int number;
    cin>>number;
    cout<<number;
    //system("pause");
    return 0;
}
