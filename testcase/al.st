var x := 1

function ADD (n: int,m:int) : int
 result n+m
 put m
 skip
end ADD

procedure putnum (n: int,m:int)
 put n
 skip
 put m
 skip
 return
 put n+m
 put m
end putnum

skip
var a:=-(1+2*3/4 mod 5)
if(-a>1) then
	put ADD(a,1)
	skip
	if(a=>2) then
  	putnum (a+1,2)
		skip
	end if
end if

var y := 1
for decreasing x : 10 .. 8
  put x
  y := 1
  loop  
    exit when (y > 10)
    y :=y  + 1
  end loop
  put y
end for


