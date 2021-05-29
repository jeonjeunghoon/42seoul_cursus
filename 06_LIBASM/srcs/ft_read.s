; ssize_t ft_read(int fildes, void *buf, size_t nbyte)

section .text
	global _ft_read
	extern ___error

_ft_read:
	mov rax, 0x2000003
	syscall
	jc is_error
	ret

is_error:
	push rax
	call ___error
	pop rdx
	mov [rax], rdx
	mov rax, -1
	ret
