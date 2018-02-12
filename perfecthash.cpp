//Студент Групи К-29 Михед Олександр Михайлович
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;
int main()
{
	
	string str;
	cout << "Enter string (a-z, A-Z)[max 12 simbols]: " << endl;
	while (cin >> str)
	{
		__int64 buf1=1, buf2=0;
		unsigned __int64 hash=0;
		bool nL = false;
		if (str.size() < 13)
		{
			for (unsigned int i = 0; i < str.size(); ++i)
			{
				buf2 = int(str[i]);
				if (buf2 == 32) buf2 = 0;
				else if (buf2 > 64 && buf2 <91) buf2 -= 38;
				else if (buf2 > 96 && buf2 <123) buf2 -= 96;
				else {nL = true; break;}
				hash = hash + buf1*buf2;
				buf1 *= 54;
			}
			if (nL) cout << "incorect simbol" << endl;
			cout.width(20);
			cout.fill('0');
			cout << hash << endl;
		}
		else cout << "to long string" << endl;
	}
}
