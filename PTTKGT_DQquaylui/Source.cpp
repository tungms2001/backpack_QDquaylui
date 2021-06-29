#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

long M, N;	//khoi tao bien voi M la khoi luong tong cua gio hang va N la so luong mon do bo vao

struct Dta {
	long W, V;	//bien khoi luong va gia tri cua goi hang thu i
};

Dta a[200];		//mang so luong mon hang

bool cmp(Dta a, Dta b) {	//xay dung ham so sanh giua 2 mon hang voi nhau
	return (float)a.V / a.W > (float)b.V / b.W;
}

long Try(int i, long W, long V) {	//ham de quy kiem tra gia tri cua tung mon hang
	if (W > M) return 0;
	if (i == N && W <= M) return V;
	long l = Try(i + 1, W + a[i].W, V + a[i].V);
	long r = Try(i + 1, W, V);
	return max(l, r);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;	//nhap vao so luong mon hang va khoi luong toi da cua gia hang
	for (int i = 0; i < N; i++) {
		cin >> a[i].W >> a[i].V;	//nhap khoi luong va gia tri cua tung mon hang
	}
	cout << endl;
	cout << "Gia tri toi da thu duoc la: ";
	sort(a, a + N, cmp);

	cout << Try(0, 0, 0);	//tra ve ket qua la tong gia tri thu duoc
}