class Solution {
public:
/*Greedy Restart
Maintain:
- running state (petrol)

If running state becomes invalid:
    Throw away the entire prefix
    Restart from the next position

Finally verify:
    Global condition (total gas >= total cost)*/

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0;
        int totalCost = 0;

        int petrol = 0;
        int start = 0;

        for(int i = 0; i < gas.size(); i++) {

            totalGas += gas[i];
            totalCost += cost[i];

            petrol += gas[i];
            petrol -= cost[i];

            if(petrol < 0) {
                start = i + 1;
                petrol = 0;
            }
        }

        if(totalGas < totalCost)
            return -1;

        return start;
    }
};