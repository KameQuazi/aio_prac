#include <bits/stdc++.h>
using namespace std;

int dist(int a,int b, int c, int d){
	int y;
	y = abs(c-a) + abs(d-b);
	return y;
}

int man(int a, int b, int c, int d){
	int y;
	y = pow(abs(c-a),2) + pow(abs(d-b),2);
	return y;
}
FILE* inf;
FILE* outf;

int row,col,prow,pcol,frow,fcol,que;

int main(){
	inf = fopen("probein.txt","r");
	outf = fopen("probeout.txt","w");
	fscanf(inf,"%d%d%d%d%d%d%d",&row,&col,&prow,&pcol,&frow,&fcol,&que);
	for(int i = 0;i<que;i++){
		int x,y,water,lava; // x,y is the coords of the querey, water and lava is dist from water / lava
		fscanf(inf,"%d%d",&x,&y);
		if(abs(prow-frow) == abs(pcol - fcol)){
			water = max(abs(prow-x),abs(pcol-y));
			lava = max(abs(frow-x),abs(fcol-y));
		}
		else{
			water = abs(prow-x) + abs(pcol-y);
			lava = abs(frow-x) + abs(fcol-y);
		}
		
		if (water==lava){
			fprintf(outf,"MOUNTAINS\n");
		}
		else if(water < lava){
			fprintf(outf,"WATER\n");
		}
		else{
			fprintf(outf,"LAVA\n");
		}
	}
		
	return 0;
}

