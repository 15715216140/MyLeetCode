537. Complex Number Multiplication
DescriptionHintsSubmissionsDiscussSolution
Given two strings representing two complex numbers.

You need to return a string representing their multiplication.
 Note i2 = -1 according to the definition.

Example 1:
Input: "1+1i", "1+1i"
Output: "0+2i"
Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, 
and you need convert it to the form of 0+2i.
Example 2:
Input: "1+-1i", "1+-1i"
Output: "0+-2i"
Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i,
 and you need convert it to the form of 0+-2i.
Note:

The input strings will not have extra blank.
The input strings will be given in the form of a+bi, 
where the integer a and b will both belong to the range of [-100, 100].
 And the output should be also in this form.

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int t = 0, a1, a2, b1 ,b2,ans1,ans2;
        for(int i = 0; a[i] != '+'; i++)
            if(a[i] != '+') t++;
        a1 = stoi(a.substr(0,t));
        a2 = stoi(a.substr(t+1,a.size()-t-2)); 
        t = 0;
        for(int i = 0; b[i] != '+'; i++)
            if(b[i] != '+') t++;
        b1 = stoi(b.substr(0,t));
        b2 = stoi(b.substr(t+1,b.size()-t-2));
        ans1 = a1*b1-a2*b2;
        ans2 = a1*b2+a2*b1;
        string s,s1,s2;
        s1 = to_string(ans1);
        s2 = to_string(ans2);
        s = s+ s1 +'+' + s2+'i';
        return s;
        
    }
}

string complexNumberMultiply(string a, string b) {
    char t[200];
    int m, n, p, q;
    sscanf(a.c_str(), "%d+%di", &m, &n);
    sscanf(b.c_str(), "%d+%di", &p, &q);
    sprintf(t, "%d+%di", (m*p-n*q), (n*p+m*q));
    string ans = t;
    return ans;
}

