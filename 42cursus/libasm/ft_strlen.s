;ft_strlen.s by joopark
;size_t		ft_strlen(const char *s);
global		_ft_strlen

section		.text
_ft_strlen:			MOV		RAX, 0					; 리턴 값을 넣는 누산기 레지스터를 카운트 변수로 사용
					JMP		cnt						; 카운트 로직 진입

cnt:
					CMP		BYTE [RDI + RAX], 0		; 1바이트 크기의 인수로 받은 포인터 위치 값과 0 비교
					JE		rtn						; JE (Jump Equal) - 같으면 종료
					INC		RAX						; 같지 않으면 누산기 레지 1 증가
					JMP		cnt						; 루프 처음으로 돌아감

rtn:				RET								; 종료 (RAX 리턴)