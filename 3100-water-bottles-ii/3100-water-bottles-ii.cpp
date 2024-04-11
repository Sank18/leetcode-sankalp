class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int sum=0;
        int empty=numBottles;
        numBottles=0;
        sum=sum+empty;
        while(empty>=numExchange)
        {
            
            while(empty>=numExchange)
            {
                empty=empty-numExchange;
                numExchange++;
                numBottles++;
            }
            empty=empty+numBottles;
            sum=sum+numBottles;
            numBottles=0;
            
            
        }
        return sum;
        
    }
};