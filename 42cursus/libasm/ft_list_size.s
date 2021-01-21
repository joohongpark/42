;ft_list_size.s by joopark
;int		ft_list_size(t_list *begin_list);
global		_ft_list_size

section		.text
_ft_list_size:			PUSH	RBP						; 프롤로그
						MOV		RBP, RSP				; 프롤로그
						XOR		RAX, RAX				; 누산기 레지 0으로 초기화
						MOV		RDX, RDI				; *begin_list data 레지에 넣음
						JMP		_loop					; 루프 진입

_loop:					CMP		RDX, 0					; 현재 노드가 null인지 확인
						JE		_ft_end					; null이면 종료
						MOV		RDX, QWORD [RDX + 8]	; next 접근
						INC		RAX						; 카운트 1 증가
						JMP		_loop					; 반복

_ft_end:				POP		RBP						; 에필로그
						RET								; 종료 (RAX 리턴)