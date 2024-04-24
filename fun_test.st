const x := 5
const x1 := 5
var y := 6
var z := true

%normal
function add (a :int, b :int) :int
result a+b
end add

% names are different&return type wrong
function add1 (a :int, b :int) :real
result a+b
end add

% no result & result is outside of function
function add2 (a :int, b :int) :real

end add2
result a+b

% no result & use return
function add3 (a :int, b :int) :real
return
end add3

% variable is outside of function
function add4 (a :int, b :int) :int
result x+b
end add4

% Invocation
const t:=add (x, y)
add (x, y)
const s:=add (x, z)
const s1:=add (x, 5)
const s2:=add (x, "123")
const w:bool:=add (x, y)
const h:bool:=add (x)
const n:bool:=add10 (x, y)
const q:int:=z(x, y)

%syntax error
function add5 (a :int, b :int)
result c+a
end add5