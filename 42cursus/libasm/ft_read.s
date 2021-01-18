;ft_read.s by joopark
;ssize_t	read(int fildes, void *buf, size_t nbyte);
global		_ft_read
extern		___error

section		.text
_ft_read:			MOV		RAX, 0x02000003			; 시스템 콜을 사용하기 위해 누산기 레지스터에 콜 고유번호 삽입
					SYSCALL							; 세개의 변수는 그대로 read 시스템콜에 들어가므로 별도로 삽입하지 않음.
					JC		error					; FreeBSD 운영체제에서 시스템 콜 도중 오류가 발생하면 Carry Flag를 set함.
					JMP		end						; 종료로 건너뜀

error:				PUSH	RAX;					; 에러 코드를 스택에 잠시 넣어둠 (___error 함수가 레지스터를 건드릴수도 있으므로)
					CALL	___error				; error 함수 호출
					POP		RDX						; 에러 코드를 RDX에 담는다.
					MOV		DWORD [RAX], EDX		; 에러 코드 (4바이트 길이)를 ___error 함수가 가리키는 위치에 넣는다.
					MOV		RAX, -1					; read 함수는 에러가 발생하면 -1를 리턴함.
					JMP		end						; 종료로 건너뜀

end:				RET								; 종료