class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        int n=timePoints.size();
        for(int i=0;i<n;i++)
        {
          string curr=timePoints[i];
          int hour=stoi(curr.substr(0,2));
          int min=stoi(curr.substr(3,2));
         int totalminutes=hour*60+min;
         minutes.push_back(totalminutes);
        }
        //step-2 sort
        sort(minutes.begin(),minutes.end());
        //difference and calculate minimum difference
        int mini=INT_MAX;
        int m=minutes.size();
        for(int i=0;i<m-1;i++)
        {
            int difference=minutes[i+1]-minutes[i];
            mini=min(mini,difference);
        }
          //something missing - THIS IS THE GAME
        int lastDiff1 = (minutes[0] + 1440) - minutes[n-1];
        int lastDiff2 = minutes[n-1] - minutes[0];
        int lastDiff = min(lastDiff1, lastDiff2);
        mini = min(mini, lastDiff);

        return mini;
    }
};