#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long int lli;

ld log26(long num)
{
    return log10l(num) / 1.415;
}

string colName(long long int n)
{
    int length = ceill(log26(n));
    char result[length];

    while (n)
    {
        lli rem = n % 26;

        result[--length] = rem ? 'A' + (rem - 1) : 'Z';
        n = n / 26 - (!rem);
    }
    
    return string(result);
}

int main()
{
    // lli num = 937482927383842;
    // cout << colName(num);

}