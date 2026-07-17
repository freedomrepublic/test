#include <iostream>
#include <vector>
using namespace std;

int searchMin(vector<double>& dist, vector<bool>& flag)
{
    double min = 100000;
    int min_index = -1;
    int n = dist.size();
    for (int i = 0; i < n; i++)
    {
        if (dist[i] < min && !flag[i])
        {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void Dijkstra(vector<vector<double>>& weightedGraph)
{
    int n = weightedGraph.size();
    vector<bool> flag(n, false);
    vector<double> dist(n, 1000000);
    dist[0] = 0;
    for (int i = 0; i < n; i++)
    {
        int u = searchMin(dist, flag);
        if (u == -1)
        {
            break;
        }
        flag[u] = true;
        for (int v = 0; v < n; v++)
        {
            if (weightedGraph[u][v] != 1000000 && dist[u] + weightedGraph[u][v] < dist[v])
            {
                dist[v] = dist[u] + weightedGraph[u][v];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (dist[i] != 1000000)
        {
            cout << "The minimum distance between 0 and " << i << " is " << dist[i] << "." << endl;
        }
        else
        {
            cout << "There is no path between 0 and " << i << "." << endl;
        }
    }
}

int main()
{
    int m, n;
    cout << "Please enter the number of graph nodes and edges:" << endl;
    cin >> m >> n;
    vector<vector<double>> weightGraph(m, vector<double>(m, 1000000));
    cout << "Please enter the undirected edges and weights:" << endl;
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        double w;
        cin >> w;
        weightGraph[u][v] = w; 
        weightGraph[v][u] = w;
    }
    Dijkstra(weightGraph);
}
