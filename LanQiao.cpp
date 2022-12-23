//
// Created by ÎÒ°®ÁÖÔÊ¶ù on 2022/12/23.
//

#include <iostream>
using namespace std;
long long int arr[44724];

int main() {
    long long int n;
    cin>>n;
    arr[0] = arr[1]=1;
    if(n==1){
      cout<<1;
      return 0;
    }
    for(int i=2 ; i <= 44723 ; ++i){
        for (int j = i/2; j > 0; --j) {

            if(i%2==0 && j == i/2){
                arr[j]=arr[j-1]*2;
            } else{
                arr[j] = arr[j]+arr[j-1];
            }

            if(n == arr[j]){
                cout<<(i + 1) * i / 2 + j + 1;
                return 0;
            }
        }
    }
    cout<<n*(n+1)/2+2;
    return 0;
}