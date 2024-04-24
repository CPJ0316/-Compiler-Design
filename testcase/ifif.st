function ADD (n: int,m:int) : int
 result n+m
end ADD
procedure putnum (n: int,m:int)
 put n
 skip
 put m
 skip
 return
end putnum

  skip
	var a:=5
	if(a>1) then
		a:= ADD(a,1)
    put a
		skip
		if(a>2) then
		putnum (a+1,2)
		skip
		end if
	end if

