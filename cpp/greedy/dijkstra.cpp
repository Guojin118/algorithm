#include <iostream>
#include <assert.h>
#include <cstring>

#define VERTEX_NUM 6

using namespace std;
int INF = 65535;
struct cost_t
{
    bool used;
    int cost;
};

int find_min_unused_vertex(cost_t path_cost[], int vertex_num)
{
    int min_cost = INF; /**/
    int min_used_vertex = -1;
    for (int i = 1; i <= vertex_num; i++)
    {
        if(path_cost[i].used==false)
        {
            if(path_cost[i].cost<min_cost)
            {
                min_cost = path_cost[i].cost;
                min_used_vertex = i;
            }
        }
    }
    return min_used_vertex;
}

void shortest_path(int g[][VERTEX_NUM+1], cost_t path_cost[])
{
    int vertex_num = VERTEX_NUM;
    path_cost[1].cost = 0;
    path_cost[1].used = true;
    for (int i = 2; i <= vertex_num; i++)
    {   /* initialize 1->i to infinite*/
        path_cost[i].used = false;
        if ( g[1][i] != 0 ) /*has path*/
        {
            path_cost[i].cost = g[1][i];
        }
        else
        {
            path_cost[i].cost = INF;
        }
    }

    int min_vertex = find_min_unused_vertex(path_cost, vertex_num);
    while(min_vertex>0 && min_vertex<=vertex_num)
    {
        for (int j = 2; j <= vertex_num; j++)
        {
            if ( g[min_vertex][j] != 0 )
            {
                path_cost[j].cost = min(g[min_vertex][j] + path_cost[min_vertex].cost, 
                                        path_cost[j].cost);
            }
        }
        path_cost[min_vertex].used = true; /*vertex relaxed*/
        min_vertex = find_min_unused_vertex(path_cost, vertex_num);
    }
}



int main()
{
    cost_t path_cost[VERTEX_NUM+1];
    static int graph[][VERTEX_NUM+1] = {
         /* 0 value means no path */
         /* 0  1  2  3  4  5  6 */
    /*0*/  {0, 0, 0, 0, 0, 0, 0},
    /*1*/  {0, 0, 2, 4, 0, 0, 0},
    /*2*/  {0, 0, 0, 1, 7, 0, 0},
    /*3*/  {0, 0, 0, 0, 0, 3, 0},
    /*4*/  {0, 0, 0, 0, 0, 0, 1},
    /*5*/  {0, 0, 0, 0, 2, 0, 5},
    /*6*/  {0, 0, 0, 0, 0, 0, 0}
    };

    shortest_path(graph, path_cost);
    for (int i = 1; i <= VERTEX_NUM; i++)
    {
        printf("%d ", path_cost[i].cost);
        printf("\n");
    }
    printf("\n");
}