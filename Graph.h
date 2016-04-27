#ifndef GRAPH_H
#define GRAPH_H
#include<vector>
#include<iostream>

struct vertex;

struct adjVertex{
    vertex *v;
    int weight;
};

struct vertex{
    int ID;
    vertex *parent;
    std::string name;
    int district;
    bool visited;
    int distance;
    std::vector<adjVertex> adj;
};

struct queueVertex{
    int distance;
    std::vector<vertex *> path;
};
class Graph
{
    public:
        Graph();
        ~Graph();
        void addEdge(std::string v1, std::string v2, int weight);
        void addVertex(std::string name);
        void displayEdges();
        void assignDistricts();
        void shortestPath(std::string startingCity, std::string endingCity);
        void shortestDistance(std::string startingCity,std::string endingCity);
        void shortestDistanceRoundTrip(std::string startingCity);

    protected:
    private:
        std::vector<vertex> vertices;
        vertex * findVertex(std::string name);
        void BFTraversalLabel(std::string startingCity, int distID);

};

struct landMarks{
    std:: string name;
    int cost;
};

class List{
public:
    List();
    void createLL(std::string name,std::string landM, int cost);
    void print();
    void popularLandmarks(std::string city);
    void Budget(std::string,int);
    void poi(std::string city);

private:
    typedef struct city
    {
        city *next;
        std::string name;
        landMarks landmark;
    }* nodePtr;

    nodePtr head;
    nodePtr curr;

};

#endif // GRAPH_H
