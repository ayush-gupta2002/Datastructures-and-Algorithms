vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    int n = A.size();
    int m = B.size();
    int i =0;
    int j = 0;
    
    vector<int> answer;
    while(i < n && j < m){
        if(A[i] < B[j]){
            i++;
        }
        else if(A[i] > B[j]){
            j++;
        }
        else{
            answer.push_back(A[i]);
            i++;
            j++;
        }
    }
    return answer;
}
