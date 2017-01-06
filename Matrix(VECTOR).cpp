#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int check(string &t, string &p, int x) {
	int summ;
	return summ;
}

int main() {
	int n;
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
	cout << "\nhV\n";
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

	
	return 0;
}
