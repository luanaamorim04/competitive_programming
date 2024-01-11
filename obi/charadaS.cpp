#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
	vector<int> perm;
	for (int i = 0; i < 8; i++)
		perm.push_back(i+1);
	set<vector<int> > cj;
	do
	{		
		int x = perm[7];
		perm.pop_back();
		cj.insert(perm);
		for (int i : perm) cout << i << ' ';
		cout << endl;
		perm.push_back(x);
	} while (next_permutation(perm.begin(), perm.end()));
	cout << cj.size() << endl;
}
