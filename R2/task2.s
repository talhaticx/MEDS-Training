.globl main

.data
num:    .word 5           # int num = 5;

.text

# int sub(int a, int b)
sub:
    sub a0, a0, a1        # return a - b
    jr  ra                # return to caller

# int compare(int a, int b)
compare:
    addi sp, sp, -4       # allocate space to save return address
    sw   ra, 0(sp)        # save return address

    jal  ra, sub          # call sub(a, b), result in a0

    bge  a0, x0, comp_true # if (a - b) >= 0, return 1
    li   a0, 0            # else return 0
    jal  comp_done

comp_true:
    li   a0, 1            # return 1

comp_done:
    lw   ra, 0(sp)        # restore return address
    addi sp, sp, 4        # free stack space
    jr   ra               # return to caller

# void dataArray(int num)
main:
dataArray:
    addi sp, sp, -48      # allocate 48 bytes: 4 (ra) + 40 (array[10]) + 4 (alignment)
    sw   ra, 0(sp)        # save return address

    mv   s0, x0           # i = 0
    lw   a0, num          # load num into a0 (used later for comparison)

loop:
    li   t0, 10           
    bge  s0, t0, done     # if i >= 10, exit loop

    lw   a0, num          # a0 = num
    mv   a1, s0           # a1 = i
    jal  ra, compare      # call compare(num, i), result in a0

    slli t0, s0, 2        # offset = i * 4 (for word size)
    add  t1, sp, t0       # t1 = sp + offset
    addi t1, t1, 4        # adjust for saved ra (4 bytes)
    sw   a0, 0(t1)        # array[i] = result of compare

    addi s0, s0, 1        # i++
    jal  x0, loop         # jump to loop start

done:
    lw   ra, 0(sp)        # restore return address
    addi sp, sp, 48       # free 48 bytes stack
    jr   ra               # return from main
