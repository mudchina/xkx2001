//Cracked by Roath
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name( HIC "玄木令" NOR, ({ "xuan mu ling", "ling"}) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "枚");
                set("long", "这是似铁非铁，似木非木的令牌便是玄劫教教主的信物玄木令。\n"
			    "见玄木令如见教主，玄木令所到之处，任何玄劫教弟子都不能违\n"
			    "背持令者的命令！\n");
                set("material", "iron");
        }
        setup();
}

void init()
{
	add_action( "do_appoint", "appoint" );
	add_action( "do_invite", "invite" );
	add_action( "do_throne", "throne" );
	add_action( "do_expell", "kaige" );
	add_action( "do_say", "say" );
}

int do_appoint(string arg)
{
	object ob, me = this_player();
	string who, pos, title;

//	if ( me->query("xjjz") < 1 )
//	   return notify_fail( "你不是玄劫教教主，无权使用这个令牌。\n" );

	if ( !arg )
	   return notify_fail( "指令：appoint <sb> as <fjz|hufa|ttzs|ttys|rdzs|rdys|zhanglao>。\n" );

	if ( sscanf(arg, "%s as %s", who, pos) != 2 ) 
	   return notify_fail( "指令：appoint <sb> as <fjz|hufa|ttzs|ttys|rdzs|rdys|zhanglao>。\n" );

	if ( pos == "fjz" ) title = "玄劫教副教主";
	else if ( pos == "hufa" ) title = "玄劫教护法";
	else if ( pos == "ttzs" ) title = "玄劫教通天左使";
	else if ( pos == "ttys" ) title = "玄劫教通天右使";
        else if ( pos == "rdzs" ) title = "玄劫教入地左使";
        else if ( pos == "rdys" ) title = "玄劫教入地右使";
	else if ( pos == "zhanglao" ) title = "玄劫教长老";
	else return notify_fail( "没有这个职位！\n" );

	if ( !(ob=present(who,environment(me))) )
	   return notify_fail( "这里并无此人！\n" );

//	if ( ob == me )
//	   return notify_fail( "你已是教主，位极荣宠，还争什劳子职位？\n" );

	if ( ob->is_character() && !living(ob) )
	   return notify_fail( "等此人转醒再说吧！\n" );

	if ( !living(ob) )
           return notify_fail( "你老眼昏花啦？这并非活物！该退位让贤了！\n" );	

	if ( !ob->query("xjjt") )
	   return notify_fail( "此人并非玄劫教中人，不能接受委任！\n" );

	message_vision( "$n委任$N为"+title+"。\n", ob, me );
	ob->set("title", title);

	return 1;
}

int do_throne(string arg)
{
        object ob, me = this_player();
	int gen;

	gen = (int)me->query("xjjz") + 1;

        if ( me->query("xjjz") < 1 )
           return notify_fail( "你不是玄劫教教主，无权使用这个令牌。\n" );

        if ( !arg )
           return notify_fail( "指令：throne <sb>。\n" );

	if ( !(ob=present(arg,environment(me))) )
           return notify_fail( "这里并无此人！\n" );

	if ( ob == me )
	   return notify_fail( "传位给你自己？不必多此一举！\n" );

	if ( ob->is_character() && !living(ob) )
           return notify_fail( "等此人转醒再说吧！\n" );

        if ( !living(ob) )
           return notify_fail( "你老眼昏花啦？这并非活物！该退位让贤了！\n" );

	if ( !ob->query("xjjt") )
           return notify_fail( "此人并非玄劫教中人，不能直接成为新教主！\n" );

        message_vision( "$N成为玄劫教第"+chinese_number(gen)+"任教主！\n", ob );
	CHANNEL_D->do_channel(me,"chat",sprintf("%s成为玄劫教第"+chinese_number(gen)+"任教主！我教一统江湖，指日可待！",ob->name()));
	message_vision( "$n将玄木令交给$N，郑重地说：以后玄劫教的重担便交给你了！\n", ob, me);
	this_object()->move(ob);

	me->set("title", "玄劫教前任教主");
	me->delete("xjjz");
	me->set("xjjt", 1);
	ob->set("title", "玄劫教教主");
	ob->set("xjjz", gen);
	ob->delete("xjjt");

	return 1;
}

int do_invite(string arg)
{
	object ob, me = this_player();

//      if ( me->query("xjjz") < 1 )
//         return notify_fail( "你不是玄劫教教主，无权使用这个令牌。\n" );

        if ( !arg )
           return notify_fail( "指令：invite <sb>。\n" );

        if ( !(ob=present(arg,environment(me))) )
           return notify_fail( "这里并无此人！\n" );

	if ( ob == me )
	   return notify_fail( "你已是教主，位极荣宠，何需入教？\n" );

        if ( ob->is_character() && !living(ob) )
           return notify_fail( "等此人转醒再说吧！\n" );

        if ( !living(ob) )
           return notify_fail( "你老眼昏花啦？这并非活物！该退位让贤了！\n" );

	if ( ob->query("xjjt") )
           return notify_fail( "此人经已入教，不需多此一举！\n" );

	message_vision( "$n正式邀请$N加入玄劫教。\n", ob, me);
	message_vision( "$n庄重将玄木令教给$N说道：如你愿意入教，对着本教的玄木令立誓说你愿意吧。\n", ob, me);
	this_object()->move(ob);
	ob->set_temp("invited", 1);
	ob->set_temp("xjjz", me->query("id"));

	return 1;
}

int do_say(string arg)
{
	object ob, me = this_player();

	if ( !arg || arg=="" ) return 0;

	if ( arg == "愿意" && me->query_temp("invited") ) {
	   if ( !(ob = present(me->query_temp("xjjz"),environment(me))) ) return 0;
//	   ob = present(me->query_temp("xjjz"),environment(me));
	
	   message_vision( "$n恭恭敬敬地跪下向$N磕了三个响头说道：属下愿为教主效命，赴汤蹈火，万死不辞！\n", ob, me);
	   message_vision( "$n双手将玄木令高举过顶还给$N，站起身来。\n", ob, me);
	   this_object()->move(ob);

	   me->set("xjjt", 1);
	   me->set("title", "玄劫教长老");
	   me->delete_temp("invited");
	   me->delete_temp("xjjz");	
	   return 1;
	}

	return 0;
}

int do_expell(string arg)
{
	object ob, me = this_player();

//      if ( me->query("xjjz") < 1 )
//         return notify_fail( "你不是玄劫教教主，无权使用这个令牌。\n" );

        if ( !arg )
           return notify_fail( "指令：expell <sb>。\n" );

        if ( !(ob=present(arg,environment(me))) )
           return notify_fail( "这里并无此人！\n" );

	if ( ob == me )
	   return notify_fail( "你想解散玄劫教？\n" );

        if ( ob->is_character() && !living(ob) )
           return notify_fail( "等此人转醒再说吧！\n" );

        if ( !living(ob) )
           return notify_fail( "你老眼昏花啦？这并非活物！该退位让贤了！\n" );

        if ( !ob->query("xjjt") )
           return notify_fail( "此人并非玄劫教中人，无须开革！\n" );

        message_vision( "$n将$N开革出玄劫教。\n", ob, me);
	ob->delete("xjjt");
	ob->set("title", "普通百姓");

	return 1;
}
