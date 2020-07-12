global _ft_strlen

_ft_strlen:
	xor rax, rax
	jmp compare

increment:
	inc rax

compare:
	cmp byte[rdi + rax], 0
	jne increment

done:
	ret
