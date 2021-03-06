
; Segment Attribute
DA_32    equ    0x4000
DA_DR    equ    0x90
DA_DRW   equ    0x92
DA_DRWA  equ    0x93
DA_C     equ    0x98
DA_CR    equ    0x9A
DA_CCO   equ    0x9C
DA_CCOR  equ    0x9E

; Segment Privilege
DA_DPL0		equ	  0x00    ; DPL = 0
DA_DPL1		equ	  0x20    ; DPL = 1
DA_DPL2		equ	  0x40    ; DPL = 2
DA_DPL3		equ	  0x60    ; DPL = 3

; Special Attribute
DA_LDT   equ    0x82

; Selector Attribute
SA_RPL0    equ    0
SA_RPL1    equ    1
SA_RPL2    equ    2
SA_RPL3    equ    3

SA_TIG    equ    0
SA_TIL    equ    4

; ??????
; usage: Descriptor Base, Limit, Attr
;        Base:  dd
;        Limit: dd (low 20 bits available)
;        Attr:  dw (lower 4 bits of higher byte are always 0)
%macro Descriptor 3	                          ; ?λ?ַ?? ?ν??ޣ? ??????
    dw    %2 & 0xFFFF                         ; ?ν???1
    dw    %1 & 0xFFFF                         ; ?λ?ַ1
    db    (%1 >> 16) & 0xFF                   ; ?λ?ַ2
    dw    ((%2 >> 8) & 0xF00) | (%3 & 0xF0FF) ; ????1 + ?ν???2 + ????2
    db    (%1 >> 24) & 0xFF                   ; ?λ?ַ3
%endmacro                                     ; ?? 8 ?ֽ?
