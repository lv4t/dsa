.text
.global _start
_start:
	movia r2, dem
	movia r3, n
	ldw r4, (r2)
	ldw r5, (r3)
	movi r6, 0x1
FOR:
	andi r7,r6, 0x1
	beq r7, r0, TEST
	addi r4, r4, 0x1 
TEST:
	addi r6, r6, 0x1
	bge r6, r5, STOP_FOR
	br FOR
STOP_FOR:
	stw r4, (r2)
.data
dem: word 0
n: .word 10
.end