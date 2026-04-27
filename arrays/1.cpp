// Min Max

#include<iostream>
using namespace std;
int main(){
int num[10]={2,3,6,8,9,54,8,4,83,32};
int min=num[0],max=num[0];


for(int i=0;i<10;i++){
   if(num[i]>max){
       max=num[i];
   }
   if(num[i]<min){
       min=num[i];
   }
}
 cout<<"Minimum Number =\t"<<min<<endl;
 cout<<"Max Number =\t"<<max<<endl;

}
