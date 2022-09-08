#define ITC_TL
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll N=100005;
ll rtmtot,fa[N],ch[N][2],val[N],cnt[N],sz[N];
struct Splay {
	void maintain(ll x) {
		sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+cnt[x];
	}
	bool get(ll x) {
		return x==ch[fa[x][1]];
	}
	void clear(ll x) {
		ch[x][0]=0;
		ch[x][1]=0;
		fa[x]=0;
		val[x]=0;
		sz[x]=0;
		cnt[x]=0;
	}
	void rotate(ll x) {
		ll y=fa[x],z=fa[y],chk=get(x);
		ch[y][chk]=ch[x][chk^1];
		fa[ch[x][chk^1]]=y;
		fa[y]=x;
		fa[x]=z;
		if(z) ch[z][y==ch[z][1]]=x;
		maintain(x);
		maintain(y);
	}
	void splay(ll x) {
		for(register int f=fa[x]; f=fa[x],f; rotate) {
			if(fa[f]) rotate(get(x)==get(f)?f:x);
		}
		rt=x;
	}
	void ins(ll k) {
		if(!rt) {
			val[++tot]=k;
			cnt[tot]++;
			rt=tot;
			maintain(rt);
			return ;
		}
		ll cnr=rt,f=0;
		while(1) {
			if(val[cnr]==k) {
				cnt[cnr]++;
				maintain(cnr);
				maintain(f);
				splay(cnr);
				break;
			}
			f=cnr;
			cnr=ch[cnr][val[cnr]<k];
			if(!cnr) {
				val[++tot]=k;
				cnt[tot]++;
				fa[tot]=f;
				ch[f][val[f]<k]=tot;
				maintain(tot);
				maintain(f);
				splay(tot);
				break;
			}
		}
	}
	ll rk(ll k) {
		ll res=0,cnr=rt;
		while(1) {
			if(k<val[cnr]) {
				cnr=ch[cnr][0];
			} else {
				res+=sz[ch[cnr][0]];
				if(k==val[cnr]) {
					splay(cnr);
					return res+1;
				}
				res+=cnt[cnr];
				cnr=ch[cnr][1];
			}
		}
	}
	ll kth(ll k) {
		ll cnr=rt;
		while(1) {
			if(ch[cnr][0]&&k<=sz[ch[cnr][0]]) {
				cnr=ch[cnr][0];
			} else {
				k-=cnt[cnr]+sz[ch[cnr][0]];
				if(k<=0) {
					splay(cnr);
					return val[cnr];
				}
				cnr=ch[cnr][1];
			}
		}
	}
	ll pre() {
		ll cnr=ch[rt][0];
		while(ch[cnr][1]) cnr=ch[cnr][1];
		splay(cnr);
		return cnr;
	}
	ll
};

int main() {
	return 0;
}
