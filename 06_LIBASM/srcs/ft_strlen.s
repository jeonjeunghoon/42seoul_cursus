; size_t ft_strlen(const char *s)

section .text
	global _ft_strlen

_ft_strlen:
	mov rax, 0x0
	jmp loop

loop:
	cmp byte [rdi + rax], 0x0
	je done
	inc rax
	jmp loop

done:
	ret