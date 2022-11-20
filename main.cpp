#include "bst.h"

#include <fstream>
using namespace std;

int main(void)
{
	char oneC = '\0';
	string line;
	BST example=new BST(true);
	
	fstream convert;
	convert.open("Convert.txt", ios::in);
cout << "Converting characters of convert.txt into Morse Code " << endl;
	if (convert.is_open()) // if Convert.txt opened successfully
	{
		while (getline(convert, line)) // reads in the whole line
		{
		
			for (int i = 0; line[i] != NULL; ++i) // and then finds each character in said line
			{
				oneC = line[i];
				
				if (oneC != ' ') // if it is not a space, find the letter in the BST
				{
					oneC = toupper(oneC);
					cout << example.lookUp(oneC) << " ";
				}
				else // if it is a space, make it three spaces not just one
				{
					cout << "   ";
				}

			}
			cout << endl; // if there is more than one line, they will be separated by new lines
		}
	}
	else
	{
		cout << "Convert.txt failed to open!" << endl;
	}
}