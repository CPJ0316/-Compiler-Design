function ADD (n: int,m:int) : int
  if(n>0) then
    result n+m
  else 
     put"<0"   
     put m
     skip
     result n+m
  end if
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
var a:=10
if(a>1) then
	put ADD(-a,1)
	skip
	if(a=>2) then
  	putnum (a+1,2)
		skip
	end if
end if



