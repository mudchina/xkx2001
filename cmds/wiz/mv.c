// Change by Server
// mv.c
 
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
        string src, dst;
 
        seteuid(geteuid(me));
        if (!arg || sscanf(arg, "%s %s", src, dst)!=2 ) return
        notify_fail("指令格式: mv <原档名> <目标档名> \n");
 
        src = resolve_path(me->query("cwd"), src);
        dst = resolve_path(me->query("cwd"), dst);
        if(!SECURITY_D->valid_read(src, this_object(), "read_file") )return notify_fail("对不起，你没有读这个档案的权?
Αn");

 
        if( !rename(src, dst) )
                write("Ok.\n");
        else
                write("你没有足够的读写权利。\n");
        return 1;
}
 
int help(object me)
{
  write(@HELP
指令格式 : mv <原档名> <目标档名>
 
此指令可让你(你)修改某个档案或目录名称。
HELP
    );
    return 1;
}
 
