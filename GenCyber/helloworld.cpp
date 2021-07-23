#include <iostream>
//allows the user to type stuff in and print stuff to the screen
#include <cstdlib>
//This is a C Plus Plus C Standard Library that allows
//a user to calculate random numbers, do math operations, and format strings
using namespace std;

int main(){
    cout << "Hello, world!";
    return 0;
}

%include "/usr/local/share/csc314/asm_io.inc"
segment .data
segment .bss
segment .text
	global  asm_main
asm_main:
	push	ebp
	mov		ebp, esp
	; ********** CODE STARTS HERE **********
	mov eax, "Hello, world!"
	call print_string
	call print_nl
	; *********** CODE ENDS HERE ***********
	mov		eax, 0
	mov		esp, ebp
	pop		ebp
	ret


