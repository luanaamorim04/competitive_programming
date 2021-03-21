#include <iostream>

int main()
{
    char a[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int count = 0;

    for (int i = 1; i < 6; i++)
    {
        char a1 = a[i];
        for (int j = 0; j < 6; j++)
        {
            char a2 = a[j];
            if (a2 != a[1] && a1 != a2)
            {
                for (int k = 0; k < 6; k++)
                {
                    char a3 = a[k];
                    if (k != 2 && a1 != a3 && a2 != a3)
                    {
                        for (int l = 0; l < 6; l++)
                        {
                            char a4 = a[l];
                            if (l != 3 && a1 != a4 && a2 != a4 && a3 != a4)
                            {
                                for (int z = 0; z < 6; z++)
                                {
                                    char a5 = a[z];
                                    if (z != 4 && a1 != a5 && a2 != a5 && a3 != a5 && a4 != a5)
                                    {
                                        for (int y = 0; y < 6; y++)
                                        {
                                            char a6 = a[y];
                                            if (y != 5 && a1 != a6 && a2 != a6 && a3 != a6 && a4 != a6 && a5 != a6)
                                            {
                                                count++;
                                            }
                                        }
                                    }
                                        std::cout << a1 << a2 << a3 << a4 << a5 << '\n';
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    std::cout << count << '\n';
}

// BADEC
// BAECD
// BCAED
// BCDEA
// BCEAD
// BDAEC
// BDEAC
// BDECA
// BEACD
// BEDAC
// BEDCA
// CABED
// CADEB
// CAEBD
// CDAEB
// CDBEA
// CDEAB
// CDEBA
// CEABD
// CEBAD
// CEDAB
// CEDBA
// DABEC
// DAEBC
// DAECB
// DCAEB
// DCBEA
// DCEAB
// DCEBA
// DEABC
// DEACB
// DEBAC
// DEBCA
// EABCD
// EADBC
// EADCB
// ECABD
// ECBAD
// ECDAB
// ECDBA
// EDABC
// EDACB
// EDBAC
// EDBCA