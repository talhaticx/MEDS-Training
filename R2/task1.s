.globl main

.data
a:  .word 7
b:  .word 0, 0, 0

.text
main:
    li   s0, 0          # i = 0
    lw   s1, a          # s1 = a (7)
    la   s2, b          # s2 = base address of b

loop:
    addi t0, x0, 3
    bge  s0, t0, finish  # if i >= 3, exit loop

    mul  t0, s0, s1     # t0 = i * a
    add  t1, s1, t0     # t1 = a + (i * a)

    slli t2, s0, 2      # offset = i * 4 (word offset)
    add  t3, s2, t2     # address of b[i]
    sw   t1, 0(t3)      # b[i] = result

    addi s0, s0, 1      # i++
    jal   x0, loop      # repeat

finish:
    jal print_b

exit:
    li  a0, 10
    ecall


print_b:
    li   s0, 0          # i = 0

loop_print:
    addi t0, x0, 3
    bge  s0, t0, exit    # if i >= 3, done printing

    slli t0, s0, 2      # offset = i * 4
    add  t1, s2, t0     # address of b[i]
    lw   a1, 0(t1)      # load b[i] into a1
    li   a0, 1          # syscall: print integer
    ecall

    # print space
    li   a1, 10         # ASCII for \n
    li   a0, 11         # syscall: print char
    ecall

    addi s0, s0, 1
    jal   x0, loop_print
