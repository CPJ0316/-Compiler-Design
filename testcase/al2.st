const a :int := 2+3
const b:= 2
const str1:= "str1----"
var c :int := 5-3
var d :int
var e := 2+3

procedure print(x:int)
  put x
  return
  put "x+1:"
  put x+1
  skip
end print

%main
d:=8
put str1
const str2:="str2****"
put str2
var i := 1
for c: 1 .. a-2
  put c
  skip
  print(c)
  for decreasing i : 3*2 .. 10-10   
    exit when (i = 1)
    put i
    skip
    
  end for
end for
skip

