#include "bits/stdc++.h"

#define ll          long long
#define pb          push_back
#define pii         pair<ll,ll>
#define vpii        vector< pii >
#define vi          vector<ll>
#define vs			vector< string >
#define vvi         vector< vector< ll > >
#define inf			1'010'000'000'000'000'017LL
#define all(it,a)   for(auto it=(a).begin();it!=(a).end();it++) 
#define sz(x)       (ll)x.size()
#define rep(i,a,b)	for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>b;i--)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define mp          make_pair
#define whatis(x)   cout << #x << " is " << x << "\n";
#define graph(n)    adj(n,vector< ll > () )

using namespace std;

template<class T>
bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T>
bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
ll DivisorCount(ll x) {
	ll ans = 1;
	for (int i = 2; i <= sqrt(x); i++) {
		int cnt = 0;
		while (x % i == 0) {
			cnt++;
			x /= i;
		}
		ans *= (cnt + 1);
		if (x == 1) break;
	}
	if (x != 1) ans *= 2;
	return ans;
}

void Main() {
	ll N, Q, sum = 0;
	cin >> N;
	vi mem(pow(10, 5) + 10, 0);
	rep(i, 0, N) {
		ll tmp;
		cin >> tmp;
		mem[tmp]++;
		sum += tmp;
	}
	cin >> Q;
	vi B(Q, 0), C(Q, 0);
	rep(i, 0, Q) cin >> B[i] >> C[i];

	rep(i, 0, Q) {
		sum = sum + (mem[B[i]] * C[i]) - (mem[B[i]] * B[i]);
		mem[C[i]] += mem[B[i]];
		mem[B[i]] = 0;
		cout << sum << endl;
	}
}




int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);

	Main();
	return 0;
}
