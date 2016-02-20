//Cracked by Roath
// 白玉峰
// maco
#include <ansi.h>

inherit ROOM;
string look_long();
string look_door();
string look_axe();
string look_lock();
string look_loop();
string look_skeleton();

void create()
{
	set("short", "白玉通道");
	set("long", (: look_long :));

	set("exits", ([
		"south" : __DIR__"jaderoad2",
	]));
	set("item_desc", ([
	"door" : (: look_door :),
	"axe" : (: look_axe :),
	"lock" : (: look_lock :),
	"loop" : (: look_loop :),
	"skeleton" : (: look_skeleton :),
	]));

	set("cost", 1);
	set("loop_rust", 1);
	set("lock_rust", 1);

	set("door_axe", 1);
	set("door_lock", 1);
	setup();
}

string look_long()
{
	object armor = new("/d/xingxiu/obj/jinjia");
	string desc;
	desc = 
	"一条长长的甬道，前面山石阻路，尽头处有一道石门(door)。\n";
	if (armor) {
	desc += HIY"只见尽头处闪闪生光，似有一堆黄金。"NOR+"走近看时，却是一副黄金盔甲，\n甲胄中是一堆枯骨(skeleton)。\n";
	destruct(armor);
	}
	else desc += "";
	return desc;
}

string look_door()
{
	object axe = new("/clone/unique/jinfu");
	string msg, desc;
	if(axe) {
	msg = HIY"金斧"NOR;
	destruct(axe);
	}
	else msg = "钢斧";

	desc = "这门厚达丈许，直是一块巨大的岩石。\n";
	if(query("door_axe"))
	desc += "一把"+msg+"(axe)插在玉石巨门的门环(loop)里。\n";
	if(query("door_lock")) 
	desc += "上下左右还有四个门环，均有两尺多长的粗大铁钮(lock)扣住。\n";

	if(query("exits/enter"))
	desc += "现在门是开着的。\n";
	return desc;
}

string look_axe()
{
	object axe = new("/clone/unique/jinfu");
	string msg, desc;
	if(axe) {
	msg = HIY"金斧"NOR;
	destruct(axe);
	}
	else msg = "钢斧";

	if(!query("door_axe")) return 0;
	
	desc = msg+"插在一个大门环里。\n";
	return desc;
}

string look_lock()
{
	string desc;
	if(!query("door_lock"))
	desc = "石门四角的铁钮都掀起来了。\n";
	else desc = "四个铁钮扣住了石门四角。\n";
	return desc;
}

string look_loop()
{
	object axe = new("/clone/unique/jinfu");
	string msg, desc;
	if(axe) {
	msg = HIY"金斧"NOR;
	destruct(axe);
	}
	else msg = "钢斧";

	if(!query("door_axe")) desc = "一个大门环，便於用以拉开(pull)石门。\n";	
	else desc = "一把"+msg+"插在门环里。\n";
	return desc;
}

string look_skeleton()
{
	object armor = new("/d/xingxiu/obj/jinjia");
	object me = this_player();
	string desc;
	if(armor) {
	message_vision("$N将"+armor->name()+"从骸骨上取下，看了看骸骨。\n", me);

	desc = "这骸骨生前或许还是个国王或者是王子。西域古国中，只有国王才能以飞骆驼作徽记。\n";	
	CHANNEL_D->do_channel(me, "rumor", sprintf("%s弄到了一副黄金盔甲。", me->query("name")));
	armor->move(this_player());
	return desc;
	}
	else return "你要看什么？\n";
}

void init()
{
	add_action("do_scrape", "scrape");
	add_action("do_push", "push");
	add_action("do_pull", "pull");
}

int do_scrape(string arg)
{
	object me, room, weapon;
	string type;

	me = this_player();
	
	if( !arg || arg=="" ) return notify_fail("你要刮什麽东西？\n");

	if (me->is_busy() || me->query_temp("pending/exercising"))
		return notify_fail("你正忙着呢。\n");

	if( !objectp(weapon = me->query_temp("weapon")) ) 
		return notify_fail("你得找些称手的工具。\n");

	type = weapon->query("skill_type");
	if(type != "sword" && type != "blade" && type != "axe" ) 
		return notify_fail(weapon->name()+"不适合用来刮铁锈。\n");

	if( arg == "door")
		return notify_fail("玉石巨门上没什麽好刮的。\n");

	if( arg == "loop") {
		if(!query("loop_rust")) 
			return notify_fail("门环上的铁锈已经刮得乾乾净净了。\n");
	message_vision("$N用"+weapon->name()+"刮去门环上的铁锈。\n", me);
	me->add("jingli", -30);
	delete("loop_rust");
	return 1;
	}
	if( arg == "lock") {
		if(!query("lock_rust")) 
			return notify_fail("铁钮上的铁锈已经刮得乾乾净净了。\n");
	message_vision("$N用"+weapon->name()+"刮去四个铁钮上的铁锈。\n", me);
	me->add("jingli", -120);
	me->start_busy(1);
	delete("lock_rust");
	return 1;
	}

	return 0;
}

int do_pull(string arg)
{
	object me, room;
	object axe;
	string msg;

	me = this_player();

	if( !arg || arg=="" ) return notify_fail("你要拉什麽？\n");

	if( arg=="axe" )
	{
		axe = new("/clone/unique/jinfu");

		if(axe) msg = HIY"金斧"NOR;
		else {
		msg = "钢斧";
		axe = new("/d/dali/obj/gangfu");
		}

		if(!query("door_axe"))
			return notify_fail("你要拉什麽？\n");

		if(query("loop_rust")) {
			destruct(axe);
			return notify_fail("你伸手去拔"+msg+"，但门环上的铁锈已锈住斧柄，取不出来，看来得先刮掉(scrape)铁锈。\n");
		}
		message_vision("$N双手拔出"+msg+"，入手甚是沉重。\n", me);
		axe->move(me);
		delete("door_axe");
		if(msg == HIY"金斧"NOR) CHANNEL_D->do_channel(me, "rumor", sprintf("%s弄到了一把黄金斧。", me->query("name")));

		return 1;
	}

	if( arg=="lock" )
	{
		if(!query("door_lock"))
			return notify_fail("铁钮已经被掀起来了。\n");

		if(query("lock_rust")) 
			return notify_fail("你伸手去掀铁钮，但铁钮已经生锈，掀不起来，看来得先刮掉(scrape)铁锈。\n");
		message_vision("$N将铁钮一一掀起。\n", me);
		delete("door_lock");
		return 1;
	}
	
	if( arg=="door" ) return notify_fail("石门上光溜溜的无着手之处，拉门环(loop)吧。\n");

	if( arg=="loop" ) {
		if(query("exits/enter")) {
		message_vision("$N使劲拉动门环，石门叽叽地响了几声，接着蓬的一声大响，石门关上了。\n", me);
		delete("exits/enter");
			if( room = find_object(__DIR__"jaderoad4") ) {
			room->delete("exits/out");
			message("vision", "只听得叽叽之声，接着蓬的一声大响，石门已从外面给人关上。\n", room );
			}
		return 1;
		}
		else {
		message_vision("$N抓住门环向里一拉，玉石巨门纹丝不动。\n", me);
		return 1;
		}
	}

	return 0;
}

int do_push(string arg)
{
	object me, room;
	me = this_player();

	if( !arg || arg=="" ) return 0;

	if( arg == "door") {

	if (me->is_busy() || me->query_temp("pending/exercising"))
		return notify_fail("你正忙着呢。\n");

	if (query("exits/enter"))
		return notify_fail("玉石巨门已经被推开了。\n");

	if(query("door_axe"))
		return notify_fail("你得先把穿过门环中的斧头拔出(pull)。\n");

	if(query("door_lock"))
		return notify_fail("你得先把扣住门的铁钮掀起(pull)。\n");

	message_vision("$N双手撑门，用力向外推去，玉石巨门叽叽发声，缓缓开了。\n", me);

	me->add("jingli", -50);

	set("exits/enter", __DIR__"jaderoad4");
		if( room = find_object(__DIR__"jaderoad4") ) {
			room->set("exits/out", __FILE__);
			message("vision", "你听得叽叽几声，有人从外面将玉石巨门推开了。\n",room );
		}
	return 1;
	}
	else return notify_fail("你要推什麽？\n");
}

