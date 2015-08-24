   0x08048998 <+48>:    mov    DWORD PTR [ebp-0x18],0xaa
   0x0804899f <+55>:    mov    BYTE PTR [ebp-0x30],0xf9
   0x080489a3 <+59>:    mov    BYTE PTR [ebp-0x2f],0xfc
   0x080489a7 <+63>:    mov    BYTE PTR [ebp-0x2e],0xff
   0x080489ab <+67>:    mov    BYTE PTR [ebp-0x2d],0xe6
   0x080489af <+71>:    mov    BYTE PTR [ebp-0x2c],0xf5
   0x080489b3 <+75>:    mov    BYTE PTR [ebp-0x2b],0xe0
   0x080489b7 <+79>:    mov    BYTE PTR [ebp-0x2a],0xf1
   0x080489bb <+83>:    mov    BYTE PTR [ebp-0x29],0xf3
   0x080489bf <+87>:    mov    BYTE PTR [ebp-0x28],0xfb
   0x080489c3 <+91>:    mov    BYTE PTR [ebp-0x27],0xf9
   0x080489c7 <+95>:    mov    BYTE PTR [ebp-0x26],0xfe
   0x080489cb <+99>:    mov    BYTE PTR [ebp-0x25],0xf7
   0x080489cf <+103>:   mov    BYTE PTR [ebp-0x24],0xfd
   0x080489d3 <+107>:   mov    BYTE PTR [ebp-0x23],0xe9
   0x080489d7 <+111>:   mov    BYTE PTR [ebp-0x22],0xf3
   0x080489db <+115>:   mov    BYTE PTR [ebp-0x21],0xff
   0x080489df <+119>:   mov    BYTE PTR [ebp-0x20],0xf4
   0x080489e3 <+123>:   mov    BYTE PTR [ebp-0x1f],0xf5
   0x080489e7 <+127>:   mov    BYTE PTR [ebp-0x1e],0x0
   0x080489eb <+131>:   mov    eax,DWORD PTR [ebp-0x18]

   Fonction func_to_pack

   0x080486e2 <+0>: push   ebp
   0x080486e3 <+1>: mov    ebp,esp
   0x080486e5 <+3>: sub    esp,0x28
   0x080486e8 <+6>: mov    DWORD PTR [ebp-0xc],0x0
   ; result key of the xor operation: this is the result we want to get
   0x080486ef <+13>:    mov    BYTE PTR [ebp-0x1b],0xbc
   0x080486f3 <+17>:    mov    BYTE PTR [ebp-0x1a],0x7a
   0x080486f7 <+21>:    mov    BYTE PTR [ebp-0x19],0x99
   0x080486fb <+25>:    mov    BYTE PTR [ebp-0x18],0xdc
   0x080486ff <+29>:    mov    BYTE PTR [ebp-0x17],0x93
   0x08048703 <+33>:    mov    BYTE PTR [ebp-0x16],0xbb
   0x08048707 <+37>:    mov    BYTE PTR [ebp-0x15],0x83
   0x0804870b <+41>:    mov    BYTE PTR [ebp-0x14],0x54
   0x0804870f <+45>:    mov    BYTE PTR [ebp-0x13],0xf1
   0x08048713 <+49>:    mov    BYTE PTR [ebp-0x12],0xe1
   0x08048717 <+53>:    mov    DWORD PTR [ebp-0x10],0x0
   0x0804871e <+60>:    jmp    0x804875d <func_to_pack+123>

   ; counter = [ebp - 0x10]
   0x08048720 <+62>:    mov    eax,DWORD PTR [ebp-0x10]
   0x08048723 <+65>:    add    eax,0x18b
   0x08048728 <+70>:    add    eax,0x804878d ; beginning of check function
   0x0804872d <+75>:    movzx  eax,BYTE PTR [eax] ; get the byte of instr in check
   0x08048730 <+78>:    mov    BYTE PTR [ebp-0x11],al
   0x08048733 <+81>:    mov    edx,DWORD PTR [ebp-0x10] ;
   0x08048736 <+84>:    mov    eax,DWORD PTR [ebp+0x8] ; arg = buffer
   0x08048739 <+87>:    add    eax,edx
   0x0804873b <+89>:    movzx  eax,BYTE PTR [eax] ; we get the good checksum here
   ; xor the good with the untrusted check
   0x0804873e <+92>:    xor    al,BYTE PTR [ebp-0x11]
   0x08048741 <+95>:    mov    edx,eax
   ; get the byte we are waiting for
   0x08048743 <+97>:    lea    ecx,[ebp-0x1b]
   0x08048746 <+100>:   mov    eax,DWORD PTR [ebp-0x10]
   0x08048749 <+103>:   add    eax,ecx
   0x0804874b <+105>:   movzx  eax,BYTE PTR [eax]
   ; compare it with the computed value coming from check xor arg
   0x0804874e <+108>:   cmp    dl,al
   0x08048750 <+110>:   je     0x8048759 <func_to_pack+119>
   ; ebp - 0xc = untrusted boolean if true: failed the xor
   0x08048752 <+112>:   mov    DWORD PTR [ebp-0xc],0x1
   0x08048759 <+119>:   add    DWORD PTR [ebp-0x10],0x1
   ; while counter <= 9
   0x0804875d <+123>:   cmp    DWORD PTR [ebp-0x10],0x9
   0x08048761 <+127>:   jle    0x8048720 <func_to_pack+62>
   0x08048763 <+129>:   cmp    DWORD PTR [ebp-0xc],0x0
   ; We won if [ebp - 0xc == 0] we are trusted
   0x08048767 <+133>:   je     0x804877b <func_to_pack+153>
   0x08048769 <+135>:   sub    esp,0xc
   ; lost the chall
   0x0804876c <+138>:   push   0x8048b30
   0x08048771 <+143>:   call   0x80484f0 <puts@plt>
   0x08048776 <+148>:   add    esp,0x10
   0x08048779 <+151>:   jmp    0x804878b <func_to_pack+169>
   ; win the chall
   0x0804877b <+153>:   sub    esp,0xc
   0x0804877e <+156>:   push   0x8048b3a
   0x08048783 <+161>:   call   0x80484f0 <puts@plt>
   0x08048788 <+166>:   add    esp,0x10
   0x0804878b <+169>:   leave
   0x0804878c <+170>:   ret
