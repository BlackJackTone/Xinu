
struct TaskStateSegment {
    unsigned int link; // 保存前一个 TSS 段选择子，使用 call 指令切换寄存器的时候由CPU填写。
    // 这 6 个值是固定不变的，用于提权，CPU 切换栈的时候用
    unsigned int esp0; // 保存 0 环栈指针
    unsigned int ss0;  // 保存 0 环栈段选择子
    unsigned int esp1; // 保存 1 环栈指针
    unsigned int ss1;  // 保存 1 环栈段选择子
    unsigned int esp2; // 保存 2 环栈指针
    unsigned int ss2;  // 保存 2 环栈段选择子
    // 下面这些都是用来做切换寄存器值用的，切换寄存器的时候由CPU自动填写。
    unsigned int cr3; 
    unsigned int eip;  
    unsigned int eflags;
    unsigned int eax;
    unsigned int ecx;
    unsigned int edx;
    unsigned int ebx;
    unsigned int esp;
    unsigned int ebp;
    unsigned int esi;
    unsigned int edi;
    unsigned int es;
    unsigned int cs;
    unsigned int ss;
    unsigned int ds;
    unsigned int fs;
    unsigned int gs;
    unsigned int ldt;
    // 这个暂时忽略
    unsigned int io_map;
};