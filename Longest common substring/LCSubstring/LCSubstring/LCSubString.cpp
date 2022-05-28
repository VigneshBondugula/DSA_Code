#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
 
const int P = 1e9 + 7; // Recommended to be a prime
const int M = 29; // Recommended to be a prime

// Helper function to run rolling hash and generate
// all hashes of substrings of given length
// Complexity O(length of string)
vector<int> generateHashes(string &s, int length) {
    vector<int> hashes;

    int hash = 0;
    int h = 1;
    for (int i = 0; i < length; i++) {
        hash = hash * M + (s[i] - 'a' + 1);
        hash %= P;
        if (i > 0) {
            h = h * M;
            h %= P;
        }
    }

    hashes.push_back(hash);
    for (int i = length; i < s.size(); i++) {
        int prevCharacter = s[i - length] - 'a';
        int newCharacter = s[i] - 'a';
        hash = (hash - h * (prevCharacter + 1) + P) % P;
        hash = (hash * M + (newCharacter + 1)) % P;
        hashes.push_back(hash);
    }
    // Note: we have to do s[i] - 'a' + 1 and not just a[i] - 'a' 
    // becasue otherwise "aab" and "ab" and "b" will have the same hash

    return hashes;
}

// Function checks is there a commong substring in s1 and s2 of size length
// Complexity O(size(S1) + size(S2))

// Note: The keen reader might realize that we are not 
// handling hash colissions of the substring within the same string
// We can handle it by using unordered_map<int, vector<int>> hashtable

bool isPossible(string &s1, string &s2, int length) {

    unordered_map<int, int> hashtable; // Key = hash, value = index
    vector<int> hashes_s1 = generateHashes(s1, length);

    for (int i = 0; i < hashes_s1.size(); i++) {
        int hash = hashes_s1[i];
        hashtable[hash] = i;
    }

    vector<int> hashes_s2 = generateHashes(s2, length);

    for (int i = 0; i < hashes_s1.size(); i++) {
        int hash = hashes_s2[i];
        // Check if hash exists
        if (hashtable.find(hash) != hashtable.end()) {
            int j = hashtable[hash];
            // Check if sub string is actually equal (there might be hash colission)
            if(s1.substr(j, length) == s2.substr(i, length))
                return true;
        }
    }
    return false;
}



int main() {
    string s1;
    string s2;
    cin >> s1 >> s2;
    int ans = 0;
    int l = 1;
    int r = min(s1.size(), s2.size());
    while (l <= r) {
        int m = (l + r) / 2;
        if (isPossible(s1, s2, m)) {
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    cout << ans << endl;
}