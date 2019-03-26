#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <set>
using namespace std;
char str[10000 + 1];
map<int, int>dm;
set<int>ds;
map<int, int>jm;
set<int>js;
map<int, int>im;
set<int>is;
int main()
{
	int t = 0;
	scanf("%d\n", &t);
	while (t--)
	{
		memset(str, 0, sizeof(str));
		gets(str);
		dm.clear(), ds.clear();
		jm.clear(),js.clear();
		im.clear(),is.clear();
		int reset = 0;
		for (int i = 0; i < strlen(str); i++)
		{
			if (str[i] == 'd')
			{
				dm[i] = 0;
				ds.insert(i);
				
			}
			if (str[i] == 'j')
			{
				for (set<int>::iterator it = ds.begin(); it != ds.end(); it++)
				{
					dm[*it]++;
				}
				jm[i] = 0;
				js.insert(i);
				
			}
			if (str[i] == 'i')
			{
				for (set<int>::iterator it = js.begin(); it != js.end(); it++)
				{
					jm[*it]++;
				}
			}
		}
		for (set<int>::iterator itd = ds.begin(); itd != ds.end(); itd++)
		{
			for (set<int>::iterator itj = js.begin(); itj != js.end(); itj++)
			{
				if (*itj > *itd)
				{
					reset +=jm[*itj];
				}
			}
		}
		printf("%d\n", reset);
	}
	return 0;
}