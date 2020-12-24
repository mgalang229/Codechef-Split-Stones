#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

void solve() {
	ll a[3], b[2];
	cin >> a[0] >> a[1] >> a[2] >> b[0] >> b[1];
	//sort all the number since next_permutation doesn't include the sorted list
	sort(a, a+3);
	sort(b, b+2);
	bool ok=0;
	do {
		do {
			//conditions:
			//1. find the number of stones required in the first and second pile
			//2. check if the required number of stones is non-negative or not
			//3. check if the sum of the number of required stones can be 
			//exactly satisfied by the excess pile.
			int one=b[0]-a[0];
			int two=b[1]-a[1];
			if(one>=0&&two>=0&&one+two==a[2])
				ok=1;
		} while(next_permutation(b, b+2));
	} while(next_permutation(a, a+3));
	cout << (ok?"YES":"NO") << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--)
		solve();
}
