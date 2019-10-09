//sorting a vector pair in ascending order as per vec.second
bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
} 

// While using it in code, use:
sort(nums.begin(),nums.end(),sortBySec);
