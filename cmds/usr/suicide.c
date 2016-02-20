// Change by Server
// suicide.c
// xQin 8/00 - enable suicide for those <10k

#include <ansi.h>

inherit F_CLEAN_UP;

int slow_suicide(object);
int halt_suicide(object);
 
int main(object me, string arg)
{
        if( me->is_busy() )
                return notify_fail("你上一个动作还没完成。\n");

        if(!arg) {
                write("请输入suicide -f\n");
                return 1;
        }
        if (me->query_temp("suicide_f") > 1)
        return notify_fail("既然这么犹豫不决，想清楚再说吧。");
	if (me->query("combat_exp") > 10000)
	return notify_fail("上天有好生之德，你现在不可以自杀。\n");	
        if( arg!="-f") 
        return notify_fail("如果真的想永远自杀，请输入suicide -f\n");
        write("如果您选择永远死掉的自杀方式，这个人物的资料就永远删除了，请务必\n"
              "考虑清楚，自杀后是不可以恢复的。确定的话请输入您的密码：");
        input_to("check_password", 1, me, 1);
        return 1;
}

private void check_password(string passwd, object me, int forever)
{
        object link_ob;
        string old_pass;

        link_ob = me->query_temp("link_ob");
        old_pass = link_ob->query("password");
        if( crypt(passwd, old_pass)!=old_pass ) {
                write("密码错误！\n");
                return;
        }

        if (forever) {
                tell_object( me,
                        HIR "\n\n你决定要自杀了，你有一分钟的时间可以后悔(halt)，否则就永别了！\n\n\n" NOR);
                me->set_temp("suicide_countdown", 30);
                me->set_temp("pending/suicide",1);
                me->start_busy((:slow_suicide:) ,(:halt_suicide:));
                message("channel:chat", HIM+"【谣言】"+me->query("name")+"("+me->query("id")+")"+"正在考虑是否要自杀！\n"+NOR, users() );
                me->add_temp("suicide_f", 1);

        }
}

int slow_suicide(object me)
{
        object link_ob;
        int stage;

        stage = me->query_temp("suicide_countdown");

        me->add_temp("suicide_countdown", -1);
        if( stage > 1 ) {
                if( stage%5 == 0 )
                        tell_object(me, HIR "你还有 " + stage*2 + " 秒的时间可以后悔。\n" NOR);
                return 1;
        }

        link_ob = me->query_temp("link_ob");
        if( !link_ob ) return 0;

        log_file("static/SUICIDE",
                sprintf("%s commits a suicide on %s\n", geteuid(me), ctime(time())) );

        seteuid(getuid());
        rm( link_ob->query_save_file() + __SAVE_EXTENSION__ );
        rm( me->query_save_file() + __SAVE_EXTENSION__ );
        write("好吧，永别了:)。\n");
        message("channel:chat", HIM+"【谣言】"+me->query("name")+"("+me->query("id")+")"+"自杀了，以后你再也看不到这个人了。\n"+NOR, users() );
        destruct(me);
        return 0;
}

int halt_suicide(object me)
{
        me->set_temp("pending/suicide",1);
       write("你经过一番苦思，最后还是觉得生命可贵，暂时打消了自杀的念头。");
        return 1;
}

int help (object me)
{
        write(@HELP
指令格式: suicide [-f]
 
如果因为某种原因你不想活了, 你可以选择自杀。
 
suicide -f : 永远的除去玩家资料, 系统会要求你
             输入密码以确认身份.
 
请慎重选择，一切自杀巫师并不给予恢复。 :)
 
HELP
);
        return 1;
}
