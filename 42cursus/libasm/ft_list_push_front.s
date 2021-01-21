;ft_list_push_front.s by joopark
;void		ft_list_push_front(t_list **begin_list, void *data);
global		_ft_list_push_front
extern		_malloc

section		.text
_ft_list_push_front:	PUSH	RBP						; 프롤로그
						MOV		RBP, RSP				; 프롤로그
						SUB		RSP, 16					; 포인터 2개분량 지역변수로 사용하기 위한 옵셋
						MOV		QWORD [RBP - 8], RDI	; **begin_list 인수를 지역변수(스택)에 저장
						MOV		QWORD [RBP - 16], RSI	; *data 인수를 지역변수(스택)에 저장
						MOV		RDI, 16					; malloc 입력인수 (64bit * 2 / 8bit = 16byte)
						CALL	_malloc					; malloc 호출
						CMP		RAX, 0					; 할당 성공 확인
						JE		_ft_list_end			; 실패시 종료
						MOV		RDX, QWORD [RBP - 16]	; *data 꺼내옴
						MOV		QWORD [RAX], RDX		; 할당한 메모리 첫번째 주소에 *data 넣음
						MOV		RDX, QWORD [RBP - 8]	; **begin_list 꺼내옴
						CMP		QWORD [RDX], 0			; *begin_list가 null이면
						JE		_next_insert_nul		; 인수로 들어온 원소를 현재 생성한 노드에 삽입
						MOV		RCX, QWORD [RDX]		; **begin_list 로부터 *begin_list 가져옴
						MOV		QWORD [RAX + 8], RCX	; 현재 노드 next에 *begin_list 삽입
						JMP		_ft_list_end			; 계속 진행

_next_insert_nul:		MOV		QWORD [RAX + 8], 0		; 현재 노드가 첫번째 노드이므로 next에 0 삽입
						JMP		_ft_list_end			; 계속 진행

_ft_list_end:			MOV		QWORD [RDX], RAX		; *begin_list에 현재 노드 삽입
						ADD		RSP, 16					; 옵셋 원복
						POP		RBP						; 에필로그
						RET								; 종료