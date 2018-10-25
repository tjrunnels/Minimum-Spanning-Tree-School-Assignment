#include <iostream>
#include "Graph.h"


void AddEdgetoMST(int, int);
void Prim(Graph*, int*, int);

int main()
{
	std::cout << "Tom Runnels - MST Lab" << std::endl;
	Graph* G1 = new Graph();
	G1->readFile("in.txt");

	Graph* G2 = new Graph();
	G2->readFile("in.txt");

	Graph* G3 = new Graph();
	G3->readFile("in.txt");

	int D[6];
	Prim(G1, D, 0);
	G1->printGraph();
	Prim(G2, D, 2);
	G2->printGraph();
	Prim(G3, D, 4);
	G3->printGraph();
	system("pause");
	return 0;
}


void AddEdgetoMST(int Vatv, int v, Graph* G) {
	std::cout << "added edge: " << Vatv << " to " << v << std::endl;
	G->addMSTEdge(v, Vatv);
}

// Prim’s MST algorithm
void Prim(Graph* G, int* D, int s) { 
	std::cout << "Begin MST starting at Vertex " << s << std::endl;
	int V[6] = { -1,-1,-1,-1,-1,-1 }; // Store closest vertex
	int i, w;
	for (int i = 0; i<G->n(); i++) // Initialize
		D[i] = 9999;
	D[s] = 0;     //caution: i changed this from D[0] = 0
	for (i = 0; i<G->n() ; i++) { // Process the vertices
		int v = G->minVertex(D);
		G->setMark(v, 1);
		if (v != s)
			AddEdgetoMST(V[v], v, G); // Add edge to MST
		if (D[v] == 9999) return; // Unreachable vertices
		for (w = G->first(v); w<G->n(); w = G->next(v, w))  //first is first neighbor of v, next is next neightbor of v, after w
			if (D[w] > G->weight(v, w)) {
				D[w] = G->weight(v, w); // Update distance
				V[w] = v; // Where it came fromv
			}
	}
	std::cout << "End of MST" << std::endl;



	std::string tim = "a";
	for (int i = 0; i < s; i++)
		tim += "b";
	G->writeMSTtoFile(tim + ".txt");

}


