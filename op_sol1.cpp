#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

void solve() {
	ll a[3], x, y;
	cin >> a[0] >> a[1] >> a[2] >> x >> y;
	//first, make sure that 'x' less than or equal to 'y'
	//to make the conditions easier in the next lines
	if(x>y)
		swap(x, y);
	//sort the first three numbers {a[0],a[1],a[2]}
	//again, to make the conditions easier in the next lines 
	sort(a, a+3);
	//first condition: check if the least number in the array is less than or equal to 'x'
	//second condition: check if the second least number is less than or equal to 'y'
	//third condition: check if the sum of all the numbers in the array is equal to 'x+y'
	/* more explanation:
	 * the reason why it is important to check the first two numbers in
	 * the array if they're less than their corresponding partners which is 'x' and 'y'
	 * is because if one of them is greater than their corresponding partner,
	 * then it will not be valid anymore since the third number which is the
	 * stones that will be added to these first two stones will only make it bigger,
	 * so that's why it is important for these first two numbers in the array to be
	 * less than their corresponding partners ('x' or 'y')
	 * */
	if(a[0]>x||a[1]>y||a[0]+a[1]+a[2]!=x+y)
		cout << "NO\n";
	else
		cout << "YES\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--)
		solve();
}
