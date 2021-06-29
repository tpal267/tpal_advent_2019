#include <stdio.h>
#include <vector>

int initialize_live_mem(int* rom, int* live_mem, size_t length = 0)
{
	for (size_t i = 0; i < length; i++)
	{
		live_mem[i] = rom[i];
	}

	return 0;
}

int iexec(int op, int a, int b, int c, int* mem)
{
	switch (op)
	{
	case 1:
		mem[c] = mem[a] + mem[b];
		break;
	case 2:
		mem[c] = mem[a] * mem[b];
		break;
	default:
		break;
	}
	return op;
}

int run_prog(int* mem, int ret_addr = 0)
{
	for (size_t i = 0; iexec(mem[i], mem[i + 1], mem[i + 2], mem[i + 3], mem) != 99; i += 4)
	{
		//printf("%d %d %d %d\n", mem[i], mem[i + 1], mem[i + 2], mem[i + 3]);
		ret_addr;
	}

	return mem[ret_addr];
}

int main()
{
	int rom[] = {	1,12,2,3,
						1,1,2,3,
						1,3,4,3,
						1,5,0,3,
						2,10,1,19,
						1,19,5,23,
						1,23,9,27,
						2,27,6,31,
						1,31,6,35,
						2,35,9,39,
						1,6,39,43,2,10,43,47,1,47,9,51,1,51,6,55,1,55,6,59,2,59,10,63,1,6,63,67,2,6,67,71,1,71,5,75,2,13,75,79,1,10,79,83,1,5,83,87,2,87,10,91,1,5,91,95,2,95,6,99,1,99,6,103,2,103,6,107,2,107,9,111,1,111,5,115,1,115,6,119,2,6,119,123,1,5,123,127,1,127,13,131,1,2,131,135,1,135,10,0,99,2,14,0,0 };

	int* live_memory = new int[sizeof(rom)/sizeof(rom[0])];

	
	int ret_code = 0;

	for (size_t i = 0; i < 100; i++)
	{
		for (size_t j = 0; j < 100; j++)
		{
			initialize_live_mem(rom, live_memory, (sizeof(rom) / sizeof(rom[0])));

			live_memory[1] = i;
			live_memory[2] = j;

			ret_code = run_prog(live_memory, 0);
			printf("%d %d %d\n", i, j, ret_code);
			if (ret_code == 19690720) {
				goto exit;
			}
		}
	}

	exit:

	
	int hold;
	scanf_s("%d", &hold);

	return 0;
}