class Solution{
  public:
    const int N = 100010;
    int S[N];
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy,int minutes){
      // minutes lenth range sum.
      // find max sum. 
      //
      
      S[0] = customers[0];
      for(int i=1;i<customers.size();i++){
        S[i] = S[i-1] + customers[i];
      }
      int maxValue;
      int index = -1
      for(int i=1;i<customers.size()-minutes;i++){
        if(S[i+minutes] - S[i-1] > maxValue){
            maxValue = S[i+minutes] - S[i-1];
            index = i;
        }
      
      }
      int target = 0;
      for(int i=0;i<index;i++){
        target += (grumpy[i] * customers[i]);
      }
      for(int i=index+minutes;i<customers.size();i++){
        target += (grumpy[i] * customers[i]);
      }

      return target;
    }}

