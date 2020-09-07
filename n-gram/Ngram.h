#pragma once

#include "Cluster.h"

#define RELATED_LANG 0.184
#define RELATED_LANG_DISTANCE 0.98288

using namespace std;

class CNgram {
public:
	CNgram(void);
	~CNgram(void);
	void CreateClusters(void);
	void ShowDocuments(void);
	void BuildClusterCentroids(void);
	void NormalizeClusters(void);
	void BuildClusterDistanceMatrix(void);
	void BuildClusterSimilarityMatrix(void);
	void ShowClusterSimilarityMatrix(void);
	void ShowClusterDistanceMatrix(void);
	void WriteClusterSimilarityMatrix(void);
	void InvestigateClusterCentroids(void);
	vector<CCluster*> m_clusters;
private:
	vector<vector<double> > m_matrix;
};
