#include<iostream>
using namespace std;
int main()
{
	int num,sum=0;
	cout<<"enter the number:";
	cin>>num;
	for(int i=1;i<=num/2;i++)
	{
		if(num%i==0)
		{
			sum=sum+i;
		}
	}
	if(sum==num)
	{
		cout<<"is a perfect number";
     }else{
	    cout<<"is not perfect number";
	}
	return 0;
}
