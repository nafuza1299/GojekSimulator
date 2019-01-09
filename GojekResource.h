#ifndef GojekResource
#define GojekResource
string locations [10] =  {"Senayan", "Kemang", "Blok M", "Pondok Indah", "Cilandak", "Menteng", "Kota Tua", "Kemayoran", "Pluit", "Kebun Jeruk" };
string name[10] = {"Ahmad","Firman","Jojo","Ben","Leon","Geralt","Noctis","Ciri","Cloud","Will"};
string lastname[10] = {"Muhammad", "Smith", "Jones", "Wilson", "Brown", "Davis", "Miller", "Taylor", "Henderson", "Thompson"};
struct Stack Senayan;
struct Stack Menteng;
struct Stack Pluit; 
struct Stack Cilandak; 
struct Stack BlokM; 
struct Stack PondokIndah; 
struct Stack Kemang;
struct Stack Kemayoran;
struct Stack KotaTua;
struct Stack KebunJeruk;

void PrintShortestPath(vector< pair<int, int> > &dist, int &start)
    {
    cout << "\nPrinting the shortest paths for node " << start << ".\n";
    for(int i = 0; i < dist.size(); i++)
        {
        cout << "The distance from node " << locations[start]<< " to node " << locations[i]<< " is: " << dist[i].first << endl;
        
        
        }
    }
    

void Printdestination(vector< pair<int, int> > &dist, int &start, int endingpoint)
{
	cout << "The distance from node " << locations[start] << " to node " << locations[endingpoint]<< " is: " << dist[endingpoint].first << endl;

    
    int currnode = endingpoint;
    cout << "The path is: " << locations[currnode];

	while(currnode != start)
        {
        currnode = dist[currnode].second;
        cout << " <- " << locations[currnode];
        }
    cout << endl << endl;
	
}

    
void printlocations()
{
	for (int i = 0; i < 10; i++)
	{
		cout << i<<". " << locations[i] << endl;
	}
}

void printdestinationopt(int startingpoint)
{
	for (int i = 0; i < 10; i++)
	{
		if (i == startingpoint)
			cout << i <<". "<< "You are here" << endl;
		else
			cout << i <<". " << locations[i] << endl;
	}
}

int gojekdriverchoose(vector< pair<int, int> > &dist, int &start)
{
	
	
	int closest = 0;
	if (dist[0].first == closest)
		closest = 1;
	for (int i = 0; i<10; i++)
	{
		
		if (i != start)
			if (dist[i].first<dist[closest].first)
				closest = i;
				
	}
	cout<< "There is a nearby Gojek " << dist[closest].first << " km away from you." << endl;
	return closest;
}
int popgojek(int x)
{
	int popped;
	string poptext = "Driver has started driving from ";
	if (x == 0 && Senayan.isEmpty() == false)
	{
		popped = Senayan.pop();
		cout << poptext << "Senayan" << endl;
	}
	
	if (x ==  1 &&  Kemang.isEmpty() == false)
	{
		popped = Kemang.pop();
		cout << poptext << "Kemang" << endl;
	}
	
	if (x == 2 && BlokM.isEmpty() == false)
	{
		popped = BlokM.pop();
		cout <<  poptext << "Blok M" << endl;
	}
	
	if (x == 3 && PondokIndah.isEmpty() == false)
	{
		popped = PondokIndah.pop();
		cout << poptext << "Pondok Indah" << endl;
	}
	
	if (x == 4 && Cilandak.isEmpty() == false)
	{
		popped = Cilandak.pop();
		cout << poptext << "Cilandak" << endl;
	}
	
	if (x == 5 && Menteng.isEmpty() == false)
	{
		popped = Menteng.pop();
		cout << poptext << "Menteng" << endl;
	}
	
	if (x == 6 && KotaTua.isEmpty() == false)
	{
		popped = KotaTua.pop();
		cout << poptext << "Kota Tua" << endl;
	}
	
	if (x == 7 && Kemayoran.isEmpty() == false)
	{
		popped = Kemayoran.pop();
		cout << poptext << "Kemayoran" << endl;
	}
	
	if (x == 8 && Pluit.isEmpty() == false)
	{
		popped = Pluit.pop();
		cout << poptext << "Pluit" << endl;
	}
	
	if (x == 9 && KebunJeruk.isEmpty() == false)
	{
		popped = KebunJeruk.pop();
		cout << poptext << "Kebun Jeruk" << endl;
	}
	
	return popped;
}
void pushgojek(int x, int pushed)
{
	string poptext  = "Driver has dropped you off at ";
	if (x == 0)
	{
	 	Senayan.push(pushed);
	 	cout << poptext << "Senayan" << endl;
	}
	
	if (x ==  1)
	{
		Kemang.push(pushed);
		cout << poptext << "Kemang" << endl;

	}
	
	if (x == 2)
	{
		BlokM.push(pushed);
		cout << poptext << "Blok M" << endl;

	}
	
	if (x == 3)
	{
		PondokIndah.push(pushed);
		cout << poptext << "Pondok Indah" << endl;

	}
	
	if (x == 4)
	{
		Cilandak.push(pushed);
		cout << poptext << "Cilandak" << endl;

	}
	
	if (x == 5)
	{
		Menteng.push(pushed);
		cout << poptext << "Menteng" << endl;

	}
	
	if (x == 6)
	{
		KotaTua.push(pushed);
		cout << poptext << "Kota Tua" << endl;

	}
	
	if (x == 7)
	{
		Kemayoran.push(pushed);
		cout << poptext << "Kemayoran" << endl;

	}
	
	if (x == 8)
	{
		Pluit.push(pushed);
		cout << poptext << "Pluit" << endl;

	}
	
	if (x == 9)
	{
		KebunJeruk.push(pushed);
		cout << poptext << "Kebun Jeruk" << endl;

	}
}

#endif
