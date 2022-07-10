addi a0, a0, 2047
addi a1, x0, -2048

addi, a2, a2, 2047

blt a2, a2, L1
blt a0, a1, L1
add a3, a2, a2
L1: