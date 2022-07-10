lui x1, 0
lui x2, 1048575

beq x1, x2, L1
beq x2, x1, L1

mul x0, x2, x2
sub x1, x0, x2
sub x1, x0, x1

beq x1, x2, L2

L1:
and x2, x2, x2
add x3, x2, x2
beq x2, x2, L3

L2:
lui x2, 1048575
add x2, x1, x0
beq x1, x2, L1

L3:
lui x1, 0
lui x2, 1048575
add x3, x0, x2

bne x2, x3, L10
bne x2, x2, L10

mul x0, x2, x2
sub x1, x0, x1

bne x1, x2, L20

L10:
and x2, x2, x2
add x3, x2, x2
addi x3, x3, -1
bne x2, x2, L30

L20:
lui x2, 1048575
add x2, x1, x0
bne x0, x2, L10

L30:
lui x1, 0
lui x2, 1048575
add x3, x0, x2

blt x2, x3, L100
blt x2, x2, L100

mul x0, x2, x2
sub x1, x0, x1

lui x1, 1
blt x2, x1, L200
blt x1, x2, L200

L100:
and x2, x2, x2
add x3, x2, x2
addi x4, x3, -1
blt x4, x3, L300

L200:
lui x2, 1048575
add x2, x1, x0
blt x0, x2, L100

L300:
lui x1, 2
lui x2, 1048575

bge x1, x2, L1000
addi x4, x0, 1
bge x4, x2, L1000

mul x0, x2, x2
sub x1, x0, x1

lui x1, 1
bge x2, x2, L2000

L1000:
and x2, x2, x2
add x3, x2, x2
addi x4, x3, -1
bge x3, x4, L3000

L2000:
lui x2, 1048575
lui x3, 1
bge x2, x3, L1000

L3000:
lui x1, 0
lui x2, 1048575
add x3, x0, x2

bltu x2, x3, L10000
bltu x2, x2, L10000

mul x0, x2, x2
sub x1, x0, x1

lui x1, 1
bltu x2, x1, L20000
bltu x1, x2, L20000

L10000:
and x2, x2, x2
add x3, x2, x2
addi x4, x3, -1
bltu x4, x3, L30000

L20000:
lui x2, 1048575
add x2, x1, x0
bltu x0, x2, L10000

L30000:
lui x1, 2
lui x2, 1048575

bgeu x1, x2, L100000
addi x4, x0, 1
bgeu x4, x2, L100000

mul x0, x2, x2
sub x1, x0, x1

lui x1, 1
bgeu x2, x2, L200000

L100000:
and x2, x2, x2
add x3, x2, x2
addi x4, x3, -1
bgeu x3, x4, L300000

L200000:
lui x2, 1048575
lui x3, 1
bgeu x2, x3, L100000

L300000: