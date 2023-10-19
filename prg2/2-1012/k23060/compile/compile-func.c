// 「extern int b;」は
// 「int 型変数b は別ファイルに書いてある定義を使ってね」という意味
extern int b;
int sub(int a)
{
return(a*b);
}