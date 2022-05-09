class Solution {
  public:
    string replaceSpaces(string &str) {
        string res;
        for (auto c : str)
            if (c == ' ')
                res += "%20";
            else
                res += c;
        return res;
    }
};
