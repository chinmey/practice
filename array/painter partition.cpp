/* check out minimum jump and longest arithmetic progression from copy towards the end*/

We have to paint n boards of length {A1, A2…An}. There are k painters available and each takes 1 unit time to paint 1 unit of board.
 The problem is to find the minimum time to get
this job done under the constraints that any painter will only paint continuous sections of boards, say board {2, 3, 4} or 
only board {1} or nothing but not board {2, 4, 5}.

Examples:

Input : k = 2, A = {10, 10, 10, 10} 
Output : 20.
Here we can divide the boards into 2
equal sized partitions, so each painter 
gets 20 units of board and the total
time taken is 20. 

Input : k = 2, A = {10, 20, 30, 40} 
Output : 60.
Here we can divide first 3 boards for
one painter and the last board for 
second painter.


include<iostream>
using namespace std;

#define ll long long int

bool isValidConfig(ll books[],ll n,ll k,ll ans){
        
    int students=1;
    ll current_pages = 0;
    
    for(int i=0;i<n;i++){
        
        if(current_pages+books[i]>ans){
            current_pages = books[i];
            students++;
            if(students>k){
                return false;
            }
            
        }
        else{
            current_pages += books[i];
            
        }
    }
    return true;
}

ll binarySearchBooks(ll books[],ll n,ll k){
    
    ll total_pages = 0;
    ll s=0,e=0;
    for(int i=0;i<n;i++){
        total_pages += books[i];
    }
    s = books[n-1];
    
    e = total_pages;
    int finalAns = s;
    
    while(s<=e){
        ll mid = (s+e)/2;
        
        if(isValidConfig(books,n,k,mid)){
            ///true
            finalAns = mid;
            e = mid-1;
            
        }
        else{
            //FALSE
            s = mid + 1;
        }
        
        
    }
    
    return finalAns;
    
}

int main(){
    
    ll n;
    ll k;
    
    cin>>n>>k;
    
    ll books[100005];
    
    for(int i=0;i<n;i++){
        cin>>books[i];
    }
    cout<<binarySearchBooks(books,n,k)<<endl; 
}



