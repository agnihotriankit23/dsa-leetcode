#include <bits/stdc++.h>
using namespace std;

// Longest common Prefix

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        childCount = 0;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};
class trie
{
public:
    TrieNode *root;
    trie(char ch)
    {
        root = new TrieNode(ch);
    }
    void insertUtil(TrieNode *root, string word)
    {

        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            root->childCount++;
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    void lcp(string str, string &ans)
    {
        for (int i = 0; i < str.size(); i++)
        {
            char ch = str[i];

            if (root->childCount == 1)
            {
                ans.push_back(ch);

                int index = str[i] - 'a';

                root = root->children[index];
            }
            else
            {
                break;
            }

            if (root->isTerminal)
            {
                break;
            }
        }
    }
};
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (find(strs.begin(), strs.end(), "") != strs.end())
        {
            return "";
        }
        trie *t = new trie('\0');
        for (int i = 0; i < strs.size(); i++)
        {
            t->insertWord(strs[i]);
        }

        string first = strs[0];
        string ans = "";
        t->lcp(first, ans);
        return ans;
    }
};

// Implement Phone Dirctory
class trie1
{
public:
    TrieNode *root;
    trie1(char ch)
    {
        root = new TrieNode(ch);
    }
    void insertUtil(TrieNode *root, string word)
    {

        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            root->childCount++;
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    void lcp(string str, string &ans)
    {
        for (int i = 0; i < str.size(); i++)
        {
            char ch = str[i];

            if (root->childCount == 1)
            {
                ans.push_back(ch);

                int index = str[i] - 'a';

                root = root->children[index];
            }
            else
            {
                break;
            }

            if (root->isTerminal)
            {
                break;
            }
        }
    }
    void printSuggestions(TrieNode *curr, vector<string> &temp, string prefix)
    {
        if (curr->isTerminal)
        {
            temp.push_back(prefix);
        }

        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            TrieNode *next = curr->children[ch - 'a'];

            if (next != NULL)
            {
                prefix.push_back(ch);
                printSuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }
    vector<vector<string>> getSuggestions(string str)
    {
        TrieNode *prv = root;
        vector<vector<string>> output;
        string prefix = "";

        for (int i = 0; i < str.length(); i++)
        {
            char lastch = str[i];

            prefix.push_back(lastch);

            TrieNode *curr = prv->children[lastch - 'a'];

            if (curr == NULL)
            {
                break;
            }
            vector<string> temp;
            printSuggestions(curr, temp, prefix);

            output.push_back(temp);
            temp.clear();
            prv = curr;
        }
        return output;
    }
};
class solution1
{
public:
    vector<vector<string>> phoneDirectory(vector<string> &contactList, string &queryStr)
    {
        trie1 *t = new trie1('\0');
        for (int i = 0; i < contactList.size(); i++)
        {
            string str = contactList[i];
            t->insertWord(str);
        }

        return t->getSuggestions(queryStr);
    }
};
int main()
{

    return 0;
}