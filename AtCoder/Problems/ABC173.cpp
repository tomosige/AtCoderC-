#pragma once
#include "../AtCoderLib.h"

// https://atcoder.jp/contests/abc173

void ABC173A() {
	ll N;
	cin >> N;
	ll res = (N % 1000 == 0) ? 0 : 1000 - (N % 1000);
	cout << res << endl;
}

void ABC173B() {
	ll N;
	cin >> N;
	vs S(N, "");
	rep(i, 0, N) cin >> S[i];

	map<string, int> res;
	res["AC"] = 0;
	res["WA"] = 0;
	res["TLE"] = 0;
	res["RE"] = 0;
	rep(i, 0, N) {
		res[S[i]] ++;
	}

	cout << "AC x " << res["AC"] << endl;
	cout << "WA x " << res["WA"] << endl;
	cout << "TLE x " << res["TLE"] << endl;
	cout << "RE x " << res["RE"] << endl;
}

void ABC173C() {
	ll H, W, K;
	cin >> H >> W >> K;
	vs c(H);
	rep(i, 0, H) cin >> c[i];
	int ans = 0;

	rep(maskR, 0, (1 << H)) {
		rep(maskC, 0, (1 << W)) {
			int black = 0;
			rep(i, 0, H) {
				rep(j, 0, W) {
					if (((maskR >> i) & 1) == 0 && ((maskC >> j) & 1) == 0 && c[i][j] == '#') black++;
				}
			}
			if (black == K) ans++;
		}
	}

	cout << ans << endl;
}

void ABC173D() {
	ll N;
	cin >> N;
	vi A(N, 0);
	rep(i, 0, N) cin >> A[i];

	sort(A.begin(), A.end(), greater<int>());
	ll sum = 0;
	sum += A[0];
	rep(i, 2, N) {
		sum += A[i / 2];
	}

	cout << sum << endl;
}