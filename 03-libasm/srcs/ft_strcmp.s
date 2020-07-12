global ft_strcmp

ft_strcmp:
	xor	rax, rax
	xor	rcx, rcx
	xor	rdx, rdx
	jmp	check

increment:
	inc	rcx

check:
	mov	dl, byte[rdi + rcx]
	mov	al, byte[rsi + rcx]
	sub	dl, 0
	sub	al, 0
	or	dl, al
	cmp	dl, 0
	je	equal

loop:
	mov	dl, byte[rdi + rcx]
	mov al, byte[rsi + rcx]
	cmp	dl, al
	je	increment

compare:
	cmp dl, al
	je	equal
	jg	large
	jmp	small

equal:
	mov	eax, 0
	jmp	done

large:
	mov eax, 1
	jmp	done

small:
	mov	eax, -1
	jmp	done

done:
	ret