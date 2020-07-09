You are given an integer N. You have to find smallest multiple of N which consists of digits 0 and 1 only. Since this multiple could be large, return it in form of a string.


https://youtu.be/sdTubUR99OA 
or copy for explaination

string Solution::multiple(int n) {
    
    if(n==1) return "1";
    
    vector<string>dp(n);
    
    dp[1]="1";
    
    queue<int>bfs;
    bfs.push(1);
    while(!bfs.empty())
    {
        int r=bfs.front();
        bfs.pop();
        
        if(r==0) return dp[r];
        
        for(int digit:{0,1}){
            int new_r=(10*r+digit)%n;
            if(dp[new_r].empty()){
                bfs.push(new_r);
                dp[new_r]=dp[r]+char('0'+digit);
            }
        }
    }
    return "0";
}
isme tle aa raha h par platform ka mistake h

just to be safe

string Solution::multiple(int N) {
    if(N==1) return "1";
    vector<int> p(N,-1);//parent state
    vector<int> s(N,-1);//step from parent to current
    //BFS
    int steps[2] = {0,1};
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        if(curr==0) break;
        for(int step: steps){
            int next = (curr*10+step)%N;
            if(p[next]==-1){
                p[next]=curr;
                s[next]=step;
                q.push(next);
            }
        }
    }
    //build reversed string
    string number;
    for(int it=0; it!=1; it=p[it])
        number.push_back('0'+s[it]);
    number.push_back('1');
    //return the reverse if it
    return string(number.rbegin(), number.rend());
}
