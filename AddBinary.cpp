class Solution {
public:
    int valueAt(string a, int i) {
        if (i >= a.size() || i < 0) { return 0; }
        return a[i] - '0';
    }

    string addBinary(string a, string b) {
        int m = a.size(), n = b.size();
        if (m == 0) { return b; }
        if (n == 0) { return a; }
        
        int carry = 0;
        string c = "";
        for (int i = 0; i < max(m, n); ++i) {
            int cur = valueAt(a, m-i-1) + valueAt(b, n-i-1) + carry;
            carry = cur / 2;
            if (cur % 2 == 0) { c.append("0"); }
            else { c.append("1"); }
        }

        if (carry) { c.append("1"); }

        reverse(c.begin(), c.end());

        return c;
    }
};

class Solution {
public:
    int valueAt(string a, int i) {
        if (i >= a.size() || i < 0) { return 0; }
        return a[i] - '0';
    }

    string addBinary(string a, string b) {
        int m = a.size(), n = b.size();
        if (m == 0) { return b; }
        if (n == 0) { return a; }
        
        int carry = 0;
        string c = "";
        for (int i = 0; i < max(m, n); ++i) {
            int cur = valueAt(a, m-i-1) + valueAt(b, n-i-1) + carry;
            carry = cur / 2;
            if (cur % 2 == 0) { c.append("0"); }
            else { c.append("1"); }
        }

        if (carry) { c.append("1"); }

        return string(c.rbegin(), c.rend());
    }
};