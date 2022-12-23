//
// Created by 我爱林允儿 on 2022/9/23.
//
#include <iostream>
#include <string.h>
using namespace std;

char* replaceSpace(char* s){

    int num = 0;
    for(int i=0;i<strlen(s);i++){
        if(s[i]==' '){
            num++;
        }
    }
    char *arr=(char*)malloc(sizeof(char)*(strlen(s)+2*num+1));
    int j=0;
    for(int i = 0;i<strlen(s);i++){
        if(s[i]==' '){
                arr[j++]='%';
                arr[j++]='2';
                arr[j++]='0';

        }else{
                arr[j++]=s[i];
        }
    }
    arr[j]='\0';
    return arr;
}

int findManChildStr(char *s){
    if(strlen(s)==0){
        return 0;
    }
    int left = 0,right = 0;
    int temp = 1 ,temp1=1;
    while(right <= strlen(s) ){
        right++;
        temp1++;
        if(right == strlen(s)){
            break;
        }
        int mid = left;
        for(int i = mid;i<right;i++){
            if(s[i]==s[right]){
                if(i==left&&right==left+1){
                    left++;
                    temp1--;
                    break;
                }else{
                    left=i;
                    temp1--;
                    if(temp<temp1){
                        temp=temp1;
                    }
                    left++;
                    temp1=right-left+1;
                    break;
                }
            }
        }
        if(temp<temp1){
            temp=temp1;
        }
    }
    return temp;
}


int main(){
    char* arr = replaceSpace("hello world");
    puts(arr);

    int count = findManChildStr("au");
    cout<<count<< endl;
//    cout<<"shajs"<<endl;
    return 0;
}