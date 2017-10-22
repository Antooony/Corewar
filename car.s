name "Tching tching(Intercepteur), Bouh!Bouh!(bruits d'anti-jeu)"
comment ""
fork %:LABEL1, #c 0 6a 
ld %-272, r3, #2 90 ff ff fe f0 3 
live %0, #1 0 0 0 0 
fork %:LABEL2, #c 0 2f 
ld %-272, r3, #2 90 ff ff fe f0 3 
fork %:LABEL3, #c 0 14 
ld %0, r2, #2 90 0 0 0 0 2 
ld %0, r4, #2 90 0 0 0 0 4 
zjmp %139, #9 0 8b 
LABEL3:
ld %4, r2, #2 90 0 0 0 4 2 
ld %0, r4, #2 90 0 0 0 0 4 
zjmp %:LABEL4, #9 0 7a 
LABEL2:
ld %-202, r3, #2 90 ff ff ff 36 3 
fork %:LABEL5, #c 0 14 
ld %0, r2, #2 90 0 0 0 0 2 
ld %0, r4, #2 90 0 0 0 0 4 
zjmp %147, #9 0 93 
LABEL5:
ld %4, r2, #2 90 0 0 0 4 2 
ld %0, r4, #2 90 0 0 0 0 4 
zjmp %130, #9 0 82 
LABEL1:
ld %400, r3, #2 90 0 0 1 90 3 
LABEL14:
live %0, #1 0 0 0 0 
fork %:LABEL6, #c 0 28 
fork %:LABEL7, #c 0 14 
ld %0, r2, #2 90 0 0 0 0 2 
ld %0, r4, #2 90 0 0 0 0 4 
zjmp %:LABEL8, #9 0 45 
LABEL7:
ld %4, r2, #2 90 0 0 0 4 2 
ld %0, r4, #2 90 0 0 0 0 4 
zjmp %:LABEL8, #9 0 34 
LABEL6:
fork %:LABEL9, #c 0 d 
ld %0, r4, #2 90 0 0 0 0 4 
zjmp %:LABEL10, #9 0 5b 
LABEL9:
ld %0, r4, #2 90 0 0 0 0 4 
zjmp %:LABEL11, #9 0 5c 
LABEL4:
ldi r2, %:LABEL12, r6, #a 64 2 0 12 6 
ld %0, r4, #2 90 0 0 0 0 4 
live %1, #1 0 0 0 1 
LABEL12:
sti r6, r2, r3, #b 54 6 2 3 
zjmp %-277, #9 fe eb 
LABEL8:
ldi r2, %:LABEL13, r6, #a 64 2 0 12 6 
ld %0, r4, #2 90 0 0 0 0 4 
live %1, #1 0 0 0 1 
LABEL13:
sti r6, r2, r3, #b 54 6 2 3 
zjmp %:LABEL14, #9 1 8b 
ldi r2, %:LABEL15, r6, #a 64 2 0 12 6 
ld %0, r4, #2 90 0 0 0 0 4 
live %1, #1 0 0 0 1 
LABEL15:
sti r6, r2, r3, #b 54 6 2 3 
zjmp %-207, #9 ff 31 
LABEL10:
live %1, #1 0 0 0 1 
fork %:LABEL10, #c ff fb 
zjmp %:LABEL10, #9 ff f8 
LABEL11:
live %1, #1 0 0 0 1 
fork %:LABEL11, #c ff fb 
zjmp %:LABEL11, #9 ff f8 
