addi x27, x0, 100

addi x5, x0, 200

addi x6, x0, 1

loop1:

sw x6, 0(x27)

addi x6, x6, 1

addi x27, x27, 4

addi x5, x5, -1

bge x5, x0, loop1



addi x5, x0, 200
loop2:

lw x7, 0(x27)

addi x6, x6, 1

addi x27, x27, -4

addi x5, x5, -1

bge x5, x0, loop2
addi x1, x1, 0
