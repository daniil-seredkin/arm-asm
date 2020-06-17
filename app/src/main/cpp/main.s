  .text
  .align 2
  .global program_main
  .type program_main, %function
program_main:
    adrp x0, message
	bl print
	ret
  .size program_main, .-program_main

   .data
message:
   .asciz "Hello, world\n"