#include <iostream>
#include <algorithm>
#include <crypt.h>
#include <string>
#include <fstream>

using namespace std;

void findPass(string pass, const string& hash) {
    crypt_data *pCryptData = new crypt_data;
    size_t pos = hash.find_last_of('$');
    string hashHead = hash.substr(0,pos);
    do {
        string newHash(crypt_r(pass.data(),hashHead.data(),pCryptData));
        if (newHash == hash) {
            cout << "Hash: " << hash << endl;
            cout << "Pass: " << pass << endl;
            break;
        }
    } while ( next_permutation( pass.begin(), pass.end() ) );
        delete pCryptData;
}

int main() {
    int kolichestvo;
    cout << "Введите число хэшей (1, 2, 4, 8): ";
    cin >> kolichestvo;
    ifstream hash1("/home/student/labs/hash");
    string *hash2 = new string [kolichestvo];
    for (int i = 0; i < kolichestvo; i++) {
        hash1 >> hash2[i];
    }
    string abc_pass = "123456789";
    for (int i = 0; i < kolichestvo; i++)
        findPass(abc_pass, hash2[i]);
    return 0;
}