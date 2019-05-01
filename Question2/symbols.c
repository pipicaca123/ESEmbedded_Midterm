#include <stdint.h>

uint32_t global_var = 0x1234;
uint32_t gol_array[]={0xA, 0xB, 0xC, 0xD, 0xE, 0xF};
extern uint32_t _mydata_lma_start;
extern uint32_t _mydata_vma_start;

void symbols(void)
{
	uint32_t *sram_debug = (uint32_t *)0x20000200;

	sram_debug[0] = 0xAAAA;

	sram_debug[1] = global_var;
	sram_debug[2] = (uint32_t)&gol_array[0];
	sram_debug[3] = (uint32_t)&gol_array[1];
	sram_debug[4] = (uint32_t)&gol_array[2];
	sram_debug[5] = (uint32_t)&gol_array[3];
	sram_debug[6] = (uint32_t)&gol_array[4];
	sram_debug[7] = (uint32_t)&gol_array[5];
	sram_debug[8] = _mydata_lma_start;
	sram_debug[9] = (uint32_t)&_mydata_lma_start;

	sram_debug[10] = _mydata_vma_start;
	sram_debug[11] = (uint32_t)&_mydata_vma_start;

	while (1)
		;
}
