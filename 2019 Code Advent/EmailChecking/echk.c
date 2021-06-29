#include <stdio.h>
#include <string.h>

int email_chk(char * str, size_t sz)
{
	int at_offset = 0, dot_flag = 0;

	if ((str[sz - 1] == '.') || (str[sz - 1] == '@')) {
		return 4; //Invalid terminating character
	}

	for (int i = 0; i < sz; i++) //Scan string for one and only one '@' character
	{
		if (str[i] == '@')
		{
			if ((!at_offset) && (i != 0))	{
				at_offset = i;
			}
			else {
				return 1; //Duplicate or initial '@'
			}
		}
	}

	for (int i = at_offset; i < sz; i++) //Scan after the @ for at least one '.'
	{
		if (str[i] == '.')	{
			dot_flag = 1;
			break;
		}
	}

	//Error Handling Block
	if (!dot_flag) {
		return 2; //No '.' in the domain
	}
	if (!at_offset) {
		return 3; //Missing '@'
	}

	return 0; //Clean
}

int main()
{
	char str[256];
	printf("Enter an email address: \n");
	scanf("%255s", str);

	switch (email_chk(str, strlen(str)))
	{
	case 0:
		printf("\nThis is a valid E-Mail Address.\n");
		break;
	case 1:
		printf("\nE-Mail Invalid: There was more than one \'@\', or it was the first character.\n");
		break;
	case 2:
		printf("\nE-Mail Invalid: There was no \'.\' in the domain.\n");
		break;
	case 3:
		printf("\nE-Mail Invalid: There was no \'@\' in the domain.\n");
		break;
	case 4:
		printf("\nE-Mail Invalid: Invalid terminating character.\n");
		break;
	default:
		printf("\nE-Mail Invalid: An unidentified error occured.\n");
		break;
	}

	return 0;
}