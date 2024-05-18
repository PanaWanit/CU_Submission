#include <bits/stdc++.h>
using namespace std;

int gapPenalty = -5;

vector<char> amino_acids = {'A', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'K', 'L',
							'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'Y'};

map<char, int> amino_acid_indices;
vector<vector<int>> pam250_matrix = {{2, -2, 0, 0, -3, 1, -1, -1, -1, -2, -1, 0, 1, 0, -2, 1, 1, 0, -6, -3},
									 {-2, 12, -5, -5, -4, -3, -3, -2, -5, -6, -5, -4, -3, -5, -4, 0, -2, -2, -8, 0},
									 {0, -5, 4, 3, -6, 1, 1, -2, 0, -4, -3, 2, -1, 2, -1, 0, 0, -2, -7, -4},
									 {0, -5, 3, 4, -5, 0, 1, -2, 0, -3, -2, 1, -1, 2, -1, 0, 0, -2, -7, -4},
									 {-3, -4, -6, -5, 9, -5, -2, 1, -5, 2, 0, -3, -5, -5, -4, -3, -3, -1, 0, 7},
									 {1, -3, 1, 0, -5, 5, -2, -3, -2, -4, -3, 0, 0, -1, -3, 1, 0, -1, -7, -5},
									 {-1, -3, 1, 1, -2, -2, 6, -2, 0, -2, -2, 2, 0, 3, 2, -1, -1, -2, -3, 0},
									 {-1, -2, -2, -2, 1, -3, -2, 5, -2, 2, 2, -2, -2, -2, -2, -1, 0, 4, -5, -1},
									 {-1, -5, 0, 0, -5, -2, 0, -2, 5, -3, 0, 1, -1, 1, 3, 0, 0, -2, -3, -4},
									 {-2, -6, -4, -3, 2, -4, -2, 2, -3, 6, 4, -3, -3, -2, -3, -3, -2, 2, -2, -1},
									 {-1, -5, -3, -2, 0, -3, -2, 2, 0, 4, 6, -2, -2, -1, 0, -2, -1, 2, -4, -2},
									 {0, -4, 2, 1, -3, 0, 2, -2, 1, -3, -2, 2, 0, 1, 0, 1, 0, -2, -4, -2},
									 {1, -3, -1, -1, -5, 0, 0, -2, -1, -3, -2, 0, 6, 0, 0, 1, 0, -1, -6, -5},
									 {0, -5, 2, 2, -5, -1, 3, -2, 1, -2, -1, 1, 0, 4, 1, -1, -1, -2, -5, -4},
									 {-2, -4, -1, -1, -4, -3, 2, -2, 3, -3, 0, 0, 0, 1, 6, 0, -1, -2, 2, -4},
									 {1, 0, 0, 0, -3, 1, -1, -1, 0, -3, -2, 1, 1, -1, 0, 2, 1, -1, -2, -3},
									 {1, -2, 0, 0, -3, 0, -1, 0, 0, -2, -1, 0, 0, -1, -1, 1, 3, 0, -5, -3},
									 {0, -2, -2, -2, -1, -1, -2, 4, -2, 2, 2, -2, -1, -2, -2, -1, 0, 4, -6, -2},
									 {-6, -8, -7, -7, 0, -7, -3, -5, -3, -2, -4, -4, -6, -5, 2, -2, -5, -6, 17, 0},
									 {-3, 0, -4, -4, 7, -5, 0, -1, -4, -1, -2, -2, -5, -4, -4, -3, -3, -2, 0, 10}};

int smithWaterman(string seq1, string seq2) {
	int m = seq1.length();
	int n = seq2.length();

	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

	int maxScore = 0;
	int max_i = 0, max_j = 0;

	for(int i = 1; i <= m; i++)
		dp[i][0] = dp[i - 1][0] + gapPenalty;
	for(int i = 1; i <= n; i++)
		dp[0][i] = dp[0][i - 1] + gapPenalty;

	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			dp[i][j] = max({
				0,
				dp[i][j - 1] + gapPenalty,
				dp[i - 1][j] + gapPenalty,
				dp[i - 1][j - 1] + pam250_matrix[amino_acid_indices[seq2[j - 1]]][amino_acid_indices[seq1[i - 1]]],
			});

			if(dp[i][j] >= maxScore) {
				maxScore = dp[i][j];
				max_i = i;
				max_j = j;
			}
		}
	}

	// Traceback to find the aligned sequences
	string alignedSeq1, alignedSeq2;
	while(max_i > 0 && max_j > 0) {
		if(dp[max_i][max_j] == 0) break;

		if(dp[max_i][max_j] ==
		   dp[max_i - 1][max_j - 1] +
			   (pam250_matrix[amino_acid_indices[seq1[max_i - 1]]][amino_acid_indices[seq2[max_j - 1]]])) {
			alignedSeq1 = seq1[max_i - 1] + alignedSeq1;
			alignedSeq2 = seq2[max_j - 1] + alignedSeq2;
			max_i--;
			max_j--;
		}
		else if(dp[max_i][max_j] == dp[max_i - 1][max_j] + gapPenalty) {
			alignedSeq1 = seq1[max_i - 1] + alignedSeq1;
			alignedSeq2 = "-" + alignedSeq2;
			max_i--;
		}
		else {
			alignedSeq1 = "-" + alignedSeq1;
			alignedSeq2 = seq2[max_j - 1] + alignedSeq2;
			max_j--;
		}
	}

	// cout << "Optimal Alignment Score: " << maxScore << endl;
	cout << maxScore << "\n";
	cout << "" << alignedSeq1 << endl;
	cout << "" << alignedSeq2 << endl;

	return maxScore;
}

int main() {
	for(int i = 0; i < (int)amino_acids.size(); ++i) {
		amino_acid_indices[amino_acids[i]] = i;
	}
	string seq1, seq2;
	cin >> seq1 >> seq2;

	smithWaterman(seq1, seq2);
	return 0;
}
