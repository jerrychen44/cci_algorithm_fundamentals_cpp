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


#define ASCII_7BIT_NUM 128
#define ASCII_8BIT_EXTEND_NUM 256

//solution 1
/*
Idea: use a char_map to record if the char appeared or not.
Time Complexity: O(slen)
Space Complexity: O(1), due to we always need xxx(128).

*/
bool is_unique_char_vector(const string &input_string){


    if(input_string.length() > ASCII_7BIT_NUM)
        return false;

    vector<bool> char_map(ASCII_7BIT_NUM,0);
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


//solution 2.a
/*
Idea: reduce the space usage by a factor of eight by using a bit vector.
assumption: string only use the lowercase letter a~z.
We can just use single int.

Time Complexity: O(slen)
Space Complexity: O(1), due to we always need bitset<256> bits(0).
ps.still need other space.

*/
bool is_unique_bitvector(const string &input_string){

    bitset<ASCII_8BIT_EXTEND_NUM> char_map(0);//init a 256 bits with zero
    //cout << char_map << endl;
    int slen = input_string.length();

    for(int i =0; i < slen ; ++i){
        //check is that bit already set to 1 or not
        int set_which_bit = input_string[i];
        cout << input_string[i] << ", " << set_which_bit << endl;

        if(char_map.test(set_which_bit) == 1)
            return false;

        //set the xth bit to 1
        char_map.set(set_which_bit);
        cout << '\n' << char_map << endl;

    }


    return true;
}


//solution 2.b
bool is_unique_normalbit(const string &input_string){

    int char_map = 0;
    int slen = input_string.length();

    for(int i =0; i < slen ; ++i){
        int set_which_bit = input_string[i];
        if (char_map & (1 << set_which_bit))
            return false; //this char used before

        char_map |= (1 << set_which_bit);
    }


    return true;
}





//solution 3
// Idea: compare every character of string to every other char of the string.
// Time complexity : 1 + 2 + 3 + ...+ n-1 + n-2 = (n-1)n/2 = O(n^2)
// space complexity: O(1),no other memory space
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


//solution 4
//we can sorted the string first by O(nlogn), and linearly check
//the string for neighboring char that are identical.
// TODO: implement this




int main(){

    string testing = "abcde";//or test
    cout << testing << endl;
    cout << &testing << endl;

    cout<<"result: "<< is_unique(testing)<< endl;
    cout<<"result: "<< is_unique_bitvector(testing)<< endl;
    cout<<"result: "<< is_unique_normalbit(testing)<< endl;

    //is_unique_test();
    cout<<"result: "<<   is_unique_char_vector(testing)<< endl;

    return 0;
}