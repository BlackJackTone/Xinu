#include <xinu.h>

// Syscall list to dispatch in kernel space

const void *syscalls[] = {
	NULL,
	&create,		// 1
	&resume,		// 2
	&recvclr,		// 3
	&receive,		// 4
	&sleepms,		// 5
	&sleep,			// 6
	&fprintf,		// 7
	&printf,		// 8
	&fscanf,		// 9
	&read,			// 10
	&open,			// 11
	&control,		// 12
	&kill,			// 13
	&getpid,		// 14
	&addargs,		// 15
	NULL,
};

// Syscall wrapper for doing syscall in user space

uint32 do_syscall(uint32 id, uint32 args_count, ...) {
	uint32 return_value;

	// You may need to pass these veriables to kernel side:

	uint32 *ptr_return_value = return_value;
	args_count;
	uint32 *args_array = 1 + &args_count;
	// args_array = args_array + args_count - 1;
	void *syscall_addr = syscalls[id];

	__asm__ (
		"pushl %%edi\n\t"
		"pushl %%esi\n\t"
		"pushl %%edx\n\t"
		"pushl %%ecx\n\t"
		"movl %[ret_val_add], %%edi\n\t"
		"movl %[arg_cnt], %%esi\n\t"
		"movl %[arg_start], %%edx\n\t"
		"movl %[call_add], %%ecx\n\t"
		"int $0x30\n\t"
		"popl %%ecx\n\t"
		"popl %%edx\n\t"
		"popl %%esi\n\t"
		"popl %%edi\n\t"
		:
		: [ret_val_add] "r" (&return_value), [arg_cnt] "r" (args_count), [arg_start] "r" (args_array), [call_add] "r" (syscall_addr)
	);

	return return_value;
}
