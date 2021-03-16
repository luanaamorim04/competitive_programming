int hanoi(int n)
{
    int num;
    if (n == 1)
        return 1;
    else 
    {
        num = 2 * (hanoi(n - 1)) + 1;
    }
    return num;
}

