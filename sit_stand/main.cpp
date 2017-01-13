#include <bits/stdc++.h>
using namespace std;

FILE* inf;
FILE* outf;

int r,c,t;
int rc;

int main(){
	inf = fopen("sitin.txt","r");
	outf = fopen("sitout.txt","w");
	fscanf(inf,"%d%d%d",&r,&c,&t);
	rc = r*c;
	if(rc>= t){
		fprintf(outf,"%d 0",t);
	
	}
	else{
		fprintf(outf,"%d %d",rc,t-rc);
	}
	return 0;
}

