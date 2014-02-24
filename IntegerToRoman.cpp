class Solution {
public:
    string intToRoman(int num) {
        // I=1, V=5, X=10, L=50, C=100, D=500, M=1000
        string res = "";
        
        res += digitToRoman(num/1000 % 10, 0, 0, 'M');
        res += digitToRoman(num/100 % 10, 'M', 'D', 'C');
        res += digitToRoman(num/10 % 10, 'C', 'L', 'X');
        res += digitToRoman(num % 10, 'X', 'V', 'I');
        
        return res;
    }
    
    string digitToRoman(int num, char ten, char five, char one) {
        string res = "";
        if (num == 9) {
            res += one; res += ten;
        } else if (num >= 5) {
            res += five;
            while (num-- > 5) res += one;
        } else if (num == 4) {
            res += one;
            res += five;
        } else if (num > 0) {
            while (num-- > 0) res += one;
        }
        
        return res;
    }
};