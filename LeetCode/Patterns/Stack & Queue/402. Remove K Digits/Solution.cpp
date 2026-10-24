class Solution {
public:
    string removeKdigits(string nums, int k) {
    stack<char> st;
int n = nums.size();

for (int i = 0; i < n; i++) {
    while (!st.empty() && k > 0 &&
           st.top() > nums[i]) {
        st.pop();
        k--;
    }
    st.push(nums[i]);
}

// Remove remaining digits from the end
while (k > 0 && !st.empty()) {
    st.pop();
    k--;
}

string res = "";

while (!st.empty()) {
    res.push_back(st.top());
    st.pop();
}

// Remove leading zeros from the result
reverse(res.begin(), res.end());

int i = 0;
while (i < res.size() && res[i] == '0') {
    i++;
}

res = res.substr(i);

if (res.empty()) return "0";

return res;
    }
};