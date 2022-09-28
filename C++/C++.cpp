#include <iostream>
#include<fstream>

using namespace std;

void Test()
{

}

void memset(void* src, char val, size_t count) {
	int i;
	for (i = 0; i < count; ++i)
	{
		*((char*)src + i) = val;
	}
	*((char*)src + i) = '\0';
}

void memcpy(void* src, void* dest) { 
	int i;
	for (i = 0; *((char*)src + i) != '\0'; ++i)
	{
		*((char*)dest + i) = *((char*)src + i);
	}
	*((char*)dest + i) = '\0';
}

void memcpy(void* src, void* dest, size_t size) {
	for (int i = 0; i <= size; ++i)
	{
		*((char*)dest + i) = *((char*)src + i);
	}
}

int main()
{
	char x[100];
	int i = 0, k = 0;
	ofstream f("C:\\Users\\artyom\\OneDrive\\Рабочий стол\\new_file.txt");
	ifstream g("C:\\Users\\artyom\\OneDrive\\Рабочий стол\\ar.txt");
	if (!g.is_open())
		cout << "Can't open file!\n";
	if (!f.is_open())
		cout << "Can't create file!\n";
	while (!g.eof())
	{
		g >> x[i];
		i++;

	}

	for (int j = 0; j < i; j++)
	{
		if (x[j] == ' ' || x[j] == ',')
			k++;
		else
			k = 0;
		if (k > 1)
			continue;
		else if (k == 1) {
			f << endl;
			continue;
		}
		f << x[j];
	}
}
