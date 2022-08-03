#include <iostream>
using namespace std;

struct node
{
    int dist[10];
    int from[10];
} rt[10];

int main()
{
    cout << "Enter number of nodes : ";
    int n;
    cin >> n;
    cout << "Enter Matrix : ";
    int m[10][10];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> m[i][j];
            m[i][i] = 0;
            rt[i].dist[j] = m[i][j];
            rt[i].from[j] = j;
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
            {
                if (m[i][j] > m[i][k] + m[k][j])
                {
                    rt[i].dist[j] = m[i][k] + m[k][j];
                    rt[i].from[j] = k;
                }
            }

    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << endl;
        cout << "Node via dist" << endl;
        for (int j = 0; j < n; j++)
        {
            cout << j + 1 << "    " << rt[i].from[j] + 1 << "     " << rt[i].dist[j] << endl;
        }
    }
}