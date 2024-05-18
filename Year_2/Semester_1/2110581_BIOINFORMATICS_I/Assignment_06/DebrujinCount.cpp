#include <bits/stdc++.h>
using namespace std;
string a[110];
string b[110];
int k = 1;
int len = 21;
int n = 100;
vector<int> g[110];
int mark[110];
int in[110];
void dfs(int u, int state) {
	mark[u] = 1;
	cout << a[u] << " " << u << " " << state + 1 << "\n";
	if(!g[u].empty()) {
		for(int i = 0; i < state + 1; i++)
			cout << " ";
	}
	for(auto &v : g[u]) {
		if(mark[v]) continue;
		dfs(v, state + 1);
	}
}
bool match(string s1, string s2) {
	int i = k;
	int j = 0;
	while(i < len && j < len - k) {
		if(s1[i] != s2[j]) return false;
		i++, j++;
	}
	return true;
}
int main() {
	FILE *pfile;
	pfile = freopen("microbiome_reads_1.txt", "r", stdin);
	for(int i = 0; i < 100; i++)
		cin >> a[i];
	fclose(pfile);
	pfile = freopen("microbiome_reads_2.txt", "r", stdin);
	for(int i = 0; i < 100; i++)
		cin >> b[i];
	fclose(pfile);

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(match(a[i], a[j])) {
				g[i].push_back(j);
				in[j]++;
			}
		}
	}
	// for(int i = 0; i < n; i++) {
	// cout << i << ": ";
	// for(auto &x : g[i]) {
	// cout << x << " ";
	// }
	// cout << "\n";
	// }
	for(int i = 0; i < n; i++) {
		if(!mark[i] && in[i] == 0) {
			dfs(i, 0);
		}
	}
}

/*

GCCTGGGACGAGATCCCGATCACCTATCCGATGGACACCGCGGCGGTATCGATGGGCTGGGGTCCGCTCGA

GCCCTTGAAAAAACAACTAACCCTTGCCAACGGCGTGGGAGTAGTCGATAGTGATTATTATAATAATTTGC

ACTCAACAAAAAAGGATTAAGTAGTGAAAGCCATTTTGAGTGTATTCGTGATGCTAGTGCTGCTGACCTCT

GTGAAAGCCAATAAAAGGACAAGGTTTTTATCCTACATGATAAAGGTAAATCCCACCAATAAAACTCTTAC

AGAAGTTTCATCCACTTGGACTAGTTTTTTAACCAATCCTCATTTAGAAAATATTCCTCAATACTACTGGG

*/