const x := 5
const x1 := 5
var y := 6
var z := true

%normal
procedure add(a :int, b :int)
return
end add

% names are different
procedure add1 (c :int, d :int)
return
end add

% no return in procedure  & return is outside of function
procedure add2 (e :int, f :int)

end add2
return

% no return & use result
procedure add3 (a :int, b :int)
result a+b
end add3

% variable is outside of function
procedure add4 (a :int, b :int)
const t:=x+b
return
end add4

% Invocation
const t:=add (x, y)
const t1:=add (x, y)-add (x, y)
add (x, y)
add (x, z)
z(x, y)
add10 (x, y)
add (x)

procedure add5 (a , b)
const t:=x+b
return
end add5