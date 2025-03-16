class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        // The minimum possible time is 1,
        // and the maximum possible time is when the slowest mechanic (highest
        // rank) repairs all cars.
        long long low = 1, high = 1LL * cars * cars * ranks[0];

        // Perform binary search to find the minimum time required.
        while (low <= high) {
            long long mid = (high + low) / 2, carsRepaired = 0;

            for (auto rank : ranks) carsRepaired += sqrt(1.0 * mid / rank);
            if (carsRepaired < cars)
                low = mid + 1;
            else
                high = mid-1;
        }

        return low;
    }
};