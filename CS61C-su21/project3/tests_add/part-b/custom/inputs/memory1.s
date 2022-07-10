lui x1, 1048575
addi x22, x0, -1
addi x3, x0, 1
addi, x4, x0, 240
sb x22, 0(x4)
sb x1, 1(x4)
sb x3, 2(x4)
sb x3, 3(x4)
sb x3, 4(x4)
addi sp, sp, -12
sh x22, 0(sp)
sh x1, 1(sp)
sh x3, 2(sp)
sw x22, 0(sp)
sw x3, 4(sp)
sw x4, 8(sp)
lb x5, 0(x4)
lb x6, 1(x4)
lb x7, 2(x4)
lb x8, 3(x4)
lb x20, 4(x4)
lh x9, 0(sp)
lh x10, 1(sp)
lh x11, 2(sp)

lw x12, 0(sp)
lw x13, 4(sp)
lw x14, 8(sp)

addi sp, sp, 12
