#include <iostream>
#include <vector>



int main(){


    // declare 1 vector which has 10 in elements
    std::vector<int> v1(10);
    std::cout << v1.size() << std::endl;




    // declare 10 vector which has 1 element in each one.
    std::vector<int> v2[10];
    std::cout << v2[0].size() << std::endl;
    std::cout << v2[9].size() << std::endl;
    // out of index
    //std::cout << v2[10].size() << std::endl;


    v2[0].push_back(2);
    v2[0].push_back(4);
    std::cout << v2[0].size() << std::endl;


    std::vector<int> *v22;

    v22 = v2;
    std::cout << v22[0].size() << std::endl;
    v22[0].pop_back();
    std::cout << v22[0].size() << std::endl;


    return 0;
}