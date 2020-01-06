.586
.model flat, stdcall
includelib userlib.lib
includelib kernel32.lib
includelib libucrt.lib

ExitProcess PROTO : DWORD
_strcpy PROTO : DWORD, : DWORD
_strcat PROTO : DWORD, : DWORD 
outstr PROTO : DWORD
outint PROTO : SDWORD
_modint PROTO : SDWORD, : SDWORD
.stack 4096
.const
	overflow db 'ERROR: VARIABLE OVERFLOW', 0 
	null_division db 'ERROR: DIVISION BY ZERO', 0
	_Lit1 BYTE " Changed", 0
	_Lit2 SDWORD 15
	_Lit3 SDWORD 13
	_Lit4 SDWORD 18
	_Lit5 SDWORD 12
	_Lit6 BYTE "Roman", 0
	_Lit7 BYTE " sdelal", 0
	_Lit8 BYTE " ", 0
	_Lit9 BYTE "kursovoi", 0
	_Lit10 BYTE " molodec", 0
	_Lit11 SDWORD 2
.data
	testnumber_y SDWORD 0
	main_x SDWORD 0
	main_y SDWORD 0
	main_z SDWORD 0
	main_sa BYTE 255 DUP(0)
	main_sb BYTE 255 DUP(0)
	main_sr BYTE 255 DUP(0)
	main_te SDWORD 0
.code

testnumber_proc PROC, testnumber_x : SDWORD, testnumber_k : SDWORD
	push testnumber_x
	push testnumber_x
	pop eax
	pop ebx
	add eax, ebx
	jo EXIT_OVERFLOW
	push eax
	push testnumber_k
	pop eax
	pop ebx
	imul eax, ebx
	jo EXIT_OVERFLOW
	push eax
	pop testnumber_y
	push testnumber_y
	call outint

	push testnumber_y

	jmp EXIT
	EXIT_DIV_ON_NULL:
	push offset null_division
	call outstr
	push - 1
	call ExitProcess

	EXIT_OVERFLOW:
	push offset overflow
	call outstr
	push - 2
	call ExitProcess

	EXIT:
	pop eax
	ret 8

testnumber_proc ENDP

teststring_proc PROC, teststring_a : DWORD
	push teststring_a
	push offset _Lit1
	call _strcat
	jo EXIT_OVERFLOW
	push eax

	jmp EXIT
	EXIT_DIV_ON_NULL:
	push offset null_division
	call outstr
	push - 1
	call ExitProcess

	EXIT_OVERFLOW:
	push offset overflow
	call outstr
	push - 2
	call ExitProcess

	EXIT:
	pop eax
	ret 4

teststring_proc ENDP

main PROC
	push _Lit2
	push _Lit3
	push _Lit3
	call _modint
	push eax
	pop ebx
	pop eax
	test ebx,ebx
	jz EXIT_DIV_ON_NULL
	cdq
	idiv ebx
	push eax
	pop main_x
	push main_x
	call outint

	push _Lit5
	push _Lit4
	call _modint
	push eax
	pop main_z
	push main_z
	call outint

	push offset _Lit6
	push offset main_sa
	call _strcpy

	push offset _Lit7
	push offset main_sb
	call _strcpy

	push offset main_sa
	push offset main_sb
	call _strcat
	jo EXIT_OVERFLOW
	push eax
	push offset _Lit8
	call _strcat
	jo EXIT_OVERFLOW
	push eax
	push offset _Lit9
	call _strcat
	jo EXIT_OVERFLOW
	push eax
	push offset main_sb
	call _strcpy

	push offset main_sb
	call outstr

	push offset main_sa
	push offset _Lit10
	call _strcat
	push eax
	push offset main_sr
	call _strcpy

	push offset main_sr
	call outstr

	push offset main_sa
	push offset main_sr
	call _strcpy
	push eax
	push offset main_sb
	call _strcpy

	push offset main_sr
	call outstr

	push _Lit11
	push _Lit11
	call testnumber_proc
	push eax
	pop main_te
	push main_te
	call outint

	push offset main_sa
	call teststring_proc
	push eax
	call outstr


	jmp EXIT
	EXIT_DIV_ON_NULL:
	push offset null_division
	call outstr
	push - 1
	call ExitProcess

	EXIT_OVERFLOW:
	push offset overflow
	call outstr
	push - 2
	call ExitProcess

	EXIT:
	push 0
	call ExitProcess

main ENDP
end main