#include <iostream> 
#include <math.h>
#define ll long long

using namespace std;

struct vetor
{
    double x, y;

    vetor operator +(vetor q) const
    {
        return {x + q.x, y + q.y};
    }
    vetor operator -(vetor q) const
    {
        return {x - q.x, y - q.y};
    }
    double operator ~() const 
    {
        return hypot(x, y);
    }
    double operator *(vetor q) const 
    {
        return (x*q.x + y*q.y);
    }
    double operator ^(vetor q) const 
    {
        return (x*q.y - y*q.x);
    }
};

int32_t main()
{
	vetor a = {1, 1};
	vetor b = {2, 2};
	vetor c = a-b;
	cout << hypot(c.x, c.y) << endl;
		
}
