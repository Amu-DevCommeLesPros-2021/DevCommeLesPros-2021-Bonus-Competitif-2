#include "utility.h"

#include <float.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Calculates the smallest number of coins required to pay a given price.
int n_coins_for_price(int const coin_set[], int const size_coin_set, int price)
{
    int n_coins = 0;

    for(int c = size_coin_set - 1; price != 0;)
    {
        if(price >= coin_set[c])
        {
            price -= coin_set[c];
            ++n_coins;
        }
        else
        {
            --c;
        }
    }

    return n_coins;
}

// Calculates the average number of coins to give change for all prices between
// 1 cent and 99 cents.
float average_change(int const coin_set[], int const size_coin_set)
{
    int n_coins_for_prices[99] = {0};

    // For all prices from 1 cent to 99 cent, calculate the number of coins.
    for(int price = 1; price < 100; ++price)
    {
        n_coins_for_prices[price] = n_coins_for_price(coin_set, size_coin_set, price);
    }

    // Calculate the average number of coins used for all prices.
    float average = 0.;
    for(int price = 1; price < 100; ++price)
    {
        average += n_coins_for_prices[price];
    }
    average /= 99;

    return average;
}

// Given a coin set, return the next possible set. e.g. [1, 2, 3] => [1, 2, 4], [1, 2, 99] => [1, 3, 4], etc.
// Return false if there are no further coin set. i.e. [1, 98, 99].
bool next_set(int coin_set[], int const size_coin_set)
{
    if(coin_set[1] == 99 - (size_coin_set - 2))
    {
        return false;
    }

    // From the highest index, find the index of the coin that hasn't reached its maximum value yet.
    // e.g. [1, 33, 98, 99] => 1
    int c;
    for(c = size_coin_set - 1; c != 0 && (coin_set[c] == 99 - (size_coin_set - (c + 1))); --c)
    {}

    // Increment the value of that coin...
    // e.g. [1, 33, 98, 99] => [1, 34, 98, 99].
    ++coin_set[c];

    // ...and set all greater coins' values to one more than the precedent.
    // e.g. [1, 34, 98, 99] => [1, 34, 35, 36].
    for(int i = c + 1; i != size_coin_set; ++i)
    {
        coin_set[i] = coin_set[i - 1] + 1;
    }

    // printf("Next coin set is %s.\n", to_string(coin_set, size_coin_set));

    return true;
}

// For a given coin set size, returns the best coin set and the average number of coins
// required for prices between 1 cent and 99 cent.
// For 'size_coin_set == 3', there are 4753 combinations possible from [1, 2, 3] to [1, 98, 99].
// For 'size_coin_set == 4', there are ???? combinations possible from [1, 2, 3, 4] to [1, 97, 98, 99].
void find_best_coin_set(int const size_coin_set, int best_coin_set[], float* lowest_average)
{
    // Initialize to [1, 2, 3, ...].
    int coin_set[size_coin_set];
    for(int i = 0; i != size_coin_set; ++i)
    {
        coin_set[i] = i + 1;
    }

    // Set current best to maximum float value.
    *lowest_average = FLT_MAX;

    int combinations = 0; 

    // Try all possible coin sets and remember the best one.
    do
    {
        ++combinations;

        float const average = average_change(coin_set, size_coin_set);
        
        // Found a better coin set. Save it.
        if(average < *lowest_average)
        {
            *lowest_average = average;
            memcpy(best_coin_set, coin_set, sizeof(int) * size_coin_set);

            // printf("Found this better coin set %s with an average of %f.\n", to_string(coin_set, size_coin_set), *lowest_average);
        }
    }
    while(next_set(coin_set, size_coin_set));

    // printf("Tried %d combinations.\n", combinations);
}

int main()
{
    float const euro_average = average_change((int[]){1, 2, 5, 10, 20, 50}, 6);
    printf("Average number of coins for the set of euro coins is %f.\n", euro_average);

    for(int size_coin_set = 3; size_coin_set < 7; ++size_coin_set)
    {
        int best_coin_set[size_coin_set];
        float lowest_average;

        find_best_coin_set(size_coin_set, best_coin_set, &lowest_average);

        printf("For a coin set of size %d, the best coin set is %s with an average of %f.\n", size_coin_set, to_string(best_coin_set, size_coin_set), lowest_average);
    }

    return 0;
}