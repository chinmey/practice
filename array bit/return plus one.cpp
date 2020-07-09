    vector<int> plusOne(vector<int>& digits) {
      int sum=0,c=1;
    for(int i=digits.size()-1;i>=0;i--)
    {
        sum=digits[i]+c;
        if(sum!=10)
        { digits[i]=sum;
         return digits;}
        else
        {
            sum=0;
            digits[i]=sum;
        }
    }
        digits.insert(digits.begin(),1);
        return digits;
}};
