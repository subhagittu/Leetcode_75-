class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int len = piles.size();

        if (len == 1) {
            return ceil((double)piles[0] / h);
        }

        int max = -1, min = 1;

        for (int i = 0; i < len; i++) {
            if (max < piles[i]) {
                max = piles[i];
            }
        }

        if (len == h) {
            return max;
        }

        int speed, hoursNeeded, prevSpeed = -1;
        do {
            speed = (max + min) / 2;
            hoursNeeded = 0;

            if (speed == prevSpeed) {
                return speed + 1;
            }

            for (int i = 0; i < len; i++) {
                hoursNeeded += ceil((double)piles[i] / speed);
            }
            
            if (hoursNeeded > h) {
                min = speed;
            } else {
                if (speed == 1) {
                    return 1;
                }
                max = speed;
            }

            prevSpeed = speed;
        } while (true);

        return -1;
    }
};
