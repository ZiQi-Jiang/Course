
main.o:     file format elf64-littleriscv


Disassembly of section .text.start_kernel:

0000000000000000 <start_kernel>:
   0:	ff010113          	addi	sp,sp,-16

0000000000000004 <.LCFI0>:
   4:	7e500513          	li	a0,2021
   8:	00113423          	sd	ra,8(sp)
   c:	00000097          	auipc	ra,0x0
  10:	000080e7          	jalr	ra # c <.LCFI0+0x8>

0000000000000014 <.LVL0>:
  14:	00000517          	auipc	a0,0x0
  18:	00050513          	mv	a0,a0
  1c:	00000097          	auipc	ra,0x0
  20:	000080e7          	jalr	ra # 1c <.LVL0+0x8>

0000000000000024 <.LVL1>:
  24:	00000097          	auipc	ra,0x0
  28:	000080e7          	jalr	ra # 24 <.LVL1>

000000000000002c <.LVL2>:
  2c:	00813083          	ld	ra,8(sp)
  30:	00000513          	li	a0,0
  34:	01010113          	addi	sp,sp,16

0000000000000038 <.LCFI1>:
  38:	00008067          	ret
