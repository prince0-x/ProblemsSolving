class Solution {
public:
    struct Offer {
        long long price;
        long long freeCopies;
    };

    int maximumSaleItems(vector<vector<int>>& items, int budget) {

        int n = items.size();

        vector<int> factorCount(n + 1, 0);
        vector<int> divisibleCount(n + 1, 0);

        long long cheapestPrice = LLONG_MAX;

        for (auto &item : items) {
            int factor = item[0];
            int price  = item[1];

            factorCount[factor]++;
            cheapestPrice = min(cheapestPrice, (long long)price);
        }

        //----------------------------------
        // Sieve:
        // divisibleCount[f]
        // = number of items whose factor
        // is divisible by f
        //----------------------------------

        for (int f = 1; f <= n; f++) {

            for (int multiple = f;
                 multiple <= n;
                 multiple += f) {

                divisibleCount[f] += factorCount[multiple];
            }
        }

        vector<Offer> offers;

        for (auto &item : items) {

            int factor = item[0];
            int price  = item[1];

            long long freeCopies =
                divisibleCount[factor] - 1;

            if (freeCopies > 0) {
                offers.push_back({price, freeCopies});
            }
        }

        //----------------------------------
        // Best efficiency first:
        // maximize 2/price
        //----------------------------------

        sort(offers.begin(), offers.end(),
             [](const Offer& a,
                const Offer& b) {

                return a.price < b.price;
             });

        long long answer = 0;

        for (auto &offer : offers) {

            long long price = offer.price;
            long long limit = offer.freeCopies;

            if (budget < price)
                continue;

            //----------------------------------
            // Compare:
            // profitable purchase => 2/price
            // cheapest normal buy => 1/minPrice
            //----------------------------------

            if (2 * cheapestPrice < price)
                break;

            long long canAfford = budget / price;

            long long buy =
                min(canAfford, limit);

            answer += 2 * buy;

            budget -= buy * price;
        }

        //----------------------------------
        // Spend remaining money
        // on cheapest item
        //----------------------------------

        answer += budget / cheapestPrice;

        return (int)answer;
    }
};