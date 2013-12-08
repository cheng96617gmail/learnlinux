INITSEG=0x9000
SETUPSEG=0x9020
SYSSEG=0x1000

.global bagtext,bagbss,bagdata,endtext,endbss,enddata
.text
bagtext:
.bss
bagbss:
.data
bagdata:

entry start
start:
    mov ax,#INITSEG
    mov ds,ax
    mov ah,#0x03
    xor bh,bh
    int 0x10
    mov [0],dx

    mov ah,#0x88
    int 0x15
    mov [2],ax

    mov ah,#0x0f
    int 0x10
    mov [4],bx
    mov [6],ax

    mov ah,#0x12
    mov bl,#0x10
    int 0x10
    mov [8],ax
    mov [10],bx
    mov [12],cx

    mov ax,#0x0000
    mov ds,ax
    mov si,[4*0x41]
    mov ax,#INITSEG
    mov es,ax
    mov di,#0x0080
    mov cx,#0x10
    rep
    movsb

    mov ax,#0x0000
    mov ds,ax
    mov si,[4*0x46]
    mov ax,#INITSEG
    mov es,ax
    mov di,#0x0090
    mov cx,#0x10
    rep
    movsb

    mov ax,#0x01500
    mov bl,#0x81
    int 0x13
    jc no_disk1
    cmp ah,#3
    je is_disk1
no_disk1:
    mov ax,#INITSEG
    mov es,ax
    mov di,#0x0090
    mov cx,#0x10
    rep
    stosb
is_disk1:
    cli
    mov ax,#0x0000
    cld
do_move:
    mov es,ax
    add ax,#0x1000
    cmp ax,#INITSEG
    jz end_move
    mov ds,ax
    sub si,si
    sub di,di
    mov cx,#0x8000
    rep
    movsw
    jmp do_move
end_move:
    mov ax,#SETUPSEG
    mov ds,ax
    lidt idt_48
    lgdt gdt_48

    call empty_8042
    mov al,#0xd1
    out #0x64,al
    call empty_8042
    mov al,#0xdf
    out #0x60,al
    call empty_8042

    mov al,#0x11
    out #0x20,al
    .word 0x00eb,0x00eb
    out #0xA0,al
    .word 0x00eb,0x00eb
    mov al,#0x20
    out #0x21,al
    .word 0x00eb,0x00eb
    mov al,#0x28
    out #0xA1,al
    .word 0x00eb,0x00eb
    mov al,#0x04
    out #0x21,al
    .word 0x00eb,0x00eb
    mov al,#0x02
    out #0xA1,al
    .word 0x00eb,0x00eb
    mov al,#0x01
    out #0x21,al
    .word 0x00eb,0x00eb
    out #0xA1,al
    .word 0x00eb,0x00eb
    mov al,#0xff
    out #0x21,al
    .word 0x00eb,0x00eb
    out #0xA1,al

    mov ax,#0x0001
    lmsw ax
    jmpi 0,8

empty_8042:
    .word 0x00eb,0x00eb
    in al,#0x64
    test al,#0x10
    jnz empty_8042
    ret

gdt:
    .word 0,0,0,0
    
    .word 0x07ff
    .word 0
    .word 0x9a00
    .word 0x00c0
    
    .word 0x07ff
    .word 0
    .word 0x9200
    .word 0x00c0

idt_48:
    .word 0
    .word 0,0

gdt_48:
    .word 256*8
    .word 512+gdt,0x9

.text
endtext:
.bss
endbss:
.data
enddata:

