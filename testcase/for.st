var i := 0
var y := 1

for i : 1 .. 10
  put i
end for
skip

var b := 1
for i : 1 .. 3
  put i
  for b : 4 .. 6
  put b
  end for
end for
skip


var x := 0
for decreasing x : 10 .. 1
  put x
end for
skip

for decreasing x : 10 .. 8
  put x
  for decreasing y : 7 .. 4
  put y
  end for
end for

skip
put i
skip
put x
skip
put b
skip
put y
skip


