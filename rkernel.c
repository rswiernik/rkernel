/*
 * File: rkernel.asm
 * Author: Reed Swiernik
 */

void clear_screen();

void kmain(void){
	const char *str = "We have boot. Woah.";
	char *vidptr = (char*)0xb8000;

	clear_screen();
	unsigned int j = 0;
	unsigned int i = 0;
	while(str[j] != '\0') {
		vidptr[i] = str[j];
		vidptr[i+1] = 0x07;
		++j; i=i+2;
	}
	return;
}

void clear_screen(){
	char *vidptr = (char*)0xb8000;
	unsigned int j = 0;
	while(j < (80 * 25 * 2)){
		vidptr[j] = ' ';
		vidptr[j+1] = 0x07;
		j = j + 2;
	}
	return;
}
