#include<bits/stdc++.h>
using namespace std;

int Query;
bool comparator(vector<string> &A, vector<string> &B)
{
  return A[Query] < B[Query];
}



class Contact_Manager
{
  vector<vector<string>> Contact_List;
  public :
    Contact_Manager()
    {
      Contact_List = vector<vector<string>>();
    }

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

    void SearchContact(string key,int query)
    {
      int start = 0, end = Contact_List.size() - 1;
      int index;

      transform(key.begin(), key.end(), key.begin(), ::tolower);
      sort(Contact_List.begin(), Contact_List.end(), comparator);
      while(start <= end)
      {
        int mid = start + (end - start) / 2;
        string currentValue = Contact_List[mid][query].substr(0,key.size());
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
      for(int i = index; i < Contact_List.size(); i++)
      {
        string currentValue = Contact_List[i][query].substr(0,key.size());
        transform(currentValue.begin(), currentValue.end(), currentValue.begin(), ::tolower);

        if(key == currentValue)
        {
          cout << Contact_List[i][query] << endl;
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
          cout << Contact_List[i][query] << endl;
          total++;
        }
        else break;
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

    if(choice == 1) contact.addContact();
    else if(choice == 2)
    {
      cout << "\n1. COMPLETE SEARCH \n";
      cout << "2. PREFIX SEARCH\n";

      int search_choice;
      cout << "\nChoice : ";
      cin >> search_choice;

      while(true)
      {
        if(search_choice == 1 || search_choice == 2)
          break;
        else 
          cout << "\nINVALID CHOICE!\n";

        cin >> search_choice;
      }

      cout << "\n1. First Name \n";
      cout << "2. Last Name \n";
      cout << "3. Phone Number\n";

      int query;
      cout << "\nChoice : ";
      cin >> query;

      while(true)
      {
        if(query == 1 || query == 2 || query == 3)
          break;
        else 
          cout << "\nINVALID CHOICE!\n";

        cin >> query;
      }

      cout << "\nKEY : ";
      string key;
      cin >> key;

      cout << "\n";
      query--;
      Query = query;
      contact.SearchContact(key,query);
    }
    else if(choice == 3) break;
    else cout << "\nInvalid Choice!\n";
  }
  return 0;
}
