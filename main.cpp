#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "cluster.h"
#include <fstream>
using namespace std;
void writeFile(int iteration);
bool should_stop();

int main() {


    vector<vector<int> > data{{2,10},{2,5},{8,4},{5,8},{7,5},{6,4},{1,2},{4,9}};
int i=1;
    while(!should_stop()){
        SBNCLA002::assign(data);
        //cout<<"Stop: "<<should_stop();
        writeFile(i);

    ++i;
}
}


bool should_stop(){
    //check for equality
    if(previous.size()==0)
        return false;
    for(int i=0;i<previous.size();i++){
        if(previous[i]!=clusters[i])
            return false;
    }
    return true;
}

void writeFile(int iteration)
{
    ofstream myfile;
    myfile.open ("output1.txt", ios::out | ios::app );
    //myfile << "Writing this to a file.\n";

    myfile<<"Iteration "<<iteration<<"\n\n";

    for(int i=0;i<clusters.size();++i){
        myfile<<"Cluster "<<i+1<<": ";
        for(int j=0;j<clusters[i].size();j++){
            if(j==clusters[i].size()-1)
            myfile<<clusters[i][j];
            else
                myfile<<clusters[i][j]<<", ";
        }
        // writeFile(clust);
        myfile<<endl;
        myfile<<"Centroid: ("<<centroids[i][0]<<", "<<centroids[i][1]<<")\n\n";
    }

    myfile.close();

}




