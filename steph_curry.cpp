/* what is the probability of steph curry making ten consecutive three pointers based on his in-game shooting percentages,
subsequently what is the probability of him making ten consecutive free throws;
career 3P% = .435, FT% = .906 
(via basketball-reference.com) */

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <set>

#include <ctime>


using namespace std;


int shooting(float shooting_percentage){

    int pdf = rand()%1000;
    int converted_shooting_percentage = shooting_percentage*1000;
    
    if (pdf < converted_shooting_percentage){
        return 1;
    }
    else
    {
        return 0;
    }
}

float mc_steph_curry(int n_drills, int consecutive_shots, float shooting_percentage){
    
    int shot;
    set <int> shot_count;
    int successful_series = 0;
    int first_shot = 0;
    int series_type;

    for (int i =0; i < n_drills; ++i){
        for (int j=0; j < consecutive_shots; ++j){
            shot = shooting(shooting_percentage);
            shot_count.insert(shot);
        }
        series_type = *shot_count.begin();
        if (shot_count.size() == 1 && series_type == 1){
            ++successful_series;
        }
        shot_count.clear();

    }
    return (float) successful_series/ (float) n_drills;
}


int main(){
    srand(time(NULL));
    float p = mc_steph_curry(10000000, 10, 0.435);
    cout << "the estimated probability of making 10 consecutive 3PTs: "<< p*100 << "%" << ", which means once in every "<< 1.0/p*10 << " shots" << endl;
    //cout << "the estimated probability of making 10 consecutive FTs: "<< p*100 << "%" << ", which means once in every "<< 1.0/p*10 << " shots" << endl;
}
