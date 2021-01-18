;ft_strcmp.s by joopark
;int		strcmp(const char *s1, const char *s2);
global		_ft_strcmp

section		.text
_ft_strcmp:			MOV		RCX, 0					; 루프를 도는 로직이 있으므로 카운트 레이즈터 사용
					JMP		cnt						; 카운트 로직으로 건너뜀

cnt:				MOV		DL, BYTE [RDI + RCX]	; 레지스터가 가리키는 값 비교를 위해 data 레지스터로 값 뽑음
					CMP		BYTE [RSI + RCX], DL	; 비교
					JNE		cmp						; 값이 다르면 루프 종료
					CMP		BYTE [RDI + RCX], 0		; 값이 같아도 널이면 종료해야 하니 비교
					JE		cmp						; 값이 널이면 종료
					INC		RCX						; 인덱스 증가
					JMP		cnt						; 루프 처음으로 돌아감

cmp:				MOV		DL, BYTE [RDI + RCX]	; 비교할 값 임시 레지스터에 집어넣기
					CMP		DL, BYTE [RSI + RCX]	; 비교
					JE		eql						; 값이 같으면 0
					JA		big						; 앞 인수가 더 크면 1 
					JB		sml						; 뒤 인수가 더 크면 -1 

eql:				MOV		EAX, 0					; 같으면 0
					RET								; 종료

big:				MOV		EAX, 1					; 앞에 인자가 더 크면 1
					RET								; 종료

sml:				MOV		EAX, -1					; 뒤에 인자가 더 크면 -1
					RET								; 종료