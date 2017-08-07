#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <limits.h>
#include <bits/stdc++.h>

#define FOR(i,n) 	        for(int i=0;i<n;i++)
#define vi                      vector<int>
#define vl			vector<long>     
#define pb                      push_back 
#define mp			make_pair
#define ll			pair<long,long>
#define all(x)			x.begin(),x.end()
#define edge			vector<ll >
#define REP(it,v)		for(auto it : v)
#define INF			LONG_MAX

using namespace std;

#ifndef INP
istream &in=cin;
#else
ifstream file("inp12.txt");
istream &in=file;
#endif

vi p,ran,a,k;

void make_set(int n) {
	FOR(i,n) {
		p.pb(i);
		ran.pb(0);
	}
}	

int find_set(int x) {
	return x==p[x]?p[x]:find_set(p[x]);
}

void link(int x, int y) {
	if(ran[x] > ran[y]) { 
		p[y] = x;
	}
	else {
		p[x] = y;
		if(ran[x] == ran[y]) ++ran[y];	
	}
}

void union_set(int x, int y) {
	link(find_set(x),find_set(y));
}

int main() {
	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
	int q;
	long n,m,c,r;
	in >> q;
	while(q-->0) {
		in >> n >> m >> c >> r;
		p.clear();
		ran.clear();
		make_set(n);
		a.assign(n,0);
		k.clear();
		while(m-->0) {
			int u,v;
			in >> u >> v;
			--u,--v;
			if(find_set(u) != find_set(v)) {
				union_set(u,v);
			}
		}
		FOR(i,p.size()) {
			if(i != find_set(i))
				++a[find_set(i)];
		}
		long s=0;
		FOR(i,a.size()) {
			if(a[i]!=0) { 
				k.pb(a[i]+1);
				s+=a[i]+1;
			}	
		}	
		long long sum=0;
		FOR(i,k.size()) {
			sum+=(c<=r)?(k[i]*c):((k[i]-1)*r+c);
		}
		cout << (long long)sum+(n-s)*c << endl;
	}
}
