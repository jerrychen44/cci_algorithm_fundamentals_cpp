/*
 * Cracking the coding interview Edition 6
 * Problem 1.3 URLify --> Replace all the spaces in a string with '%20'.
 * Assumption : We have enough space to accomodate addition chars
 * Preferebly in place
 */

#include <iostream>
#include <cstring>

using namespace std;
/*
 * Function : urlify
 * Args     : string long enough to accomodate extra chars + true len
 * Return   : void (in place transformation of string)
 */

void urlify(char *str, int len)
{
    int space_num = 0;
    int i = 0,j = 0;

    //get space_num
    for(i =0 ; i < len ; ++i){
        if(str[i] == ' '){
            space_num ++;
        }
    }

    int needspace = len + 2 * space_num; //for ' ' -> '%20'
    i = needspace - 1 ;//find last element index
    cout << "i = "<< i << endl;

    //we checking the str from the end to the beginning.
    //we can use the buffer from the end of string as an in place manipulation.
    for (j = len -1; j >=0 ; --j){

        cout << str[j] << endl;
        if ( str [j] != ' '){
            //the string size is 17, we in place move the char to the end of string
            str[i] = str [j];
            i--;
        }else{
            str[i] = '0';
            i--;
            str[i] = '2';
            i--;
            str[i] = '%';
            i--;
        }
        cout << "i = "<< i << endl;
        cout << "j = "<< j << endl;
        cout << str << endl;

    }


}

int main()
{
    char str[] = "Mr John Smith    ";                       //String with extended length ( true length + 2* spaces)
    std::cout << "Actual string   : " << str << std::endl;
    urlify(str, 13);                                        //Length of "Mr John Smith" = 13
    std::cout << "URLified string : " << str << std::endl;
    return 0;
}
