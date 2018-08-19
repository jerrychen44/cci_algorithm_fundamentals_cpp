/*

hint:
1. use hash table
2. bit vector useful ?
3. O(NlogN) is possible ?

*/

#include <iostream>
#include <string>
#include <bitset>
#include <vector>
using namespace std;


bool is_unique_char_vector(const string &input_string){

    if(input_string.length() > 128)
        return false;

    vector<bool> char_map(128,0);
    int slen = input_string.length();

    for (int i =0; i < slen ; ++i){

        if(char_map[input_string[i]]==true)
            return false;

        char_map[input_string[i]] = true;
    }



    return true;
}



bool is_unique_test(){

    bitset<256> bits(0);//init a 256 bits with zero
    cout << bits << endl;

    int which_bit_set_to_1 = 0;
    cout << which_bit_set_to_1 << endl;

    //check the bit you want to set to 1 is already is 1 or not
    cout << bits.test(which_bit_set_to_1) << endl;


    bits.set(which_bit_set_to_1);
    cout << bits << endl;

    cout << bits.test(which_bit_set_to_1) << endl;




    bits.set(which_bit_set_to_1);
    cout << bits << endl;

    cout << bits.test(which_bit_set_to_1) << endl;

    return true;
}



bool is_unique_bitvector(const string &input_string){
    //a = 97 + 26 =
    bitset<256> bits(0);//init a 256 bits with zero
    //cout << bits << endl;
    int slen = input_string.length();

    for(int i =0; i < slen ; ++i){
        //check is that bit already set to 1 or not
        int set_which_bit = input_string[i];
        //cout << set_which_bit << endl;

        if(bits.test(set_which_bit) == 1)
            return false;


        bits.set(set_which_bit);
        //cout << bits << endl;

    }


    return true;
}





//no other memory space
//1 + 2 + 3 + ...+ n-1 + n-2 = (n-1)n/2 = O(n^2)
bool is_unique(const string &input_string){

    //cout << &input_string << endl;//pass by reference
    //cout << input_string << endl;
    int slen = input_string.length();
    //cout << slen << endl;

    for (int i =0; i < slen ; ++i){
        for (int j = i + 1; j < slen ; ++j){
            if(input_string[i] == input_string [j])
                return false;
        }
    }
    return true;
}



int main(){

    string testing = "abcde";//or test
    cout << testing << endl;
    cout << &testing << endl;

    cout<<"result: "<< is_unique(testing)<< endl;
    cout<<"result: "<< is_unique_bitvector(testing)<< endl;
    //is_unique_test();
    cout<<"result: "<<   is_unique_char_vector(testing)<< endl;

    return 0;
}