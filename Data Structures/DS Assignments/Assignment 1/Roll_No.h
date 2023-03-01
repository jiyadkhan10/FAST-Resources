#include <iostream>
using namespace std;


double** Load_Data(string path); // Return 2D array which contains Data in that path. 
								// Data in 2D should be clean (definition of cleaning data is already mentioned in the assignment description)
								
double ** Distance(double * predictedArray,int predictedArraySize, double ** data,int dataRows,int dataCols); 
    // Return mean of all datapoint with the predicted datapoint along with Gardepoint in DS 
    
double ** Sort_k_Dis(int k, double ** distance, int distanceRows, int distanceCols);
	// Return the 1st k sorted distance with Grade point in Ascending order 
	
string Grade_Frequency(double ** sortedKList, int sortedKListRows,int sortedKListCols); 
	// Return the most frequent Grade in DS; You need to convert Grade point in Grade 



double * all_means(double ** Data,int dataRows,int dataCols);  // calculate and return mean of all datapoints

double * initia_k_Means(int k, double * allMeans, int allMeansSize); // Return Mean of 1st 13 students and index of the array will be cluster number 
// i-e , value in 0th index will be considered as the mean of cluster 0 ,  
// value in 1st index will be considered as the mean of cluster 1.

double *  Dist(double * allMeans,int allMeansSize, double * clusterMeans,int clusterMeansSize);
// Find the distance between mean of all datapoint and the mean of each cluster.  
// Assign closest cluster to each datapoint
// calculate new mean against each cluster 
// Return Updated Mean 

bool  Accuracy(double * oldClusterMeans,int oldClusterMeansSize, double * newClusterMeans,int newClusterMeansSize);
// return True if both means are same otherwise return false 

string Prediction(double newData, double * meansOfClustors,int meansOfClustorsSize);
// Calculate the distance of upcoming datapoint with the whole cluster means
//  and convert the index of closest cluster mean into Grade and return it.
