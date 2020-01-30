#include <iostream>
#include <assert.h>
#include <cstring>

using namespace std;

#define INF 65535
#define VERTEX_NUM 7
#define EDGE_NUM 10

void bellman_ford(int edges[][EDGE_NUM+1], int path_cost[])
{
    bool updated = true; /* to ensure first update*/
    for (int i = 1; i <= VERTEX_NUM; i++)
    {   //suppose update iteration num should be VERTEX_NUM -1 
        //but we want to ensure if there is negative weight cycle
        //so we introduce one more iteration to check if still any update
        if (updated == true)
        {
            updated = false;
            for (int k = 1; k <= EDGE_NUM; k++)
            {
                int start = edges[k][0];
                int end = edges[k][1];
                int weight = edges[k][2];
                int new_weight = path_cost[start]+weight;
                if (new_weight<path_cost[end])
                {
                    path_cost[end] = new_weight;
                    updated = true;
                }
            }
        }
        else
        {
            break;
        }
    }

    if(updated)
    {
        printf("negative weight cycle found, bellman ford algorithm not work\n");
    }
}

int main()
{
    int path_cost[] = {0, 0, INF, INF, INF, INF, INF, INF};
    int edges[][EDGE_NUM+1] = 
    {   /*  {start, end,    weight}*/
            { 0,     0,       0 },
            { 1,     2,       6 },
            { 1,     3,       5 },
            { 1,     4,       5 },
            { 2,     5,      -1 },
            { 3,     2,      -2 },
            { 3,     5,       1 },
            { 4,     3,      -2 },
            { 4,     6,      -1 },
            { 5,     7,       3 },
            { 6,     7,       3 },
    };

    bellman_ford(edges, path_cost);
    for (int i = 1; i <= VERTEX_NUM; i++)
    {
        printf("%d ", path_cost[i]);
    }
    printf("\n");
}