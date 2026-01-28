#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
struct cv {
	int a;
	int b;
}pp[1000];
bool cmp(cv x, cv y) {
	return x.a > y.b;
}
int main(){
	int n,sum=0;
    cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> pp[i].a;
		pp[i].b = i;
	}
	sort(pp, pp + n, cmp);
	int x = 0;
	for (int i = n - 1;i >= 0;i--) {
		sum += pp[x].a * i;
	}
	for (int i = 0;i<n;i++) {
		cout << pp[i].a << " ";
	}
	printf("\n%.2f", sum * 1.0 / n);
}