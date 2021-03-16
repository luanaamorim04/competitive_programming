#include <iostream>

using namespace std;

const int MAX_ALUNOS = 1000;
int i, indice_melhor, n, turma;
struct aluno
{
    int codigo, media;
};
aluno alunos[MAX_ALUNOS];

int main()
{
	while (cin >> n && n > 0)
	{
		for (i = 0; i < n; i++)
			cin >> alunos[i].codigo >> alunos[i].media;
	
		indice_melhor = 0;
		for (i = 1; i < n; i++)
			if (alunos[i].media > alunos[indice_melhor].media)
		        indice_melhor = i;

        cout << "Turma " << ++turma << endl;
		
        for (i = 0; i < n; i++)
        {
            if (alunos[i].media == alunos[indice_melhor].media)
            cout << alunos[i].codigo << ' ';
        }

        cout << endl << endl;
	}
	return 0;
}
