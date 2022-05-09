#include <iostream>
#include <cstring>
#include <algorithm>
#define MAXN 200001

using namespace std;

int t, n, a, arr[MAXN], ans, nums[MAXN], freq[MAXN];

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        memset(nums, 0, sizeof(nums));
        memset(freq, 0, sizeof(freq));
        ans = 1;
        for (int i = 0; i < n; i++) 
        {
            cin >> arr[i];
            nums[arr[i]]++;
            freq[arr[i]]++;
        }

        sort(arr, arr+n);

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 1) continue;
            ans = max(ans, nums[arr[i]]);
            for (int j = arr[i]*2; j < MAXN; j += arr[i])
            {
                nums[j] = max(nums[j], nums[arr[i]] + freq[j]);
            }
        }
        
        cout << n - (ans + freq[1]) << endl;
    }
}