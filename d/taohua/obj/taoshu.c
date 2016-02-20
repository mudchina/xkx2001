//Cracked by Roath

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(GRN"桃树"NOR, ({ "tao shu", "shu", "tree" }) );
	set_weight(300000);
	set_max_encumbrance(5000000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "株");
                set("long", "这是一株枝叶繁茂的桃树，比之桃花岛上其它桃树要大上许多。\n"
			    "似乎应该砍下(kan)些枝叶修理修理了。\n");
		set("value", 1000);
		set("material", "wood");
		set("no_get",1);
	}
	setup();
}

void init()
{
	add_action("do_slash", "kan");
}

int do_slash(string arg)
{
	object ob1, ob2, ob3, ob4, me;

	me = this_player();
	ob1 = present("xiao tiefu", me);

        if (me->is_busy()
        || me->query_temp("pending/exercising")
        || me->query_temp("exit_blocked"))
                return notify_fail("你现在正忙着呢。\n");

        if( !objectp(ob1 = me->query_temp("weapon"))
        || (string)ob1->query("skill_type") != "axe")
                return notify_fail("你没有称手家伙如何伐木？！\n");	

        if( (string)ob1->query("name") != "小铁斧" ) {
		message_vision(CYN"$N一声大喝，手持"+ob1->query("name")+"目露凶光，对桃树恶狠狠的砍了过去！\n"NOR, me);
                message_vision(CYN"只听得“喀嚓”一声，桃树被拦腰砍为两段！\n"NOR,me);
		destruct(this_object());
		return 1;
//		return notify_fail("你麻烦大了。\n");
	}

	if (!arg || (arg != "shu" && arg !="tree" && arg != "tao shu"))
		return notify_fail("你要砍什麽？！\n");
	if (query("slashed"))
		return notify_fail("这株桃树已经被修整过了！\n"); 	

	message_vision(CYN"$N衣袖一卷，抽出一把小铁斧，“吭哟！吭哟”的劈下一段段的桃枝......\n"NOR, me);

	message_vision(CYN"$N擦了擦汗，拾起几根桃木枝。\n"NOR, me);
	ob2 = new(__DIR__"taomu");
	ob2->move(me);
        ob3 = new(__DIR__"taomu");
        ob3->move(me);
        ob4 = new(__DIR__"taomu");
        ob4->move(me);
	set("slashed", 1);
	set("long", "这是一株枝叶繁茂的桃树，比之桃花岛上其它桃树要大上许多。\n"
                    "似乎刚被修整过。\n");

	call_out("renew", 300, me);
	return 1;
}

void renew()
{
	this_object()->delete("slashed");
	set("long", "这是一株枝叶繁茂的桃树，比之桃花岛上其它桃树要大上许多。\n"
                    "似乎应该砍下(kan)些枝叶修理修理了。\n");
}
