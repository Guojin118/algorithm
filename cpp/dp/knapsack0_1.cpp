#include <iostream>
#include <assert.h>
#include <algorithm>
#include <cstring>
using namespace std;

#define AVAIL_ITEM_NUM 4
#define TOTAL_WEIGHT 8
int knapsack01( int profit[], int weight[], bool involve[] )
{
    int total_profit = 0;
    int weight_profit_table[AVAIL_ITEM_NUM+1][TOTAL_WEIGHT+1] = {0};
    
    //contruct weight profit table
    for (int i = 1; i <= AVAIL_ITEM_NUM; i++)
    {
        for (int w = 1; w <= TOTAL_WEIGHT; w++)
        {
            if ( (w-weight[i]) < 0 )
            {
                weight_profit_table[i][w] = weight_profit_table[i-1][w];
            }
            else
            {
                weight_profit_table[i][w] = max(
                    weight_profit_table[i-1][w],
                    weight_profit_table[i-1][w-weight[i]] + profit[i]);
            }
        }
    }

    //find items involved
    int left_weight = TOTAL_WEIGHT;

    for (int i = AVAIL_ITEM_NUM; i > 0; i--)
    {
        if (weight_profit_table[i][left_weight] > weight_profit_table[i-1][left_weight])
        {
            involve[i] = true;
            left_weight = left_weight - weight[i];
        }
    }

    total_profit = weight_profit_table[AVAIL_ITEM_NUM][TOTAL_WEIGHT];
    return total_profit;
}


int main()
{
    int profit[] = {0, 1, 2, 5, 6};
    int weight[] = {0, 2, 3, 4, 5};
    bool involved[] = {false, false, false, false, false};
    int total_profit = 0;
    total_profit = knapsack01(profit, weight, involved);

    printf("total profit : %d\n", total_profit);

    for(int i = 1; i <= AVAIL_ITEM_NUM; i++)
    {
        printf("involved item(%d): %d \n", i, involved[i]);
    }
    printf("\n");
}