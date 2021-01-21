;ft_list_sort.s by joopark
;void		ft_list_sort(t_list **begin_list, int (*cmp)());
global		_ft_list_sort

section		.text
_ft_list_sort:			PUSH	RBP						; 프롤로그
						MOV		RBP, RSP				; 프롤로그
						SUB		RSP, 32					; 지역변수 (8바이트 4개)
						MOV		QWORD [RBP - 8], RDI	; **begin_list 인수를 지역변수(스택)에 저장
						MOV		QWORD [RBP - 16], RSI	; *cmp 함수 인수를 지역변수(스택)에 저장
						MOV		RDX, QWORD [RDI]		; **begin_list가 가리키는 곳을 RDX에 저장
						MOV		QWORD [RBP - 24], RDX	; *begin_list가 가리키는 곳을 지역변수(p1)에 저장
						JMP		_sort_loop_s_1			; 루프 진입

_sort_loop_s_1:			MOV		RDX, QWORD [RBP - 24]	; 지역변수(p1) 꺼내기
						CMP		RDX, 0					; 현재 노드가 null인지 확인
						JE		_ft_sort_end			; null이면 종료
						MOV		RCX, QWORD [RBP - 8]	; **begin_list 인수 꺼내기
						MOV		RCX, QWORD [RCX]		; 서브 루프
						MOV		QWORD [RBP - 32], RCX	; 지역변수(p2) 저장
						JMP		_sort_loop_s_2			; 서브루프 진입

_sort_loop_s_2:			MOV		RCX, QWORD [RBP - 32]	; 지역변수(p2) 꺼내기
						MOV		RAX, QWORD [RCX + 8]	; next 접근
						CMP		RAX, 0					; next 노드가 null인지 확인
						JE		_sort_loop_e_1			; null이면 서브루프 종료
						MOV		RDI, QWORD [RCX]		; data를 인수1에 집어넣음
						MOV		RSI, QWORD [RAX]		; 다음 노드의 data를 인수2에 집어넣음
						CALL	QWORD [RBP - 16]		; *cmp call
						CMP		EAX, 0					; 0과 비교
						JLE		_sort_loop_e_2			; 0과 같거나 작으면 루프 다시 돔
						MOV		RAX, QWORD [RBP - 32]	; RAX에 지역변수(p2) 꺼내기
						MOV		RDX, QWORD [RAX]		; RDX <- p2.data
						MOV		RCX, QWORD [RAX + 8]	; RCX <- p2.next
						MOV		RCX, QWORD [RCX]		; RCX <- p2.next.data
						MOV		QWORD [RAX], RCX		; p2.data에 p2.next.data 삽입
						MOV		RAX, QWORD [RAX + 8]	; p2.next 접근
						MOV		QWORD [RAX], RDX		; p2.next.data에 p2.data 삽입
						JMP		_sort_loop_e_2			; 0이면 루프 다시 돔

_sort_loop_e_2:			MOV		RCX, QWORD [RBP - 32]	; 지역변수(p2) 꺼내기
						MOV		RCX, QWORD [RCX + 8]	; 다음 주소로 이동
						MOV		QWORD [RBP - 32], RCX	; 지역변수(p2) 저장
						JMP		_sort_loop_s_2			; 루프 재진입

_sort_loop_e_1:			MOV		RDX, QWORD [RBP - 24]	; 지역변수(p1) 꺼내기
						MOV		RDX, QWORD [RDX + 8]	; next 접근
						MOV		QWORD [RBP - 24], RDX	; 지역변수(p1) 저장
						JMP		_sort_loop_s_1			; 루프 반복

_ft_sort_end:			ADD		RSP, 32					; 옵셋 원복
						POP		RBP						; 에필로그
						RET								; 종료