 If difference between count of odd set bits (Bits set at odd positions) and even set bits is multiple of 3 then is the number.
 
 while (n) { 
        /* If odd bit is set then 
        increment odd counter */
        if (n & 1) 
            odd_count++; 
  
        /* If even bit is set then 
        increment even counter */
        if (n & 2) 
            even_count++; 
        n = n >> 2; 
    } 
  
    return isMultipleOf3(abs(odd_count - even_count)); 
} 

	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    int c=0;
	    for(int i=0;i<s.size();i++)
	    {
	        if(s[i]=='1')
	        {
	            if(i%2!=0)
	            c--;
	            else
	            c++;
	            
	        }
	    }
	    if(c%3==0)
	    cout<<"1"<<endl;
	    else
	    cout<<"0"<<endl;
	}
	return 0;
}
