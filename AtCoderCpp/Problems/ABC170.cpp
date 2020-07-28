#pragma once
#include "../AtCoderLib.h"

// https://atcoder.jp/contests/abc170

void ABC170A() {
	vi X(5, 0);
	rep(i, 0, 5) cin >> X[i];
	rep(i, 0, 5) {
		if (X[i] == 0) cout << i + 1 << endl;
	}
}

void ABC170B() {
	ll X, Y;
	cin >> X >> Y;

	bool ans = false;
	rep(c, 0, X + 1) {
		rep(t, 0, X + 1) {
			if ((c + t == X) && (c * 2 + t * 4 == Y)) ans = true;
		}
	}
	cout << (ans ? "Yes" : "No") << endl;
}

void ABC170C() {
	ll X, N;
	cin >> X >> N;
	vector<bool> P(110, false);
	rep(i, 0, N) {
		ll temp;
		cin >> temp;
		P[temp] = true;
	}
	ll ans = 0;
	ll diff = 1000;
	repr(i, 101, -1) {
		if (!P[i]) {
			if (abs(X - i) <= diff) {
				diff = abs(X - i);
				ans = i;
			}
		}
	}
	cout << ans << endl;
}

void ABC170D() {
	ll N;
	cin >> N;
	vi A(N, 0);
	rep(i, 0, N) cin >> A[i];

	sort(A.begin(), A.end());
	A.push_back(0);

	ll ans = 0;
	vector<bool> dp(A[N - 1] + 1, false);
	rep(i, 0, N) {
		if (dp[A[i]]) continue;
		if (A[i] != A[i + 1]) ans++;
		for (ll k = A[i]; k < dp.size(); k += A[i])
		{
			dp[k] = true;
		}
	}
	cout << ans << endl;
}