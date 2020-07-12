global	_ft_strdup
extern	_malloc

_ft_strdup:
	cmp rdi, 0
	je error

get_len:
	xor rcx, rcx
	jmp len

increment:
	inc rcx

len:
	cmp byte[rdi + rcx], 0
	jne increment

malloc_start:
	push rdi
	inc rcx
	mov rdi, rcx
	call _malloc
	pop rdi
	cmp rax, 0
	je error

init:
	xor rcx, rcx
	xor rdx, rdx
	jmp dup

compare:
	cmp byte[rdi + rcx], 0
	je null

dup:
	mov dl, byte[rdi + rcx]
	mov byte[rax + rcx], dl
	inc rcx
	jmp compare

null:
	mov byte[rax + rcx], 0
	jmp done

error:
	xor rax, rax

done:
	ret
