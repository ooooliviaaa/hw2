#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
set<string> parseStringToWords(string rawWords)
{
    string final = convToLower(rawWords);
    //if there is only one word inside, just return the word 
    std::set<std::string> newset;
    if(final.size() <= 1){
        return newset;
    }
    //if it is the other case, then split at punctuation 
    else{
        
        string s;
        for(int i = 0; i < (int)final.size(); i++){
            if(97 <= (int)final[i] && (int)final[i] <= 122){
                s += final[i];
            }
            else{
              if(s.size() >= 2){
                newset.insert(s);
              }
              s = "";
            }
        }
        newset.insert(s);
    }
    return newset;
}
/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
