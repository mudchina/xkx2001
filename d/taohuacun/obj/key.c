// key.c
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("私房钥匙", ({"key", "yaoshi"}));
	set("long",
		"这是一把桃花村私人住宅的钥匙。
可以用来开门(unlock)和关门(lock)。\n");
	set("unit", "把");
	set("weight", 10);
	set("no_put",1);
	set("no_get",1);
	set("no_drop",1);
}

string query_autoload() { return 1 + ""; }	//autoload weapon

void init()
{
        add_action("do_lock","lock");
	add_action("do_unlock","unlock");
}

int do_unlock()
{
	object table, bottle, rose, room, here, me = this_player();

	if (!me->query("home"))
		return notify_fail("你没私宅呀，在这开什么开！\n");
	if ((string)environment(me)->query("short")!="桃花坪")
		return notify_fail("你的私宅在桃花谷里桃花坪上！\n");
	room = new("/d/taohuacun/obj/player");
	room -> set("short", me->query("home/home_name"));
	room -> set("long", me->query("home/home_desc")+"\n");
	if(!( here = find_object("/d/taohuacun/taohua5")) )
		here = load_object("/d/taohuacun/taohua5");
	here->set("exits/enter", file_name(room) );
	room->set("exits/out", "/d/taohuacun/taohua5" );
	table = new("/d/taohuacun/obj/table");
	bottle = new("/d/taohuacun/obj/bottle");
	rose = new("/d/taohuacun/obj/rose");
	rose -> move(bottle);
	bottle -> move(table);
	table -> move(room);
        set("sleep_room", "1");
	room->set("sleep_room","1");
	message_vision(HIG "$N掏出钥匙，轻轻一旋，举手推开房门。\n" NOR,me);
	return 1;
}
int do_lock()
{
	object here;
	if(!( here = find_object("/d/taohuacun/taohua5")) )
		here = load_object("/d/taohuacun/taohua5");
	here->delete("exits/enter");
	message_vision(HIG "只听得碰的一声响，$N把房门关上了。\n" NOR, this_player());
	return 1;
}
