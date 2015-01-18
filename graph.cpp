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
    Edge():mVertexIndex(NONE){};
    Edge(int AdjVertex) { mVertexIndex = AdjVertex; } //TODO Can we merge two constructor together? 
	~Edge() {}

    int adjVertex() const {return mVertexIndex;};
private:
    int mVertexIndex;
};


class Vertex
{
    friend class Graph;

public:
    Vertex() {};
    Vertex(const std::string& name) {mName = name;}
	~Vertex() {};

	const std::string& name() const { return mName; }
    void addEdge(int v);

private:
    std::string mName;
    std::list<Edge> mEdgeList;
};




//Adjecent list
class Graph
{
public:
    Graph() {};
    ~Graph(){};

    int addVertex(const std::string& name);
    bool addEdge(const std::string& name1, const std::string& name2);
    //void dfs() const;
    //void bfs() const;

    void print(void) const;
private:
    std::vector<Vertex> mAList;
};

//-----------------------------------------------------------------------------
//Implementation
//-----------------------------------------------------------------------------

using namespace std;

//-----------------------------------------------------------------------------
// Class Vertex
//-----------------------------------------------------------------------------
void Vertex::addEdge(int v)
{
    if (v < 0) return;
    if (!mEdgeList.empty()) {
	for (list<Edge>::const_iterator i = mEdgeList.begin(); i != mEdgeList.end();
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

int Graph::addVertex(const string& name)
{
    if (name.empty()) {
	cout << "Vertex name is empty." << endl;
	return NONE;
    }
    if (!mAList.empty()) {
	    for (vector<Vertex>::const_iterator i = mAList.begin(); i < mAList.end(); i++) {
	        if (name == i->name()) {
		        cout << "Vertex " << name << " is existing" << endl;
		        return i-mAList.begin();
	        }
	    }
    }

    Vertex v(name);
    mAList.push_back(v);
    return mAList.size() - 1;
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
    for (unsigned int i = 0; i < mAList.size(); i++) {
	if (v1 == NONE) {
	    if (name1 == mAList[i].name())  v1 = i; 
	}
	if (v2 == NONE) {
	    if (name2 == mAList[i].name())  v2 = i;
	}

	if (v1 != NONE && v2 != NONE) break;

    }
    if (v1 == NONE) v1 = addVertex(name1);
    if (v2 == NONE) v2 = addVertex(name2);
	
    mAList[v1].addEdge(v2);
	mAList[v2].addEdge(v1);
    return true;
}

//TODO add overload for stream?

void Graph::print(void) const
{
    cout << "Graph" << endl;

    for (vector<Vertex>::const_iterator i = mAList.cbegin(); i < mAList.cend(); i++) {
	cout << i->name() << "\t" ;
	//Use direct access to Vertex. TODO add iterator.
	
	for (list<Edge>::const_iterator j = i->mEdgeList.begin(); 
		j != i->mEdgeList.end(); j++) {
	    cout << mAList[j->adjVertex()].name() << "\t";
	}
	
	cout << endl;
    }
	return;
}

} //end of namespace CAD

using namespace CAD;
Graph& createGraph(Graph& g)
{
    g.addEdge("A", "B");
    g.addEdge("A", "C");
	g.addEdge("B", "C");
	g.addEdge("B", "D");
	g.addEdge("B", "E");
    g.addEdge("C", "D");
    g.addEdge("C", "E");
	return g;
    
}

int main()
{

    CAD::Graph g;
    g = createGraph(g);
    g.print();

    return 0;
}
