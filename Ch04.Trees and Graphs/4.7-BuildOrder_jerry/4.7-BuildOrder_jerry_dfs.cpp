
#include <iostream>
#include <vector>
#include <map>


class Project{


public:


    Project(std::string name);

    void addNeighber(Project *endnode){

        //node is not in map yet
        if(! string2instance_map->count(endnode->getName())){
            //add the node as my neighber
            point_to_children->push_back(endnode);
            //add to hash map, string2instance_map
            string2instance_map->insert(std::pair<std::string, Project*>(endnode->getName(),endnode));

        }

    }

    //pointer ver
    std::vector<Project *> *point_to_children;
    std::map<std::string, Project*> *string2instance_map;

    //std::vector<Project> point_to_children;
    //std::map<std::string, Project> string2instance_map;
    std::string name;


    //add for dfs version
    enum State { COMPLETE=1, INPROCESS, BLANK};
    State state;
    State getState(){
        return state;
    }
    void setState(State newstate){
        this->state = newstate;
    }

    std::string getName(){
        return name;
    }

    std::vector<Project*>* getpoint_to_children(){
        return point_to_children;
    }

};


Project::Project(std::string name){
    //pointer ver
    this->point_to_children = new std::vector<Project *>;
    this->string2instance_map = new std::map<std::string, Project*>;


    this->name = name;
    this->state = BLANK;

}


class Graph{

public:
    std::vector<Project*> *nodes_poll;
    std::map<std::string, Project*> *graph_string2instance_map;


    Graph(){
        this->nodes_poll = new std::vector<Project *>;
        this->graph_string2instance_map = new std::map<std::string, Project*>;
    }


    Project* getOrCreateNode(std::string name){
        //create node if it doesn't exit yet
        if(!graph_string2instance_map->count(name)){
            Project *node = new Project(name);
            nodes_poll->push_back(node);
            std::cout << "Node not exit, CreateNode: "<< name << std::endl;
            //add it to the string2instance map
            graph_string2instance_map->insert(std::pair<std::string, Project*>(name,node));
        }
        std::cout << "return node instance "<< graph_string2instance_map->find(name)->second->name
                                                                                        << std::endl;
        return graph_string2instance_map->find(name)->second;
    }

    void addEdge(std::string startName, std::string endName){
        Project *startnode = getOrCreateNode(startName);
        Project *endnode = getOrCreateNode(endName);
        //put endnode to point_to_children list of startNode
        startnode->addNeighber(endnode);

        for(int i =0; i < startnode->point_to_children->size(); ++i)
            std::cout << "      endnode "<< startnode->point_to_children->at(i)->name << std::endl;

    }

    void printNodes(){
        std::cout << "******"<<__FUNCTION__ << std::endl;

        for(int i =0; i < nodes_poll->size(); ++i){
            std::cout << nodes_poll->at(i)->name << std::endl;
        }
    }

    std::vector<Project*>* getNodes(){
        return nodes_poll;
    }
};

//create instance and fill the dependencies
Graph buildGraph(std::vector<std::string> graph_nodes,
                std::vector<std::vector<std::string> > dependencies){

    std::cout << "******"<<__FUNCTION__ << std::endl;
    //create the nodes
    Graph graph =  Graph();
    std::cout << &graph << std::endl;
    //initial the graph
    std::cout << "******"<<__FUNCTION__<<"=> getOrCreateNode" << std::endl;
    for(int i=0; i < graph_nodes.size(); ++i){

        graph.getOrCreateNode(graph_nodes[i]);
    }

    //fill the dependencies
    std::cout << "******"<<__FUNCTION__<<"=> addEdge" << std::endl;
    for(int i =0; i < dependencies.size(); ++i){
        std::string firstname = dependencies[i][0];
        std::string endname   = dependencies[i][1];

        graph.addEdge(firstname, endname);
    }

    return graph;
    //del
}


bool doDFS(Project *node, std::vector<Project*> *ordered ){

    if(node->getState() == Project::INPROCESS){
        std::cout << "hit the cycle, reutrn false" << std::endl;
        return false;//cycle
    }

    if(node->getState() == Project::BLANK){
        std::cout << "node "<< node->name << ",->getState() == Project::BLANK, IN"<< std::endl;
        node->setState(Project::INPROCESS);

        std::vector<Project*>* children = node->getpoint_to_children();

        for(int i =0; i < children->size(); ++i){
            if( ! doDFS(children->at(i), ordered)){
                std::cout << "! doDFS(children->at(i), ordered), reutrn false" << std::endl;
                return false;
            }
        }

        node->setState(Project::COMPLETE);
        ordered->push_back(node);
        std::cout << "node "<< node->name << ",set COMPLETE and push to ordered "<< std::endl;

    }else{
        //0 BLANK, 1 INPROCESS, 2 COMPLETE
        std::cout << "node "<< node->name << ", not BLANK ,->getState() == "<< node->getState() << std::endl;

    }



    return true;
}


std::vector<Project*> getorderedProjects(std::vector<Project*> *nodes_poll){

    std::cout << "******"<<__FUNCTION__ << std::endl;

    std::cout <<"nodes_poll->size(): " << nodes_poll->size() << std::endl;
    std::vector<Project*> ordered;

    for(int i=0; i < nodes_poll->size(); ++i){
        std::cout << "node "<< nodes_poll->at(i)->name << ",nodes_poll->at(i)->getState() == "<< nodes_poll->at(i)->getState() << std::endl;
        if(nodes_poll->at(i)->getState() == Project::BLANK){
            if( !doDFS(nodes_poll->at(i), &ordered)){
                return {};
            }
        }
    }





    return ordered;
}


std::vector<Project*> findbuildOrder(std::vector<std::string> projects,
                                    std::vector<std::vector<std::string> > dependencies){



    Graph graph = buildGraph(projects, dependencies);
    //std::cout << &graph << std::endl;
    //std::cout << graph.nodes_poll->size() << std::endl;
    graph.printNodes();



    std::vector<Project*> ordered = getorderedProjects(graph.getNodes());

    //check result
    for(int i=0; i < ordered.size() ; ++i){
        std::cout << ordered[ordered.size()-1 - i ]->name << ", ";
    }
    std::cout << std::endl;

    return ordered;
}




void testingProject(){

    //pointer ver

    Project test0= Project("test0");


    Project test= Project("current");
    std::cout << test.name << std::endl;
    std::cout << test.point_to_children->size() << std::endl;
    test.point_to_children->push_back(&test0);
    std::cout << test.point_to_children->size() << std::endl;
    std::cout << (test.point_to_children->at(0))->name << std::endl;



    Project maptest0= Project("maptest0");
    Project mapcurrent= Project("mapcurrent");


    test.string2instance_map->insert(std::pair<std::string, Project*>("test0", &maptest0));
    test.string2instance_map->insert(std::pair<std::string, Project*>("current", &mapcurrent));

    //std::string tt="current";

    std::cout << test.string2instance_map->find("test0")->second->name << std::endl;


    /*
    Project test0= Project("test0");


    Project test= Project("current");
    std::cout << test.name << std::endl;
    std::cout << test.point_to_children.size() << std::endl;
    test.point_to_children.push_back(test0);
    std::cout << test.point_to_children.size() << std::endl;
    std::cout << (test.point_to_children.at(0)).name << std::endl;

    Project maptest0= Project("maptest0");
    Project mapcurrent= Project("mapcurrent");
    test.string2instance_map.insert(std::pair<std::string, Project>("test0", maptest0));
    test.string2instance_map.insert(std::pair<std::string, Project>("current", mapcurrent));
    std::cout << test.string2instance_map.find("test0")->second.name << std::endl;

    //check key, 0: no , 1: yes
    std::cout << test.string2instance_map.count("test0") << std::endl;

    test0.incrementDependencies();
    std::cout << test0.getName() << ", "<<test0.getNumberDependencies() << std::endl;
    */
}


void testingGraph(){
    Graph testg = Graph();
}

int main(){

    //testingProject();
    //testingGraph();

    //{"a", "b", "c", "d", "e", "f"}
    std::vector<std::string > projects_source;
    projects_source.push_back("a");
    projects_source.push_back("b");
    projects_source.push_back("c");
    projects_source.push_back("d");
    projects_source.push_back("e");
    projects_source.push_back("f");
    //check
    for(int i =0; i < projects_source.size(); ++i){
        std::cout << projects_source[i] << std::endl;
    }

    //{"a", "d"}, {"f", "b"}, {"b", "d"}, {"f", "a"}, {"d", "c"}}
    std::vector<std::vector<std::string> > dependencies_source;
    std::vector<std::string> tmp;
    tmp.push_back("a");
    tmp.push_back("d");
    dependencies_source.push_back(tmp);
    tmp.clear();
    tmp.push_back("f");
    tmp.push_back("b");
    dependencies_source.push_back(tmp);
    tmp.clear();
    tmp.push_back("b");
    tmp.push_back("d");
    dependencies_source.push_back(tmp);
    tmp.clear();
    tmp.push_back("f");
    tmp.push_back("a");
    dependencies_source.push_back(tmp);
    tmp.clear();
    tmp.push_back("d");
    tmp.push_back("c");
    dependencies_source.push_back(tmp);
    tmp.clear();

    //check
    for(int i =0; i < dependencies_source.size(); ++i){
        for(int j =0; j< dependencies_source[i].size(); ++j)
            std::cout << dependencies_source[i][j]<<", ";
        std::cout<< std::endl;
    }


    //std::cout << <<std::endl;


    findbuildOrder(projects_source,dependencies_source );



    return 0;
}
