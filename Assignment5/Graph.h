#pragma once
#include <iostream>
#include <fstream>
#include <string>


class Graph {

public:
	Graph() {}

	//returns the number of verts
	const int n() {
		return numOfVerts;
	}

	void readFile(std::string filename)
	{
		std::ifstream inFile;
		inFile.open(filename);
		int input;
		for(int j = 0; j < 6; j++)
			for (int i = 0; i < 6; i++) {
				inFile >> input;				
				chart[j][i] = input;
			}
		inFile.close();
	}

	void writeMSTtoFile(std::string filename)
	{
		std::ofstream outFile;
		outFile.open(filename);
		for (int j = 0; j < 6; j++) {
			for (int i = 0; i < 6; i++) {
				if (MST[j] == i || MST[i] == j)
					outFile << chart[j][i] << " ";
				else
					outFile << "0 ";
			}
			outFile << std::endl;
		}
		outFile.close();
		std::cout << std::endl << std::endl;
	}


	void printGraph()
	{
		for (int j = 0; j < 6; j++) {
			for (int i = 0; i < 6; i++) {
				if (MST[j] == i || MST[i] == j)
					std::cout << chart[j][i] << " ";
				else
					std::cout << "0 ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}



	const int weight(int x, int y)
	{
		return chart[x][y];
	}


	//returns the index with the lowest D value of the unvisited indexes
	int minVertex(int* D)
	{
		int minIndex = -1;
		for (int i = 0; i < 6; i++)
		{
			if (visited[i] != 1) //if it's unvisited
			{
				if (minIndex == -1)
					minIndex = i;
				else if (D[i] < D[minIndex])
					minIndex = i;
			}
		}
		return minIndex;
	}
	
	//sets index to visited
	void setMark(int index, int val)
	{
		visited[index] = val;
	}

	//returns the first neigbor of index
	int first(int index)
	{
		for (int i = 0; i < numOfVerts; i++)
		{
			if (chart[index][i] > 0 )
				return i;
		}
	}

	//returns the next neigbor of index, after w
	int next(int index, int w)
	{
		for (int i = w+1; i < numOfVerts; i++)
		{
			if (chart[index][i] > 0 )
				return i;
		}
	}

	void addMSTEdge(int a, int b)
	{
		MST[a] = b;
	}

	void printMST()
	{

		for (int i = 0; i < 6; i++) {
			std::cout << MST[i] << " ";
		}
	}



private:
	int numOfVerts{ 6 };
	int chart[6][6];
	int visited[6] = { 0,0,0,0,0,0 };
	int MST[6] = { -1,-1,-1,-1,-1,-1 };
};