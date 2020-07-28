#pragma once
#include "../AtCoderLib.h"

// https://atcoder.jp/contests/abc171

void ABC171A() {
	char a;
	cin >> a;
	cout << ((65 <= a && a <= 90) ? 'A' : 'a') << endl;
}

void ABC171B() {
	ll N, K;
	cin >> N >> K;
	vi P(N, 0);
	rep(i, 0, N) cin >> P[i];

	sort(P.begin(), P.end());
	ll sum = 0;
	rep(i, 0, K) sum += P[i];
	cout << sum << endl;
}

void ABC171C() {
	ll N;
	cin >> N;

	string name;
	ll tempN = N;
	while (tempN > 0) {
		tempN--;
		name += (tempN % 26) + 'a';
		tempN /= 26;
	}
	reverse(name.begin(), name.end());
	cout << name << endl;
}

void ABC171D() {
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