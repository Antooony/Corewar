.name "Underscore"
.comment "__UNDERSCORE_S__"
label24:
	ld		%0, r2 #2 90 9 9 9 9 2 
	zjmp	%:label1 #9 1 F3 
	zjmp	%-511 #9 FE 1 
label3:
	live	%-42 #1 FF FF FF D6 
	sti		r10, r11, r13 #B 54 A B D 
	add		r12, r13, r13 #4 54 C D D 
	xor		r13, %-255, r14 #8 64 D FF FF FF 1 E 
	zjmp	%:label2 #9 9 D 
	ld		%0, r14 #2 90 9 9 9 9 E 
	zjmp	%:label3 #9 FF DF 
label2:
	ld		%0, r13 #2 90 9 9 9 9 D 
	zjmp	%:label3 #9 FF D5 
label20:
	live	%-42 #1 FF FF FF D6 
	ld		%-128, r6 #2 90 FF FF FF 80 6 
	fork	%:label4 #C C 1B 
	ld		%190056198, r7 #2 90 B 54 7 6 7 
	ld		%0, r5 #2 90 9 9 9 9 5 
	ld		%0, r16 #2 90 9 9 9 9 10 
	zjmp	%:label5 #9 9 22 
label4:
	ld		%84541307, r7 #2 90 5 9 FF 7B 7 
	ld		%4, r5 #2 90 9 9 9 4 5 
	ld		%190056198, r16 #2 90 B 54 7 6 10 
label21:
	st		r16, -490 #3 70 10 FE 16 
label22:
	st		r7, -491 #3 70 7 FE 15 
label5:
	ld		%0, r2 #2 90 9 9 9 9 2 
	zjmp	%-511 #9 FE 1 
	lldi	%42, %42, r16 #E A4 A 2A 2 2A 10 
label9:
	live	%-42 #1 FF FF FF D6 
	sti		r1, %:label3, %1 #B 68 1 FF 76 7 1 
	ld		%57672959, r10 #2 90 3 70 4 FF A 
	ld		%-30, r11 #2 90 FF FF FF E2 B 
	ld		%-5, r12 #2 90 FF FF FF FB C 
	st		r1, 6 #3 70 1 1 6 
label6:
	live	%-42 #1 FF FF FF D6 
label10:
	fork	%:label3 #C FF 50 
	ld		%-165, r13 #2 90 FF FF FF 5B D 
	ld		%0, r2 #2 90 9 9 9 9 2 
	zjmp	%:label6 #9 FF EA 
label26:
	sti		r1, %:label7, %1 #B 68 1 1 38 3 1 
	sti		r1, %:label8, %1 #B 68 1 1 5B 5 1 
label11:
	fork	%:label9 #C FF B3 
	st		r1, 6 #3 70 1 1 6 
	live	%:label10 #1 FF FF FF D6 
	or		r1, r1, r7 #7 54 1 1 7 
	ld		%1880161814, r9 #2 90 70 10 FE 16 9 
	ld		%1879571989, r10 #2 90 70 7 FE 15 A 
	ld		%34209281, r11 #2 90 2 9 FE 1 B 
label23:
	fork	%:label8 #C C 2D 
label7:
	live	%:label11 #1 FF FF FF D6 
	fork	%:label12 #C C D 
	ld		%0, r2 #2 90 9 9 9 9 2 
	zjmp	%:label13 #9 9 99 
label12:
	ld		%191104768, r7 #2 90 B 64 7 7 7 
	ld		%5, r6 #2 90 9 9 9 5 6 
	ld		%0, r2 #2 90 9 9 9 9 2 
	zjmp	%:label14 #9 9 3B 
label8:
	live	%:label7 #1 FF FF FF D6 
	fork	%:label15 #C C 1B 
	ld		%101056768, r7 #2 90 6 6 1 1 7 
	ld		%9, r6 #2 90 9 9 9 9 6 
	ld		%0, r2 #2 90 9 9 9 9 2 
	zjmp	%:label14 #9 9 1B 
label15:
	ld		%0, r2 #2 90 9 9 9 9 2 
	ld		%12, r6 #2 90 9 9 9 C 6 
	ld		%0, r2 #2 90 9 9 9 9 2 
	zjmp	%:label14 #9 9 3 
label14:
	st		r1, 6 #3 70 1 1 6 
	live	%-42 #1 FF FF FF D6 
	sti		r7, r6, %317 #B 58 7 6 1 3D 
	ld		%0, r2 #2 90 9 9 9 9 2 
	zjmp	%309 #9 1 35 
	sti		r16, %:label16, %1 #B 68 10 1 BF B 1 
	fork	%:label17 #C C A0 
	ld		%:label18, r16 #2 90 9 9 9 18 10 
	sti		r16, %:label16, %1 #B 68 10 1 AE A 1 
	st		r1, 6 #3 70 1 1 6 
label19:
	live	%-42 #1 FF FF FF D6 
label18:
	ld		%0, r2 #2 90 9 9 9 9 2 
	zjmp	%511 #9 1 FF 
label13:
	ld		%16, r12 #2 90 9 9 9 10 C 
	add		r12, r9, r9 #4 54 C 9 9 
	add		r12, r10, r10 #4 54 C A A 
	add		r12, r11, r11 #4 54 C B B 
	st		r1, 6 #3 70 1 1 6 
	live	%:label19 #1 FF FF FF D6 
	ld		%0, r2 #2 90 9    2 
	sti		r1, %:label20, %1 #B 68 1 FE 63 6 1 
	sti		r9, %:label21, %1 #B 68 9 FE 98 9 1 
	sti		r10, %:label22, %1 #B 68 A FE 96 9 1 
	sti		r11, %:label5, %6 #B 68 B FE 94 9 6 
	fork	%:label20 #C FE 47 
	zjmp	%:label23 #9 FF F 
label1:
	ld		%16777216, r16 #2 90 1 1 1 1 10 
	sti		r16, %:label24, %6 #B 68 10 FD FF F 6 
	st		r1, 117 #3 70 1 1 75 
	sti		r1, %:label25, %1 #B 68 1 1 44 4 1 
	ld		%507, r4 #2 90 9 9 1 FB 4 
	ld		%507, r6 #2 90 9 9 1 FB 6 
	st		r1, 6 #3 70 1 1 6 
	live	%-42 #1 FF FF FF D6 
label17:
	ld		%190055170, r8 #2 90 B 54 3 2 8 
	ld		%67699190, r9 #2 90 4 9 1 F6 9 
	st		r8, 511 #3 70 8 1 FF 
	st		r9, 510 #3 70 9 1 FE 
label16:
	ld		%24, r8 #2 90 9 9 9 18 8 
	fork	%:label26 #C FE 86 
	fork	%:label27 #C C 2E 
label25:
	live	%-1 #1 FF FF FF FF 
	ld		%0, r2 #2 90 9 9 9 9 2 
	ld		%190055682, r3 #2 90 B 54 5 2 3 
	ld		%190056194, r5 #2 90 B 54 7 2 5 
	ld		%190056194, r7 #2 90 B 54 7 2 7 
	ld		%0, r16 #2 90 9 9 9 9 10 
	zjmp	%448 #9 1 C0 
label27:
	live	%0 #1 1 1 1 1 
	ld		%4, r2 #2 90 9 9 9 4 2 
	ld		%101253622, r3 #2 90 6 9 1 F6 3 
	ld		%134807571, r5 #2 90 8 9 9 13 5 
	ld		%134807571, r7 #2 90 8 9 9 13 7 
	ld		%0, r16 #2 90 9 9 9 9 10 
	zjmp	%405 #9 1 95 
