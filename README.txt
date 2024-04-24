針對javaa，我所做的改動如下

於javaa.y

針對label內容不能為空的部分，於op_line的部分，新增label，使其可以接受label為空的狀況(第763行)


於javaa.l
針對註釋輸出/會有問題的部分進行修改
原本:
"/*"(\\.|[^\\*/]|"*"[^/])*"*/"		{echo(yytext);}
修改版:
%x mul_COMMENT


"/*"  {
  check_comment=1;
  BEGIN mul_COMMENT;
} 
<mul_COMMENT>"*/"  {
  if(check_comment==1)
  {
  printf("/*");
  check_comment=0;
  }
  echo(yytext);
  BEGIN INITIAL;
}
<mul_COMMENT>\n  {
  if(check_comment==1)
  {
  printf("/*");
  check_comment=0;
  }
  echo(yytext);
  linenumber++;
}
<mul_COMMENT>.  {
  yymore();
}
