#include<bits/stdc++.h>
using namespace std;
#define inf 10000000
long long dist[5005];
vector<pair<int,int>>graph[5005];
void dijkstra(int src)
{
   priority_queue<pair<int,int>,vector<pair<int,int>>,greater< pair<int,int>>>pq;
   for(int i=1;i<=5005;i++)dist[i]=INT_MAX;
   pq.push({0,src});
   dist[src]=0;
   while(!pq.empty())
   {
       int curdis=pq.top().first;
       int curnod=pq.top().second;
       pq.pop();
           for(auto child:graph[curnod])
           {
               if(dist[child.first]>curdis+child.second)
               {
                   dist[child.first]=curdis+child.second;
                   pq.push({dist[child.first],child.first});
               }
           }
   }
}
int main()
{
    int t;cin>>t;
    for(int k=1;k<=t;k++)
    {
        int n;cin>>n;
        int r;cin>>r;
        for(int i=1;i<5005;i++)
        graph[i].clear();
        for(int i=0;i<r;i++)
        {
            int a,b,w;
            cin>>a>>b>>w;
            graph[a].push_back({b,w});
            graph[b].push_back({a,w});
        }
        int dist2[n+5];
        dijkstra(1);
        for(int i=1;i<=n;i++)dist2[i]=dist[i];
        dijkstra(n);
        int ans=INT_MAX;
        for(int i=1;i<=n;i++)
        {
            for(auto x:graph[i])
            {
                int d=dist2[i]+dist[x.first]+x.second;
                if(d>dist2[n])ans=min(ans,d);
            }
        }
        printf("Case %d: ",k);
        cout<<ans<<endl;


    }
}
