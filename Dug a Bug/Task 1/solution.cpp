#include<bits/stdc++.h>
 
using namespace std;
 
vector<int> arr[10001];
vector<int> res;
int in[10001];
 
void kahn(int n){
   priority_queue<int, vector<int>, greater<int>>q;
    for(int i=1;i<=n;i++){
        if(in[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int curr = q.top();
        res.push_back(curr);
        q.pop();
        for(int node : arr[curr]){
            in[node]--;
            if(in[node]==0){
                q.push(node);
            }
        }
    }
    int len = res.size();
    if(len != n){
        cout<<"Sandro fails."<<"\n";
        return;
    }
    for(int i=0;i<len;i++){
        cout<<res[i]<<" ";
    }
    cout<<"\n";
}
 
int main(){
    int n,m,a,b;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        arr[a].push_back(b);
        in[b]++;
    }
    kahn(n);
} 

