/* QUE- Given a string with repeated characters, the task is to rearrange characters in a string so that no two adjacent characters are same.

Note : It may be assumed that the string has only lowercase English alphabets.

Examples:

Input: aaabc
Output: abaca

Input: aaabb
Output: ababa

Input: aa
Output: Not Possible

Input: aaaabc
Output: Not Possible

  // function for priority_queue to store Key
    // according to freq
    bool operator<(const Key &k) const
    {
        return freq < k.freq;
    }  ----- IMPORTANT */

 #include<bits/stdc++.h>
 using namespace std;

 struct Key{

   int  freq;
   char ch;

   bool operator <(const Key &k)const
   {
       return freq<k.freq;
   }

 };
 void rearrangeString(string str)
 {
     int count[26]={0};
     int n=str.length();
     for(int i=0;i<str.length();i++)
        count[str[i]-'a']++;

    priority_queue<Key>pq;

    for(char c='a';c<='z';c++)
    {
        if(count[c-'a'])
        {
            pq.push(Key{count[c-'a'],c});
        }
    }
    str="";
    Key prev{-1,'#'};

    while (!pq.empty())
    {
        // pop top element from queue and add it
        // to string.
        Key k = pq.top();
        pq.pop();
        str = str + k.ch;

        // IF frequency of previous character is less
        // than zero that means it is useless, we
        // need not to push it
        if (prev.freq > 0)
            pq.push(prev);


        (k.freq)--;
        prev = k;
    }


    if (n != str.length())
        cout << " Not valid String " << endl;

    else
        cout << str << endl;
}





     int main()
{
    string str = "bbbaa" ;
    rearrangeString(str);
    return 0;
}


