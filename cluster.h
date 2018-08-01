#include <vector>
#include <string>

// here there is definition of methods under my namespase
#ifndef CLUSTER_H
#define CLUSTER_H

extern std::vector<std::vector<int> > clusters;

extern std::vector<std::vector<double> > centroids;
namespace SBNCLA002{
  //defining a vector of clusters




double euclidianDist(double x1,double y1,double x2,double y2);
std::vector<double> calCentroid(std::vector<int> &cluster,std::vector<std::vector<int> > &data);
void popCentroids(std::vector<std::vector<int> > &data);
void assign(std::vector< std::vector<int> > &data);


}


#endif