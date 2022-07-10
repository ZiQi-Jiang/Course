addi x25, x0, 255

addi x5, x0, 1

add x8, x2, x0

addi x26, x0, 240

sb x25, 1(x26)

add x25, x25, x5

sb x25, 0(x26)

add x25, x25, x5

sb x25, 1(x26)

add x25, x25, x5

sb x25, 2(x26)

add x25, x25, x5

sb x25, 3(x26)

add x25, x25, x5

sb x25, 4(x26)

lb x18, 0(x26)

lb x19, 1(x26)

lb x18, 2(x26)

lb x19, 3(x26)

lb x19, 4(x26)

addi x25, x25, 100

add x25, x25, x5

sb x25, 4(x26)

lh x20, 4(x26)

add x25, x25, x5

sb x25, 8(x26)

lh x20, 8(x26)

addi x26, x0, 280

slli x24, x25, 8

add x25, x25, x5

sh x25, 0(x26)

lh x23, 0(x26)

addi x26, x0, 280

addi x6, x0, 255

add x25, x25, x5

sw x25, 8(x26)

add x25, x25, x5

sw x25, 12(x26)

add x25, x25, x5

sw x25, 16(x26)

lw x6, 8(x26)

lw x7, 12(x26)

lw x28, 16(x26)

or x23, x24, x25

slli x22, x23, 16

or x21, x22, x23

lw x8, 4(x26)

lh x9, 6(x26)

lb x18, 7(x26)

lb x19, 8(x26)

add x10, x9, x18

addi x5, x0, -10

addi x6, x0, 1000

auipc x30, 0

label:

addi x5, x5, 1

bge x5, x0, end

jalr x0, x30, 0

add x10, x20, x20

end:

add x10, x20, x20
