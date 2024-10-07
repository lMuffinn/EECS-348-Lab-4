/*
NFL score
Purpose: Give a list of all possible score combinations to achieve a given score
Date Created: 10-6-2024
Author: Matthew Eagleman
*/
//Headers
#include <stdio.h>
//Finding the score
void find_combos(int target_score){
    //find the plays that can result in the given score
    int max_saf = target_score / 2;
    int max_fg = target_score / 3;
    int max_td = target_score / 6;
    int max_tdfg = target_score / 7;
    int max_td2p = target_score / 8;
    for (int td2p = 0;td2p<=max_td2p; td2p++){
        for (int tdfg = 0;tdfg<=max_tdfg; tdfg++){
            for (int td = 0;td<=max_td; td++){
                for (int fg = 0;fg<=max_fg; fg++){
                    for (int saf = 0;saf<=max_saf; saf++){
                        int test_score = td2p*8+tdfg*7+td*6+fg*3+saf*2;
                        if (test_score == target_score) printf("\n%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety",td2p,tdfg,td,fg,saf);
                    }
                }
            }
        }
    }
}
//Program
int main(){
    //Run the program
    int score;
    while (1){
        printf("\n\nInput a score of 1 or less to STOP");
        printf("\nEnter NFL score: ");
        scanf(" %d", &score);
        if (score < 2) break;
        printf("\nPossible combinations of scoring plays if a team's score is %d", score);
        find_combos(score);
    }
}