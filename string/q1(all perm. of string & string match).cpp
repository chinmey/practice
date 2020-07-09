#include<bits/stdc++.h>
using namespace std;
int main()
 {
     int t;
     cin>>t;
     while(t--){

          string s;

    cin >> s;


    sort(s.begin(), s.end());
    do
    {
        cout << s << " ";
    } while(next_permutation(s.begin(), s.end()));

     cout<<endl;}
	return 0;
}

----------------------------------------------------------------------------------------------------


For capital alphabets 65 – 90
For small alphabets 97 – 122
For digits 48 – 57
size_t find (const string& str, size_t pos = 0);
size_t find (const char* s, size_t pos = 0);
// CPP program to demonstrate working of string 
// find to search a string 
#include <iostream> 
#include <string> 

using namespace std; 

int main() 
{ 
	string str = "geeksforgeeks a computer science"; 
	string str1 = "geeks"; 

	// Find first occurrence of "geeks" 
	size_t found = str.find(str1); 
	if (found != string::npos) 
		cout << "First occurrence is " << found << endl; 

	// Find next occurrence of "geeks". Note here we pass 
	// "geeks" as C style string. 
	char arr[] = "geeks"; 
	found = str.find(arr, found+1); 
	if (found != string::npos) 
		cout << "Next occurrence is " << found << endl; 

	return 0; 
} 
First occurrence is 0
Next occurrence is 8
