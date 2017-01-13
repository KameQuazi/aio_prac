#include <bits/stdc++.h>
using namespace std;

FILE* inf;
FILE* outf;

int d,q;
int ans;

int main(){
	inf = fopen("mixin.txt","r");
	outf = fopen("mixout.txt","w");
	fscanf(inf,"%d%d",&d,&q);
	
	ans = d/q;
	if(d%q == 0){
		fprintf(outf,"%d",ans);
	}
	else{
		fprintf(outf,"%d %d/%d",ans,d%q,q);
	}
	return 0;
}

