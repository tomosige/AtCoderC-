#pragma once
#include "../AtCoderLib.h"

// https://atcoder.jp/contests/dp

void Frog1()
{
	int N;
	cin >> N;
	vi H(N + 10, 0);
	for (size_t i = 0; i < N; i++)
	{
		cin >> H[i];
	}
	vi dp(N + 10, inf);
	dp[0] = 0;

	for (size_t i = 0; i < N; i++)
	{
		for (size_t h = 1; h <= 2; h++)
		{
			chmin(dp[i + h], dp[i] + abs(H[i] - H[i + h]));
		}
	}

	cout << dp[N - 1] << endl;
}

void Frog2()
{
	int N, K;
	cin >> N >> K;
	vi H(N + 10, 0);
	for (size_t i = 0; i < N; i++)
	{
		cin >> H[i];
	}
	vi dp(N + 10, inf);
	dp[0] = 0;

	for (size_t i = 0; i < N; i++)
	{
		for (size_t h = 1; h <= K; h++)
		{
			chmin(dp[i + h], dp[i] + abs(H[i] - H[i + h]));
		}
	}

	cout << dp[N - 1] << endl;
}

void Vacation()
{
	int N;
	cin >> N;
	vvi ABC(N, vi(3, 0));
	for (size_t i = 0; i < N; i++)
	{
		cin >> ABC[i][0] >> ABC[i][1] >> ABC[i][2];
	}

	vvi dp(N + 1, vi(3, 0));

	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			for (size_t k = 0; k < 3; k++)
			{
				if (j == k)continue;
				chmax(dp[i + 1][k], dp[i][j] + ABC[i][k]);
			}
		}
	}

	ll result = max(dp[N][0], max(dp[N][1], dp[N][2]));
	cout << result << endl;
}

void Knapsack1()
{
	int N, W;
	cin >> N >> W;
	vi weight(N, 0), value(N, 0);
	rep(i, 0, N)
		cin >> weight[i] >> value[i];

	vvi dp(N + 10, vi(W + 10, 0));

	rep(i, 0, N) {
		rep(w, 0, W + 1) {
			if (w - weight[i] >= 0)
				chmax(dp[i + 1][w], dp[i][w - weight[i]] + value[i]);
			chmax(dp[i + 1][w], dp[i][w]);
		}
	}
	cout << dp[N][W] << endl;
}