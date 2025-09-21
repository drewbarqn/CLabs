#include <stdio.h>
int cubesumdig(int n);
int main(){
	int lg;
	int rg;
	scanf("%d", &lg);
	scanf ("%d", &rg);
	if(lg>=rg){
		printf("Input error\n");
		 return 1;
		 }
	for(int i = lg; i<=rg; i++){
		int x = cubesumdig(i);
		int y = i*i;
		if(x==y){
		printf("%d \n", i);
		}
	}
return 0;
}
int cubesumdig(int n) {
int x = 0;
while (n>0){
	x+=n%10;
	n/=10;
}
x = x*x*x;
return x;
}


