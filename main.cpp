
#include <bits/stdc++.h>
using namespace std;

string SHIT_CYPHIR_ENC(const string& input, int k) {
    string s1 = input;

    vector<char> pt(s1.size());

    for (int i = 0; i < s1.size(); ++i) {
        pt[i] = tolower(s1[i]);
    }

    vector<char> ct(s1.size());

    for (int i = 0; i < s1.size(); ++i) {
        if (isspace(pt[i])) {
            ct[i] = pt[i];
        } else {
            ct[i] = pt[i] + k;
            if (ct[i] > 'z') {
                ct[i] = 'a' + ((pt[i] + k) - 'z' - 1);
            }
        }
    }

    string encrypted;
    for (int i = 0; i < s1.size(); ++i) {
        encrypted.push_back(ct[i]);
    }
    cout << "\n";
    return encrypted;
}

string SHIT_CYPHIR_DEC(const string& input, int k) {
    string s1 = input;
    vector<char> pt(s1.size());

    for (int i = 0; i < s1.size(); ++i) {
        pt[i] = tolower(s1[i]);
    }

    vector<char> ct(s1.size());

    for (int i = 0; i < s1.size(); ++i) {
        if (isspace(pt[i])) {
            ct[i] = pt[i];
        } else {
            if (pt[i] - k < 'a') {
                ct[i] = (pt[i] - 'a' - k) + 'z' + 1;
            } else {
                ct[i] = pt[i] - k;
            }
        }
    }

    string decrypted;
    for (int i = 0; i < s1.size(); ++i) {
        decrypted.push_back(ct[i]);
    }
    cout << "\n";
    return decrypted;
}


string removeSpaces(const string& str) {
    string result;
    for (char ch : str) {
        if (!isspace(ch)) {
            result.push_back(ch);
        }
    }
    return result;
}
string encryptRailFence(const string& input, int d) {
    string s = removeSpaces(input);
    int n = s.length();
    vector<vector<char>> m(d, vector<char>(n + 100, '.'));
    int index = 0;
    int i = 0, j = 0;
    m[0][0] = s[0];

    while (s[index] != '\0') {
        for (int t = 1; t <= d - 1; ++t) {
            i++;
            j++;
            index++;
            m[i][j] = s[index];
        }
        for (int k = 1; k <= d - 1; ++k) {
            i--;
            j++;
            index++;
            m[i][j] = s[index];
        }
    }

    string encrypted;
    for (int k1 = 0; k1 < d; ++k1) {
        for (int k = 0; k < n; ++k) {
            if (m[k1][k] != '.') {
                if (isalpha(m[k1][k])) {
                    encrypted.push_back(m[k1][k]);
                }
            }
        }
    }
    return encrypted;
}

string decryptRailFence(const string& input, int d) {
    string s = removeSpaces(input);
    int n = d;
    vector<vector<char>> a(n, vector<char>(s.size(), ' '));
    int j = 0;
    int flag = 0;
    int temp = 0;

    for (int i = 0; i < s.size(); ++i) {
        a[j][i] = '0';
        if (j == n - 1) {
            flag = 1;
        } else if (j == 0) {
            flag = 0;
        }
        if (flag == 0) {
            j++;
        } else {
            j--;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < s.size(); ++j) {
            if (a[i][j] == '0') {
                a[i][j] = s[temp++];
            }
        }
    }

    flag = 0;
    j = 0;
    string decrypted;
    for (int i = 0; i < s.size(); ++i) {
        decrypted.push_back(a[j][i]);
        if (j == n - 1) {
            flag = 1;
        } else if (j == 0) {
            flag = 0;
        }
        if (flag == 0) {
            j++;
        } else {
            j--;
        }
    }
    return decrypted;
}



string  PLAYFAIRencrypt(string input) {
    stack<char> s;
    vector<char> v;
    for (int i = 0; i < input.size(); ++i) {
        if (s.empty())
            s.push(input[i]);
        else {
            if (s.top() == input[i]) {
                v.push_back(s.top());
                s.pop();
                v.push_back('x');
                s.push(input[i]);
            } else {
                v.push_back(s.top());
                s.pop();
                v.push_back(input[i]);
            }
        }
    }
    if (v.size() % 2 != 0) {
        v.push_back('x');
    }

    int n = 2;
    vector<string> v2;
    string r;
    for (int i = 0; i < v.size(); ++i) {
        if (i % n == 0 && i != 0) {
            v2.push_back(r);
            r = "";
        }
        r += v[i];
    }
    if (!r.empty())
        v2.push_back(r);

    char matrix[5][5] = {
            {'m', 'o', 'n', 'a', 'r'},
            {'c', 'h', 'y', 'b', 'd'},
            {'e', 'f', 'g', 'i', 'k'},
            {'l', 'p', 'q', 's', 't'},
            {'u', 'v', 'w', 'x', 'z'}
    };

    string result;
    int firstx, secx, secy, firsty;

    for (int i = 0; i < v2.size(); ++i) {
        string s6 = v2[i];

        firstx = secx = secy = firsty = 0;
        for (int j = 0; j < 5; ++j) {
            for (int k = 0; k < 5; ++k) {
                if (s6[0] == matrix[j][k]) {
                    firstx = j;
                    firsty = k;
                }
                if (s6[1] == matrix[j][k]) {
                    secx = j;
                    secy = k;
                }
            }
        }
        if (firstx == secx) {
            firsty = (firsty + 1) % 5;
            secy = (secy + 1) % 5;
        } else if (firsty == secy) {
            firstx = (firstx + 1) % 5;
            secx = (secx + 1) % 5;
        } else {
            int temp = firsty;
            firsty = secy;
            secy = temp;
        }
        result += matrix[firstx][firsty];
        result += matrix[secx][secy];
    }
    cout << "Encrypted string: " << result << "\n" ; return result;}
string PLAYFAIRdecrypt(string input) {
    stack<char> s;
    vector<char> v;
    for (int i = 0; i < input.size(); ++i) {
        if (s.empty())
            s.push(input[i]);
        else {
            if (s.top() == input[i]) {
                v.push_back(s.top());
                s.pop();
                v.push_back('x');
                s.push(input[i]);
            } else {
                v.push_back(s.top());
                s.pop();
                v.push_back(input[i]);
            }
        }
    }
    if (v.size() % 2 != 0) {//34an myb4 fdel lettre lw7do
        v.push_back('x');
    }

    int n = 2;
    vector<string> v2;
    string r;
    for (int i = 0; i < v.size(); ++i) {
        if (i % n == 0 && i != 0) {
            v2.push_back(r);
            r = "";
        }
        r += v[i];
    }
    if (!r.empty())
        v2.push_back(r);

    char matrix[5][5] = {
            {'m', 'o', 'n', 'a', 'r'},
            {'c', 'h', 'y', 'b', 'd'},
            {'e', 'f', 'g', 'i', 'k'},
            {'l', 'p', 'q', 's', 't'},
            {'u', 'v', 'w', 'x', 'z'}
    };

    string result;
    int firstx, secx, secy, firsty;

    for (int i = 0; i < v2.size(); ++i) {
        string s6 = v2[i];

        firstx = secx = secy = firsty = 0;
        for (int j = 0; j < 5; ++j) {
            for (int k = 0; k < 5; ++k) {
                if (s6[0] == matrix[j][k]) {
                    firstx = j;
                    firsty = k;
                }
                if (s6[1] == matrix[j][k]) {
                    secx = j;
                    secy = k;
                }
            }
        }
        if (firstx == secx) {
            firsty = (firsty - 1) % 5;
            secy = (secy - 1) % 5;
        } else if (firsty == secy) {
            firstx = (firstx - 1) % 5;
            secx = (secx - 1) % 5;
        } else {
            int temp = firsty;
            firsty = secy;
            secy = temp;
        }
        result += matrix[firstx][firsty];
        result += matrix[secx][secy];
    }
    cout << "Decrypted string: " << result << "\n"; return result;
}
string removeNonAlphabetic(string text) {
    string text_without_non_alpha;
    for (char c : text) {
        if (isalpha(c)) {
            text_without_non_alpha += c;
        }
    }
    return text_without_non_alpha;
}
int main() {
    string input;
    cout << "Enter string: ";
    getline(cin, input);
    string input1= removeSpaces(input);
    string input2=removeNonAlphabetic(input1);
    int d;
    cout << "Enter key: ";
    cin >> d;

    string encrypted1 = SHIT_CYPHIR_ENC(input2, d);
    cout << "Encrypted string BY SHIFT CIPHER: " << encrypted1 << "\n";


    /* string decrypted = decrypt(encrypted, d);
     cout << "Decrypted string: " << decrypted << "\n";*/


    string encryptRailFenceSTRING = encryptRailFence(encrypted1, d);
    cout << "Encrypted by Rail Fence: " << encryptRailFenceSTRING << "\n";
    string encryptPLAYFAIRSTRING =PLAYFAIRencrypt(encryptRailFenceSTRING);
    string decrptPLAYFAIRSTRING= PLAYFAIRdecrypt(encryptPLAYFAIRSTRING);
    string decrypted = SHIT_CYPHIR_DEC(encryptRailFenceSTRING, d);
    cout << "Decrypted string BY SHIFT CYPHER: " << decrypted << "\n";

    string decryptRailFenceSTRING = decryptRailFence(decrypted, d);
    cout << "Decrypted by Rail Fence: " << decryptRailFenceSTRING << "\n";
    return 0;
}
