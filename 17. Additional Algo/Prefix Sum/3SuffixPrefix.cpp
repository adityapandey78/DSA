
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int nums[] = {1, 2, 3, 4};
    int n = sizeof(nums) / sizeof(nums[0]);

    vector<int> prep(n);
    prep[0] = nums[0];
    vector<int> suffp(n);
    suffp[n - 1] = nums[n - 1];

    for (int i = 1; i < n; i++)
    {
        prep[i] = prep[i - 1] * nums[i];
    }

    for (int i = n - 2; i >=0; i--)
    {
        suffp[i] = suffp[i + 1] * nums[i];
    }

    for (int i = 0; i < n; i++)
    {
        nums[i] = prep[i - 1] * suffp[i + 1];
    }
    for (int i = 0; i < n; i++)
    {
        cout << prep[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << suffp[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}
