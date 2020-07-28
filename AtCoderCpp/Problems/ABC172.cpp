#pragma once
#include "../AtCoderLib.h"

// https://atcoder.jp/contests/abc172

void ABC172A() {
	ll a;
	cin >> a;
	ll result = a + pow(a, 2) + pow(a, 3);
	cout << result << endl;
}

void ABC172B() {
	string S, T;
	cin >> S >> T;
	ll diff = 0;
	rep(i, 0, S.size()) {
		if (S[i] != T[i]) diff++;
	}
	cout << diff << endl;
}

void ABC172C() {
	ll N, M, K;
	cin >> N >> M >> K;
	vi A(N, 0), B(M, 0);
	rep(i, 0, N) cin >> A[i];
	rep(i, 0, M) cin >> B[i];

	vi canReadB(N + 1, 0);
	ll tempSumA = 0, tempSumB = 0;
	rep(i, 0, M) {
		if (B[i] + tempSumB > K) break;
		tempSumB += B[i];
		canReadB[0]++;
	}
	ll result = canReadB[0];
	rep(i, 1, N + 1) {
		if (A[i - 1] + tempSumA > K) break;
		tempSumA += A[i - 1];
		canReadB[i] = canReadB[i - 1];
		while (tempSumA + tempSumB > K) {
			canReadB[i]--;
			tempSumB -= B[canReadB[i]];
		}
		chmax(result, i + canReadB[i]);
	}

	cout << result << endl;
}

void ABC172D() {
	ll N;
	cin >> N;

	ll result = 0;
	rep(i, 1, N + 1) {
		ll X = N / i;
		result += i * X * (X + 1) / 2;
	}

	cout << result << endl;
}