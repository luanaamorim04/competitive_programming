/*

COMPLEXIDADE DE ALGORITMOS

O(1) - constante
O(log(N)) - logarítmico
O(N) - linear 
O(N * log(N)) - supralinear
O(N ^ 2) - quadrático
O(N ^ 3) - cúbico
O(2 ^ N) - exponencial
O(N!) - exponencial

-> 1 segundo é mais ou menos 1.000.000 operações

DESCOBRIR COMPLEXIDADE NO MACETE

ver maior grau no polinômio

O(2N + 7) -> O(N)
O(N ^ 2 + N) -> O(N ^ 2)

cada linha é uma operação simples O(1)
_________________________________________

Exemplo 1:

int main()
{
    int n;
    cin >> n;
    cout << n;
    return 0;
}

Complexidade = O(4) -> O(1)
__________________________________________

Exemplo 2:

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
    }
    return 0;
}

Complexidade = O(3 + n) -> O(N)
___________________________________________

Exemplo 3:

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> m[i][j];

    return 0;
}

Complexidade = O(3 + n * n) -> O(n ^ 2)
____________________________________________

Exemplo 4:

int main()
{
    // achar numero de digitos
    int n, ans = 0;
    cin >> n;
    while (n)
    {
        ans++;
        n /= 10;
    }

    cout << ans;
}

Complexidade = O(log(N) na base 10) -> O(log(N));
_______________________________________________



*/