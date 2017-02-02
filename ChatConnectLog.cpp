#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<string, vector<int>>> a(n);
	vector<string> log(n);
	for (int i = 0; i < n; i++)
		cin >> log[i];
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		string curestr = log[i];
		bool notFound = false;
		for (int j = 0; j <= i; j++) {
			if (curestr == a[j].first) {
				notFound = false;
				if (a[j].second.size() >= 4) {
					cout << "Disconnected #" << a[j].second[0] + 1 << endl;
					a[j].second.erase(a[j].second.begin());
				}
				a[j].second.push_back(i);
				break;
			}
			else notFound = true;
		}
		if (notFound) {
			a[cnt].first = curestr;
			a[cnt].second.push_back(i);
			cnt++;
		}
	}
	return 0;
}
