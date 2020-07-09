Rahul and Ankit are the only two waiters in Royal Restaurant. Today, the restaurant received N orders. The amount of tips may differ when handled by different waiters, if Rahul takes the ith order, he would be tipped Ai rupees and if Ankit takes this order, the tip would be Bi rupees.
In order to maximize the total tip value they decided to distribute the order among themselves. One order will be handled by one person only. Also, due to time constraints Rahul cannot take more than X orders and Ankit cannot take more than Y orders. It is guaranteed that X + Y is greater than or equal to N, which means that all the orders can be handled by either Rahul or Ankit. Find out the maximum possible amount of total tip money after processing all the orders.





#include <bits/stdc++.h>
using namespace std;

struct tip
{
    int absval;
    int index;
};

bool comparator(struct tip t1, struct tip t2)
{
    return (t1.absval > t2.absval);
}

int maxTip(int a[], int b[], int n, int x, int y) {
    struct tip c[n];
    int sum  = 0;
    for(int i = 0; i < n; i++) {
        int k = abs(a[i] - b[i]);
        c[i].absval = k;
        c[i].index = i;
    }

    sort(c, c+n, comparator);

    for(int i = 0; i < n; i++) {
        // you can use int k = c[i].index and use k in place of c[i].index
        // As you can see c[i].index is used multiple times so you can reduce it if you want.
        if(a[c[i].index] > b[c[i].index]) {
            if(x > 0) {
                sum = sum + a[c[i].index];

                x--;
            } else {
                sum = sum + b[c[i].index];
                y--;
            }
        } else {
            if( y > 0) {
                sum = sum + b[c[i].index];
                y--;
            } else {
                sum = sum + a[c[i].index];
                x--;
            }
        }
    }

    return sum;
}

int main() {
	//code
	int t;
	cin >> t;
	while(t--) {
	    int n, x, y;
	    cin >> n >> x >> y;
	    int a[n];
	    int b[n];
	    for(int i = 0; i < n; i++) {
	        cin >> a[i];
	    }
	    for(int i = 0; i < n; i++) {
	        cin >> b[i];
	    }

	    cout << maxTip(a, b, n, x, y) << endl;
	}
	return 0;
}



/*

INPUT
1      -----> for no of test cases
7 3 4  -----> value on n , xa and y
8 7 5 9 6 6 8   -------> array of first waiter tip for ith order
1 7 5 1 2 3 9   -------> array of second waiter tip for ith order

OUTPUT
47

*/
