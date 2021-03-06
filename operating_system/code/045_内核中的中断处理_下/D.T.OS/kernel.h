
#ifndef KERNEL_H
#define KERNEL_H

#include "type.h"
#include "const.h"

typedef struct {
    ushort limit1;
    ushort base1;
    byte   base2;
    byte   attr1;
    byte   attr2_limit2;
    byte   base3;
} Descriptor;

typedef struct {
    Descriptor * const entry;
    const int          size;
} GdtInfo;

typedef struct {
    ushort offset1;
    ushort selector;
    byte   dcount;
    byte   attr;
    ushort offset2;
} Gate;

typedef struct {
    Gate * const entry;
    const int    size;
} IdtInfo;

typedef struct {
    uint gs;
    uint fs;
    uint es;
    uint ds;
    uint edi;
    uint esi;
    uint ebp;
    uint kesp;
    uint ebx;
    uint edx;
    uint ecx;
    uint eax;
    uint raddr;
    uint eip;
    uint cs;
    uint eflags;
    uint esp;
    uint ss;
} RegValue;

typedef struct
{
    uint   previous;
    uint   esp0;
    uint   ss0;
    uint   unused[22];
    ushort reserved;
    ushort iomb;
} TSS;

typedef struct
{
    RegValue   rv;
    Descriptor ldt[3];
    TSS        tss;
    ushort     ldtSelector;
    ushort     tssSelector;
    uint       id;
    char       name[8]; 
    byte       stack[512];
} Task;

int SetDescValue(Descriptor* pDesc, uint base, uint limit, ushort attr);
int GetDescValue(Descriptor* pDesc, uint* pBase, uint* pLimit, ushort* pAttr);
int SetIntHandler(Gate* pGate, uint ifunc);
int GetIntHandler(Gate* pGate, uint* pIFunc);

#endif
