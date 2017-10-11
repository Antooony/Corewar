.name "42"
.comment "just a basic living prog"
l2: sti r1 123 %1
and r1 %0 r1
live: live %1
zjmp %:live
bonjour: sti r1 %:l2 %1