#include "StdAfx.h"
#include "Ngram.h"

CNgram::CNgram(void) {}

CNgram::~CNgram(void) {}

void CNgram::CreateClusters(void) {

	// English cluster
	m_clusters.insert(m_clusters.end(),new CCluster("English"));
	m_clusters[m_clusters.size()-1]->AddDocument(new CHashTable("Sterling - Hacker Crackdown.txt"));
	m_clusters[m_clusters.size()-1]->AddDocument(new CHashTable("Hazlitt - Liber Amoris or The New Pygmalion.txt"));
	m_clusters[m_clusters.size()-1]->AddDocument(new CHashTable("Levy - Hackers, Heroes of the Computer Revolution.txt"));
	m_clusters[m_clusters.size()-1]->AddDocument(new CHashTable("Chomsky - How America Determines Friends and Foes.txt"));
	m_clusters[m_clusters.size()-1]->AddDocument(new CHashTable("Darwin - The Descent of Man.txt"));
	m_clusters[m_clusters.size()-1]->AddDocument(new CHashTable("Scott - The Lady of the Lake.txt"));
	m_clusters[m_clusters.size()-1]->AddDocument(new CHashTable("Schwartau - Terminal Compromise.txt"));
	m_clusters[m_clusters.size()-1]->AddDocument(new CHashTable("Locke - Two Treatises of Government.txt"));
	
	// Norwegian cluster
	m_clusters.insert(m_clusters.end(),new CCluster("Norwegian"));
	m_clusters[m_clusters.size()-1]->AddDocument(new CHashTable("Asbjørnsen - Norske Folkeeventyr.txt"));

	// Danish cluster
	m_clusters.insert(m_clusters.end(),new CCluster("Danish"));
	m_clusters[m_clusters.size()-1]->AddDocument(new CHashTable("Bang - Min gamle kammerat.txt"));

	// Finnish cluster
	m_clusters.insert(m_clusters.end(),new CCluster("Finnish"));
	m_clusters[m_clusters.size()-1]->AddDocument(new CHashTable("Aho - Rautatie.txt"));

	// Swedish cluster
	m_clusters.insert(m_clusters.end(),new CCluster("Swedish"));
	m_clusters[m_clusters.size()-1]->AddDocument(new CHashTable("Engelbrekt - Svenskarna och deras hövdingar.txt"));
	m_clusters[m_clusters.size()-1]->AddDocument(new CHashTable("Selma - Herr Arnes penningar.txt"));
	/*
	// Spanish cluster
	m_clusters.insert(m_clusters.end(),new CCluster("Spanish"));
	m_clusters[m_clusters.size()-1]->AddDocument(new CHashTable("Cervantes - Don Quijote.txt"));

	// Latin cluster
	m_clusters.insert(m_clusters.end(),new CCluster("Latin"));
	m_clusters[m_clusters.size()-1]->AddDocument(new CHashTable("Horace - Odes and Epodes.txt"));

	// Italian cluster
	m_clusters.insert(m_clusters.end(),new CCluster("Italian"));
	m_clusters[m_clusters.size()-1]->AddDocument(new CHashTable("Dante - Divina Commedia di Dante.txt"));

	// French cluster
	m_clusters.insert(m_clusters.end(),new CCluster("French"));
	m_clusters[m_clusters.size()-1]->AddDocument(new CHashTable("Bergerat - Contes de Caliban.txt"));

	// Dutch cluster
	m_clusters.insert(m_clusters.end(),new CCluster("Dutch"));
	m_clusters[m_clusters.size()-1]->AddDocument(new CHashTable("Conscience - Redevoeringen.txt"));

	// Flemish cluster
	m_clusters.insert(m_clusters.end(),new CCluster("Flemish"));
	m_clusters[m_clusters.size()-1]->AddDocument(new CHashTable("Heine - De Franse Pers.txt"));

	// German cluster
	m_clusters.insert(m_clusters.end(),new CCluster("German"));
	m_clusters[m_clusters.size()-1]->AddDocument(new CHashTable("Mommsen - Roemische Geschichte.txt"));

	// Portugese cluster
	m_clusters.insert(m_clusters.end(),new CCluster("Portugese"));
	m_clusters[m_clusters.size()-1]->AddDocument(new CHashTable("Netto - Lendas do Sul.txt"));

	// Welsh cluster
	m_clusters.insert(m_clusters.end(),new CCluster("Welsh"));
	m_clusters[m_clusters.size()-1]->AddDocument(new CHashTable("Edwards - Cartrefi Cymru.txt"));

	// ==============================================
	// Phase 2
	// ==============================================
	
	// Yoruba cluster
	m_clusters.insert(m_clusters.end(),new CCluster("Yoruba"));
	m_clusters[m_clusters.size()-1]->AddDocument(new CHashTable("Anti Ahmadiyya Movement in Islam (Yoruba).txt"));
	*/
	// Old English cluster
	m_clusters.insert(m_clusters.end(),new CCluster("Old English"));
	m_clusters[m_clusters.size()-1]->AddDocument(new CHashTable("Beowulf (Old English).txt"));

	// Middle English cluster
	m_clusters.insert(m_clusters.end(),new CCluster("Middle English"));
	m_clusters[m_clusters.size()-1]->AddDocument(new CHashTable("Chaucer - Miller's Tale (Middle English).txt"));
	/*
	// Romanian cluster
	m_clusters.insert(m_clusters.end(),new CCluster("Romanian"));
	m_clusters[m_clusters.size()-1]->AddDocument(new CHashTable("COMUNICARE DIN PARTEA COMISIEI CATRE CONSILIUL SI (Romanian).txt"));
	//m_clusters[m_clusters.size()-1]->AddDocument(new CHashTable("Zarifopol - Din registrul ideilor gingase (romanian).txt"));

	// Serbien cluster
	m_clusters.insert(m_clusters.end(),new CCluster("Serbien"));
	m_clusters[m_clusters.size()-1]->AddDocument(new CHashTable("Desimirovic - BIOLOSKE OSNOVE STANJA SVESTI (Serbien).txt"));

	// Slovene cluster
	m_clusters.insert(m_clusters.end(),new CCluster("Slovene"));
	m_clusters[m_clusters.size()-1]->AddDocument(new CHashTable("Egon Tomazic Kompetence (Slovenien).txt"));
	*/
	// Latvian cluster
	m_clusters.insert(m_clusters.end(),new CCluster("Latvian"));
	m_clusters[m_clusters.size()-1]->AddDocument(new CHashTable("Grozijumi - Par interešu konflikta noveršanu valsts amatpersonu darbiba (Latvia).txt"));
	/*
	// Swahili cluster
	m_clusters.insert(m_clusters.end(),new CCluster("Swahili"));
	m_clusters[m_clusters.size()-1]->AddDocument(new CHashTable("History of Zaire (Swahili).txt"));
	*/
	// Lithuanian cluster
	m_clusters.insert(m_clusters.end(),new CCluster("Lithuanian"));
	m_clusters[m_clusters.size()-1]->AddDocument(new CHashTable("NRC - nepiln_justic_Liet (Lithuanian).txt"));
	/*
	// Estonian cluster
	m_clusters.insert(m_clusters.end(),new CCluster("Estonian"));
	//m_clusters[m_clusters.size()-1]->AddDocument(new CHashTable("Paavel - Psüühilise erivajadusega (Eesti).txt"));
	m_clusters[m_clusters.size()-1]->AddDocument(new CHashTable("Kreutzwald - rahva tervise eest voitleja.txt"));
	
	// Slovak cluster
	m_clusters.insert(m_clusters.end(),new CCluster("Slovak"));
	m_clusters[m_clusters.size()-1]->AddDocument(new CHashTable("rowling_-_harry_potter_a_vezen_z_azkabanu (Slovakia).txt"));
	
	// Polish cluster
	m_clusters.insert(m_clusters.end(),new CCluster("Polish"));
	m_clusters[m_clusters.size()-1]->AddDocument(new CHashTable("KOMISJA WSPOLNOT EUROPEJSKICH - KOMUNIKAT KOMISJI (Polish).txt"));

	// Catalan cluster
	m_clusters.insert(m_clusters.end(),new CCluster("Catalan"));
	m_clusters[m_clusters.size()-1]->AddDocument(new CHashTable("Pujols - La religió de Francesc (Catalan).txt"));

	// Xhosa cluster
	m_clusters.insert(m_clusters.end(),new CCluster("Xhosa"));
	m_clusters[m_clusters.size()-1]->AddDocument(new CHashTable("Isifundo somgaqo-nkqubo wolwimi nokucetywa kwawo kulawulo lweenqila lwasenTshona Koloni (Xhosa).txt"));

	// Hungarian cluster
	m_clusters.insert(m_clusters.end(),new CCluster("Hungarian"));
	m_clusters[m_clusters.size()-1]->AddDocument(new CHashTable("Rosevear - TEREMTÉSTUDOMÁNY (Hungarian).txt"));

	// Croat cluster
	m_clusters.insert(m_clusters.end(),new CCluster("Croat"));
	m_clusters[m_clusters.size()-1]->AddDocument(new CHashTable("Sredisnja Depozitarna Agencija - Pruzanje usluga obracuna, obustave i uplate predujma (Kroatia).txt"));

	// Icelandic cluster
	m_clusters.insert(m_clusters.end(),new CCluster("Icelandic"));
	m_clusters[m_clusters.size()-1]->AddDocument(new CHashTable("Trausta - Anna frá Stóruborg (icelandic).txt"));

	// Zulu cluster
	m_clusters.insert(m_clusters.end(),new CCluster("Zulu"));
	m_clusters[m_clusters.size()-1]->AddDocument(new CHashTable("Ukusetshenziswa kwezilimi ezehlukene emisebenzini umgomo wenqubo yedimokhrasi kwezezilimi (Zulu).txt"));

	// Czech cluster
	m_clusters.insert(m_clusters.end(),new CCluster("Czech"));
	m_clusters[m_clusters.size()-1]->AddDocument(new CHashTable("studium2003-4 (Czech).txt"));

	// Turkish cluster
	m_clusters.insert(m_clusters.end(),new CCluster("Turkish"));
	m_clusters[m_clusters.size()-1]->AddDocument(new CHashTable("uzelturk - GÖLGE EKONOMÝ (turkish).txt"));
	*/
}

void CNgram::ShowDocuments(void) {
	for(int i=0;i<m_clusters.size();i++) m_clusters[i]->ShowDocuments();
}

void CNgram::BuildClusterCentroids(void) {
	for(int i=0;i<m_clusters.size();i++) m_clusters[i]->BuildCentroid();
}

void CNgram::NormalizeClusters(void) {
	for(int i=0;i<m_clusters.size();i++) m_clusters[i]->NormalizeDocuments();
}

void CNgram::BuildClusterSimilarityMatrix(void) {
	printf("Building cluster similarity matrix.\n");

	// let's make our own STL matrix
	vector<double> column;
	column.assign(m_clusters.size(),0.0);
	m_matrix.assign(m_clusters.size(),column);

	for(int i=0;i<m_clusters.size();i++)
		for(int j=0;j<i+1;j++)
			if(i == j) m_matrix[j][i] = 1.0;
				else m_matrix[j][i] = m_clusters[i]->m_centroid->m_skiplist.Similarity(m_clusters[j]->m_centroid->m_skiplist); 
}

void CNgram::ShowClusterSimilarityMatrix(void) {
	double maximum = 0.0;
	double minimum = 2.0;

	vector<string> relationVector;
	string tempString;

	cout << "\nSimilarity matrix for all clusters" << endl;
	cout << "=======================================================================" << endl;
	
	printf("\t");
	for(int j=0;j<m_clusters.size();j++) printf("%7s ",m_clusters[j]->m_name.substr(0,7).c_str());
	printf("\n\n");

	for(int i=0;i<m_clusters.size();i++) {
		printf("%7s ",m_clusters[i]->m_name.substr(0,7).c_str());
		
		for(int j=0;j<i+1;j++) {
			printf("%7.5f ",m_matrix[j][i]);

			if(m_matrix[j][i] >= RELATED_LANG && m_matrix[j][i] < 1.0) {
				tempString = m_clusters[j]->m_name;
				tempString.append(" -> ").append(m_clusters[i]->m_name);
				relationVector.push_back(tempString);
			}

			if(m_matrix[j][i] < minimum) minimum = m_matrix[j][i];
			if((m_matrix[j][i] > maximum) && (m_matrix[j][i] != 1.0)) maximum = m_matrix[j][i];
		}

		printf("\n");
	}

	printf("\nStrong relationships\n====================\n");
	for(int i=0;i<relationVector.size();i++) printf("%s\n",relationVector[i].c_str());

	printf("\n\nMinimum: %f\n",minimum);
	printf("Maximum: %f\n",maximum);
}

void CNgram::ShowClusterDistanceMatrix(void) {
	double maximum = 0.0;
	double minimum = 2.0;

	vector<string> relationVector;
	string tempString;

	cout << "\nDistance matrix for all clusters" << endl;
	cout << "=======================================================================" << endl;
	
	printf("\t");
	for(int j=0;j<m_clusters.size();j++) printf("%7s ",m_clusters[j]->m_name.substr(0,7).c_str());
	printf("\n\n");

	for(int i=0;i<m_clusters.size();i++) {
		printf("%7s ",m_clusters[i]->m_name.substr(0,7).c_str());
		
		for(int j=0;j<i+1;j++) {

			// the matrix contains the similarity measurement cos theta
			// cos = adj / hyp
			// a^2 = b^2 + c^2 - 2 * b * c * cos A
			double b = m_matrix[j][i];
			double distance = sqrt(b*b + 1.0 - 2 * b * b);
			printf("%7.5f ",distance);

			if(distance <= RELATED_LANG_DISTANCE && distance > 0.0) {
				tempString = m_clusters[j]->m_name;
				tempString.append(" -> ").append(m_clusters[i]->m_name);
				relationVector.push_back(tempString);
			}

			if((distance < minimum) && (distance != 0.0)) minimum = distance;
			if(distance > maximum) maximum = distance;
		}

		printf("\n");
	}

	printf("\nStrong relationships\n====================\n");
	for(int i=0;i<relationVector.size();i++) printf("%s\n",relationVector[i].c_str());

	printf("\n\nMinimum: %f\n",minimum);
	printf("Maximum: %f\n",maximum);
}

void CNgram::WriteClusterSimilarityMatrix(void) {
	ofstream cluster("cluster_sim_matrix.txt");

	double maximum = 0.0;
	double minimum = 2.0;

	cluster << "\nSimilarity matrix for all clusters" << endl;
	cluster << "=======================================================================" << endl;
	
	cluster << "\t";
	for(int j=0;j<m_clusters.size();j++) cluster << j << "\t";
	cluster << endl << endl;

	for(int i=0;i<m_clusters.size();i++) {
		cluster << i << "\t";
		
		for(int j=0;j<i+1;j++) {
			cluster << m_matrix[j][i] << "\t";
			if(m_matrix[j][i] < minimum) minimum = m_matrix[j][i];
			if((m_matrix[j][i] > maximum) && (m_matrix[j][i] != 1.0)) maximum = m_matrix[j][i];
		}

		cluster << endl;
	}

	cluster << endl << endl << "Minimum: " << minimum << endl;
	cluster << "Maximum: " << maximum << endl;

	cluster.close();
}

void CNgram::InvestigateClusterCentroids(void) {
	m_clusters[0]->MineSimilarities(m_clusters[1]);
}