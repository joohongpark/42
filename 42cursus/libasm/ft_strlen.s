;ft_strlen.s by joopark
;size_t		ft_strlen(const char *s);
global		_ft_strlen

section		.text
_ft_strlen:			MOV		RAX, 0
					JMP		cnt

cnt:
					CMP		BYTE [RDI + RAX], 0
					JE		rtn
					INC		RAX
					JMP		cnt

rtn:				RET