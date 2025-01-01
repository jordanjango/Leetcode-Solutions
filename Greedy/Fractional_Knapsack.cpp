class Solution {
  public:
    //we need to compare the profit/weight and sort the values
    static bool comp(Item a,Item b){
        double i1 = (double)a.value/a.weight;
        double i2 = (double)b.value/b.weight;
        return i1>i2;
    }
  
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        vector<Item> item;
        double maxProfit = 0.0;
        for(int i = 0;i<val.size();i++){
            item.push_back({val[i],wt[i]});
        }
        //let's sort the items
        sort(item.begin(),item.end(),comp);
        //now we need to loop over the items
        for(int i=0;i<items.size();i++){
            if(items[i].weight<=capacity){
                maxProfit+=items[i].value;
                weight-=items[i].weight;
            }else{
                double fraction = (double)capacity/items[i].weight;
                finalValue+=items[i].value*fraction;
                break;
            }
        }
        return maxProfit;
    }
};