/*

Given a list of lowercase alphabet strings words and a lowercase alphabet string s,
return whether or not the string can be broken down using the list of words. It's
 not required to use all of the words and you can reuse words.
*/

#include<bits/stdc++.h>
using namespace std;

map<string,int> m;
vector<int> dp;

bool func(string s,int idx,int l){
    if(idx==l) return true;
    if(dp[idx]!=-1) return dp[idx];
    bool flag=false;
    for(int i=idx;i<l;i++){
        string s1=s.substr(idx,i-idx+1);
        if(m.find(s1)!=m.end()) flag=flag || func(s,i+1,l);
    }
    return dp[idx]=flag;
}

bool solve(vector<string>& words, string s) {
    m.clear();
    for(auto x:words) m[x]++;
    int l=s.length();
    if(l==0) return true;
    dp.clear();
    dp.resize(l,-1);
    return func(s,0,l);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    // cout<<t<<endl;
    while(t--){
        int n;
        cin>>n;
        vector<string> words(n);
        for(int i=0;i<n;i++) cin>>words[i];
        string s;
        cin>>s;
        if(solve(words,s)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}