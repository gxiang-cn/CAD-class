// Graphic homework
// 
#include <iostream>
#include <string>
#include <vector>
#include <list>

namespace CAD
{

const int NONE = -1;

class Edge
{
public:
    Edge():mVertexIndex(NONE);
    Edge(int AdjVertex) { mVertexIndex = AdjVertex; }; //TODO Can we merge two constructor together? 
    ~Edge(); 

    const int adjVertex() {return mVertexIndex;};
private:
    int mVertexIndex;
}


class Vertex
{
    friend class Graph;

public:
    Vertex(const std::string& name) {mName = name;}
    ~Vertex();

    const std::string& name();
    void addEdge(int v);

private:
    std::string mName;
    std::List<Edge> mEdgeList;
};


typedef std::list<Vertex> VertexList;

//Adjecent list
class Graph
{
public:
    Graph();
    ~Graph();

    bool addVertex(const std::string& name);
    bool addEdge(const std::string& name1, const std::string& name2);
    void dfs();
    void bfs();
    void print();
private:
    std::vector<Vertex> mAList;
};

//-----------------------------------------------------------------------------
//Implementation
//-----------------------------------------------------------------------------

using std;

//-----------------------------------------------------------------------------
// Class Vertex
//-----------------------------------------------------------------------------
void Vertex::addEdge(int v)
{
    if (v < 0) return;
    if (!mEdgeList.empty()) {
	for (list::const_iterator i = mEdgeList.begin(); i < mEdgeList.end();
		i++) {
	    if (i->adjVertex() == v) {
		cout << "Edge to " << v << "exists" << endl;
		return;
	    }
	}
    }
    Edge e(v);
    mEdgeList.push_back(e);
    return;
}

//-----------------------------------------------------------------------------
// Class Graph
//-----------------------------------------------------------------------------

bool Graph::addVertex(const string& name)
{
    if (name.empty()) {
	cout << "Vertex name is empty." << endl;
	return false;
    }
    if (!mAList.empty()) {
	for (vector::iterator i = mAList.begin(); i < mAList.end(); i++) {
	    if (name == i->name()) {
		cout << "Vertex" << name << "is existing" << endl;
		return false;
	    }
	}
    }

    Vertex v(name);
    mAList.push_back(v);
    return true;
}

bool Graph::addEdge(const string& name1, const string& name2)
{
    if (name1.empty()) {
	cout << "Vertex name1 is empty." << endl;
	return false;
    }

    if (name2.empty()) {
	cout << "Vertex name2 is empty." << endl;
	return false;
    }

    int v1 = NONE;
    int v2 = NONE;
    for (int i = 0; i < mAList.size(); i++) {
	if (v1 != NONE) {
	    if (name1 == mAList[i].name())  v1 = i; 
	}
	if (v2 != NONE) {
	    if (name2 == mAList[i].name())  v2 = i;
	}

	if (v1 != NONE && v2 != NONE) {
	    mAList[v1].addEdge(v2)
	    return true;
	} 
    }
    if (v1 == NONE) addVertex(name1);
    if (v2 == NONE) addVertex(name2);
    mAList[v1].addEdge(v2);
    return true;
}

//TODO add overload for stream?
void Graph::print()
{
    cout << "Graph" << endl;
    for (vector::const_iterator i = mAList.begin(); i < mAList.end(); i++) {
	cout << i->name() << "\t" ;
	//Use direct access to Vertex. TODO add iterator.
	for (vecotr::const_iterator j = i->mEdgeList.begin(); 
		j < i->mEdgeList.end(); j++) {
	    cout << mAList[j->adjVertex()].name() << "\t";
	}
	cout << endl;
    }
}

} //end of namespace CAD

Graph& createGraph(Graph& g)
{
    g.addEdge("A", "B");
    g.addEdge("A", "C");
    g.addEdge("C", "D");
    g.addEdge("B", "E");
    g.addEdge("C", "E");
    
}

int main()
{

    Graph g;
    g = createGraph(g);
    g.print();

    return 0;
}
