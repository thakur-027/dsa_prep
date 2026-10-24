class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        auto getDayOfYear = [&](string date) {
            int month = stoi(date.substr(0, 2));
            int day = stoi(date.substr(3, 2));
            int days = 0;
            for (int i = 0; i < month - 1; ++i) {
                days += daysInMonth[i];
            }
            return days + day;
        };
        
        int aStart = getDayOfYear(arriveAlice);
        int aEnd = getDayOfYear(leaveAlice);
        int bStart = getDayOfYear(arriveBob);
        int bEnd = getDayOfYear(leaveBob);
        
        int overlapStart = max(aStart, bStart);
        int overlapEnd = min(aEnd, bEnd);
        
        return max(0, overlapEnd - overlapStart + 1);
    }
};
