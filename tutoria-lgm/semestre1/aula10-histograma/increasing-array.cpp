#include <iostream> 
#define MAXN (int) (1<<20)
#define MAXL 18 
#define int long long

using namespace std;

int n, q, l, r, psa[MAXN], resp[MAXN], maior[MAXL][MAXN], arr[MAXN], prox_maior[MAXN];

int32_t main()
{
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		psa[i] = psa[i-1] + arr[i];
		maior[0][i] = i;
	}

	arr[n+1] = 1e9;
	for (int i = n; i >= 1; i--)
	{
		prox_maior[i] = i+1;
		while (arr[prox_maior[i]] <= arr[i]) prox_maior[i] = prox_maior[prox_maior[i]];
		resp[i] = resp[prox_maior[i]] + (prox_maior[i]-i-1)*arr[i] - (psa[prox_maior[i]-1] - psa[i]);
	}

	for (int i = 1; i < MAXL; i++)
		for (int j = 1; j <= n; j++)
			maior[i][j]=(arr[maior[i-1][j]]>arr[maior[i-1][j+(1<<(i-1))]]?maior[i-1][j]:maior[i-1][j+(1<<(i-1))]);

	while (q--)
	{
		cin >> l >> r;
		int msb = 31 - __builtin_clz(r-l+1);
		int esq = maior[msb][l];
		int dir = maior[msb][r - (1<<msb) + 1];
		int big = (arr[esq] > arr[dir] ? esq : dir); 
		cout << resp[l] - resp[prox_maior[big]]- ((prox_maior[big] - r - 1)*arr[big] - psa[prox_maior[big]-1] + psa[r]) << endl;
	}

}
