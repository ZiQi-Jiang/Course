addi a0, a0, 2047
addi a1, x0, -2048
addi, a2, a2, 2047

lui s4, 1048575

srai s3, s3, 11

srli s4, s3, 1

jal x1, L0
addi t0, x0, 3
L0:
and x2, x2, x2
jal x0, L1
add x3, x2, x2
L1:
jal x1, L2
sub x4, x0, x3
L2:
jal x2, L3
L5:
jal L00
mul x5, x4, x3
L4:
sll x6, x5, x4
jal x6, L5
mulhu x7, x6, x5
L3:
jal x3, L4
addi t0, x0, 3
L00:
beq t0, x0 end

addi t0, t0, -1

jal x1, L1

end: