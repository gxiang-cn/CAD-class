// Graphic homework
// 
#include <iostream>
#include <string>
#include <vector>
#include <list>

namespace CAD
{

class Node
{
public:
    Node(const std::string& name) {mName = name;}
    ~Node();

    const std::string& name();
private:
    
    std::string mName;
};

typedef std::list<Node> NodeList;

//adjecent list
class Graph
{
public:
    Graph();
    ~Graph();

    void addNode(const Node& n);
    void addNode(const std::string& name);
    void addEdge(const Node& n1, const Node&2);
    void dfs();
    void bfs();
private:
    std::vector<NodeList> mAList;
};

}


int main(int argc, char** argv)
{
    std::cout << "It's for test\t haha" << std::endl;
    return 0;
}
