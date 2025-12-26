global:
	.string "hello%d\n"
	.globl	main
global2:
	.string	"%d\n"
main:
	push	%rbp
	mov	%rsp, %rbp
	sub	$16, %rsp
	mov	$5, -12(%rbp)
	mov	$6, -8(%rbp)
	mov	$0, -4(%rbp)
	mov	-12(%rbp), %edx
	mov	-8(%rbp), %eax
	add	%edx, %eax
	mov	%eax, -4(%rbp)
	mov	-4(%rbp), %eax
	mov	%eax, %esi
	lea	global2(%rip), %rax
	/*ojjl;jl;lj
	xvbcvb*/
	mov	%rax, %rdi
	mov	$0, %eax
	call	printf
	mov	$0, %eax
	leave
	ret
