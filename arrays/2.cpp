// found & not found

#include<iostream>
using namespace std;
int main(){
int num[10]={2,3,6,8,9,54,8,4,83,32};
int input=0;
cout<<"Enter Number to Find in Array=\t";
cin>>input;


for(int i=0;i<10;i++){
   if(input==num[0]){
      cout<<"Number Found in Array";
      break;
   }
   else{
      cout<<"Number Not Found in Array";
   }
}


}
