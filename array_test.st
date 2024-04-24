%normal
var a: array 1..10 of int
var z:= 5
% wrong index
var b: array 2..true of int
var c: array "123456" .. 10 of int
var d: array z .. 10 of int
var e: array z+5 .. 10 of int

%Invocation
var j := a[5]+a[6]

var n:int :=a[1]
var k :=a[11]
var w :=a[false]

% assignment
a[8]:= 9

a[9]:= 1.2

const b : int := 0
b[8]:=4

%index out of range
const t :=a[0]
t :=a[1]
var s:=a[0]+c[3]
% syntax error
var m :array 2 .. 9 of 0

