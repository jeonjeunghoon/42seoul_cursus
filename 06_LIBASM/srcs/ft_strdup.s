; char *ft_strdup(const char *s1);

section .text
	global _ft_strdup
	extern _ft_strlen
	extern _ft_strcpy
	extern _malloc

_ft_strdup:
	cmp rdi, 0
	je is_null
	push rsi
	push rdi
	call _ft_strlen
	inc rax
	push rdi
	mov rdi, rax
	call _malloc
	cmp rax, 0
	je is_error
	mov rdi, rax
	pop rsi
	call _ft_strcpy
	jmp done

is_null:
	mov rax, 0
	ret

is_error:
	pop rdi
	pop rdi
	pop rsi
	ret

done:
	mov rax, rdi
	pop rdi
	pop rsi
	ret