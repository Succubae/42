.name "test2"
.comment "J'ai un nom, tu sais...."

ld %32, r1
aff r1
ld %32, r2
aff r2
add r2, r1, r3
aff r3
st r2, 150
aff r2
aff	r3
st r2, r3
aff r3
aff r2
ld %125, r1
ld %32, r2
ld %32, r3
sti r1, r2, r3
