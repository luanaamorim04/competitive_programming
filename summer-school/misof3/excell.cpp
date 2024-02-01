#include <bits/stdc++.h>
#include <iostream>
#define int unsigned long long

using namespace std;

int r, c, q;

string numto(string s)
{
	int line = 0, col = 0;
	int n = stoll(s);
	string pos, pos2;
	line = n / c;
	col = n % c;
	if (col) line++;
	else col = c;

//	cout << line << ' ' << col << endl;
	
	while (col)
	{
		pos += (char)('A' + ((col+25)%26));
		col = ((col-1) /26);
	}

	reverse(pos.begin(), pos.end());

	while (line)
	{
		pos2 += (char)('0' + (line%10));
		line /= 10;
	}

	reverse(pos2.begin(), pos2.end());
	return pos+pos2;
}

int tonum(string s)
{
	string col, line;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9') line += s[i];
		else col += s[i];
	}

	int m = 0;
	for (int i = 0; i < col.size(); i++)
	{
		m *= 26;
		m += ((col[i]-'A')%26) + 1; 
	}

	return (stoll(line)-1)*(c) + m;

}

int32_t main()
{
	cin >> r >> c >> q;
	while (q--)
	{
		string s;
		cin >> s;
		if (s[0] >= '0' && s[0] <= '9') cout << numto(s) << endl;
		else cout << tonum(s) << endl;

	}
}
