#include <iostream>
#include <vector>

using namespace std;

int search_Mindist (vector<double>& dist, vector<bool>& flag)
{
    double min = 1000000;
    int min_index = -1;
    for (int i = 0; i < dist.size(); i++)
    {
        if (flag[i] == false && dist[i] < min)
        {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void Dijkstra (vector<vector<double>>& Graph)
{
    vector<double> dist (Graph.size(), 10000000);
    vector<bool> flag (Graph.size(), false);
    dist[0] = 0;
    for (int i = 0; i < dist.size(); i++)
    {
        int u = search_Mindist(dist, flag);
        flag[u] = true;
        for (int v = 0; v < dist.size(); v++)
        {
            if(dist[u] + Graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + Graph[u][v];
            }
        }
    }
    for (int i = 0; i < dist.size(); i++)
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
