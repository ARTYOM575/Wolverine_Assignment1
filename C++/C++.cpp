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
	char x;
	ofstream dest("C:\\Users\\artyom\\OneDrive\\Рабочий стол\\new_file.txt");
	ifstream src("C:\\Users\\artyom\\OneDrive\\Рабочий стол\\ar.txt");
	if (!src.is_open())
		cout << "Can't open file!\n";
	if (!dest.is_open())
		cout << "Can't create file!\n";
	while (!src.eof())
	{
		src.get(x);
		if (x != ' ' && x != ',' && x != '\n')
		{
			while (!src.eof() && x != ' ' && x != ',' && x != '\n')
			{
				dest << x;
				src.get(x);
			}
			dest << '\n';
		}
	}
	src.close();
	dest.close();
}