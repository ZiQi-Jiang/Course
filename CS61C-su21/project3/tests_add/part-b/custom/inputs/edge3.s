addi a0, x0, 2

addi a1, x0, 31

addi a2, x0, 1

loop:

mul a2, a2, a0

addi a1, a1, -1

bge a1, x0, loop

slli x6, x5, 31
srli x6, x5, 31