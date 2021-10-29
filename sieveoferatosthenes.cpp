#include<bits/stdc++.h>
using namespace std;
void prime(long int);
int main(){
    long int n;
    cin>>n;
    prime(n);
}
void prime(long int n){
    long int arr[n]={0};
    for(long int i=2;i<=n;i++){
        if(arr[i]==0){
            for (long int j=i*i;j<=n;j+=i){
                arr[j]=1;
            }
        }
    }
    for(long int i=2;i<=n;i++){
        if (arr[i]==0){
            cout<<i<<" ";
        }
    }
}