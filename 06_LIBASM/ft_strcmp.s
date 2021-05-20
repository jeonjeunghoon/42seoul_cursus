; int ft_strcmp(const char *s1, const char *s2)

section .text
	global _ft_strcmp

_ft_strcmp:
	push rbx
	push rcx
	mov rcx, 0
	jmp loop

loop:
	mov al, byte [rdi + rcx]
	mov bl, byte [rsi + rcx]
	cmp al, 0
	je done
	cmp bl, 0
	je done
	cmp al, bl
	jne done
	inc rcx
	jmp loop

done:
	movzx rax, al
	movzx rbx, bl
	sub rax, rbx
	pop rbx
	pop rcx
	ret