;ft_atoi_base.s by joopark
;int		ft_atoi_base(char *str, char *base);
global		_ft_atoi_base

section		.text
_ft_atoi_base:		PUSH	RBP						; 프롤로그
					MOV		RBP, RSP				; 프롤로그
					MOV		RBX, RBP				; 오프셋
					SUB		RBX, 256				; 스택은 역 오프셋이으로 256 뺌
					JMP		_basedigit_clr			; 크기가 256인 배열을 클리어하기 위한 루틴

_basedigit_clr: 	MOV		BYTE [RBX], 0			; 0으로 초기화
					INC		RBX						; 오프셋 증가
					CMP		RBX, RBP				; 종료 조건 (베이스 포인터와 현재 옾셋 포인터)
					JE		_ft_atoi_base2			; 다음 단계로
					JMP		_basedigit_clr			; 반복

_ft_atoi_base2:		MOV		RBX, RSI				; 입력인수 베이스 레지스터에 삽입
					JMP		_basedigit_main			; 유효한 입력인지 검사하는 루틴

_basedigit_main:	CMP		BYTE [RBX], 0			; 널 문자가 올때까지 반복한다.
					JE		_basedigit_ok			; 널 문자가 올때까지 반복되면 정상
					XOR		RDX, RDX				; 데이터 레지 초기화
					MOV		DL, BYTE [RBX]			; 데이터 레지에 문자 저장
					MOV		RCX, RBP				; 배열 인덱스 찾기 위해 기준점인 베이스 포인터 삽입
					SUB		RCX, RDX				; 베이스 포인터에 현재 오프셋 뺌
					INC		BYTE [RCX]				; 해당 배열 1 증가
					CMP		BYTE [RCX], 1			; 해당 배열이 1보다 크면 중복 문자열이 있으므로 중단
					JG		_basedigit_nok			; 점프
					CMP		DL, 43					; +
					JE		_basedigit_nok			; 점프
					CMP		DL, 45					; -
					JE		_basedigit_nok			; 점프
					INC		RBX						; 포인터 1 증가
					JMP		_basedigit_main			; 반복

_basedigit_ok:		MOV		RDX, RBX				; RDX에 베이스 길이 구하기 위해 널문자 오프셋 저장
					SUB		RDX, RSI				; 입력 인수 (문자 시작점) 뺌
					CMP		RDX, 2					; 길이가 2 미만이면 종료
					JB		_basedigit_nok
					JMP		_isspace				; 다음 단계로

_basedigit_nok:		XOR		RAX, RAX				; 비정상 상황이므로 리턴값 0으로 초기화
					JMP		_end					; 종료

_isspace:			CMP		BYTE [RDI], 9			; \t
					JE		_isspace_inc			; 반복
					CMP		BYTE [RDI], 10			; \n
					JE		_isspace_inc			; 반복
					CMP		BYTE [RDI], 11			; \v
					JE		_isspace_inc			; 반복
					CMP		BYTE [RDI], 12			; \f
					JE		_isspace_inc			; 반복
					CMP		BYTE [RDI], 13			; \r
					JE		_isspace_inc			; 반복
					CMP		BYTE [RDI], 32			; space
					JE		_isspace_inc			; 반복
					JMP		_ft_atoi_base3			; 아니면 다음단계로

_isspace_inc:		INC		RDI						; 포인터 증가
					JMP		_isspace				; 반복

_ft_atoi_base3:		MOV		RAX, 1					; 리턴값 1 미리 저장
					JMP		_sign					; 부호 지정

_sign:				CMP		BYTE [RDI], 43			; +
					JE		_rtn_plus				; +	일때
					CMP		BYTE [RDI], 45			; -
					JE		_rtn_minus				; -	일때
					JMP		_ft_atoi_base4			; 다음 단계로

_rtn_plus:			MOV		RAX, 1					; 1
					INC		RDI						; 포인터 증가
					JMP		_sign					; 반복

_rtn_minus:			MOV		RAX, -1					; -1
					INC		RDI						; 포인터 증가
					JMP		_sign					; 반복

_ft_atoi_base4:		PUSH	RAX
					XOR		RAX, RAX
					JMP		_ft_atoi_base5

_ft_atoi_base5:		XOR		RBX, RBX				; 오프셋 0으로
					JMP		_isvaild

_isvaild:			MOV		CL, BYTE [RSI + RBX]	; Count 레지로 옮겨놓기
					CMP		CL, 0					; 널 문자가 올때까지 반복한다.
					JE		_isvaild_end			; 널 문자가 오면 루프 중단
					CMP		CL, BYTE [RDI]			; 현재 atoi 할 문자와 비교
					JE		_isvaild_ok				; 오프셋 가지고 atoi하러 감
					INC		RBX						; 오프셋 증가
					JMP		_isvaild				; 반복

_isvaild_ok:		IMUL	RAX, RDX				; base (RDX) 곱함
					ADD		RAX, RBX				; 자리수 (옵셋) 더함
					INC		RDI						; 오프셋 증가
					JMP		_ft_atoi_base5

_isvaild_end:		JMP		_end

_end:				POP		RDX
					IMUL	RAX, RDX				; 부호 곱함
					POP		RBP						; 에필로그
					RET								; 종료 (RAX 리턴)

;XCHG	RDX, RAX				; swap
