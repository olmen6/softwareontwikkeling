#include <stdio.h>
#include <string.h>

char str[] = "tekst,10,20, wit,the quick brown fox jumps over the lazy dog, consolas, 1, normaal\n";

int main()
{

	parser(str);
	
    return (0);
}

int parser(char* msg)
{
	char* token;
	const char delim = ",";
	
	//eerste token
	char* token = strtok_r(msg, delim, &msg);
	//al de andere tokens
	char i = 0;
	for (i=0; i<9; i++)
	{
		if (token != NULL)
		{
			
		} else (return (0))
	}
    
    return (0);
}
