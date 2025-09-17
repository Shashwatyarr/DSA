
class FoodRatings
{
public:
    unordered_map<string, pair<int, string>> fcr;
    unordered_map<string, set<pair<int, string>>> cfr;
    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings)
    {
        for (int i = 0; i < foods.size(); i++)
        {
            fcr[foods[i]] = {ratings[i], cuisines[i]};
            cfr[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    void changeRating(string food, int newRating)
    {
        auto [oldRating, cuisine] = fcr[food];
        cfr[cuisine].erase({-oldRating, food});
        cfr[cuisine].insert({-newRating, food});
        fcr[food] = {newRating, cuisine};
    }
    string highestRated(string cuisine)
    {
        return cfr[cuisine].begin()->second;
    }
};
