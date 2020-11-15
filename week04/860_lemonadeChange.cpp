//
// Created by lewang on 11/15/20.
//

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int size = bills.size();
        int five = 0, ten = 0;
        for(int  i = 0; i < size; i++) {
            if(bills[i] == 5) {
                five ++;
            }else if(bills[i] == 10){
                if(five < 1){
                    return false;
                }
                ten ++;
                five --;
            }else if(bills[i] == 20){
                if(ten > 0&& five > 0){
                    ten --;
                    five --;
                }else if(five > 2){
                    five -=3;
                }else return false;
            }
        }
        return true;
    }
};
