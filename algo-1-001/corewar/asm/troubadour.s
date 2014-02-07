.name "Camille"
.comment "Je m'appelle Poupoune et je suis un super gros con de troubadour"

	#test LD
	#OK
	#test AND
	#OK
	#test AFF
	#OK
	#test ADD
	ld	%-6, r2
	ld	-745, r3
	lld	-8, r3
	add	r2, r3, r2
	st	r2, 32
	#ld %45, r2
	#ld %37, r3
	#ld %89, r4
	#ld %88, r5
	#fork %11
	#st r2, r4
	#st r3, r5
	#aff r4
	#aff r5
	#test LDI
	#test LFORK
	#test LIVE
	#test LLD
	#test LLDI
	#test OR
	#test ST
	#test STI
	#ld	%748, r2
	#ld	%21, r3
	#sti	r2, %84, r3
	#ld	%-845, r4
	#ld	%42, r5
	#sti	r4, %104, r5
	#test SUB
	#test XOR
	#test ZJMP
