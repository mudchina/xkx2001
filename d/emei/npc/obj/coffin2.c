//Cracked by Roath
// /d/emei/obj/coffin.c 石棺

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIW"石棺"NOR, ({ "coffin", "guan cai", "guan" }) );
	set_weight(3000);
	set_max_encumbrance(50000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "口");
                set("long", "这是一具白玉石雕成的石棺，里面躺着一具骸骨。\n");
		set("value", 1000);
//		set("material", "stone");
		set("no_get",1);
		set("no_drop",1);
//		set("objects",  ([__DIR__"obj/ruanwei-jia" : 1,]) );
	}
	setup();
}

int is_container() { return 1; }

void init()
{
	add_action("do_put", "put");
	add_action("do_open", "open");
}

int do_put(string arg)
{
	object me, obj;
	string item, target; 
	int amount;

	me = this_player();

	if( !arg || sscanf(arg, "%s in %s", item, target) != 2 )
                return notify_fail("你要将什么东西放进哪里？\n");
                
        if( item == "all" ) {
		write("还是一样一样来吧。\n");
		return 1;
	}
                                                                
	sscanf(item, "%d %s", amount, item);
	
	if( !objectp(obj = present(item, me)) )
		return notify_fail("你要给谁什么东西？\n");

	if( obj->query("no_drop") ) {
		write("这样东西不能离开你。\n");
		return 1;
	}
	return 0;
}

int do_open(string arg)
{
	if ( !arg && ( arg != "coffin" ) && ( arg != "guan" ) )
		return notify_fail("什么？\n");

	return notify_fail("白玉石棺盖已经是开的了。\n");
}


