#include<bits/stdc++.h>
using namespace std;

int Query;
bool is_updated[3] = {false, false, false};

bool comparator(vector<string> &A, vector<string> &B)
{
  return A[Query] < B[Query];
}

vector<vector<string>> Contact_List;

class Contact_Manager
{
  public :
    void addContact()
    {
      string firstName, lastName, phone;
      cout << "\nFIRST NAME : ";
      cin >> firstName;

      cout << "\nLAST NAME : ";
      cin >> lastName;

      cout << "\nPHONE : ";
      cin >> phone;
      Contact_List.push_back({firstName, lastName, phone});
    }

    void SearchContact(string key,int query, int flag)
    {
      int start = 0, end = Contact_List.size() - 1;
      int index = -1;

      transform(key.begin(), key.end(), key.begin(), ::tolower);
      if(is_updated[query])
        sort(Contact_List.begin(), Contact_List.end(), comparator);
      is_updated[query] = false;

      while(start <= end)
      {
        int mid = start + (end - start) / 2;
        string currentValue;

        if(flag == 2) currentValue = Contact_List[mid][query].substr(0,key.size());
        else currentValue = Contact_List[mid][query];

        transform(currentValue.begin(), currentValue.end(), currentValue.begin(), ::tolower);

        if(currentValue == key) 
        {
          index = mid;
          break;
        }

        else if(currentValue < key) 
          start = mid + 1;

        else
          end = mid - 1;
      }

      int total = 0;
      if(index != -1)
      {
        for(int i = index; i < Contact_List.size(); i++)
        {
          string currentValue = Contact_List[i][query].substr(0,key.size());
          transform(currentValue.begin(), currentValue.end(), currentValue.begin(), ::tolower);

          if(key == currentValue)
          {
            cout << Contact_List[i][0]<<" " << Contact_List[i][1] << " " << Contact_List[i][2] << endl;
            total++;
          }
          else break;
        }

        for(int i = index - 1; i >= 0; i--)
        {
          string currentValue = Contact_List[i][query].substr(0,key.size());
          transform(currentValue.begin(), currentValue.end(), currentValue.begin(), ::tolower);

          if(key == currentValue)
          {
            cout << Contact_List[i][0]<<" " << Contact_List[i][1] << " " << Contact_List[i][2] << endl;
            total++;
          }
          else break;
        }
      }

      cout << "\nTOTAL : " << total << endl;
    }
  
};

int main()
{
  while(true)
  {
    cout << "\n";
    cout << "1. ADD\n";
    cout << "2. SEARCH\n";
    cout << "3. EXIT\n";

    int choice;
    cout << "\nChoice : ";
    cin >> choice;

    Contact_Manager contact;

    if(choice == 1)
    {
      contact.addContact();
      is_updated[0] = is_updated[1] = is_updated[2] = true;
    }
    else if(choice == 2)
    {
      cout << "\n1. COMPLETE SEARCH \n";
      cout << "2. PREFIX SEARCH\n";

      int search_choice;
      cout << "\nChoice : ";

      while(true)
      {
        cin >> search_choice;
        if(search_choice == 1 || search_choice == 2)
          break;
        else 
          cout << "\nINVALID CHOICE!\n";
      }

      cout << "\n1. First Name \n";
      cout << "2. Last Name \n";
      cout << "3. Phone Number\n";

      int query;
      cout << "\nChoice : ";

      while(true)
      {
        cin >> query;
        if(query == 1 || query == 2 || query == 3)
          break;
        else 
          cout << "\nINVALID CHOICE!\n";
      }

      cout << "\nKEY : ";
      string key;
      cin >> key;

      cout << "\n";
      query--;
      Query = query;
      contact.SearchContact(key,query,search_choice);
    }
    else if(choice == 3) break;
    else cout << "\nInvalid Choice!\n";
  }
  return 0;
}
