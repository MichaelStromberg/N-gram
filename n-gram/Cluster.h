#pragma once

#include <vector>
#include "hashtable.h"
#include "SkipList.h"

using namespace std;

class CCluster {
public:
	CCluster(std::string name);
	~CCluster(void);

	void AddDocument(CHashTable* pSkipList);
	void ShowDocuments(void);
	void BuildCentroid(void);
	void BuildSimilarityMatrix(void);
	void BuildDistanceMatrix(void);
	void ShowSimilarityMatrix(void);
	void NormalizeDocuments(void);
	void MineSimilarities(CCluster* cluster2);
	
	string m_name;
	CHashTable* m_centroid;
	int m_numdocs;
	vector<CHashTable*> m_skiplists;
	vector<vector<double> > m_matrix;
};
