//Book allocation problem from HackerBlocks
// used Binary search here
#include<iostream>
using namespace std;
bool validMin(int* pages , int b, int s, int mid) {

	int student_count = 1;
	int pages_read = 0;
	for (int i = 0; i < b; i++) {

		if (pages_read + pages[i] > mid) {
			//now we will need new student
			student_count++;
			pages_read = pages[i];
			if (student_count > s) {
				return false;
			}
		}
		else {
			pages_read += pages[i];
		}
	}
	return true;
}
int main() {
// you can comment out following 4 lines if your compiler throws some error/doesn't give any output/ online judge says wrong answer
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif
	int t;
	cin >> t;
	while (t--) {
		int s, b;
		cin >> b >> s;
		int pages[b];
		int sum = 0;
		int ans = 0;
		for (int i = 0; i < b; i++) {
			cin >> pages[i];
			sum += pages[i];
		}
		// st here means starting index of the space over which we'll apply Binary Search
		//e - end
		int st = pages[b - 1];
		int e = sum;

		while (st <= e) {
			int mid = (st + e) / 2;

			bool check = validMin( pages , b,  s,  mid);
			if (check) {

				ans = mid;

				e = mid - 1;
			}
			else {
				st = mid + 1;
			}
		}
		cout << ans << endl;
	}
}
