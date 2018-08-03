#include <iostream>
#include "cluster.h"
#include <vector>
#include <string>
#include <cmath>
#include <limits>

using namespace std;
vector<vector<int> > clusters;
vector<vector<int> > previous;
vector<int> c1;
vector<int> c2;
vector<int> c3;
vector<vector<double> >centroids{{2,10},{5,8},{1,2}};

//for calculating the euclidian distance
double SBNCLA002::euclidianDist(double x1,double y1,double x2,double y2){
//calculate value here
    double value=sqrt(pow((x1-x2),2)+pow((y1-y2),2));
//assigningcout<<value<<" for "<<x1<<" "<<x2<<" "<<y1<<" "<<y2<<endl;
    return value;
}

//works fine, calculating the centroid
//takes in two vectors, cluster and the data
vector<double> SBNCLA002::calCentroid(vector<int> &cluster,vector< vector<int> > &data){

    double totalX=0;
    double totalY=0;
    for(int index:cluster){
        totalX+=data[index-1][0];//subract 1 because clusters are not counting like computers
        totalY+=data[index-1][1];
    }

    vector<double> centroid;
// cout<<totalX<<endl;
    centroid.push_back(totalX/cluster.size());
    centroid.push_back(totalY/cluster.size());

    return centroid;
}


void SBNCLA002::popCentroids(vector<vector<int> > &data){

    for(vector<double> &vec: centroids)
        vec.clear();
    centroids.clear();


    //use clusters to calculate and populate centroids
    for(vector<int> &cluster: clusters){
     //   cout<<"length is "<<cluster.size()<<endl;
        vector<double> temp= SBNCLA002::calCentroid(cluster,data);
      //  cout<<temp[0]<<" temp is  "<<temp[1]<<endl;
        centroids.push_back(temp);
    }

}


double smallest(double d1, double d2, double d3){
    return std::min(std::min(d1,d2),d3);
}

bool areSame(double d1, double d2){
    return fabs(d1-d2)< std::numeric_limits<double>::epsilon();
}




void SBNCLA002::assign(vector< vector<int> > &data){
    int count=1;
    //clusters.reserve(3);


    if( !clusters.empty()){
       // cout<<"centroids new"<<endl;
       previous=clusters;
       SBNCLA002::popCentroids(data);//new centroids
//        for(auto cent:centroids)
//            cout<<cent[0]<<" cent is "<<cent[1]<<endl;
    }

//clear the clusters for new ones
    for(vector<int> &cluster: clusters){

        cluster.clear();
        c1.clear();
        c2.clear();
        c3.clear();

    }
    clusters.clear();

//now do the assigning
//loop over the data and cal the distance from each centroid

    for(const vector<int> &val:data){

        double d1= SBNCLA002::euclidianDist(val[0], val[1],centroids[0][0],centroids[0][1]);
        double d2= SBNCLA002::euclidianDist(val[0], val[1],centroids[1][0],centroids[1][1]);
        double d3= SBNCLA002::euclidianDist(val[0], val[1],centroids[2][0],centroids[2][1]);


        double smallst = smallest(d1,d2,d3);

        if(areSame(smallst,d1)){

            c1.push_back(count);
        }
        if(areSame(smallst,d2)){
            c2.push_back(count);
        }
        if(areSame(smallst,d3)){
            c3.push_back(count);

        }


        count++;
    }

    clusters.push_back(c1);
    clusters.push_back(c2);
    clusters.push_back(c3);

}










