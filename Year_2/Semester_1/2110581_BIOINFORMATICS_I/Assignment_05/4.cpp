#include <iostream>
#include <string>
#include <vector>

using namespace std;

int max_of_three(int a, int b, int c) {
	return max(a, max(b, c));
}

void printAlignment(const string& sequence1, const string& sequence2, const vector<vector<int>>& scores,
					pair<int, int> maxPosition) {
	string alignedSequence1, alignedSequence2, alignment;

	int i = maxPosition.first;
	int j = maxPosition.second;

	while(i > 0 && j > 0 && scores[i][j] > 0) {
		if(scores[i][j] == scores[i - 1][j - 1] + (sequence1[i - 1] == sequence2[j - 1] ? 3 : -3)) {
			alignedSequence1 = sequence1[i - 1] + alignedSequence1;
			alignedSequence2 = sequence2[j - 1] + alignedSequence2;
			alignment = (sequence1[i - 1] == sequence2[j - 1] ? "|" : " ") + alignment;
			i--;
			j--;
		}
		else if(scores[i][j] == scores[i - 1][j] - 1) {
			alignedSequence1 = sequence1[i - 1] + alignedSequence1;
			alignedSequence2 = "-" + alignedSequence2;
			alignment = " " + alignment;
			i--;
		}
		else {
			alignedSequence1 = "-" + alignedSequence1;
			alignedSequence2 = sequence2[j - 1] + alignedSequence2;
			alignment = " " + alignment;
			j--;
		}
	}

	cout << "Optimal Alignment:" << endl;
	cout << alignedSequence1 << endl;
	cout << alignment << endl;
	cout << alignedSequence2 << endl;
}

int main() {
	string sequence1 = "TACGGGCCCGCTA";
	string sequence2 = "TAGCCCTATCGGTCA";

	int matchScore = 3;
	int substitutionPenalty = -3;
	int openingGapPenalty = 5;
	int extensionGapPenalty = 1;

	int m = sequence1.length();
	int n = sequence2.length();

	vector<vector<int>> scores(m + 1, vector<int>(n + 1, 0));

	int maxScore = 0;
	pair<int, int> maxPosition;

	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			int match =
				scores[i - 1][j - 1] + (sequence1[i - 1] == sequence2[j - 1] ? matchScore : substitutionPenalty);
			int deleteGap = scores[i - 1][j] - (j > 1 ? extensionGapPenalty : openingGapPenalty);
			int insertGap = scores[i][j - 1] - (i > 1 ? extensionGapPenalty : openingGapPenalty);

			scores[i][j] = max_of_three(0, match, max_of_three(deleteGap, insertGap, 0));

			if(scores[i][j] >= maxScore) {
				maxScore = scores[i][j];
				maxPosition = make_pair(i, j);
			}
		}
	}

	cout << "Max Score: " << maxScore << endl;
	printAlignment(sequence1, sequence2, scores, maxPosition);

	return 0;
}
