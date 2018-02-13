//Студент Групи К-29 Михед Олександр Михайлович
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;
int main()
{
	
	string str;
	string result;
	cout << "Enter string (a-z, A-Z, [Space]): " << endl;
	while (getline(cin, str))
	{
		result.clear();
		bool nL = false;
		for (unsigned int i = 0; i < str.size(); ++i)
		{
				
			if (str[i] == 32) result.append("00");
			else if (str[i] >= 'A' && str[i] <= 'Z') result.append(to_string(int(str[i]) - 28));
			else if (str[i] >= 'a' && str[i] <= 'z') result.append(to_string(int(str[i]) - 86));
			else if (str[i] >= '0' && str[i] <= '9') result.append(to_string(int(str[i]) + 15));
			else {nL = true; break;}
		}
		if (nL) cout << "incorect simbol" << endl;
		else cout << result << endl;
	}
}
