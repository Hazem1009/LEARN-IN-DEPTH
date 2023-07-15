
.section .vectors

.word	0x20001000
.word	reset_handler
.word	default_handler
.word	default_handler
.word	default_handler
.word	default_handler
.word	default_handler
.word	default_handler
.word	default_handler
.word	default_handler


.section .text

reset_handler:
	bl main
	b .

.thumb_func
default_handler:
	b reset_handler
