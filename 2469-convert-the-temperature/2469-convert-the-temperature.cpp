class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        vector<double> res;
        double k=celsius+273.15;
        res.push_back(k);
        double j=(double(celsius*1.80))+32.00;
        res.push_back(j);
        return res;
    }
};