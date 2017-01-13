#include <bits/stdc++.h>
using namespace std;

FILE* inf;
FILE* outf;
int que;
int total = 0;
int sec = 0;

int main(){
	inf = fopen("madonna.in","r");
	outf = fopen("madonna.out","w");
	fscanf(inf,"%d",&que);
	for(int i =0;i<que;i++){
		int t,s;
		fscanf(inf,"%d%d",&t,&s);
		if(total > s){
			total -= s;
			total += t;
		}
		else{
			sec += (s-total);
			total = t;
		}	
	}
	fprintf(outf,"%d",sec);	
	return 0;
}
