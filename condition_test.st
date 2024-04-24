const i :=true
var t:=1
%if
if i  then
const j:="123"
end if

%if-else
if i  then
const j:="123"
else
const a:="987"
end if


%if-if-else
if i  then
const j:="123"
  if(t=1) then
    const a:=j
  else
    const b:=j
    const c:=a
  end if
end if


%if-condition type wrong
if(5)then

end if
