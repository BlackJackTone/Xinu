define lala
	target remote:1234
	file xinu.elf
	b create
	b resume
	# b ctxsw
	# b ret_k2u
	b main
	b shell
	b fprintf
	# b setsegs
	# b ltss
	b do_syscall
	b _Xint48
end

define bubu
	target remote:1234
	file xinu.elf
end

define cici
	b shell
	c
	b do_syscall
	b _Xint48
end

define didi
	b putc
	b shell
	b main
	b startup
	display/x proctab[1]->prstkptr
	display/x *((int*)(proctab[1]->prstkptr)+0)
	display/x *((int*)(proctab[1]->prstkptr)+1)
	display/x *((int*)(proctab[1]->prstkptr)+2)
	display/x proctab[1]->kel_prstkptr
	display/x *((int*)(proctab[1]->kel_prstkptr)+0)
	display/x *((int*)(proctab[1]->kel_prstkptr)+1)
	display/x *((int*)(proctab[1]->kel_prstkptr)+2)
end