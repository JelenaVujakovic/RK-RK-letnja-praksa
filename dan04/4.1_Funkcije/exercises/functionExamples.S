	.data
hello:
	.ascii "hello from assembly function\n"

	.global	printMessage
	.global sumAsm

	.text
	
printMessage:
  push {ip, lr}
  mov R7, #4
  mov R0, #1
  mov R2, #29
  ldr R1, =hello
  swi 0
  mov R7, #1
  swi 0
  pop {ip, pc}


sumAsm:
	push {ip, lr}
	add r0, r0, r1
	pop {ip, pc}
