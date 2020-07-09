
There are n engineers numbered from 1 to n and two arrays: speed and efficiency, where speed[i] and efficiency[i] represent the speed and efficiency for the i-th engineer respectively.
 Return the maximum performance of a team composed of at most k engineers, since the answer can be a huge number, return this modulo 10^9 + 7.

The performance of a team is the sum of their engineers' speeds multiplied by the minimum efficiency among their engineers

Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 2
Output: 60

We have the maximum performance of the team by selecting engineer 2 (with speed=10 and efficiency=4) and engineer 5 (with speed=5 and efficiency=7). 
That is, performance = (10 + 5) * min(4, 7) = 60.


For a given efficiency, we pick all workers with the same or better efficiency. If the number of workers is greater than k, we pick k fastest workers.

Algorigthm
Sort workers based on their efficiency. Starting from the most efficient worker, compute and track the maximum performance. We can use a running sum to track all workers' speed.

When the amount of available workers exceeds k, remove the 'slowest' worker from sum. To do that, we can use a min heap.

int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
    vector<pair<int, int>> eff_sp;
    priority_queue <int, vector<int>, greater<int> > pq_speeds;
    long sum = 0, res = 0;
    for (auto i = 0; i < n; ++i)
        eff_sp.push_back({efficiency[i], speed[i]});  
    sort(begin(eff_sp), end(eff_sp));/*[{2,8},{3,3},{4,10},{5,2},{7,5},{9,1}]*/
    for (auto i = n - 1; i >= 0; --i) {
        sum += eff_sp[i].second;
        pq_speeds.push(eff_sp[i].second);
        if (pq_speeds.size() > k) {
            sum -= pq_speeds.top();
            pq_speeds.pop();
        }
        res = max(res, sum * eff_sp[i].first);
    }
    return res % 1000000007;
}

/* first iteration -- sum=1,queue=1,res=9
second iteration -- sum=6 queue=1 5 res=42
third iteration-- sum=7 queue=2 5 res=42
fourth iteration --sum=15 queue 5 10 res=60
and so on*/
