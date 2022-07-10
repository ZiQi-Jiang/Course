addi a0, a0, 2047
addi a1, x0, -2048
addi, a2, a2, 2047

lui s4, 1048575

srai s3, s3, 11

srli s4, s3, 1

jal x1, L0
addi t0, x0, 3
L0:
addi t0, x0, 3
L1:
beq t0, x0 end

addi t0, t0, -1

jal x1, L1

end: