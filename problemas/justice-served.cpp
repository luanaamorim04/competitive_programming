#include <iostream> 
#include <map> 
#define MAXN (int) (4e5 + 10)
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define iii tuple<int, int, int>

using namespace std;

vector<iii> v;
vector<int> arr;
map<int, int> mapa;
int n, a, b, st[MAXN<<2], resp[MAXN];

void update(int idx, int i, int j, int pos, int val)
{
	if (i == j)
	{
		st[idx] = max(st[idx], val);
		return;
	}
	int mid = (i+j)/2;
	if (pos <= mid) update(esq(idx), i, mid, pos, val);
	else update(dir(idx), mid+1, j, pos, val);
	st[idx] = max(st[esq(idx)], st[dir(idx)]);
}

int query(int idx, int i, int j, int l, int r)
{
	if (i > r || j < l) return 0;
	if (i >= l && j <= r) return st[idx];
	int mid = (i+j)/2;
	int x = query(esq(idx), i, mid, l, r);
	int y = query(dir(idx), mid+1, j, l, r);
	return max(x, y);
}

int32_t main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		v.push_back({a, -(a+b-1), i});
		arr.push_back(a);
		arr.push_back(a+b-1);
	}
	
	sort(arr.begin(), arr.end());
	sort(v.begin(), v.end());
	for (int i = 0; i < arr.size(); i++)
		mapa[arr[i]] = i+1;

	for (auto[l, r, idx] : v)
	{
		r = -r;
		l = mapa[l];
		r = mapa[r];
		resp[idx] = query(1, 1, 2*n, r, 2*n);
		update(1, 1, 2*n, r, 1 + resp[idx]);
	}

	for (int i = 0; i < n; i++) cout << resp[i] << ' ';
	cout << endl;
}
