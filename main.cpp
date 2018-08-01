#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "cluster.h"

using namespace std;

int main() {


    vector<vector<int> > data{{2,10},{2,5},{8,4},{5,8},{7,5},{6,4},{1,2},{4,9}};

    for(int i=0;i<5;++i){
        cout<<"Iteration: "<<i<<endl;
        SBNCLA002::assign(data);



        for(vector<int> clust: clusters){
            for(int val:clust){
                cout<<val<<", ";

            }
            cout<<endl;
        }
    }
}





