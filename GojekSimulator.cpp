#include "Gostack.h"
#include "GojekResource.h"
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>
# define INF 0x3f3f3f3f 

using namespace std;

// An adjacency list. Each adjList[i] holds a all the friends of node i.
// The first int is the vertex of the friend, the second int is the edge weight.


vector< vector<pair<int, int> > > FormAdjList()
{
	// Our adjacency list.
	vector< vector<pair<int, int> > > adjList;
	srand((int)time(0)); //randomizes the traffic factor 

	// We have 7 vertices, so initialize 7 rows.
	const int n = 10;

	for (int i = 0; i < n; i++)
	{
		// Create a vector to represent a row, and add it to the adjList.
		vector<pair<int, int> > row;
		adjList.push_back(row);
	}
	


	// Now let's add our actual edges into the adjacency list.
	// See the picture here: https://www.srcmake.com/uploads/5/3/9/0/5390645/spadjlist_orig.jpg
	
	adjList[0].push_back(make_pair(1, 8+rand() % 10 ));
	adjList[0].push_back(make_pair(2, 5+rand() % 10 ));
	adjList[0].push_back(make_pair(5, 5+rand() % 10 ));
	
	adjList[1].push_back(make_pair(0, 8+rand() % 10 ));
	adjList[1].push_back(make_pair(2, 4+rand() % 10 ));
	adjList[1].push_back(make_pair(3, 6+rand() % 10 ));
	adjList[1].push_back(make_pair(4, 6+rand() % 10 ));

	adjList[2].push_back(make_pair(0, 5+rand() % 10 ));
	adjList[2].push_back(make_pair(1, 4+rand() % 10 ));
	adjList[2].push_back(make_pair(4, 8+rand() % 10 ));

	adjList[3].push_back(make_pair(1, 6+rand() % 10 ));
	adjList[3].push_back(make_pair(4, 5+rand() % 10 ));
	adjList[3].push_back(make_pair(5, 14+rand() % 10 ));

	adjList[4].push_back(make_pair(1, 6+rand() % 10 ));
	adjList[4].push_back(make_pair(2, 8+rand() % 10 ));
	adjList[4].push_back(make_pair(3, 5+rand() % 10 ));

	adjList[5].push_back(make_pair(0, 5+rand() % 10 ));
	adjList[5].push_back(make_pair(6, 9+rand() % 10 ));
	adjList[5].push_back(make_pair(3, 14+rand() % 10 ));

	adjList[6].push_back(make_pair(7, 10+rand() % 10 ));
	adjList[6].push_back(make_pair(9, 12+rand() % 10 ));
	adjList[6].push_back(make_pair(8, 7+rand() % 10 ));
	adjList[6].push_back(make_pair(5, 9+rand() % 10 ));



	adjList[7].push_back(make_pair(6, 10+rand() % 10 ));
	adjList[7].push_back(make_pair(8, 16+rand() % 10 ));

	adjList[8].push_back(make_pair(7, 16+rand() % 10 ));
	adjList[8].push_back(make_pair(6, 7+rand() % 10 ));
	adjList[8].push_back(make_pair(9, 13+rand() % 10 ));
	
	adjList[9].push_back(make_pair(6, 12+rand() % 10));
	adjList[9].push_back(make_pair(8, 13+rand() % 10));


	// Our graph is now represented as an adjacency list. Return it.
	return adjList;
}

vector< pair<int, int> > Prims(vector< vector<pair<int, int> > > &adjList, int &start) 
{ 
    //Initializes the weights of the nodes to infinity
	cout << "\nGetting the path from " << start << " to all other nodes.\n";
    vector<pair<int, int> > dist; 

    int n = adjList.size();
    for(int i = 0; i < n; i++)
    {
        dist.push_back(make_pair(1000000007, i));
    }
	// Create a priority queue to store vertices
    priority_queue<pair<int, int>, vector< pair<int, int> >, greater<pair<int, int> > > pq;

	int src = start; // Taking vertex 0 as source 

	// Create a vector for keys and initialize all 
	// keys as infinite (INF) 
	vector<int> keyA(start, INF); 

	// To store parent array which in turn store MST 
	vector<int> parent(start, -1); 

	// To keep track of vertices included in MST 
	vector<bool> inMST(start, false); 

	// Insert source itself in priority queue and initialize 
	// its key as 0. 
	pq.push(make_pair(0, src)); 
	dist[src].first = 0; 

	/* Looping till priority queue becomes empty */
	while (!pq.empty()) 
	{ 
		// The first vertex in pair is the minimum key 
		// vertex, extract it from priority queue. 
		// vertex label is stored in second of pair (it 
		// has to be done this way to keep the vertices 
		// sorted key (key must be first item 
		// in pair) 
		int u = pq.top().second; 
		pq.pop(); 

		inMST[u] = true; // Include vertex in MST 

		// Traverse all adjacent of u 
		for (auto x : adjList[u]) 
		{ 
			// Get vertex label and weight of current adjacent 
			// of u. 
            int v = x.first; 
			int weight = x.second; 

			// If v is not in MST and weight of (u,v) is smaller 
			// than current key of v 
			if (inMST[v] == false && dist[v].first> weight) 
			{ 
				// Updating key of v 
				dist[v].first = weight; 
				dist[v].second = u;
				pq.push(make_pair(dist[v].first, v)); 
			} 
		} 
	} 
	
	return dist;
}  

// Given an Adjacency List, find all shortest paths from "start" to all other vertices.
vector< pair<int, int> > DijkstraSP(vector< vector<pair<int, int> > > &adjList, int &start)
    {
    cout << "\nGetting the shortest path from " << locations[start] << " to all other nodes.\n";
    vector<pair<int, int> > dist; // First int is dist, second is the previous node. 
    
    // Initialize all source->vertex as infinite.
    int n = adjList.size();
    for(int i = 0; i < n; i++)
        {
        dist.push_back(make_pair(1000000007, i)); // Define "infinity" as necessary by constraints.
        }
        
    // Create a PQ.
    priority_queue<pair<int, int>, vector< pair<int, int> >, greater<pair<int, int> > > pq;
    
    // Add source to pq, where distance is 0.
    pq.push(make_pair(start, 0));
    dist[start] = make_pair(0, start);
    
    // While pq isn't empty...
    while(pq.empty() == false)
        {
        // Get min distance vertex from pq. (Call it u.)
        int u = pq.top().first;
        pq.pop();
        
        // Visit all of u's friends. For each one (called v)....
        for(int i = 0; i < adjList[u].size(); i++)
            {
            int v = adjList[u][i].first;
            int weight = adjList[u][i].second;
            
            // If the distance to v is shorter by going through u...
            if(dist[v].first > dist[u].first + weight)
                {
                // Update the distance of v.
                dist[v].first = dist[u].first + weight;
                // Update the previous node of v.
                dist[v].second = u;
                // Insert v into the pq. 
                pq.push(make_pair(v, dist[v].first));
                }
            }
        }
    
    return dist;
    }

int runsimulation(vector< pair<int, int> > &dist, int &startingpoint, int endingpoint)
{    
	// Print the list.
	Printdestination(dist, startingpoint, endingpoint);	
	//PrintShortestPath(dist, startingpoint); //checks whether or not the path is accurate
	//prints out the loading screen
	cout <<"Press Enter..."<<endl;
	getch();
	system("cls");
	cout << "Finding the Driver..";
	Sleep(1000);
	cout <<".";
	Sleep(1000);
	cout <<".";
	Sleep(1000);
	system("cls");
	
	//initializes the Gojekstacks
	//each stack is pushed a random amount of Gojeks
	int randomgojek;
	int i;
	for (i = 0; i < randomgojek;  i++)
	{
		Senayan.push(i);
		Menteng.push(i);
		Cilandak.push(i);
		Pluit.push(i);
		BlokM.push(i);
		PondokIndah.push(i);
		Kemang.push(i);
		Kemayoran.push(i);
		KotaTua.push(i);
		KebunJeruk.push(i);
	}
	
	//calls the gojekdriver
	int gojekcall = gojekdriverchoose(dist, startingpoint);
	cout << "Calling gojek driver from " << locations[gojekcall] << endl;
	//randomizes the GojekDriver's name
	int randname;
	randname = rand() % 9 + 0;
	int randlastname;
	randlastname = rand() % 9 + 0;
	cout << "Gojek Driver "<< name[randname] << " " << lastname[randlastname] << " has been called." <<endl;
	//Pops the gojek driver from their current location
    int popped;
  	popped = popgojek(gojekcall);
  	//pushes the gojek driver into the destination of the customer
  	pushgojek(endingpoint, popped);
  	cout << "\nThank You For Using our Application" << endl;
  	cout << "Press Enter to return main menu"<< endl;
  	getch();
  	system("cls");
  	cout << "Returning to main menu..";
  	Sleep(1000);
  	cout << ".";
  	Sleep(1000);
  	cout<< ". ";
  	Sleep(1000);
  	system("cls");
  	
	int main();
}

int main()
{
	bool test = true;
	while (test)
	{
		vector< vector<pair<int, int> > > adjList = FormAdjList();

		// Get a list of shortest path distances for node 0.
		//Menu selection for the program
		int startingpoint;
		int endingpoint;
		int choice;
		cout << "Select Algorithm: \n1. Djiksra \n2. Prims \n3. Exit" <<endl;
		cin >> choice;
		//if exit is chosen
		if (choice == 3)
		{
			cout << "Exiting Application..";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			return 0;	
		}
		//if any other number is selected, this will not be printed
		if (choice == 1 or choice == 2)
		{
		
		cout << "Select starting node" << endl;
		printlocations();
		cin >> startingpoint;
		cout << "Select Destination" << endl;
		printdestinationopt(startingpoint);
		cin  >> endingpoint;
		}
		//if Dijkstra is selected		
		if (choice == 1)
		{
			vector< pair<int, int> > dist = DijkstraSP(adjList, startingpoint);	
			runsimulation(dist, startingpoint, endingpoint);
	
		}
		//if prims is selected
		else if (choice == 2)
		{
			vector< pair<int, int> > dist = Prims(adjList, startingpoint);	
			runsimulation(dist, startingpoint, endingpoint);
		}
	
	}
	
	


}
	

