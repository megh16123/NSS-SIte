
 #include <iostream>
 #include <cstdlib>
 #include <cstring>
 #include <cstdio>
 #include <cmath>
 #include <algorithm>
 #include <ctime>
 #include <vector>
 #include <queue>
 #include <map>
 #include <set>
 using namespace std;
 typedef long long LL;
 const int MAXN = 1011;
 const int MAXM = 20011;
 const int MOD = 2000000;
 int n,m,L,s,t,ecnt;
 int first[MAXN],to[MAXM],next[MAXM],w[MAXM],dis[MAXN];
 int tag[MAXM];
 int dui[MAXN*10],head,tail;
 bool in[MAXN],ok;
 
 inline int getint()
 {
        int w=0,q=0; char c=getchar();
        while((c<'0' || c>'9') && c!='-') c=getchar(); if(c=='-') q=1,c=getchar(); 
        while (c>='0' && c<='9') w=w*10+c-'0', c=getchar(); return q ? -w : w;
 }
 
 inline void SPFA(){
     //memset(dis,63,sizeof(dis));
     for(int i=1;i<=n;i++) dis[i]=1000000001;
     dis[s]=0;   head=tail=0;   dui[++tail]=s; memset(in,0,sizeof(in)); in[s]=1;
     while(head!=tail) {
     head%=n; head++; int u=dui[head]; in[u]=0;
     for(int i=first[u];i>0;i=next[i]) {
         int v=to[i];
         if(dis[v]>dis[u]+w[i]) {
         dis[v]=dis[u]+w[i];
         if(!in[v]) { tail%=n; tail++; dui[tail]=v; in[v]=1; }
         }
     }
     }
 }
 
 inline void work(){
     //memset(first,-1,sizeof(first));
     n=getint(); m=getint(); L=getint(); s=getint()+1; t=getint()+1;
     int x,y,z;ecnt=1;
     for(int i=1;i<=m;i++) {
     x=getint()+1; y=getint()+1; z=getint();
     next[++ecnt]=first[x]; first[x]=ecnt; to[ecnt]=y; w[ecnt]=z; if(z==0) tag[ecnt]=1,w[ecnt]=1;
     next[++ecnt]=first[y]; first[y]=ecnt; to[ecnt]=x; w[ecnt]=z; if(z==0) tag[ecnt]=1,w[ecnt]=1;
     }
     SPFA();   if(dis[t]>L) { printf("NO"); return ; }
     ok=false;
     for(int i=1;i<=n;i++) {
     for(int j=first[i];j>0;j=next[j]) {
         if(j & 1)
         if(tag[j]) {
             if(dis[t]==L){ ok=true ; break;}
             if(dis[t]<L) {
             w[j]=w[j^1]=L-dis[t]+1;
             SPFA();        
             }
         }
     }
     if(ok) break;
     }
     if(!ok && dis[t]!=L) { printf("NO"); }
     else{
     printf("YES\n");
     for(int i=1;i<=n;i++)  
         for(int j=first[i];j>0;j=next[j]) 
         if(j&1)
             printf("%d %d %d\n",to[j]-1,to[j^1]-1,w[j]);
     }
 }
 
 int main()
 {
   work();
   return 0;
 }