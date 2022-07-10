addi s2, x0, 2047
addi s3, x0, -2048 

lui s4, 1048575
srai s3, s3, 11
srli s4, s3, 1

addi s5, x0, 1
