#include<string>

using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		if (p.size() == 0) return s.size() == 0;

		if (p.size() == 1) return s.size() == 1 && (s[0] == p[0] || p[0] == '.');

		//patern�ַ����ĳ��ȴ���1

		if (p[1] == '*')//*������ַ���ǰ׺���ظ������
		{
			if (isMatch(s, p.substr(2, p.size()))) return true; //���*ǰ׺�ظ�0�� ��s��*֮���ģʽ��ƥ��
			else
			{
				//*ǰ׺�����ظ�һ��
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