global ft_strcpy

ft_strcpy:
	xor rcx, rcx
	xor rdx, rdx

compare:
	cmp byte[rsi + rcx], 0
	je done

copy:
	mov dl, byte[rsi + rcx]
	mov byte[rdi + rcx], dl
	inc rcx
	jmp compare

done:
	mov byte[rdi + rcx], 0
	mov rax, rdi
	ret