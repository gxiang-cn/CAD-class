// Graphic homework

namespace CAD{

class Node
{
public:
    node();
    ~node();
    name();
private:
    
    string mName;
}

typedef list<node> NodeList;
//adjecent list
class Graph
{
pubic:
    Graph();
    ~Graph();

    dfs();
    bfs();
private:
    vector<NodeList> mAList;
}

}
