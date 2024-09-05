#include<stdio.h>
int fibnocci(int n){
	

if(n<=1){
	return n;
}
else{
	return fibnocci(n-1)+fibnocci(n-2);
}
}
int main()
{
	int n;
	printf("enter the numbers upto  limit:");
	scanf("%d",&n);
	printf("fibnocci series:");
	for(int i=0;i<n;i++){
		printf(" %d ",fibnocci(i));
	}
	return 0;
}
