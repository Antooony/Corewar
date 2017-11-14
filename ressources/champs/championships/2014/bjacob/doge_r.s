.name "Candy"
.comment ""
st r1, r12 #3 50 1 C 
ld %0, r14 #2 90 9 9 9 9 E 
zjmp %:label1 #9 9 F1 
label2:
st r9, -256 #3 70 9 FF F 
st r10, -256 #3 70 A FF F 
st r14, -9 #3 70 E FF F7 
st r4, -21 #3 70 4 FF EB 
st r14, -30 #3 70 E FF E2 
st r4, -256 #3 70 4 FF F 
st r4, -256 #3 70 4 FF F 
st r4, -256 #3 70 4 FF F 
st r4, -256 #3 70 4 FF F 
st r4, -256 #3 70 4 FF F 
st r4, -256 #3 70 4 FF F 
st r4, -256 #3 70 4 FF F 
st r4, -256 #3 70 4 FF F 
st r4, -256 #3 70 4 FF F 
st r4, -256 #3 70 4 FF F 
st r4, -256 #3 70 4 FF F 
st r9, -256 #3 70 9 FF F 
st r10, -256 #3 70 A FF F 
st r14, -9 #3 70 E FF F7 
st r4, -21 #3 70 4 FF EB 
st r14, -30 #3 70 E FF E2 
st r4, -256 #3 70 4 FF F 
st r4, -256 #3 70 4 FF F 
st r4, -256 #3 70 4 FF F 
st r4, -256 #3 70 4 FF F 
st r4, -256 #3 70 4 FF F 
st r4, -256 #3 70 4 FF F 
st r4, -256 #3 70 4 FF F 
st r4, -256 #3 70 4 FF F 
st r4, -256 #3 70 4 FF F 
st r4, -256 #3 70 4 FF F 
st r4, -256 #3 70 4 FF F 
st r4, -256 #3 70 4 FF F 
st r4, -256 #3 70 4 FF F 
st r4, -256 #3 70 4 FF F 
st r4, -256 #3 70 4 FF F 
st r4, -256 #3 70 4 FF F 
st r4, -256 #3 70 4 FF F 
st r10, -256 #3 70 A FF F 
st r14, -9 #3 70 E FF F7 
st r4, -21 #3 70 4 FF EB 
st r14, -30 #3 70 E FF E2 
ld %0, r15 #2 90 9 9 9 9 F 
zjmp %:label2 #9 FF 27 
label5:
live %42 #1 1 1 1 2A 
fork %:label3 #C C 67 
ld %0, r16 #2 90 9 9 9 9 10 
zjmp %:label1 #9 9 3 
label1:
live %42 #1 1 1 1 2A 
ld %57672449, r3 #2 90 3 70 3 1 3 
ld %57672959, r4 #2 90 3 70 4 FF 4 
ld %42991616, r9 #2 90 2 90 9 9 9 
ld %235536380, r10 #2 90 E 9 FF FC A 
ld %16777216, r11 #2 90 1 1 1 1 B 
xor r12, r14, r15 #8 54 C E F 
sti r15, %:label4, %1 #B 68 F F 18 1 1 
sti r15, %:label5, %1 #B 68 F FF BA B 1 
sti r15, %:label6, %1 #B 68 F 1 5B 5 1 
zjmp %:label4 #9 9 3 
label4:
live %42 #1 1 1 1 2A 
fork %:label2 #C FE C8 
fork %:label7 #C 1 4E 
ld %0, r15 #2 90 9 9 9 9 F 
zjmp %:label5 #9 FF 97 
label3:
st r3, 256 #3 70 3 1 1 
st r3, 256 #3 70 3 1 1 
st r3, 256 #3 70 3 1 1 
live %1 #1 1 1 1 1 
st r3, 256 #3 70 3 1 1 
st r3, 256 #3 70 3 1 1 
st r3, 256 #3 70 3 1 1 
st r3, 256 #3 70 3 1 1 
live %1 #1 1 1 1 1 
st r3, 256 #3 70 3 1 1 
live %1 #1 1 1 1 1 
st r3, 256 #3 70 3 1 1 
live %1 #1 1 1 1 1 
st r3, 256 #3 70 3 1 1 
st r3, 256 #3 70 3 1 1 
st r3, 256 #3 70 3 1 1 
st r3, 256 #3 70 3 1 1 
live %1 #1 1 1 1 1 
st r3, 256 #3 70 3 1 1 
live %1 #1 1 1 1 1 
st r3, 256 #3 70 3 1 1 
live %1 #1 1 1 1 1 
st r3, 256 #3 70 3 1 1 
live %1 #1 1 1 1 1 
st r3, 256 #3 70 3 1 1 
live %1 #1 1 1 1 1 
st r3, 256 #3 70 3 1 1 
st r3, 256 #3 70 3 1 1 
st r3, 256 #3 70 3 1 1 
st r3, 256 #3 70 3 1 1 
live %1 #1 1 1 1 1 
st r3, 256 #3 70 3 1 1 
live %1 #1 1 1 1 1 
st r3, 256 #3 70 3 1 1 
live %1 #1 1 1 1 1 
st r3, 256 #3 70 3 1 1 
live %1 #1 1 1 1 1 
st r3, 256 #3 70 3 1 1 
zjmp %:label3 #9 FF 42 
label8:
live %42 #1 1 1 1 2A 
st r9, 256 #3 70 9 1 1 
st r9, 256 #3 70 9 1 1 
st r9, 256 #3 70 9 1 1 
st r9, 256 #3 70 9 1 1 
st r9, 256 #3 70 9 1 1 
st r9, 256 #3 70 9 1 1 
st r9, 256 #3 70 9 1 1 
st r9, 256 #3 70 9 1 1 
st r9, 256 #3 70 9 1 1 
st r9, 256 #3 70 9 1 1 
st r9, 256 #3 70 9 1 1 
st r9, 256 #3 70 9 1 1 
st r9, 256 #3 70 9 1 1 
st r9, 256 #3 70 9 1 1 
st r9, 256 #3 70 9 1 1 
st r9, 256 #3 70 9 1 1 
st r9, 256 #3 70 9 1 1 
st r9, 256 #3 70 9 1 1 
st r9, 256 #3 70 9 1 1 
st r9, 256 #3 70 9 1 1 
st r9, 256 #3 70 9 1 1 
st r9, 256 #3 70 9 1 1 
st r9, 256 #3 70 9 1 1 
zjmp %:label8 #9 FF 88 
label6:
live %1 #1 1 1 1 1 
label7:
live %1 #1 1 1 1 1 
fork %:label8 #C FF 7B 
st r4, 254 #3 70 4 4 FE 
zjmp %:label7 #9 FF F3 
