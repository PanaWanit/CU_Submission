#include <bits/stdc++.h>
using namespace std;

struct DNA {
	string s;
	int overlap;
	bool isReverse;
	int idx;
	DNA(string s, int overlap, bool isReverse, int idx) : s(s), overlap(overlap), isReverse(isReverse), idx(idx) {}
};

// const vector<string> dna{"CCTAAGGCGC", "GCGCGGGCGC", "CTTAGGCCGC", "GGGCGCCTTA", "GCGGCCTAAG", "GCGCCCGCGC"};
vector<string> dna;
bool vis[10];

map<char, char> dna_map = {{'A', 'T'}, {'C', 'G'}, {'G', 'C'}, {'T', 'A'}};
string getComplement(string s) {  // actually reverse complement
	for(auto& x : s) {
		x = dna_map[x];
	}
	reverse(s.begin(), s.end());
	return s;
}
int cnt = 0;
void findDna(vector<DNA> v) {  // pair ()
	if((int)v.size() == (int)dna.size()) {
		// string ans = "";
		// for(auto& x : v) {
		// 	ans += x.s.substr(x.overlap);
		// }
		// int sum_overlap = -10;
		// for(auto& x : v) {
		// 	cout << string(10 - x.overlap + sum_overlap, ' ') + x.s << "\n";
		// 	sum_overlap += 10 - x.overlap;
		// }
		// cout << string(sum_overlap + 10, '-') << "\n";
		// cout << ans << "\n\n**************************************************\n";
		cout << v.back().s.size() << "\n";
		cout << v.back().s << "\n";
		for(auto& x : v)
			cout << "read: " << x.idx + 1 << " at index " << x.overlap << "\n";
		return;
	}
	for(int i = 0; i < (int)dna.size(); i++) {
		if(vis[i]) continue;
		vis[i] = 1;
		if((int)v.size() == 0) {
			// no reverse
			v.emplace_back(dna[i], 0, false, i);
			findDna(v);
			v.pop_back();

			// reverse
			// v.emplace_back(getComplement(dna[i]), 0, true, i);
			// findDna(v);
			// v.pop_back();
		}
		else {
			for(int overlap_size = 9; overlap_size >= 1; overlap_size--) {
				overlap_size = 6;  // set to 40 for output from file 1 and 2
				string back_dna = v.back().s;
				if(back_dna.substr(back_dna.size() - overlap_size) == dna[i].substr(0, overlap_size)) {
					v.emplace_back(back_dna + dna[i].substr(overlap_size), overlap_size, false, i);
					findDna(v);
					v.pop_back();
				}
				// if(back_dna.substr(back_dna.size() - overlap_size) == getComplement(dna[i]).substr(0, overlap_size))
				// { 	v.emplace_back(back_dna + getComplement(dna[i]).substr(overlap_size), overlap_size, true, i);
				// 	findDna(v);
				// 	v.pop_back();
				// }
				break;
			}
		}
		vis[i] = 0;
	}
}
int main() {
	int n;
	cin >> n;
	string s;
	for(int i = 0; i < n; i++)
		cin >> s, dna.push_back(s);
	findDna(vector<DNA>());
	return 0;
}
/*
16
CCGGGGGCCC
CGCGCGGGTG
ACCGCGCGCG
CGGGTGATTC
TGATTCCTCC
GGGCCCCCGG
GGCCCGGCAC
CACGGTTGGA
GCAGCCCGTC
GAAGGGGGGG
CCCGTCTTCA
CGGCACCGCG
GGGGGGCCCG
TCCTCCGGGG
TCTTCACGGT
GTTGGAAGGG

70
GCAGCCCGTCTTCACGGTTGGAAGGGGGGGCCCGGCACCGCGCGCGGGTGATTCCTCCGGGGGCCCCCGG

16
AGCCGGACAG
GCGCGGGCGG
CCGGGCGCGG
GGGCGGTGCG
GGTGCGCCAG
GGACAGCGCG
GGGGGCCCCC
CGCGGGTGAT
CCCGGCACCG
ATTCCTCCGG
GCACCGCGCG
GCCCCCGGGC
CTCCGGGGGC
CGCCAGCCGG
CGCGCGCGGG
GGTGATTCCT

70
CCCGGCACCGCGCGCGGGTGATTCCTCCGGGGGCCCCCGGGCGCGGGCGGTGCGCCAGCCGGACAGCGCG

100
GCAGCCCGTCTTCACGGTTGGAAGGGGGGGCCCGGCACCGCGCGCGGGTGATTCCTCCGGGGGCCCCCGGGCGCGGGCGGTGCGCCAGCCGGACAGCGCG
*/