.name ""
.comment ""

l2:		sti r01, %:live, %1
		and r1, %0, r1

live:	live %1
		zjmp %:live
