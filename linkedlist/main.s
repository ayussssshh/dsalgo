	.file	"main.c"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"node1 data %d\n"
.LC1:
	.string	"node1 next  %p\n"
.LC2:
	.string	"node2 data %d\n"
.LC3:
	.string	"node2 next  %p\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB39:
	.cfi_startproc
	endbr64
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$16, %edi
	call	malloc@PLT
	movl	$10, %edx
	movl	$2, %edi
	leaq	.LC0(%rip), %rsi
	movl	$20, (%rax)
	movq	%rax, %rbx
	movq	$0, 8(%rax)
	xorl	%eax, %eax
	call	__printf_chk@PLT
	movq	%rbx, %rdx
	movl	$2, %edi
	xorl	%eax, %eax
	leaq	.LC1(%rip), %rsi
	call	__printf_chk@PLT
	movl	(%rbx), %edx
	leaq	.LC2(%rip), %rsi
	xorl	%eax, %eax
	movl	$2, %edi
	call	__printf_chk@PLT
	movq	8(%rbx), %rdx
	movl	$2, %edi
	xorl	%eax, %eax
	leaq	.LC3(%rip), %rsi
	call	__printf_chk@PLT
	movq	%rbx, %rdi
	call	free@PLT
	xorl	%eax, %eax
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE39:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04.1) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
