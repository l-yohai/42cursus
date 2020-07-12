```wasm
mov x, y    ; y 데이터를 x로 복사한다.                    x ← y
and x, y    ; x와 y를 and 연산 후 결과를 x에 넣는다.       x ← x and y
or x, y     ; x와 y를 or 연산 후 결과를 x에 넣는다.        x ← x or y
xor x, y    ; x와 y를 xor 연산 후 결과를 x에 넣는다.       x ← x xor y
add x, y    ; x와 y를 덧셈 연산 후 결과를 x에 넣는다.      x ← x + y
sub x, y    ; x와 y를 뺄셈 연산 후 결과를 x에 넣는다.      x ← x - y
inc x       ; x의 값을 1증가 시킨다.                      x ← x + 1
dec x       ; x의 값을 1감소 시킨다.                      x ← x - 1
syscall     ; 원하는 시스템 함수를 호출한다. rax에 해당 시스템 콜 번호를 넣고 쓴다.
db          ; 프로그램을 실행할 때 메모리에 있을 데이터의 바이트를 선언한다.
```

- 범용 레지스터 (64bit - 32bit - 16bit - up 8bit - down 8bit)
    - rax (- eax - ax - ah - al)
    - rbx (- ebx - bx - bh - bl)
    - rcx (- ecx - cx - ch - cl)
    - rdx (- edx - dx - dh - dl)

- 인덱스 레지스터
    - rsi (src index)
    - rdi (dest index)

- 자주 쓰는 명령어
	- mov : 오퍼랜드 1에 오퍼랜드 2의 값을 대입합니다.
	- add : 오퍼랜드 1에 오퍼랜드 2를 더합니다.
	- sub : 오퍼랜드 1에 오퍼랜드 2를 뺍니다.
	- inc : 오퍼랜드 값을 1 증가 시킵니다.
	- dec : 오퍼랜드 값을 1 감소시킵니다.
	- call : 프로시져를 호출합니다. (함수 호출)
	- ret : 호출의 다음 지점으로 이동합니다. (함수를 끝내고 호출 지점으로 돌아갑니다.)
	- cmp : 오퍼랜드 1과 2의 값을 비교합니다.  (오퍼랜드 1의 값) - (오퍼랜드 2의 값)
	- jmp : 분기 (자세한 설명은 [https://8jz5.tistory.com/50](https://8jz5.tistory.com/50))
	- push : 레지스터 내부의 값을 스택에 임시 저장하고 *레지스터 내부를 비웁니다*.
	- pop : push된 값을 해당 레지스터로 가져옵니다. (push, pop은 **후입선출**을 따릅니다.)

- 함수 호출 시 매개변수는 rdi, rsi, rdx, rcx, r8, r9 를 통해 넘어오거나 넘겨집니다.
- 이 때 매개변수의 갯수와 관계없이 이 레지스터들에 값이 들어가 있다면 오류가 날 수 있습니다.
- 반환값은 항상 rax에 저장됩니다.

