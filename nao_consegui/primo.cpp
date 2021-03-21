#include <iostream>

bool composto[3000000];   

int main()
{

    int N, Q, count, anterior = 2;
    std::cin >> Q; 
    composto[1] = true;
    int res[Q];
    
    for (int h = 0; h < Q; h++)
    {
        count = 0;
        std::cin >> N;
        for (int i = 2; i <= N; ++i)
        {
            if(!composto[i] && anterior < N)
            {
                count++;
                for(int j = anterior; j*i <= N; ++j)
                    composto[i*j] = true;
            } 
            else if (!composto[i])
                count++;
        }
        anterior = N;
        res[h] = count;
    }   

    for (int h = 0; h < Q; h++)
         std::cout << res[h] << '\n';

}
