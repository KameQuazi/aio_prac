#include <bits/stdc++.h>
using namespace std;

FILE* inf;
FILE* outf;
int queue2[100000];
int qfront = 0;
int qback = 0;

void qpush(int item){
	queue2[qback] = item;
	qback = qback+1;
}

void qpop(){
	int popped_item;
	popped_item = queue2[qfront];
	qfront = qfront + 1;
}

int main(){
	inf = fopen("queuesin.txt","r");
	outf = fopen("queuesout.txt","w");

	while(1){
		int iter;
		fscanf(inf,"%d",&iter);
		if(iter == -1){
			qpop();
			if (qfront == qback){
				fprintf(outf,"%s","queue is empty!");
			}
		}
		else if(iter ==-2){
			return 0;
		}
		else{
			qpush(iter);
		}
		if(qfront != qback){
			for(int i = qfront;i<qback;i++){
				fprintf(outf,"%d ",queue2[i]);
			}	
		}
		fprintf(outf,"\n");
	}
	return 0;
}
