//Cracked by Roath
// mv.c
 
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
        string src, dst;
 
        seteuid(geteuid(me));
        if (!arg || sscanf(arg, "%s %s", src, dst)!=2 ) return
        notify_fail("Ö¸Áî¸ñÊ½: mv <Ô­µµÃû> <Ä¿±êµµÃû> \n");
 
        src = resolve_path(me->query("cwd"), src);
        dst = resolve_path(me->query("cwd"), dst);
        if(!SECURITY_D->valid_read(src, this_object(), "read_file") )return notify_fail("¶Ô²»Æğ£¬ÄãÃ»ÓĞ¶ÁÕâ¸öµµ°¸µÄÈ¨Á
¦¡£\n");

 
        if( !rename(src, dst) )
                write("Ok.\n");
        else
                write("ÄãÃ»ÓĞ×ã¹»µÄ¶ÁĞ´È¨Àû¡£\n");
        return 1;
}
 
int help(object me)
{
  write(@HELP
Ö¸Áî¸ñÊ½ : mv <Ô­µµÃû> <Ä¿±êµµÃû>
 
´ËÖ¸Áî¿ÉÈÃÄã(Äã)ĞŞ¸ÄÄ³¸öµµ°¸»òÄ¿Â¼Ãû³Æ¡£
HELP
    );
    return 1;
}
 
