#include<iostream>
using namespace std;
int main(){
	int data[10]={5,3,4,5,6};
	int size = 6;
	int key;
	cout<<"Enter value to search:";
	
	cin>>key;
	int i=0;
	while(i<size && data[i]!=key){
		i++;
	}
	if(i<size){
		cout<<"Found at index:"<<i<<endl;
	}
	else{
		cout<<"Not found:"<<endl;
	}
	return 0;
}
