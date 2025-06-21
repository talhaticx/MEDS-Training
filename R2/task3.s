.globl _start

.text
_start:
    la  t0, num           # Load address of num
    lw  a0, 0(t0)         # Load num into a0 (32-bit load)

    call fact             # Call factorial

    la  t0, result        # Store result
    sw  a0, 0(t0)         # 32-bit store

    # Write result to tohost for logging
    sw  a0, tohost, t1

    j   write_tohost      # Spin here

fact:
    addi sp, sp, -8
    sw   ra, 0(sp)
    sw   s0, 4(sp)

    li   t0, 1
    ble  a0, t0, fact_base

    mv   s0, a0
    addi a0, a0, -1
    call fact
    mul  a0, s0, a0
    j    fact_end

fact_base:
    li   a0, 1

fact_end:
    lw   ra, 0(sp)
    lw   s0, 4(sp)
    addi sp, sp, 8
    ret

write_tohost:
    li x1, 1
    sw x1, tohost, t5
    j write_tohost

.data
num:    .word 5          # 32-bit value
result: .word 0

.align 12
.section ".tohost","aw",@progbits;                            
.align 4; .global tohost; tohost: .dword 0;                     
.align 4; .global fromhost; fromhost: .dword 0;
