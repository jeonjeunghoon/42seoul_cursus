; size_t ft_strlen(const char *s)

section .text
	global _ft_strlen

_ft_strlen:
	mov rax, 0
	cmp rdi, 0
	je done
	jmp loop

loop:
	cmp byte [rdi + rax], 0
	je done
	inc rax
	jmp loop

done:
	ret