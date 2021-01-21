;ft_list_remove_if.s by joopark
;void		ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
global		_ft_list_remove_if
extern		_free

section		.text
_ft_list_remove_if:		PUSH	RBP						; 프롤로그
						MOV		RBP, RSP				; 프롤로그
						SUB		RSP, 48					; 지역변수 (8바이트 6개)
						MOV		QWORD [RBP - 8], RDI	; [RBP - 8] <- **begin_list
						MOV		QWORD [RBP - 16], RSI	; [RBP - 16] <- *data_ref
						MOV		QWORD [RBP - 24], RDX	; [RBP - 24] <- (*cmp)()
						MOV		QWORD [RBP - 32], RCX	; [RBP - 32] <- (*free_fct)(void *)
						CMP		QWORD [RBP - 8], 0		; **begin_list가 null인지 확인
						JE		_end					; null이면 중단
						MOV		RAX, QWORD [RBP - 8]	; **begin_list에 접근
						CMP		QWORD [RAX], 0			; *begin_list가 null인지 확인
						JE		_end					; null이면 중단
						MOV		RAX, QWORD [RAX]		; *begin_list에 접근
						MOV		RDI, QWORD [RAX]		; *begin_list->data에 접근해 인수1에 집어넣음
						MOV		RSI, QWORD [RBP - 16]	; *data_ref를 인수2에 집어넣음
						CALL	QWORD [RBP - 24]		; *cmp call
						CMP		EAX, 0					; 0과 비교
						JNE		_set_di					; 0이 아니면 재귀호출 루틴으로
						MOV		RAX, QWORD [RBP - 8]	; **begin_list에 접근
						MOV		RAX, QWORD [RAX]		; *begin_list에 접근
						MOV		RCX, QWORD [RAX + 8]	; *begin_list->next에 접근
						MOV		QWORD [RBP - 40], RCX	; next를 지역변수에 잠시 저장
						MOV		RDI, QWORD [RAX]		; tmp->data를 인수1에 집어넣음
						CALL	QWORD [RBP - 32]		; *free_fct call
						MOV		RAX, QWORD [RBP - 8]	; **begin_list에 접근
						MOV		RDI, QWORD [RAX]		; *begin_list를 인수1에 집어넣음
						CALL	_free					; free call
						MOV		RAX, QWORD [RBP - 8]	; **begin_list에 접근
						MOV		RCX, QWORD [RBP - 40]	; next 꺼냄
						MOV		[RAX], RCX				; **begin_list가 가리키는 주소에 next 넣음
						MOV		RDI, QWORD [RBP - 8]	; **begin_list를 인수1에 집어넣음
						JMP		_recur1					; 재귀호출 루틴으로

_set_di:				MOV		RAX, QWORD [RBP - 8]	; **begin_list에 접근
						MOV		RAX, QWORD [RAX]		; *begin_list에 접근
						ADD		RAX, 8					; *begin_list->next에 접근
						MOV		RDI, RAX				; *begin_list->next 주소를 인수1에 집어넣음
						JMP		_recur1					; 재귀호출 루틴으로

_recur1:				MOV		RSI, QWORD [RBP - 16]	; *data_ref를 인수2에 집어넣음
						MOV		RDX, QWORD [RBP - 24]	; (*cmp)()를 인수3에 집어넣음
						MOV		RCX, QWORD [RBP - 32]	; (*free_fct)(void *)를 인수4에 집어넣음
						CALL	_ft_list_remove_if		; 재귀호출
						JMP		_end					; 종료

_end:					ADD		RSP, 48					; 옵셋 원복
						POP		RBP						; 에필로그
						RET								; 종료