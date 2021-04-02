#include <iostream>
#include <cmath>
//#include <bits/stdc++.h>

using namespace std;

struct Ponto{
    double x, y;
    Ponto(){}
    Ponto(double _x, double _y){
      x = _x;
      y = _y;
    }
    Ponto operator+(const Ponto &oth){
      return Ponto(x + oth.x, y + oth.y);
    }
    Ponto operator-(const Ponto &oth){
      return Ponto(x - oth.x, y - oth.y);
    }
};

double dis(Ponto a, Ponto b);
Ponto medio(Ponto a, Ponto b);
bool colineares(Ponto a, Ponto b, Ponto c);
double coef(Ponto a, Ponto b);
double angulo(double a, double b);

int main()
{
    Ponto pontos[7];
    for (int i = 0; i < 7; i++)
        cin >> pontos[i].x >> pontos[i].y;
    
    // angulo agudo entre p2 p1 p3 :(
    double a = coef(pontos[0], pontos[1]);
    double b = coef(pontos[0], pontos[2]);
    if ( abs((a - b) / (1 + (a * b))) < 0)
    {
        cout << "teste 1\n";
        return 0;
    }

    // dis(p1, p2) == dis(p1, p3)
    if (dis(pontos[0], pontos[1]) != dis(pontos[0], pontos[2]))
    {
       cout << "teste 2\n";
        return 0;
    }

    // p2, p3, p4, p5 sao colineares 
    if (colineares(pontos[1], pontos[2], pontos[3]) == false || colineares(pontos[4], pontos[2], pontos[3]) == false)
    {
        cout << "teste 3\n";
        return 0;
    }

    // ponto medio p2 p3 == ponto medio p4 p5 
    Ponto medio1 = medio(pontos[1], pontos[2]);
    Ponto medio2 = medio(pontos[3], pontos[4]);
    if (medio1.x != medio2.x || medio1.y != medio2.y)
    {
        cout << "teste 4\n";
        return 0;
    }  

    // p2 p3 > p4 p5
    if (dis(pontos[1], pontos[2]) <= dis(pontos[3], pontos[4]))
    {
        cout << "teste 5\n";
        return 0;
    }

    // p4 p6 perpendicular a p2 p3 :(
    double k = coef(pontos[3], pontos[5]);
    double l = coef(pontos[1], pontos[2]);
    cout << k << ' ' << l << endl;
    if ( k != -1 * (1 / l))
    {
        cout << "teste 6\n";
        return 0;
    }

    // p4 p6 == p5 p7
    if (dis(pontos[3], pontos[5]) != dis(pontos[4], pontos[6]))
    {
        cout << "teste 7\n";
        return 0;
    }

    // p1 p6 separado por p2 p3 
    if (coef(pontos[0], pontos[5]) == coef(pontos[1], pontos[2]))
    {
        cout << "teste 8\n";
        return 0;
    }

    //cout << coef(pontos[0], pontos[5]) << endl;

    cout << 'S' << endl;
    
}







double dis(Ponto a, Ponto b)
{
    int lado1 = (a.x - b.x) * (a.x - b.x);
    int lado2 = (a.y - b.y) * (a.y - b.y);
    return sqrt( abs(lado1 + lado2) );
}

Ponto medio(Ponto a, Ponto b)
{
    Ponto res;
    res.x = (a.x + b.x) / 2;
    res.y = (a.y + b.y) / 2;
    return res;
}

bool colineares(Ponto a, Ponto b, Ponto c)
{
    double det = (a.x * b.y) + (a.y * c.x) + (b.x * c.y) - (b.y * c.x) - (c.y * a.x) - (a.y * b.x);
    if (det == 0)
        return true;
    
    return false;
}
  
double coef(Ponto a, Ponto b)
{
    //if (b.x - a.x) return 0;
    return (b.y - a.y) / (b.x - a.x);
}

double angulo(double a, double b)
{
    return (a - b) / (1 + (a * b));
}
