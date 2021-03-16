#include <vector>

/*
    DIST[U] = menor caminho de S para U
    processado -> vértice que foi relaxado
    começo:
        ninguém foi processado
        DIST[U] = INF para todo U
        DIST[S] = 0, S é a origem

    meio:
        para todo vértice U não processado:
            escolhe U com menor DIST[U]
            relaxo seus vizinhos

    *toda vez que relaxo os vizinhos de U, 
    eu tenho certeza que DIST[U] é menor possível

    começo:
        começo com S
        relaxo seus vizinhos
*/

int n;
int m;
int s;
int u, v, w;
vector<vector<pair<int, int> > >adj;
vector<int> dist; // dist[u] guardar menor caminho de S até U
vi proc;// pproc[u] diz se U ja foi processado
vi ult; // ult[u] diz qual ultimo vértice anterior a U no menor caminho de S até U

void dijkstra(int s){
    dist = vi(n+1,INF);
    proc = vi(n+1,0);
    ult = vi(n+1,-1);
    dist[s] = 0;

    for (int i=1; i<=n; ++i){
        u = 0;//nunca usado
        for (int j=1; j<=n; ++j){
            if (!proc[j] && dist[j] <= dist[u]){
                u = j;
            }
        }
        proc[u] = 1;

        for (auto [v,w] : adj[u]){
            if (dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                ult[v] = u;
            }
        }
    }
}