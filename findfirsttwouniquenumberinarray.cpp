#include<bits/stdc++.h>
using namespace std;
int main(void){
vector<int> arr={2,4,6,7,4,5,6,2};
int sumxor=0;
for (int i=0;i<arr.size();i++){
sumxor=sumxor^arr[i];
}
int tmp=sumxor,newxor=0;
   int setbit=0,pos=0;
   while(setbit!=1){
       setbit=sumxor & 1;
       sumxor>>=1;
       pos++;
   }
   for (int i=0;i<arr.size();i++){
       if (((1<<(pos-1)) & arr[i]) != 0){
           newxor=newxor ^arr[i];
       }
   }
   cout<<newxor<<",";
       cout<< (newxor ^ tmp) << endl;
}
