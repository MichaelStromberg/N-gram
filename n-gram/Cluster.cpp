#include "StdAfx.h"
#include ".\cluster.h"

CCluster::CCluster(string name)
: m_name(name)
, m_numdocs(0)
{
	m_centroid = new CHashTable();
}

CCluster::~CCluster(void)
{}

void CCluster::AddDocument(CHashTable* pSkipList) {
	m_numdocs++;
	m_skiplists.insert(m_skiplists.end(),pSkipList);
}

void CCluster::ShowDocuments(void) {
	cout << "\nDocuments in cluster " << m_name.c_str() << endl;
	cout << "=======================================================================" << endl;
	for(int i=0;i<m_numdocs;i++) cout << "- " << m_skiplists[i]->m_filename.c_str() <<
		" (" << m_skiplists[i]->m_numhashes << ")" << endl;
}

void CCluster::BuildSimilarityMatrix(void) {
	printf("Building similarity matrix.\n");

	// let's make our own STL matrix
	vector<double> column;
	column.assign(m_numdocs+1,0.0);
	m_matrix.assign(m_numdocs+1,column);

	for(int i=0;i<m_numdocs+1;i++) {
		for(int j=0;j<i+1;j++) {

			if(i < m_numdocs) {

				//cout << "Calculating similarity between " << m_skiplists[i]->m_filename.c_str() << " & " << m_skiplists[j]->m_filename.c_str() << ": ";
				if(i == j) m_matrix[j][i] = 1.0;
					else m_matrix[j][i] = m_skiplists[i]->m_skiplist.Similarity(m_skiplists[j]->m_skiplist);
			
			} else if(j < m_numdocs) {
			
				//cout << "Calculating similarity between centroid & " << m_skiplists[j]->m_filename.c_str() << ": ";
				m_matrix[j][i] = m_centroid->m_skiplist.Similarity(m_skiplists[j]->m_skiplist);
			
			} else {
			
				//cout << "Calculating similarity between centroid & centroid" << ": ";
				m_matrix[j][i] = 1.0;
			}

			//cout << m_matrix[j][i] << endl;
		}
	}
}

void CCluster::ShowSimilarityMatrix(void) {
	double maximum = 0.0;
	double minimum = 2.0;

	cout << "\nSimilarity matrix for cluster " << m_name.c_str() << endl;
	cout << "=======================================================================" << endl;
	
	printf("\t");
	for(int j=0;j<m_numdocs;j++) printf("%7d ",j);
	printf("      C\n\n");

	for(int i=0;i<m_numdocs+1;i++) {
		if(i < m_numdocs) printf("%7d ",i);
			else printf("      C ");
		
		for(int j=0;j<i+1;j++) {
			printf("%7.5f ",m_matrix[j][i]);
			if(m_matrix[j][i] < minimum) minimum = m_matrix[j][i];
			if((m_matrix[j][i] > maximum) && (m_matrix[j][i] != 1.0)) maximum = m_matrix[j][i];
		}

		printf("\n");
	}

	printf("\n\nMinimum: %f\n",minimum);
	printf("Maximum: %f\n",maximum);
}

void CCluster::BuildCentroid(void) {
	printf("Building centroid.\n");

	// Add the vectors from the skip lists into the centroid skip list
	for(int i=0;i<m_numdocs;i++) m_centroid->m_skiplist.AddSkipList(m_skiplists[i]->m_skiplist);
	
	m_centroid->m_numhashes = m_centroid->m_skiplist.nTotalElements;
	printf("- hashes in centroid: %d\n",m_centroid->m_numhashes);
}

void CCluster::NormalizeDocuments(void) {
	printf("Normalizing cluster documents.\n");

	// normalize the skip lists
	for(int i=0;i<m_numdocs;i++) m_skiplists[i]->m_skiplist.Normalize();

	// normalize the centroid
	m_centroid->m_skiplist.Normalize();
}
void CCluster::MineSimilarities(CCluster* cluster2) {
	printf("Mining cluster similarities.\n");
	SkipList<unsigned int,double> similaritylist;

	similaritylist.AddSkipList(cluster2->m_centroid->m_skiplist);
	similaritylist.RemoveDisjunctSkipList(m_centroid->m_skiplist);

	cout << "Hashes in local centroid:         " << m_centroid->m_skiplist.nCount << endl;
	cout << "Hashes in other cluster centroid: " << cluster2->m_centroid->m_skiplist.nCount << endl;
	cout << "Hashes in similarity centroid:    " << similaritylist.nCount << endl;


}
