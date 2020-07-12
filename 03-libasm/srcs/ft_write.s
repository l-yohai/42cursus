global ft_write
extern ___error

ft_write:
	mov rax, 1
	syscall
	jc error
	ret

error:
	push rax
	call ___error
	pop qword[rax]
	mov rax, -1
	ret