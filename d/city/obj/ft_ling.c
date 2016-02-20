//Cracked by Roath
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name( HIC "斧头令" NOR, ({ "futou ling", "ling"}) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "枚");
                set("long", 
	"这枚斧头令乃是斧头帮主用来接纳 (jiena) 或者开除 (kaichu) 帮众的信物．\n"
	 	   );
                set("material", "iron");
        }
        setup();
}

void init()
{
	add_action( "do_jiena", "jiena" );
	add_action( "do_kaichu", "kaichu" );
}

int do_jiena(string arg)
{
    object ob, me = this_player();

    if ( me->query("futou_bang") < 1 )
         return notify_fail( "你不是斧头帮众，无权使用这个令牌。\n" );

    if ( !arg )
           return notify_fail( "指令：jiena <sb>。\n" );

        if ( !(ob=present(arg,environment(me))) )
           return notify_fail( "这里并无此人！\n" );

	if (ob == me) 
	    return notify_fail("你已经是斧头帮的了．\n");

        if ( ob->is_character() && !living(ob) )
           return notify_fail( "等此人转醒再说吧！\n" );

        if ( !living(ob) )
           return notify_fail( "你老眼昏花啦？这并非活物！该退位让贤了！\n" );

	if ( ob->query("futou_bang") )
           return notify_fail( "此人经已入帮，不需多此一举！\n" );

	message_vision( "$n正式邀请$N加入斧头帮。\n", ob, me);
	ob->set("futou_bang", 10);

	return 1;
}

int do_kaichu(string arg)
{
	object ob, me = this_player();

      if ( me->query("futou_bang") < 1 )
         return notify_fail( "你不是斧头帮众，无权使用这个令牌。\n" );

        if ( !arg )
           return notify_fail( "指令：expell <sb>。\n" );

        if ( !(ob=present(arg,environment(me))) )
           return notify_fail( "这里并无此人！\n" );

        if ( ob->is_character() && !living(ob) )
           return notify_fail( "等此人转醒再说吧！\n" );

        if ( !living(ob) )
           return notify_fail( "你老眼昏花啦？这并非活物！该退位让贤了！\n" );

        if ( !ob->query("futou_bang") )
           return notify_fail( "此人并非帮中之人，无须开革！\n" );

        message_vision( "$n将$N开革出斧头帮。\n", ob, me);
	ob->delete("futou_bang");

	return 1;
}
