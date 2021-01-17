;ft_strcpy.s by joopark
;char		*strcpy(char * dst, const char * src);
global		_ft_strcpy

section		.text
_ft_strcpy:			MOV		RAX, RDI				; 리턴 값은 첫번째 인수이므로 첫번째 인수에 대입
					MOV		RCX, 0					; 카운트 변수 0으로 초기화 (Count 레지의 일반적인 용도로 사용)
					JMP		cnt						; 카운트 로직으로 건너뜀

cnt:				MOV		DL, BYTE [RSI + RCX]	; Data 레지에 두번째 인수(src) + 인덱스 위치의 데이터 대입
					MOV		BYTE [RAX + RCX], DL	; 그 데이터를 dest + 인덱스 위치에 삽입
					CMP		BYTE [RSI + RCX], 0		; 널문자 비교
					JE		end						; stc + 인덱스 데이터가 널이면 루프 종료
					INC		RCX						; 인덱스 증가
					JMP		cnt						; 카운트 로직 처음으로 돌아감

end:				MOV		BYTE [RAX + RCX], 0		; 널문자 삽입
					RET								; 종료 (리턴값은 dest임)