lui x1, 0
lui x2, 1048575

mul x0, x2, x2
sub x1, x0, x2
and x2, x2, x2
add x3, x2, x2
sub x4, x0, x3
mul x5, x4, x3
sll x6, x5, x4
mulhu x7, x6, x5

lui x8, 1048575
sub x9, x0, x8

addi x10, x0, -1

and x11, x10, x9
or x11, x11, x11
or x12, x11, x10

sub x13, x10, x10

sll x14, x13, x10
addi x15, x0, -31

sll x16, x8, x15
mulh x17, x8, x8
mulhu x18, x17, x17

slt x19, x18, x18
sub x20, x0, x8
slt x21, x19, x20
slt x22, x20, x21
slt x23, x8, x8
addi x25, x0, 20
sll x24, x8, x25
xor x26, x24, x23
srl x27, x26, x25
sra x28, x27, x25
or x29, x28, x8
and x30, x29, x29
and x31, x30, x30
and x31, x8, x0
or x31, x8, x0
