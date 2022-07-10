addi a0, a0, 2047
addi a1, x0, -2048

addi, a2, a2, 2047

bltu a2, a2, L1
bltu a0, a1, L1
add a3, a2, a2
L1: