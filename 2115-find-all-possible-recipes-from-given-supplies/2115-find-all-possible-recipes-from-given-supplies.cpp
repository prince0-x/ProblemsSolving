class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
    unordered_set<string> available(supplies.begin(), supplies.end());
    queue<int> recipe_queue;
    
    for (int index = 0; index < recipes.size(); index++) {
        recipe_queue.push(index);
    }

    vector<string> ans;
    int lastsize =-1;
    while (recipe_queue.size()!=lastsize)// Correct condition
    {
        lastsize = recipe_queue.size();
        int itemsize = recipe_queue.size();
        while (itemsize-- > 0) {
            int rindex = recipe_queue.front();
            recipe_queue.pop();
            bool got_result = true;

            for (auto ingredient : ingredients[rindex]) {
                if (!available.count(ingredient)) {
                    got_result = false;
                    break;
                }
            }

            if (got_result) {
                ans.push_back(recipes[rindex]);
                available.insert(recipes[rindex]);  // ✅ Add the prepared recipe to available
            } else {
                recipe_queue.push(rindex);
            }
        }
    }
    return ans;
}

};
