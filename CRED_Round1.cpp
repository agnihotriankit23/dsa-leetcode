#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    // Properties
    char data;
    TrieNode *children[256];
    int childCount;
    bool isTerminal;

    TrieNode(char ch) // Parametrized Constructor
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

struct ContactManager
{
    //   private:
public:
    string firstName, lastName, contactNumber;

    ContactManager()
    {
        firstName = "";
        lastName = "";
        contactNumber = "";
    }
    ContactManager(string firstName, string lastName, string contactNumber)
    {
        this->firstName = firstName;
        this->lastName = lastName;
        this->contactNumber = contactNumber;
    }
};

class Contact_book
{
public:
    vector<ContactManager> Contact_List;
    void AddContact()
    {
        // cout<<"Add Contact"<<endl;
        string FirstName, LastName, ContactNumber;
        cout << "Enter First Name: ";
        cin >> FirstName;
        cout << "Enter Last Name: ";
        cin >> LastName;
        cout << "Contact Number: ";
        cin >> ContactNumber;
        Contact_List.push_back(ContactManager(FirstName, LastName, ContactNumber));
    }

    void Search(vector<vector<string>> &suggestions)
    {

        cout << "1. For First Name\n";
        cout << "2. For second Name\n";
        cout << "3. For Phone Number\n";

        int option;
        cin >> option;

        vector<string> storage;
        if (option == 1)
        {
            for (auto i : Contact_List)
            {
                storage.push_back(i.firstName);
            }
        }
        else if (option == 2)
        {
            for (auto i : Contact_List)
            {
                storage.push_back(i.lastName);
            }
        }
        else if (option == 3)
        {
            for (auto i : Contact_List)
            {
                storage.push_back(i.contactNumber);
            }
        }

        for (auto i : storage)
            cout << i << " ";
        cout << endl;

        string query;
        cout << "Enter your target Prefix query\n";
        cin >> query;

        trie *t = new trie('\0');
        for (int i = 0; i < storage.size(); i++)
        {
            string str = storage[i];
            t->insertWord(str);
        }

        suggestions = t->getSuggestions(query);
    }

    void PrintContacts()
    {
        // cout << "First\tName Last Name\t  Contact\n";
        for (auto j : Contact_List)
        {
            cout << j.firstName << " " << j.lastName << " " << j.contactNumber << endl;
        }
    }
};

int main()
{
    Contact_book obj1;
    while (true)
    {
        cout << "1. ADD\n";
        cout << "2. SEARCH\n";
        cout << "3. Print\n";
        cout << "4. EXIT\n";

        int choice;
        cin >> choice;
        if (choice == 1)
        {
            obj1.AddContact();
        }
        else if (choice == 2)
        {

            vector<vector<string>> suggestions;

            obj1.Search(suggestions);
            // suggestions = contactManager(contactList, query);

            int size = suggestions.size();
            cout << "Printing Macthing Words.....\n";
            for (auto i : suggestions[size - 1])
            {
                for (auto j : i)
                {
                    // if(j==query)
                    // {
                    cout << j;
                }
                cout << endl;
            }
        }
        else if (choice == 3)
        {

            obj1.PrintContacts();
        }
        else if (choice = 4)
        {
            break;
        }
        else
        {
            cout << "Invalid Choice\n";
        }
    }
    /*
    vector<string> contactList;
    contactList.push_back("cod");
    contactList.push_back("coding");
    contactList.push_back("codding");
    contactList.push_back("code");
    contactList.push_back("coly");

    string query;

    query = "cod";
    */

    return 0;
}