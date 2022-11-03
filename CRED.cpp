#include <bits/stdc++.h>
using namespace std;

class Contact_Manager
{
    vector<vector<string>> Contact_List;

public:
    void addContact()
    {
        string fname, lname, phone;
        cin >> fname >> lname >> phone;
        Contact_List.push_back({fname, lname, phone});
    }

    void SearchContact(string key, int query)
    {
        int start = 0, end = Contact_List.size() - 1;
        int index;
        transform(key.begin(), key.end(), key.begin(), ::tolower);

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            string currentValue = Contact_List[mid][query].substr(0, key.size());
            transform(currentValue.begin(), currentValue.end(), currentValue.begin(), ::tolower);

            if (currentValue == key)
            {
                index = mid;
                break;
            }

            else if (currentValue < key)
                start = mid + 1;

            else
                end = mid - 1;
        }

        int total = 0;
        for (int i = index; i < Contact_List.size(); i++)
        {
            string currentValue = Contact_List[i][query].substr(0, key.size());
            transform(currentValue.begin(), currentValue.end(), currentValue.begin(), ::tolower);

            if (key == currentValue)
            {
                cout << Contact_List[i][query] << endl;
                total++;
            }
            else
                break;
        }

        for (int i = index - 1; i >= 0; i--)
        {
            string currentValue = Contact_List[i][query].substr(0, key.size());
            transform(currentValue.begin(), currentValue.end(), currentValue.begin(), ::tolower);

            if (key == currentValue)
            {
                cout << Contact_List[i][query] << endl;
                total++;
            }
            else
                break;
        }

        cout << "TOTAL : " << total << endl;
    }
};

int main()
{
    /*while (true)
    {
        cout << "\n";
        cout << "1. ADD\n";
        cout << "2. SEARCH\n";
        cout << "3. EXIT\n";

        int choice;
        cin >> choice;

        Contact_Manager contact;

        if (choice == 1)
            contact.addContact();
        else if (choice == 2)
        {
            cout << "1. COMPLETE SEARCH \n";
            cout << "2. PREFIX SEARCH\n";

            int search_choice;
            cin >> search_choice;

            while (true)
            {
                if (search_choice == 1 || search_choice == 2)
                    break;
                else
                    cout << "INVALID CHOICE!\n";

                cin >> search_choice;
            }

            cout << "1. First Name \n";
            cout << "2. Last Name \n";
            cout << "3. Phone Number\n";

            int query;
            cin >> query;

            while (true)
            {
                if (search_choice == 1 || search_choice == 2)
                    break;
                else
                    cout << "INVALID CHOICE!\n";

                cin >> query;
            }

            cout << "KEY : ";
            string key;
            cin >> key;

            cout << "\n";
            contact.SearchContact(key, query);
        }
        else if (choice == 3)
            break;
        else
            cout << "Invalid Choice!\n";
    }*/
    return 0;
}