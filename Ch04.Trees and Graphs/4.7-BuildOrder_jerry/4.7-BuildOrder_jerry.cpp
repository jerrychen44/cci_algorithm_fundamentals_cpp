
#include <iostream>
#include <vector>
#include <map>


class Project{


public:


    Project(std::string name);

    void addNeighber(Project inputnode){

        //node is not in map yet
        if(! map.count(inputnode.getName())){
            //add the node A as my neighber
            children.push_back(inputnode);
            //add to hash map
            map.insert(std::pair<std::string, Project>(inputnode.getName(),inputnode));

            inputnode.incrementDependencies();


        }

    }

    //pointer ver
    //std::vector<Project> *children;
    //std::map<std::string, Project> *map;

    std::vector<Project> children;
    std::map<std::string, Project> map;
    std::string name;
    int dependencies;



    void incrementDependencies(){
        dependencies++;
    }

    void decrementDependencies(){
        dependencies--;
    }



    std::string getName(){
        return name;
    }

    std::vector<Project> getChildren(){
        return children;
    }

    int getNumberDependencies(){
        return dependencies;
    }


};


Project::Project(std::string name){
    //pointer ver
    //this->children = new std::vector<Project>;
    //this->map = new std::map<std::string, Project>;


    this->name = name;
    this->dependencies = 0;

}


class Graph{

public:
    std::vector<Project> nodes;
    std::map<std::string, Project> map;

    Project getOrCreateNode(std::string name){
        if(!map.count("name")){
            Project node = Project(name);
            nodes.push_back(node);
            map.insert(std::pair<std::string, Project>(name,node));
        }

        return map.find(name)->second;
    }

    void addEdge(std::string startName, std::string endName){
        Project startnode = getOrCreateNode(startName);
        Project endnode = getOrCreateNode(endName);
        startnode.addNeighber(endnode);
    }

    std::vector<Project> getNodes(){
        return nodes;
    }
};



void testingProject(){

    //pointer ver
    /*
    Project test0= Project("test0");


    Project test= Project("current");
    std::cout << test.name << std::endl;
    std::cout << test.children->size() << std::endl;
    test.children->push_back(test0);
    std::cout << test.children->size() << std::endl;
    std::cout << (test.children->at(0)).name << std::endl;



    Project maptest0= Project("maptest0");
    Project mapcurrent= Project("mapcurrent");


    test.map->insert(std::pair<std::string, Project>("test0", maptest0));
    test.map->insert(std::pair<std::string, Project>("current", mapcurrent));

    //std::string tt="current";

    std::cout << test.map->find("test0")->second.name << std::endl;
    */


    Project test0= Project("test0");


    Project test= Project("current");
    std::cout << test.name << std::endl;
    std::cout << test.children.size() << std::endl;
    test.children.push_back(test0);
    std::cout << test.children.size() << std::endl;
    std::cout << (test.children.at(0)).name << std::endl;

    Project maptest0= Project("maptest0");
    Project mapcurrent= Project("mapcurrent");
    test.map.insert(std::pair<std::string, Project>("test0", maptest0));
    test.map.insert(std::pair<std::string, Project>("current", mapcurrent));
    std::cout << test.map.find("test0")->second.name << std::endl;

    //check key, 0: no , 1: yes
    std::cout << test.map.count("test0") << std::endl;

    test0.incrementDependencies();
    std::cout << test0.getName() << ", "<<test0.getNumberDependencies() << std::endl;
}


void testingGraph(){
    Graph testg = Graph();
}

int main(){

    //testingProject();
    testingGraph();






    return 0;
}