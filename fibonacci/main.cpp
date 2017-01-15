#include <bits/stdc++.h>
using namespace std;

FILE* inf;
FILE* outf;
int num;
int fib[1600];

int cry(int x){
	if(x==1 or x==2){
		return 1;
	}
	if(fib[x] == 0){
		fib[x] = cry(x-1) + cry(x-2);
		fib[x] %= 1000;
	}
	return fib[x];
}





int main(){
	inf = fopen("fibin.txt","r");
	outf = fopen("fibout.txt","w");
	fscanf(inf,"%d",&num);
	fprintf(outf,"%d",cry(num%1500)%1000);
	

	return 0;
}
