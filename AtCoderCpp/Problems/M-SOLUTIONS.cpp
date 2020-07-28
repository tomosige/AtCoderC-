#pragma once
#include "../AtCoderLib.h"

// https://atcoder.jp/contests/m-solutions2020

void solveA() {
	ll X;
	cin >> X;
	cout << 8 - ((X / 200) - 2) << endl;
}

void solveB() {
	ll A, B, C, K;
	cin >> A >> B >> C >> K;

	bool result = false;
	rep(i, 0, K) {
		if (A >= B) {
			B *= 2;
			continue;
		}
		if (B >= C) {
			C *= 2;
			continue;
		}
	}
	if (A < B && B < C) result = true;
	cout << (result ? "Yes" : "No") << endl;
}

void solveC() {
	ll N, K;
	cin >> N >> K;
	vi A(N, 0);
	rep(i, 0, N) cin >> A[i];

	rep(i, 0, N - K) {
		cout << ((A[i] < A[i + K]) ? "Yes" : "No") << endl;
	}
}

void solveD() {
	ll N;
	cin >> N;
	vi A(N, 0);
	rep(i, 0, N) cin >> A[i];

	ll money = 1000;
	ll stock = 0;

	rep(i, 0, N - 1) {
		money += stock * A[i];
		stock = 0;
		if (A[i + 1] > A[i]) {
			stock += (money / A[i]);
			money -= stock * A[i];
		}
	}
	money += stock * A[N - 1];

	cout << money << endl;
}