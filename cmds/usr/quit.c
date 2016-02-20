// Change by Server
// quit.c
//last update: Marz added forced_quit on 07/06/96

#include <command.h>

inherit F_DBASE;
inherit F_CLEAN_UP;

private int slow_quit(object);

void create() 
{
	seteuid(getuid());
	set("channel_id", "离线指令");
	set("id", "quit");
}

int main(object me, string arg)
{
	if( (me->is_busy() || me->is_fighting() || me->query_temp("cursed", 1)) 
	&&  !me->query_temp("quit/forced") )
		return notify_fail("你现在正忙着做其他事，不能退出游戏！\n");

	if ( me->query_temp("quit/forced") ) call_out("slow_quit", 0, me);
	
	if( me->query_temp("quitting") )
		return notify_fail("游戏退出进程已经启动，正在进行中！\n");

	if( environment(me)->query("invalid_startroom") ) 
	{
	// the following two lines added by Mongol. 6/12/97.  To avoid login
	// from hell, etc.
//		me->delete("startroom");
		me->set("startroom", "/d/city/kedian");
		tell_object( me, "\n你在一个不能进入游戏的地方退出，下次进入游戏将从别的地方开始。\n");
		me->set_temp("quitting", 1);
		tell_object( me, "\n开始退出游戏，进行中 ...\n\n" );
		call_out("slow_quit", 10 + random(10), me);
	} else if( environment(me)->query("valid_startroom") ) {
		me->set("startroom", base_name(environment(me)));
		me->set_temp("quitting", 1);
		slow_quit(me);
	} else {
		tell_object( me, "\n开始退出游戏，进行中 ...\n\n" );
		me->set("startroom", base_name(environment(me)));
		me->set_temp("quitting", 1);
		call_out("slow_quit", 10 + random(10), me);
	}

	return 1;
}

private int slow_quit(object me)
{
	int i, stage;
	string msg;
	object *inv, link_ob;

	if( objectp(me) && wizhood(me) == "(player)" ) {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++) {
			if( !inv[i]->query_autoload() )
				DROP_CMD->do_drop(me, inv[i]);

			if( me->query_encumbrance() > me->query_max_encumbrance() ) {
			    if( base_name(inv[i]) == GOLD_OB || base_name(inv[i]) == SILVER_OB ) {
				tell_object(me, "你带了太多金钱超重了！只好将"+inv[i]->name()+"丢弃了！\n");
				destruct(inv[i]);
			    }
			}
		}
			
	}

	if (!me) return 1;
	link_ob = me->query_temp("link_ob");

	// We might be called on a link_dead player, so check this.
	if( link_ob ) {

		// Are we possessing in others body ?
		if( link_ob->is_character() ) {
			write("你的魂魄回到" + link_ob->name(1) + "的身上。\n");
			exec(link_ob, me);
			me->delete_temp("quitting");
			link_ob->setup();
			return 1;
		}

		link_ob->set("last_on", time());
		link_ob->set("last_from", query_ip_name(me));
		link_ob->save();
		LOGIN_D->write_log(link_ob);
		destruct(link_ob);
	}

	write("欢迎下次再来！\n");
	message("system", me->name() + "离开游戏。\n", environment(me), me);

	if (stringp(msg = me->query_temp("quit/report_msg")))
		CHANNEL_D->do_channel(this_object(), "sys", me->name() + msg);
	else	
		CHANNEL_D->do_channel(this_object(), "sys", me->name() + "离开游戏了。");

	me->save();
	destruct(me);

	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : quit

当你(你)想暂时离开时, 可利用此一指令。
HELP
    );
    return 1;
}

