// found & not found

#include<iostream>
using namespace std;
int main(){
int num[10]={2,3,6,8,9,54,8,4,3,3};
int input=0,count=0;
cout<<"Enter Number to count how many times occur =\t";
cin>>input;


for(int i=0;i<10;i++){
   if(input==num[i]){
      count+=1;
      
   }
   
}
 cout<<"This "<<input<<" was occurs in "<<count<<"\t times.";

}
