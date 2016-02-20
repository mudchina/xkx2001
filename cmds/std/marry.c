//Cracked by Roath
// marry.c

#include <ansi.h>
#include <dbase.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob, old_app;

        if (me->is_busy())
                return notify_fail("你现在正忙着呢。\n");

	if( !arg ) 
		return notify_fail("指令格式：marry | jia <对象>\n");

	if( !(ob = present(arg, environment(me)))
	||	!ob->is_character() )
		return notify_fail("你想嫁给谁？\n");

       	if( !living(ob) ) 
		return notify_fail("你必须先把" + ob->name() + "弄醒。\n");
		
        if( (object)ob->query_temp("marriage/propose") != me ) {
        	if( (old_app = me->query_temp("marriage/accept")) == ob )
        		return notify_fail("你已经答应嫁给他了，催催他赶紧办酒席买戒指吧! \n");
        	else if( (old_app = me->query_temp("marriage/ring")) == ob )
        		return notify_fail("喜酒都喝了，快些去买戒指吧! \n");
        	else if( me->is_spouse_of(ob) )
        		return notify_fail("你已经嫁给他了! \n");
        	else
        		return notify_fail("可惜" + ob->name() + "并没有向你求婚。\n");
        }	
		
	ob->delete_temp("marriage/propose");
	
	if( me->query("age") < 16 ) {
		tell_object(ob, me->name() + "很想嫁给你，不过你得耐心等几年。\n");
		write("小孩子捣什么乱? \n");
		return 1;
	}
		
	if( me->query("gender") != "女性" ) {
		message_vision("$N嘻皮笑脸地对$n说道：“小相公，跟我回家去，保你享福...”\n", me, ob);
		return 1;		
	}	
		
	if( me->query("class") == "bonze" ) {
		tell_object(ob, me->name() + "已入佛门，你就死了这条心吧。\n");
		write("你身在佛门，这婚嫁之事，不想也罢！\n");
		return 1;
	}
	                       
        if( me->query("class") == "taoist" ) {
                tell_object(ob, me->name() + "已出家，你就死了这条心吧。\n");
                write("你已出家，这婚嫁之事，不想也罢！\n");
                return 1;
        }

 
	if( me->is_married() ) {
        	tell_object(ob, "可惜你晚了一步，" + me->name() + "已经名花有主了。\n");
		write("一女嫁二夫? 你不嫌害臊?!\n");
		return 1;
	}
		
	if( objectp(old_app) ) {
		write("你改变主意不想嫁给" + old_app->name() + "了。\n");
		tell_object(old_app, me->name() + "改变主意不想嫁给你了。\n");		
		me->delete_temp("marriage/ring");
		old_app->delete_temp("marriage/banquet");
		old_app->delete_temp("marriage/ring");
	}
	                	
	message_vision("$N羞答答地点点头, 答应嫁给$n。\n", me, ob);
	me->set_temp("marriage/accept", ob);
	ob->set_temp("marriage/banquet", me);
	return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : marry|jia <对象>
 
这个指令能让你答应嫁给某人，但你必须先等对方用 propose 指令向你
求婚。

请参考相关指令 propose、love。
HELP
        );
        return 1;
}
