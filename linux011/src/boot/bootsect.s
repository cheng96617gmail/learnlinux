SYSSIZE=0x3000

.global bagtext,bagbss,bagdata,endtext,enddata,endbss

.text
bagtext:
.data
bagdata:
.bss
bagbss:

SETUPLEN=4
BOOTSEG=0x07c0
INITSEG=0x9000
SETUPSEG=0x9020
SYSSEG=0x1000
ENDSEG=SYSSEG+SYSSIZE

ROOT_DEV=0x306

entry start
start:
    mov ax,#BOOTSEG
    mov ds,ax
    mov ax,#INITSEG
    mov es,ax
    mov cx,#256
    sub si,si
    sub di,di
    rep 
    movw
    jmpi go,INITSEG
go:
    mov ax,cs
    mov ds,ax
    mov es,ax
    mov ss,ax
    mov sp,#0xff00
load_setup:
    mov dx,#0x0000
    mov cx,#0x0002
    mov bx,#0x0200
    mov ax,#0x0200+SETUPLEN
    int 0x13
    jnc ok_load_setup
    mov dx,0x0000
    mov ax,0x0000
    int 0x13
    jmp load_setup

ok_load_setup:
    mov dl,#0x00
    mov ax,#0x0800
    int 0x13
    mov ch,#0x00
    mov sectors,cx
    mov ax,#INITSEG
    mov es,ax
    
    mov ah,#0x03
    xor bh,bh
    int 0x10
    mov cx,#24
    mov bx,#0x0007
    mov bp,#msgl
    mov ax,#0x1301
    int 0x10

    mov ax,#SYSSEG
    mov es,ax
    call read_it
    call kill_motor

    mov ax,root_dev
    cmp ax,#0
    je root_defined

    mov bx,sectors
    mov ax,#0x0208
    cmp bx,#0x15
    je root_defined

undef_root:
    jmp undef_root

root_defined:
    mov root_dev,ax

    jmpi 0,SYSSEG


    sread: .word 1+SETUPLEN
    head:  .word 0
    track: .word 0

read_it:
    mov ax,es
    test ax,0x0fff
die:
    jne die
    xor bx,bx

rp_read:
    mov ax,es
    cmp ax,#ENDSEG
    jb ok1_read
    ret

ok1_read:
    mov ax,sectors
    sub ax,sread
    mov cx,ax
    shl cx,#9
    add cx,bx
    jnc ok2_read
    je ok2_read
    xor ax,ax
    sub ax,bx
    shr ax,#9
ok2_read:
    call read_track
    mov cx,ax
    add ax,sread
    cmp ax,sectors
    jne ok3_read
    mov ax,#1
    sub ax,head
    jne ok4_read
    inc track

ok4_read:
    mov head,ax
    xor ax,ax
ok3_read:
    mov sread,ax
    add bx,cx
    jnc rp_read
    mov ax,es
    mov ax,#0x0100
    mov es,ax
    xor bx,bx
    jmp rp_read

read_track:
    push ax
    push bx
    push cx
    push dx
    mov dx,track
    mov cx,sread
    inc cx
    mov ch,dl
    mov dx,head
    mov dh,dl
    mov dl,#0
    and dx,#0x0100
    mov ah,#0x02
    int 0x13
    jc bad_rt
    pop dx
    pop cx
    pop bx
    pop ax
    ret

bad_rt:
    mov dx,#0x0000
    mov ax,#0x0000
    int 0x13
    pop dx
    pop cx
    pop bx
    pop ax
    ret
kill_motor:
    push dx
    mov dx,#0x3f2
    mov al,#0
    outb
    pop dx
    ret

sectors:
    .word 0
msgl:
    .byte 13,10
    .ascii "Loading System ..."
    .byte 13,10,13,10
.org 508
root_dev:
    .word ROOT_DEV
boot_flag:
    .word 0xAA55

.text
endtext:
.bss
endbss:
.data
enddata:

    
