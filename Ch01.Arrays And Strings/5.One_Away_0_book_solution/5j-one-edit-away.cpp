/*
 * Problem: There are three possible edits that can be performed on a string.
 * 1. Insert a char.
 * 2. Delete a char.
 * 3. Replace a char.
 *
 * Given two strings, determine if they are one or 0 edit away.
 *
 * Approach :
 * 1. Case when strings are of some length --> possible edit is replace.
 *    If there are more than one mismatch, return false
 *
 * 2. Case when One string is bigger than another
 *    Smaller string ------------> Bigger String
 *                     insert
 *                     delete
 *    smaller string <-----------  Bigger String
 *
 *    Idea is check if there are more than one mismatch discounting the already
 *    difference in the string. Therefore for first mismatch we do not move the pointer
 *    pointing to smaller string, and then expect it to match from next char of bigger
 *    string.
 */

//whatever insert or delete will only cause one different char between two strings.
//and two string will have different lens
//which means , we can allow only one different char appeared at the first time.
//and still move i index at that moment.

//i,j should move one index when the char is the same.
//if not the same, we still move i at the first mismatch in replace case to check next char.

#include <iostream>
#include <string>
#include <cmath>


bool oneEditAway( const std::string & str1, const std::string & str2 )
{
    if ( std::abs( int(str1.length()) - int(str2.length()))  > 1 ) {
        return false;
    }

    int len1 = str1.length();
    int len2 = str2.length();
    //find which str is longer one
    std::string smaller = len1 < len2 ? str1 : str2;
    std::string bigger =  len1 < len2 ? str2 : str1;

    unsigned int i = 0, j = 0;
    bool mismatchDone = false;

    while ( i < smaller.length() && j < bigger.length() )
    {
        if ( smaller[i] != bigger[j] ) {
            //find one char difference

            if (mismatchDone) {
                std::cout << "more then one mismatch" << std::endl;
                return false;
            }

            mismatchDone = true; // set the mismatch flag to true at first time.

            if ( len1 == len2 ) {

                ++i;   //case of replace, move smaller str index move right
                std::cout << "len1 == len2, replace case" << std::endl;
            }

        } else { // char the same, check next char

                ++i;   //move short pointer if its a match, dont move it in case of first mismatch
        }


        ++j;           //always move long string pointer.
    }
    return true;
}


void translate( bool result, const std::string str1, const std::string str2 )
{
    if (result == true ) {
        std::cout << str1 << " and " << str2 << " are one edit away\n";
    } else {
        std::cout << str1 << " and " << str2 << " are not one edit away\n";
    }
}

int main()
{
    translate ( oneEditAway("pale", "ple"), "pale", "ple" );
    std::cout << std::endl;
    //the same
    translate ( oneEditAway("pales", "pale"), "pales", "pale" );
    std::cout << std::endl;
    translate ( oneEditAway("pale", "pales"), "pale", "pales" );
    std::cout << std::endl;

    translate ( oneEditAway("pale", "bale"), "pale", "bale" );
    std::cout << std::endl;

    translate ( oneEditAway("pale", "bake"), "pale", "bake" );
    return 0;

}
