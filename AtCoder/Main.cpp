#include "bits/stdc++.h"
#include <boost/math/common_factor_rt.hpp>
#include <boost/multi_array.hpp>
#include <boost/optional.hpp>
#include <boost/range/irange.hpp>
#include <boost/range/algorithm.hpp>
#include <boost/range/adaptors.hpp>

using namespace std;
using namespace boost;
using namespace boost::math;

namespace adaptor = boost::adaptors;

void Main()
{
	int n, m;
	cin >> n >> m;
	cout << gcd(n, m) << endl;
	cin >> n;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);

	Main();
}