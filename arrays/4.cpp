// grade roll marks gpa


#include<iostream>
using namespace std;
int main(){

char grade[10] = {'A', 'B', 'A', 'C', 'B', 'F', 'A', 'B', 'C', 'A'};
int roll[10] = {101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
int marks[10] = {85, 72, 91, 55, 78, 32, 95, 81, 64, 88};
float gpa[10] = {3.8, 3.2, 4.0, 2.5, 3.5, 1.2, 3.9, 3.6, 2.8, 3.8};
int roll_num=0;
bool found = false;
cout<<"Enter Roll Number to Find Student Record"<<endl;
cin>>roll_num;

for(int i=0;i<10;i++){
    if(roll_num==roll[i]){
        cout<<"------Record Found------"<<endl;
        cout<<"Roll Number =\t"<<roll_num<<endl;
        cout<<"Marks =\t"<<marks[i]<<endl;
        cout<<"GPA =\t"<<gpa[i]<<endl;
        cout<<"Grade =\t"<<grade[i]<<endl;
        found = true;
        break;
    }
    

}

if (!found) {
        cout << "------No Record Found------" << endl;
    }
    return 0;

}