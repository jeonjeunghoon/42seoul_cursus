; int ft_strcmp(const char *s1, const char *s2)

section .text
	global _ft_strcmp

_ft_strcmp:
	push rcx
	push rdi
	push rsi
	mov rax, 0
	mov rcx, 0
	jmp loop

loop:
	mov al, [rdi]
	mov cl, [rsi]
	cmp al, cl
	jne done
	cmp al, 0
	je done
	inc rdi
	inc rsi
	jmp loop


done:
	sub rax, rcx
	pop rsi
	pop rdi
	pop rcx
	ret