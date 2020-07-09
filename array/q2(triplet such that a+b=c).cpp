 /*find triplets such that a+b=c


 take input array,sort it in descending order{using merge sort}
and apply this logic */



 for(k=0;k<n-2;k++)
	  {
	      arr[k]=-arr[k];
	      i=k+1;
	      j=n-1;

	      while(i!=j)
	      {
	           s=arr[k]+arr[i]+arr[j];
	          if(s==0)
	          {
	              ans++;
	              i++;

	          }
	          else if(s>0)
	          i++;
	          else if(s<0)
	          j--;

	      }
	     if(k==n-3)
	     {
	         if(ans==0)
	         cout<<"-1"<<endl;
	         else
	         cout<<ans<<endl;
	     }

	  }}

