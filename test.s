.name "42"
.comment "just a basic living prog"
l2: sti r1, 156,%1
and r1,%-211,r1
ld %33,r1
live: live %1
zjmp %:live
bonjour: sti r1, %:l2, %1
