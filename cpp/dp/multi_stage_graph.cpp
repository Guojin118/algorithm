#include <iostream>
#include <assert.h>
#include <cstring>

using namespace std;

struct graph_t {
    int vertex_num;
    int edge_num;
    int start;
    int end;
    int edge[64][64];

    graph_t()
    {
        vertex_num = 12;
        edge_num = 21;
        start = 1;
        end = 12;
        memset(edge, 0, sizeof(edge));
        edge[1][2] = 9;
        edge[1][3] = 7;
        edge[1][4] = 3;
        edge[1][5] = 2;

        edge[2][6] = 4;
        edge[2][7] = 2;
        edge[2][8] = 1;

        edge[3][6] = 2;
        edge[3][7] = 7;
        
        edge[4][8] = 11;
                
        edge[5][7] = 11;
        edge[5][8] = 8;
    
        edge[6][9] = 6;
        edge[6][10] = 5;

        edge[7][9] = 4;
        edge[7][10] = 3;

        edge[8][10] = 5;
        edge[8][11] = 6;
    
        edge[9][12] = 4;
        edge[10][12] = 2;
        edge[11][12] = 5;    
    };
};


int shortest_path(graph_t &g)
{
    static int edge[1024][1024];
    static int cost[1024];
    static int d[1024];
    int vertex_num = g.vertex_num;

    //initialization
    memset(edge,0,sizeof(edge));
    memset(cost, 0, sizeof(cost));
    memset(d, 0, sizeof(d));
    for(int i=0; i<=vertex_num; i++)
    {
        for(int j=0; j<=vertex_num; j++)
        {
            edge[i][j] = g.edge[i][j];
            //printf("%d ", edge[i][j]);
        }
        //printf("\n");
    }
    
    cost[vertex_num] = 0;
    d[vertex_num] = vertex_num;
    for (int i = vertex_num-1; i > 0; i--)
    {   
        cost[i] = 65535;
        for(int j=i+1; j<=vertex_num; j++)
        {
            int temp_cost = edge[i][j] + cost[j];
            if ( (edge[i][j]!=0) && (cost[i] > temp_cost))
            {
                cost[i] = temp_cost;
                d[i] = j;
            }
        }    
    }

    int path = 1;
    printf("path: ");
    while(path<vertex_num)
    {
        printf("%d ", d[path]);
        path = d[path];
    }
    printf("\n");
    printf("cost : %d\n", cost[1]);
        
    return cost[1];
}

int main()
{
    graph_t abc;
    shortest_path(abc);
}