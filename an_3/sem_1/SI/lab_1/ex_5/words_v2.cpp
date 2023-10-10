

#include <iostream>
#include <list>
#include <cstring>
#include <crypt.h>
#include <vector>
#include <math.h>

using namespace std;

string target_salt = "$6$9kfonWC7$";
string target_pw_hash = "$6$9kfonWC7$gzqmM9xD7V3zzZDo.3Fb5mAdM0GbIR2DYTtjYpcGkXVWatTC0pa/XVvKTXLb1ZP0NG9cinGRZF7gPLdhJsHDM/";

// define the maximum length for the password to be searched
#define MAX_LEN 8

vector<string> pwlist;

// check if the pw and salt are matching the hash
int check_password(string& pw, string& salt, string& hash)
{
    const char* res = crypt(pw.c_str(), salt.c_str());

    cout << "password " << pw << "\n";
    cout << "hashes to " << res << "\n";
    
    for (size_t i = 0; i < hash.length(); i++)
        if (res[i] != hash[i])
            return 0;

    cout << "match !!!" << "\n";
    return 1;
}



string generateAndSearch(const vector<string>& wordset, int maxLength) {

    vector<string> combinations;
    combinations.push_back("");
    
    for (int length = 1; length <= maxLength; ++length) {
        vector<string> newCombinations;

        for (const string& prefix : combinations) {
            for (string s : wordset) {
                string newCombination = prefix + s;
                newCombinations.push_back(newCombination);
                if (check_password(newCombination, target_salt, target_pw_hash))
                    return newCombination;
            }
        }

        combinations = move(newCombinations);
    }

    return "";
}


main()
{
    string salt;
    string target;
    string password;

    // define the character set from which the password will be built
    vector<string> wordset = {"red", "green", "blue", "orange", "pink"};
    
    password = generateAndSearch(wordset, wordset.size());

    if (password.length() > 0)
        cout << "password found: " << password << "\n";
    else
        cout << "password not found" << "\n";
}