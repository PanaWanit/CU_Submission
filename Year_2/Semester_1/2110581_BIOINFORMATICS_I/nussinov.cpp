
#include <bits/stdc++.h>
#define MAX_N 1001

#define DPRINTC(C) printf(#C " = %c\n", (C))
#define DPRINTS(S) printf(#S " = %s\n", (S))
#define DPRINTD(D) printf(#D " = %d\n", (D))
#define DPRINTLLD(LLD) printf(#LLD " = %lld\n", (LLD))
#define DPRINTLF(LF) printf(#LF " = %.5lf\n", (LF))

using namespace std;
typedef long long lld;
typedef unsigned long long llu;

int n;
string A;
int dp[MAX_N][MAX_N];

bool complementary(char X, char Y) {
	return ((X == 'A' && Y == 'U') || (X == 'U' && Y == 'A') || (X == 'C' && Y == 'G') || (X == 'G' && Y == 'C') ||
			(X == 'G' && Y == 'U') || (X == 'U' && Y == 'G'));
}

int nussinov(int i, int j) {
	if(dp[i][j] != -1) return dp[i][j];

	if(i >= j) {
		dp[i][j] = 0;
		return 0;
	}

	int ret = 0;
	ret = max(ret, nussinov(i + 1, j));
	ret = max(ret, nussinov(i, j - 1));
	if(complementary(A[i], A[j])) ret = max(ret, nussinov(i + 1, j - 1) + 1);
	for(int k = i + 1; k < j; k++) {
		ret = max(ret, nussinov(i, k) + nussinov(k + 1, j));
	}

	dp[i][j] = ret;
	return ret;
}

inline int nussinov() {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			dp[i][j] = -1;
		}
	}

	return nussinov(0, n - 1);
}

string get_bracketing(int i, int j) {
	if(i == j) return ".";
	if(i > j) return "";

	if(nussinov(i, j) == nussinov(i + 1, j)) {
		string left = ".";
		return left + get_bracketing(i + 1, j);
	}

	if(nussinov(i, j) == nussinov(i, j - 1)) {
		string right = ".";
		return get_bracketing(i, j - 1) + right;
	}

	if(complementary(A[i], A[j]) && nussinov(i, j) == nussinov(i + 1, j - 1) + 1) {
		string left = "";
		string right = "";
		return "(" + left + get_bracketing(i + 1, j - 1) + right + ")";
	}

	for(int k = i + 1; k < j; k++) {
		if(nussinov(i, j) == nussinov(i, k) + nussinov(k + 1, j)) {
			return get_bracketing(i, k) + get_bracketing(k + 1, j);
		}
	}

	return "FAIL";	// should never happen!
}

int main() {
	A = "GGGCAAUCCUCUUCGGGCCC";
	n = A.size();

	printf("%d\n", nussinov());
	cout << get_bracketing(0, n - 1) << endl;

	return 0;
}