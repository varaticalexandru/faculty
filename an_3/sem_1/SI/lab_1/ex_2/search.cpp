

#include <iostream>
#include <list>
#include <cstring>
#include <crypt.h>
#include <vector>
#include <math.h>

using namespace std;

string target_salt = "$6$SvT3dVpN$";
string target_pw_hash = "$6$SvT3dVpN$lwb3GViLl0J0ntNk5BAWe2WtkbjSBMXtSkDCtZUkVhVPiz5X37WflWL4k3ZUusdoyh7IOUlSXE1jUHxIrg29p.";

// define the maximum length for the password to be searched
#define MAX_LEN 8

vector<string> pwlist;
vector<string> pwlist2;

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



vector<string> generateCombinations(const string& charset, int maxLength) {

    vector<string> combinations;
    vector<string> allCombinations;
    combinations.push_back("");
    
    for (int length = 1; length <= maxLength; ++length) {
        vector<string> newCombinations;

        for (const string& prefix : combinations) {
            for (char c : charset) {
                string newCombination = prefix + c;
                newCombinations.push_back(newCombination);
            }
        }

        allCombinations.insert(end(allCombinations), begin(newCombinations), end(newCombinations));
        combinations = move(newCombinations);
    }

    return allCombinations;
}

string exhaustiveSearch() {
    for (int i = 0; i < pwlist.size(); i++) {
        for (int j = 0; j < pwlist2.size(); j++) {
            if ((pwlist[i] + pwlist2[j]).length() <= MAX_LEN) {
                string new_password = pwlist[i] + pwlist2[j];
                if (check_password(new_password, target_salt, target_pw_hash)) {
                    return new_password;
                }
            }
        }
    }

    return "";
}


main()
{
    string salt;
    string target;
    string password;

    // define the character set from which the password will be built
    string charset = "abc12";
    string non_alpha_num = "!@#";

    pwlist.push_back("");

    pwlist = generateCombinations(charset, charset.size());
    pwlist2 = generateCombinations(non_alpha_num, non_alpha_num.size());

    password = exhaustiveSearch();

    if (password.length() > 0)
        cout << "password found: " << password << "\n";
    else
        cout << "password not found" << "\n";
}