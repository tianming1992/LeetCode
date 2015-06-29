#include<string>

using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		if (p.size() == 0) return s.size() == 0;

		if (p.size() == 1) return s.size() == 1 && (s[0] == p[0] || p[0] == '.');

		//patern字符串的长度大于1

		if (p[1] == '*')//*代表该字符的前缀能重复任意次
		{
			if (isMatch(s, p.substr(2, p.size()))) return true; //如果*前缀重复0次 即s与*之后的模式串匹配
			else
			{
				//*前缀至少重复一次
				if (s.size() > 0 && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1, s.size()), p))
				{
					return true;
				}
			}
		}
		else
		{
			if (s.size()> 0 && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1, s.size()), p.substr(1, p.size())))
				return true;
		}
		return false;

	}
};

int main()
{
	Solution s;
	s.isMatch("aaa", "a*");
	return 0;
}