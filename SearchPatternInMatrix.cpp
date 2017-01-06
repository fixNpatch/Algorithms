#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int check(string &t, string &p, int x) {
	int sum = 0, i = 0, j, end = p.length();
	bool brk;
	while (i < x) {
		if (i + end > x) break;
		else {
			brk = false;
			j = 0;
			while (j < end) {
				if ((t[i + j] != p[j]) && (p[j] != '?')) {
					brk = true;
				}
				j++;
			}
			if (!brk) sum++;
		}
		i++;
	}
	return sum;
};

int main() {
	int n, m;
	cin >> n;
	vector<string> hV(n);
	vector<string> vV(n);
	
	char cure;
	for (int i = 0; i < n; i++)	{
		for (int j = 0; j < n; j++) {
			cin >> cure;
			hV[i].push_back(cure);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			vV[i].push_back(hV[j][i]);
		}
	}
	cin >> m;
	string pattern;
	for (int i = 0; i < m; i++) {
		cin >> cure;
		pattern += cure;
	}

	/*cout << "\nhV\n";
	for (int i = 0; i < n; i++)	{
		for (int j = 0; j < n; j++)
			cout << hV[i][j] << " ";
		cout << endl;
	}
	cout << "\nvV\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << vV[i][j] << " ";
		cout << endl;
	}
	
	cout << "\npattern\n";
	for (int i = 0; i < n; i++)
		cout << pattern[i];*/

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += check(hV[i], pattern, n);
		ans += check(vV[i], pattern, n);
	}
	cout << "Search Completed\n";
	cout << "Answer is " << ans << endl;
	return 0;
}
