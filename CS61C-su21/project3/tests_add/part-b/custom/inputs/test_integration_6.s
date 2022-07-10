addi s1 x0 10
addi t0 x0 0
addi t1 x0 0
loop_begin:
beq s1 x0 end_loop
mul t0 s1 s1
add t0 t0 t0
addi s1 s1 -2
jal x0, loop_begin
  
end_loop:
addi a0 x0 0