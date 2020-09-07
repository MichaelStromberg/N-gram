// n-gram.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Ngram.h"

int _tmain(int argc, _TCHAR* argv[]) {

	CNgram ngram;
	ngram.CreateClusters();
	ngram.ShowDocuments();
	ngram.BuildClusterCentroids();
	ngram.NormalizeClusters();

	//printf("Distance: %f\n",ngram.m_clusters[1]->m_centroid->m_skiplist.Distance(ngram.m_clusters[2]->m_centroid->m_skiplist));

	ngram.BuildClusterSimilarityMatrix();
	ngram.ShowClusterDistanceMatrix();
	//ngram.ShowClusterSimilarityMatrix();

	//ngram.InvestigateClusterCentroids();
	//ngram.WriteClusterSimilarityMatrix();

	return 0;
}

