//======= Copyright (c) 2024, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     Test Driven Development - graph
//
// $NoKeywords: $ivs_project_1 $tdd_code.cpp
// $Author:     Timur Kininbayev <xkinin00@stud.fit.vutbr.cz>
// $Date:       $2024-02-14
//============================================================================//
/**
 * @file tdd_code.cpp
 * @author Martin Dočekal
 * @author Karel Ondřej
 *
 * @brief Implementace metod tridy reprezentujici graf.
 */

#include "tdd_code.h"


/**
 *  New includes in .h file: 
 *  #include <stdexcept> 
    #include <algorithm> 
    #include <set>

    protected:
    std::vector<Node*> nodeList;    ///< seznam uzlů
    std::vector<Edge> edgeList;     ///< seznam hran 
 * 
 */
Graph::Graph(){}

Graph::~Graph(){
}

std::vector<Node*> Graph::nodes() {
    return nodeList;
}

std::vector<Edge> Graph::edges() const{
    return edgeList;
}

//function to add node to the graph
Node* Graph::addNode(size_t nodeId) {
    for(Node *node : nodeList){
        if(node->id == nodeId)
            return nullptr;
    }

    Node *newNode = new Node();
    newNode->id = nodeId;
    nodeList.push_back(newNode);
    return newNode;
}

//function to add edge to the graph
bool Graph::addEdge(const Edge& edge){
    //check if nodes exist
    if(getNode(edge.a) == nullptr)
        addNode(edge.a);

    if(getNode(edge.b) == nullptr)
        addNode(edge.b);

    //check if edge already exists
    if(containsEdge(edge))
        return false;

    //check if edge is not a loop
    if (edge.a == edge.b)
        return false;
    
    edgeList.push_back(edge);
    return true;
}

//function to add multiple edges to the graph
void Graph::addMultipleEdges(const std::vector<Edge>& edges) {
    for (Edge edge : edges)
        addEdge(edge);
}

//function to get node by id
Node* Graph::getNode(size_t nodeId){
    for(Node *node : nodeList){
        if(node->id == nodeId)
            return node;
    }
    return nullptr;
}

//function to check if edge exists
bool Graph::containsEdge(const Edge& edge) const{
    for(Edge e : edgeList){
        if(e == edge)
            return true;
    }
    return false;
}

//function to remove node from the graph
void Graph::removeNode(size_t nodeId) {
    //check if node exists
    auto nodeIt = std::find_if(nodeList.begin(), nodeList.end(), [nodeId](const Node* node) { return node->id == nodeId; });
    if (nodeIt != nodeList.end()) { // node found
        delete *nodeIt; 
        nodeList.erase(nodeIt);
    } 
    else
        throw std::out_of_range("Node not found");

    //remove all edges connected to the node
    edgeList.erase(std::remove_if(edgeList.begin(), edgeList.end(), [nodeId](const Edge& edge) { return edge.a == nodeId || edge.b == nodeId; }), edgeList.end());
}

//function to remove edge from the graph
void Graph::removeEdge(const Edge& edge) {
    //check if edge exists
    for (auto actual_edge = edgeList.begin(); actual_edge != edgeList.end(); ) {
        if (*actual_edge == edge){ // edge found
            actual_edge = edgeList.erase(actual_edge);
            return;
        } 
        else
            ++actual_edge;
    }
    throw std::out_of_range("Edge not found");
}

//function to count nodes in the graph
size_t Graph::nodeCount() const{
    return nodeList.size();
}

//function to count edges in the graph
size_t Graph::edgeCount() const{
    return edgeList.size();
}

//function to count degree of the node
size_t Graph::nodeDegree(size_t nodeId) const{
    size_t degree = 0;
    for(Edge edge : edgeList){ // count all edges connected to the node
        if(edge.a == nodeId || edge.b == nodeId)
            degree++;
    }
    if (degree == 0)
        throw std::out_of_range("Node not found");

    return degree;
}

//function to count maximum degree of the graph
size_t Graph::graphDegree() const{
    size_t maxDegree = 0;
    for(Node *node : nodeList){
        size_t degree = nodeDegree(node->id);
        if(degree > maxDegree)
            maxDegree = degree;
    }
    return maxDegree;
}

//function to color the graph
void Graph::coloring() {
    //reset colors
    for (Node* node : nodeList)
        node->color = 0;

    //color the nodes
    for (Node* node : nodeList) {
        std::set<size_t> usedColors;

        for (const Edge& edge : edgeList) { // find all used colors
            if (edge.a == node->id || edge.b == node->id) { // node is connected to the edge
                Node* adjacent = (edge.a == node->id) ? getNode(edge.b) : getNode(edge.a);
                if (adjacent->color != 0) 
                    usedColors.insert(adjacent->color);
            }
        }
        // find the first unused color
        size_t color = 1;
        while (usedColors.find(color) != usedColors.end())
            color++;

        node->color = color; // color the node
    }
}

//function to clear the graph
void Graph::clear() {
    for(Node *node : nodeList)
        delete node;

    nodeList.clear();
    edgeList.clear();
}

/*** Konec souboru tdd_code.cpp ***/
