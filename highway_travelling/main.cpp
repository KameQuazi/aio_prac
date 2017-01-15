#include <bits/stdc++.h>
using namespace std;

FILE* inf;
FILE* outf;

int graph[101][101], n;
int dist[101];
bool done[101];
queue<int> getto[101];


void djkis(int s){
	for(int i = 0; i < n ; i++){
		dist[i] = INT_MAX;
		done[i] = false;
	}
	dist[s] = 0;
	while(true){
		int u = -1;
		int best = INT_MAX;
		for(int i = 0; i < n; i++) if(!done[i] && dist[i] < best){
			u = i;
			best = dist[i];
		}
		if (best == INT_MAX) break;

		for (int v =0;v<n;v++) if (!done[v] && graph[u][v] != 0){
			if(dist[v] > dist[u] + graph[u][v]){
				getto[v] = getto[u];
				getto[v].push(u);
			}
			dist[v] = min(dist[v],dist[u] + graph[u][v]);
			cout << v << " " << dist[v] << endl;
		}
		done[u] = true;
	}
}


int start,end_of;
int a=1,b=1,c=1;

int main(){
	inf = fopen("highwayin.txt","r");
	outf = fopen("highwayout.txt","w");
	fscanf(inf,"%d%d%d",&n,&start,&end_of);
	cout << a <<  " " << b  <<  " " << c << endl;
	while(a!=0 and b!=0 and c!=0){
		fscanf(inf,"%d%d%d",&a,&b,&c);
		if(a==0) break;
		graph[a][b] = c;
		graph[b][a] = c;
	}
	n += 1;
	djkis(start);
	if(dist[end_of] == INT_MAX){
		fprintf(outf,"Stuck!");
		return 1;
	}
	fprintf(outf,"%d \n",dist[end_of]);
	while(!getto[end_of].empty()){
		cout<<getto[end_of].front();
		fprintf(outf,"%d ",getto[end_of].front());
		getto[end_of].pop();
	}
	fprintf(outf,"%d",end_of);
	return 1;
	
}
