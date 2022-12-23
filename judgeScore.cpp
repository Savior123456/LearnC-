//
// Created by �Ұ����ʶ� on 2022/10/18.
//

#include <iostream>
using namespace std;
#include <string>
#include <vector>

class Person
{
public:
    Person(string name,int score){
        this->m_name = name;
        this->m_score = score;
    }

    string getName(){
        return this->m_name;
    }

    int getScore(){
        return this->m_score;
    }


private:
    string m_name;
    int m_score;
};


void test01(){

    vector<Person> judger;
    string name;
    int score;
    for(int i = 0;i<5;i++){
        cout<<"�������"<<i<<"��ѡ�ֵ�����:";
        cin>>name;
        cout<<"�������"<<i<<"��ѡ�ֵĳɼ�:";
        cin>>score;
        judger.push_back(Person(name,score));
    }

    int max = 0;
    int min = 0;

    for(int i = 0;i<5;i++){

        if(judger.at(max).getScore()<judger.at(i).getScore()){
            max = i;
        }

        if(judger.at(min).getScore()>judger.at(i).getScore()){
            min = i;
        }
    }

    double avg_score = 0;
    for(int i = 0;i<5;i++){
        avg_score+=(double)judger.at(i).getScore();
    }

    avg_score -= (judger.at(max).getScore()+judger.at(min).getScore());
    avg_score /=3;
    cout<<"����ѡ��ȥ����߷ֺ���ͷֵ�ƽ����Ϊ:"<<avg_score<<endl;

}
int main() {
    test01();
    //system("pause");
    return 0;
}