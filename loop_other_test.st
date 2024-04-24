% block-normal
const i:=3
begin
var t :=i+2
end 

%put
put 5+2
put "123465"
put true
put 2.3

%get
%get 5+2
get i
get b

var x: array 1..10 of int
get x

function add (a :int, b :int) :int
result a+b
end add

get add

%loop-normal-exit when
loop
var in:=1
var sum := in + i
exit when ddd = sum
end loop

%loop-normal-exit
loop
var in:=1
var sum := in + i
exit
end loop

%loop-normal
loop
var in:=1
var sum := in + i
end loop

%for-loop-normal
for ddd: 1 .. 10
var sum := ddd + i
end for

%for-loop-normal(decreasing)
for decreasing ddd: 10 .. 1
var sum := ddd + i
end for

%for-loop-normal(decreasing:index wrong)
for decreasing ddd: 1 .. 10
var sum := ddd + i
end for

for ddd: "123" .. 10
var sum := ddd + i
end for

%for-loop-exit when
for ddd: 1 .. 10
var sum := ddd + i
exit when sum=5
end for

%for-loop-exit
for ddd: 1 .. 10
var sum := ddd + i
exit
end for

%exit not in loop
exit

%for-loop-index:not const
var test:int
var test2:=2

for ddd: 1 .. test
var sum := ddd + i
exit
end for

for ddd: 1 .. test2+1
var sum := ddd + i
exit
end for

var j := 5

for k:1..j
end for
