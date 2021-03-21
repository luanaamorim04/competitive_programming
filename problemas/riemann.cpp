#include <iostream>

using namespace std;

bool e_composto[3000010];
int primos[3000010], nums[100010], pos = 1;

void crivo(int n)
{
    for(int i = 2; i <= n; ++i)
    {
        if(e_composto[i] == false)
        {
            for(int j = 2; j*i <= n; ++j)
            {
                e_composto[i*j] = true;
            }
            primos[i] = pos;
            pos++;
        }
        else
        {
            primos[i] = -1;
        }
        
    }
    return;
}

int main(){
    primos[0] = 0;
    primos[1] = 0; 
    int Q, max = 0;
    e_composto[1] = true; 
    cin >> Q;
    for(int i = 0; i < Q; i++)
    { 
        cin >> nums[i];
        if (max < nums[i])
            max = nums[i];

    }

    crivo(max);

    for (int i = 0; i < Q; i++)
    {
        cout << primos[nums[i]] << endl;
    }

}
