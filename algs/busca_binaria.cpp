int busca(int x, int y)
{
    int ini = 0, fim = y - 1;
    while (ini <= fim)
    {
        int meio = (ini + fim) / 2;
        if (lista[meio] == x) return meio;
        else if (lista[meio] < x)
        {
            ini = meio + 1;
        } 
        else if (lista[meio] > x)
        {
            fim = meio - 1;
        }
    }

    return -1;
}