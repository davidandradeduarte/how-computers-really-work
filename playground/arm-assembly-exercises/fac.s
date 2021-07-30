.global _start

.text
_start:
    ldr r1, =n      @ set r1 = address of n
    ldr r0, [r1]    @ set r0 = the value of n
    subs r3, r0, #1 @ set r3 = r0 - 1
    ble end         @ jump to end if r3 <= 0
loop:
    mul r0, r3, r0  @ set r0 = r3 x r0
    subs r3, r3, #1 @ decrement r3
    bne loop        @ jump to loop if r3 > 0
end:
    ldr r1, =result @ set r1 = address of result
    str r0, [r1]    @ store r0 at result

@ Exit the program
    mov r0, #0
    mov r7, #1
    svc 0

.data
    n: .word 5
    result: .word 0
