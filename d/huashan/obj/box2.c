//Cracked by Roath
// box2.c 小铁盒

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("铁盒", ({"tie he", "he", "box"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("long",
			"此盒高约一尺见方，不知道里面装着什么东西。\n");
                set("material", "steel");
		set("value", 100);
        }
}

void init()
{
	add_action("do_open", "open");
}

int do_open(string arg)
{
	object ob1, ob2, me=this_player();

	if ( !arg || arg =="" )
		return notify_fail("你要将什么打开？\n");

	if ( ob1 = present(arg, me) ) {
		message_vision("$N打开小铁盒，发现一盒中有封信柬和一本书。\n", me);
		write( "信柬上写着：君是忠厚仁者，葬我骸骨，当酬以重宝秘术。\n" );
		write( "大铁盒开启时有毒箭射出，盒中书谱地图均假，上有剧毒，\n" );
		write( "以惩贪欲恶徒。真者在此小盒内。\n" );

		ob2=new(__DIR__"jinshe_book2");
		ob2->move(me);
		destruct(ob1);

	   	return 1;
	}
	else return 0;
}
