;ft_strdup.s by joopark
;char		*ft_strdup(const char *s1);
global		_ft_strdup
extern		_malloc

section		.text
_ft_strdup:			PUSH	RBP						; 프롤로그
					MOV		RBP, RSP				; 프롤로그
					MOV		RCX, 0					; 카운트 레지스터를 카운트 변수로 사용
					JMP		cnt						; 카운트 로직 진입

cnt:				CMP		BYTE [RDI + RCX], 0		; 1바이트 크기의 인수로 받은 포인터 위치 값과 0 비교
					JE		gen						; JE (Jump Equal) - 같으면 카운트 중지
					INC		RCX						; 같지 않으면 누산기 레지 1 증가
					JMP		cnt						; 루프 처음으로 돌아감

gen:				PUSH	RDI						; 현재 인수를 잠시 스택에 저장
					MOV		RDI, RCX				; malloc 입력인수 (문자열 길이)
					PUSH	RCX						; 문자열 길이도 잠시 스택에 저장
					INC		RDI						; 널문자를 위해 1 더함
					CALL	_malloc					; malloc 호출
					POP		RCX						; 문자열 길이 꺼냄
					POP		RDI						; 카피할 메모리 처음 위치 꺼냄
					CMP		RAX, 0					; 할당 성공 확인
					JE		end						; 실패시 종료
					JMP		cpy						; 카피 로직으로 감

cpy:				MOV		DL, BYTE [RDI + RCX]	; 카피할 위치 + 인덱스를 데이터 레지스터로 뽑음
					MOV		BYTE [RAX + RCX], DL	; 그 데이터를 dest + 인덱스 위치에 삽입
					CMP		RCX, 0					; 오프셋이 0인지 확인
					JE		end						; 오프셋이 0이면 종료
					DEC		RCX						; 인덱스 감소
					JMP		cpy						; 카피 로직 처음으로 돌아감

end:				POP		RBP						; 에필로그
					RET								; 종료 (RAX 리턴)