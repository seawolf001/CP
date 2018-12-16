/*********** [ scopeInfinity ] ******************/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef std::vector<ll> vll;
typedef std::vector<int> vi;

#define forv(it,m) for (auto it = (m).begin(); it != (m).end(); ++it)
#define rep(i,n) for (int i=0;i<n;i++)
#define endl '\n' 
#define mp make_pair
#define pb(x) push_back((x))
#define what_is(x) cerr << #x << " is " << (x) << endl;

ll MOD = 1e9+7;
ll PRIME =  102838201;
ll INF = LLONG_MAX/4;

vector<string> &split(const std::string &s, char delim, vector<string> &e) {
    stringstream ss(s);
    string item;
    while(getline(ss, item, delim))
        e.push_back(item);
    return e;
}


ll Pow(ll a ,ll b ,ll Mo){
    ll ans = 1;
    for (; b; b >>= 1, a = a * a % Mo)
        if (b&1) ans = ans * a % Mo;
    return ans;
}


ll nCr(ll n,ll r) {
    static ll MAXF = 1e6;
    static std::vector<ll> fact(MAXF,1);
    for (int i = 1; i < MAXF; ++i)  fact[i]=(fact[i-1]*i)%MOD;
    MAXF=0;
    return (fact[n]*Pow((fact[r]*fact[n-r])%MOD,MOD-2,MOD))%MOD;
}

vector<int> Zfunc(string &s) {
    int n=s.length();
    vector<int> z(n,0);
    for(int i=1,l=0,r=0;i<n;i++) {
        if(i<=r) 
            z[i] = min(z[i-l],r-i+1);
        while(i+z[i]<n && s[i+z[i]]==s[z[i]])
            z[i]++;
        if(r<i+z[i]-1)
            l=i,r=i+z[i]-1;
    }
    return z;
}
const ll MC = 1e6+10;
ll n2ForColorSS[MC] = {0};
ll nForColorSS[MC] = {0};


int get(int N) {
    N+=2;
		ll s = 0;
		while(N) {
			s=nForColorSS[N]+s;
			N=N-(N&-N);
		}
		return s;
	}

	void update(int index,int x) {
        index+=2;
		while(index<MC) {
			nForColorSS[index]+=x;
			index=index+(index&-index);
		}
	}

int get2(int N) { N+=2;
		ll s = 0;
		while(N) {
			s=n2ForColorSS[N]+s;
			N=N-(N&-N);
		}
		return s;
	}

	void update2(int index,int x) { index+=2;
		while(index<MC) {
			n2ForColorSS[index]+=x;
			index=index+(index&-index);
		}
	}
ll n;
struct edge
{
	int id;
	int a,b;
	int c;
	edge(int id,int x,int y,int z) {
		this->id=id;a=x;b=y;c=z;
	}
	int counter(int s) {
		// cerr<<"X "<<s<<" \t "<<a<<' '<<b<<endl;
		assert(s==a || s==b);
		// cerr<<"U";
		if(s==a)
			return b;
		// cerr<<"A";
		
		return a;
		// cerr<<"B";

	}
};
std::vector<edge> edges;
std::vector<std::vector<int> > G;
std::vector<ll> nodesInComp;
std::vector<ll> nForColor;
std::vector<ll> n2ForColor;

int COMP = 0;
std::vector<int> componentColor;
std::vector<int> edgeToComp;
void dfs(int s,int p,int col,int cmp) {
	// cerr<<">>>>> "<<(s+1)<<endl;
		
	// cerr<<"Node "<<(s+1)<<" : "<<(G[s].size())<<endl;
	// rep(i,G[s].size())
	// cerr<<" To "<<(edges[ G[s][i] ].counter(s) + 1 )<<" ";
	// cerr<<endl;
	for(int i=0;i<G[s].size();i++)
	{
		// if(s==0)
		// 	continue;
		// cerr<<"Here "<<G[s][i]<<endl;
		edge e = edges[G[s][i]];
		// cerr<<"\n:";
		int next = e.counter(s);
		// cerr<<"NExt : "<<next<<endl;
		if(next==p)
			continue;
		// cerr<<"Not here";
		if(col!=e.c) {
			// cerr<<"NEW 1";
			// Edge with new color
			componentColor.push_back(e.c);
			assert(edgeToComp[e.id]==-1 || edgeToComp[e.id]==COMP);
			edgeToComp[e.id]=COMP;
			// me and other both are in new comp
			nodesInComp.push_back(2);
			COMP++;
			nForColor[e.c]+=2;
			// cerr<<"NEW ";
		} else {
			// cerr<<"Old 1";
			nodesInComp[cmp]++;
			edgeToComp[e.id]=cmp;
			nForColor[e.c]++;

			// cerr<<"Old ";
		}
		dfs(e.counter(s),s,e.c,edgeToComp[e.id]);
		// cerr<<"Returning to node "<<(s+1)<<endl;
	}
	// cerr<<"COmpleted node "<<(s+1)<<endl;
}

/*
std::vector<ll> col;
map<int,int> compToCol;
map<int,std::set<int> > nodesInComp;
map<int,int> edgeToComp;
int CCS = 0;
void dfs(int s,int p,int col_,int cc,int ed) {
	nodesInComp[cc].insert(s);
	edgeToComp[ed] = cc;
	compToCol[cc] = col_;
	rep(i,G[s].size())
	if(G[s][i].first!=p)
	{
		if(col[ G[s][i].second ]!=col_) {
			nodesInComp[ CCS+1 ].insert(s);
			dfs(G[s][i].first,s,col[G[s][i].second],++CCS,G[s][i].second);
		} else
		dfs(G[s][i].first,s,col_,cc,G[s][i].second);
	}
}
ll getComp(ll n) {
	// edge to component
	return edgeToComp[n];
} 
ll getP(ll c) {
	//pick 2 from size of c 
	ll s = nodesInComp[c].size();
	return s*(s-1)/2;
}
ll n;
	
void changeCol(int e,int c,int leaf) {
	col[e]=c;
	nodesInComp.clear();
	compToCol.clear();
	edgeToComp.clear();
	CCS = 0;
	dfs(leaf,-1,col[G[leaf][0].second],CCS,G[leaf][0].second);
}*/
int findEdge(int node,int p,int col) {
	rep(i,G[node].size()) {
		if(edges[G[node][i]].c==col)
			if(edges[G[node][i]].counter(node)!=p)
				return edges[G[node][i]].id;
	}
	return -1;
}
int countNode(int s,int p,int oldc) {
	// cout<<"At "<<(s+1)<<endl
	int count = 1;
	rep(i,G[s].size())
	{
		edge e = edges[G[s][i]];
		if(e.counter(s)==p)
			continue;
		if(e.c==oldc) {
			count+=countNode(e.counter(s),s,oldc);
		}
	}
	return count;
}
void updateComponent(int s,int p,int oldc,int cmp) {
	rep(i,G[s].size())
	{
		edge e = edges[G[s][i]];
		// cerr<<" Checking Edge Comp of "<<e.id<<"("<<e.c<<") to "<<cmp<<endl;
		int n = e.counter(s);
		// cerr<<"CNode "<<s<<" next "<<n<<" and p = "<<p<<endl;
		if(n==p)
			continue;
		// cerr<<"Edge Color : "<<e.c<<" change comp of edge having color "<<oldc<<endl;
		if(e.c==oldc) {
			edgeToComp[e.id] = cmp;
			// cerr<<"Updated Edge Comp of "<<e.id<<" to "<<cmp<<endl;
			updateComponent(e.counter(s),s,oldc,cmp);
		}
	}
}
void checkComponents(int s,int p,int cmp,int c,string &msg) {
	rep(i,G[s].size()){
		edge e= edges[G[s][i]];
		int n = e.counter(s);
		if(s==61) {
			cerr<<" >> "<<s<<" and "<<n<<endl;
		}
		if(n!=p) {
			if(e.c==c) {
				cerr<<e.c<<" Color with comp "<<edgeToComp[e.id]<<" and color "<<componentColor[edgeToComp[e.id]]<<endl;
				cerr<<e.id<<" : "<<edgeToComp[e.id]<<" needs "<<cmp<<"("<<componentColor[cmp]<<")"<<endl;
				int val = (edgeToComp[e.id]==cmp);
				cerr<<e.a<<" "<<e.b<<"ffffffff\n";
				if(!val) {
					cerr<<"At "<<s<<" "<<msg<<endl;
				}
				assert(val);
				checkComponents(n,s,cmp,e.c,msg);
			} else {
				checkComponents(n,s,edgeToComp[e.id],e.c,msg);
			}
		}
	}
}
void checkComponents(int leaf,string msg){
	return ;
		checkComponents(leaf,-1,edgeToComp[ G[leaf][0] ], edges[ G[leaf][0] ].c ,msg );
	
}

int main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false);cin.tie(0);
	// cout<<fixed<<setprecision(1);
	
	cin>>n;
	G.resize(n);
	// edges, edgeToComp, componentColor, nForColor, n2ForColor
	edgeToComp.resize(n-1,-1);
	nForColor.resize(1e6+1,0);
	n2ForColor.resize(1e6+1,0);

	rep(i,n-1) {
		int a,b,c;
		cin>>a>>b>>c;
		a--;b--;
		// c=(c%10);//+1;
		G[a].push_back(edges.size());
		G[b].push_back(edges.size());
		// cout<<(a+1)<<" > "<<edges.size()<<endl;
		// cout<<(b+1)<<" > "<<edges.size()<<endl;

		edges.push_back(edge(i,a,b,c));
	}
	// return 0;
	int leaf = -1;
	rep(i,n)
	if(G[i].size()==1)
		leaf = i;
	//assert(leaf!=-1);
	{
		edge e = edges[ G[leaf][0] ];
		componentColor.push_back(e.c);
		edgeToComp[e.id]=COMP;
		nodesInComp.push_back(1);
		COMP++;
		nForColor[e.c]++;

		dfs(leaf,-1,e.c,COMP-1);
		rep(i,COMP) {
			n2ForColor[componentColor[i]]+=nodesInComp[i]*nodesInComp[i];
                 update2(componentColor[i],n2ForColor[componentColor[i]]);
                 update(componentColor[i],nForColor[componentColor[i]]);
					
			// cerr<<"Comp "<<i<<" Col "<<componentColor[i]<<" : "<<n2ForColor[componentColor[i]]<<" : "<<nForColor[componentColor[i]]<<endl;
		}
		// return 0;
	}
	checkComponents(leaf,"Failed at Init");
				
	// changeCol(leaf,col[leaf],leaf);
	ll q;
	cin>>q;
int ERR =0;

ll asd = 1,asd2=23;
		
	while(q--) {
		ll a,b,c;;
		cin>>a>>b;
		// a=1;
		// asd=(rand())%30;
		// b=1+asd;
	// 	// continue;
		// if(a!=1 && ERR)
		// 	assert(0);
		if(a==1) {
			cin>>c;
			asd2=(rand())%100;
			// c=(asd2)%10;
			ERR=1;
			{
				b--;
				int u = edges[b].a;
				int v = edges[b].b;
				int oldc = edges[b].c;
				// c=oldc;
				// cerr<<a<<" "<<b<<" "<<c<<endl;
				
				if(oldc==c)
					continue;
				/*
				std::vector<ll> nodesInComp;
				std::vector<ll> nForColor;
				std::vector<ll> n2ForColor;

				int COMP = 0;
				std::vector<int> componentColor;
				std::vector<int> edgeToComp;
				*/

				// Remove of OldColor edge
				checkComponents(leaf,"Failed in Starting");
					
				{
					int findOnU = findEdge(u,v,oldc);
					int findOnV = findEdge(v,u,oldc);
					assert(findOnU!=b);
					assert(findOnV!=b);

						
					if(findOnV>=0 && findOnU>=0) {
						// continue;
						//cerr<<"Case 1 1 : \n";
						// cerr<<u<<","<<v<<"\t"<<findOnU<<","<<findOnV<<endl;
						// cerr<<endl;
						int compU = edgeToComp[findOnU];
						int compV = edgeToComp[findOnV];
						// cerr<<compU<<" "<<compV<<endl;
						// cerr<<componentColor[ compU]<<" "<<componentColor[ compV ]<<endl;
						// cerr<<edges[b].c<<endl;
						assert(compU==compV);
						
						// Split b/w V and U,, create new component for V
						// V is on 'b' size
						int nodesInV = countNode(edges[b].b,edges[b].a,oldc);
						int nodesInU = countNode(edges[b].a,edges[b].b,oldc);
						// cout<<nodesInU<<" "<<nodesInV<<" : "<<oldc<<endl;

						ll countN2 = n2ForColor[oldc];
						countN2 -= nodesInComp[compU]*nodesInComp[compU];
						countN2 += nodesInV*nodesInV + nodesInU*nodesInU;
						
						{
							componentColor.push_back(oldc);
							nodesInComp.push_back(nodesInV);
							updateComponent(edges[b].b,edges[b].a,oldc,COMP);
							// edgeToComp[findOnV]=COMP;
							COMP++;
						}
						nodesInComp[compU]=(nodesInU);
                        
                        update2(oldc,countN2 - n2ForColor[oldc] );
						n2ForColor[oldc] = countN2;
					} else if(findOnV<0 && findOnU<0) {
						//cerr<<"Case 1 2\n";
                        
                        update2(oldc,-4 );
                        update(oldc,-2 );
						
						n2ForColor[oldc] -= 4;
						nForColor[oldc] -= 2;
					} else if(findOnV>=0 && findOnU<0) {
						// int compU = edgeToComp[findOnU];
						int compV = edgeToComp[findOnV];
						//cerr<<"Case 1 3\n";
						
						assert(oldc==componentColor[compV]);
						
						// Split b/w V and U,, create new component for V
						// V is on 'b' size
						int nodesInV = countNode(edges[b].b,edges[b].a,oldc);
						// int nodesInU = countNode(edges[b].a,edges[b].b,oldc);
						// cout<<nodesInU<<" "<<nodesInV<<" : "<<oldc<<endl;

						ll countN2 = n2ForColor[oldc];
						countN2 -= nodesInComp[compV]*nodesInComp[compV];
						nodesInComp[compV]--;
						countN2 += nodesInComp[compV]*nodesInComp[compV];
                        
                        update2(oldc,countN2 - n2ForColor[oldc] );
						n2ForColor[oldc] = countN2;
                        update(oldc,-1);
						
						nForColor[oldc]--;

					} else if(findOnV<0 && findOnU>=0) {
						int compU = edgeToComp[findOnU];
						// int compV = edgeToComp[findOnV];
						//cerr<<"Case 1 4\n";
						
						assert(oldc==componentColor[compU]);
						
						// Split b/w V and U,, create new component for V
						// V is on 'b' size
						// int nodesInV = countNode(edges[b].b,edges[b].a,oldc);
						int nodesInU = countNode(edges[b].a,edges[b].b,oldc);
						// cout<<nodesInU<<" "<<nodesInV<<" : "<<oldc<<endl;

						ll countN2 = n2ForColor[oldc];
						countN2 -= nodesInComp[compU]*nodesInComp[compU];
						nodesInComp[compU]--;
						countN2 += nodesInComp[compU]*nodesInComp[compU];
                        
                        update2(oldc,countN2 - n2ForColor[oldc] );
						n2ForColor[oldc] = countN2;
						nForColor[oldc]--;
                        update(oldc,-1);

					} 
					 // else assert(0);
				}

				// Add of new color edge
				{
					int findOnU = findEdge(u,v,c);
					int findOnV = findEdge(v,u,c);
					assert(findOnU!=b);
					assert(findOnV!=b);

					if(findOnV>=0 && findOnU>=0) {
						int compU = edgeToComp[findOnU];
						int compV = edgeToComp[findOnV];
						//cerr<<"Case 2 1\n";
						
						// cerr<<compU<<" "<<compV<<endl;
						// cerr<<componentColor[ compU]<<" "<<componentColor[ compV ]<<endl;
						// cerr<<edges[b].c<<" needs to change to "<<c<<endl;
						
						assert(componentColor[compU]==componentColor[compV]);
						
						updateComponent(edges[b].b,edges[b].a,c,compU);
						edgeToComp[b] = compU;
						// Merge V to U
						// rep(i,G[v].size()) {
						// 	edge e2 = edges[G[v][i]];
						// 	if(e2.counter(v)!=u) {}
						// }
						
						// edgeToComp[findOnV] = compU;
						ll countN2 = n2ForColor[c];
						countN2 -= nodesInComp[compU]*nodesInComp[compU] + nodesInComp[compV]*nodesInComp[compV];
						nodesInComp[compU] += nodesInComp[compV];
						countN2 += nodesInComp[compU]*nodesInComp[compU];
                        
                        update2(c,countN2 - n2ForColor[c] );
						n2ForColor[c] = countN2;
						// cerr<<"After change\n ";

						// compU = edgeToComp[findOnU];
						// compV = edgeToComp[findOnV];
						// cerr<<findOnU<<" "<<findOnV<<endl;
						// cerr<<compU<<" "<<compV<<endl;
						// cerr<<componentColor[ compU]<<" "<<componentColor[ compV ]<<endl;
						// cerr<<edges[b].c<<" needs to change to "<<c<<endl;
						
					} else if(findOnV<0 && findOnU<0) {
						
						{
						//cerr<<"Case 2 2\n";
							componentColor.push_back(c);
							nodesInComp.push_back(2);
							edgeToComp[b]=COMP;
							n2ForColor[c]+=4;
							nForColor[c]+=2;
                            update2(c,4 );
                        update(c,2);
						


							COMP++;
						}
						
					} else if(findOnV<0 && findOnU>=0) {
						//cerr<<"Case 2 3\n";
						
						int compU = edgeToComp[findOnU];
						//int compV = edgeToComp[findOnV];

						assert(componentColor[compU]==c);
						
						edgeToComp[b] = compU;
						// Merge V to U
							
						ll countN2 = n2ForColor[c];
						countN2 -= nodesInComp[compU]*nodesInComp[compU];
						nodesInComp[compU]++;
						countN2 += nodesInComp[compU]*nodesInComp[compU];
                        update2(c,countN2 - n2ForColor[c] );
						
						n2ForColor[c] = countN2;
						nForColor[c]+=1;update(c,1);
						
						
					} else if(findOnV>=0 && findOnU<0) {
					//	cerr<<"Case 2 4\n";
						
						// int compU = edgeToComp[findOnU];
						int compV = edgeToComp[findOnV];

						assert(componentColor[compV]==c);
						cerr<<" Old Component of edge "<<edgeToComp[b]<<endl;
						edgeToComp[b] = compV;
						// Merge V to U
							
						ll countN2 = n2ForColor[c];
						countN2 -= nodesInComp[compV]*nodesInComp[compV];
						nodesInComp[compV]++;
						countN2 += nodesInComp[compV]*nodesInComp[compV];
                        update2(c,countN2 - n2ForColor[c] );
						
						n2ForColor[c] = countN2;
						nForColor[c]+=1;update(c,1);
						

						// compV = edgeToComp[findOnV];
						// cerr<<findOnU<<" "<<findOnV<<endl;
						// cerr<<" "<<" "<<compV<<endl;
						// cerr<<" "<<" "<<componentColor[ compV ]<<endl;
						// cerr<<edges[b].c<<" needs to change to "<<c<<endl;
						// cerr<<"Component of b :"<<edgeToComp[b]<<endl;
						// cerr<<u<<' '<<v<<endl;
						
					} 
					// else assert(0);

				}
				


				edges[b].c = c;
				checkComponents(leaf,"Failed after Change");
					


			}
			// changeCol(b-1,c,leaf);
		} else if(a==2) {
			cin>>c;
			ll s= 0;
            s= get2(c)-get2(b-1) - get(c)+get(b-1);
			//for(int i=b;i<=c;i++) {
				// cerr<<n2ForColor[i]<<' '<<nForColor[i]<<endl;
				//s+=n2ForColor[i]-nForColor[i];
			//}
			// assert(s%2==0);
			s/=2;
			// forv(it,nodesInComp) {
			// 	int col = compToCol [ it->first ] ;
			// 	if(col>=b && col<=c)
			// 		s+=getP(it->first);
			// 	// cout<<col<<": ";
			// 	// forv(it2,it->second)
			// 	// cout<<((*it2)+1)<<" ";cout<<endl;
			// 	// s+=getT(c1);
			// }
			cout<<s<<endl;
		} else if(a==3) {
			ll x = edgeToComp[b-1];
			ll y = nodesInComp[x];
			cout<<(y*(y-1)/2)<<endl;
		}

	}

	return 0;
}
