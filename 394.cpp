class Solution {
public:

    string decodeString(string s) {
        stack<pair<int, string>> ans_helper;
        string ans = "";
        int i = 0;
        while(i < s.length()) {
            // Number and empty string
            if(s[i] - '0' <= 9 && s[i] - '0' >= 0) {
                int num_begin = i;
                while(s[i] - '0' <= 9 && s[i] - '0' >= 0)
                    i++;
                int number = stoi(s.substr(num_begin, i-num_begin));
                ans_helper.push({number, ""});
                continue;
            }
            if(s[i] - 'a' >= 0 && s[i] - 'a' <= 26) {
                int str_begin = i;
                while(s[i] - 'a' >= 0 && s[i] - 'a' <= 26)
                    i++;
                string curr_string = s.substr(str_begin, i-str_begin);
                if(!ans_helper.empty()) {
                    ans_helper.top().second += curr_string;
                }
                else {
                    ans += curr_string;
                }
                continue;
            }
            if(s[i] == ']') {
                pair<int, string> el = ans_helper.top();
                ans_helper.pop();
                string new_string;
                while(el.first--)
                    new_string += el.second;
                if(ans_helper.empty())
                    ans += new_string;
                else
                    ans_helper.top().second += new_string;
                i++;
            }
            else
                i++;
        }
        return ans;
    }
};
