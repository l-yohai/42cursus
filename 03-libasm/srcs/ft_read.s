global ft_read
extern ___error

ft_read:
	mov rax, 0
	syscall
	jc error
	ret

error:
	push rax
	call ___error
	pop qword[rax]
	mov rax, -1
	ret