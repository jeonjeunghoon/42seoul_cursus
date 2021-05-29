; char *ft_strcpy(char *dst, const char *src)

section .text
	global _ft_strcpy

_ft_strcpy:
	cmp rsi, 0
	je is_null
	push rcx
	mov rcx, 0
	jmp loop

loop:
	mov dl, byte [rsi + rcx]
	mov byte [rdi + rcx], dl
	inc rcx
	cmp [rsi + rcx], byte 0
	jz done
	jmp loop

is_null:
	mov rax, 0
	ret

done:
	mov byte [rdi + rcx], 0
	mov rax, rdi
	pop rcx
	ret