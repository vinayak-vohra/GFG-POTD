bool isPowerofTwo(long long n)
{
    if (!n)
        return 0;

    return !(n & (n - 1));
}