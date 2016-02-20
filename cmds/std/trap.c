//Cracked by Roath
//trap.c 掘地为牢
//cleansword 06/15/97

#include <ansi.h>

inherit F_CLEAN_UP;

void digging(object, int);
void create() { seteuid(getuid()); }

mapping default_dirs = ([
	"north":        "北",
	"south":        "南",
	"east":         "东",
	"west":         "西",
	"northup":      "北边",
	"southup":      "南边",
	"eastup":       "东边",
	"westup":       "西边",
	"northdown":    "北边",
	"southdown":    "南边",
	"eastdown":     "东边",
	"westdown":     "西边",
	"northeast":    "东北",
	"northwest":    "西北",
	"southeast":    "东南",
	"southwest":    "西南",
	"up":           "上",
	"down":         "下",
	"out":          "外",
	"enter":        "里",
]);

int main(object me, string arg)
{
	object roomfrom, roomto, roomtrap, *inv;
	mapping exits;
	string dir, from, to, *dirs;
	int i, depth;

	if( me->query("shen") >= 0)
	return notify_fail("你出身正派，竟敢打这种歪门邪道的主意？！\n");

	if( me->query("combat_exp") >= 100000)
	return notify_fail("如此下三烂的把戏，象你这样的高手不屑为之吧？！\n");

	if( me->query_skill("digging", 1) <= 30)
	return notify_fail("你这点本事都没学全，如何会挖掘陷阱？\n");

	if( me->is_fighting() )
	return notify_fail("一边打架一边挖掘？你真是活腻了！\n");

	if( me->is_busy() )
	return notify_fail("你现在正忙着！\n");

	if(!present("tie qiao", me))
	return notify_fail("得找把趁手的工具吧？n");

	inv = all_inventory(environment(me));
	if( sizeof(inv) > 0)
	for(i=0; i<sizeof(inv); i++) {
		if( userp(inv[i]) && inv[i] != me )
		return notify_fail("胆子这么大？现在可有旁人在场，不能挖！\n");
	}

	if( !arg || !environment(me)->query("exits/" + arg) )
	return notify_fail("你往哪个方向设陷阱？\n");

	if( strsrch(arg, "jump") >= 0 ) 
	return notify_fail("你不能往这个方向设陷阱！\n");

	if( !environment(me)->query("trap_room") )
		roomfrom = environment(me);
	else	return notify_fail("你不能在陷阱之内再设陷阱！\n");

	if( !roomfrom->query("outdoors"))
	return notify_fail("你不能这里挖掘陷阱！\n");

	if( sizeof(roomfrom->query("exits")) >= 4 )
	return notify_fail("这里是通衢大道，你不能此乱挖陷阱！\n");

	if( roomfrom->query("cost") <= 1 )
	return notify_fail("此处土质坚实，似乎难以挖掘陷阱！\n");

	if(!( roomto = find_object(roomfrom->query("exits/" + arg)) ) )
	roomto = load_object(roomfrom->query("exits/" + arg));

	if( roomto->query("trap_room") )
	return notify_fail("那边已经有了个陷阱！\n");

	if( !roomto->query("outdoors"))
	return notify_fail("你不能在别人房门口乱挖！\n");

	depth = me->query_skill("digging", 1)*10
		+ me->query_str()*2 
		+ me->query_int()*2 
		+ me->query_kar()*2
		+ me->query("jingli")/2;

	if( me->query("jingli") < depth * roomfrom->query("cost") / 10 )
	return notify_fail("你的力气不够了！\n");

	roomtrap = new("/clone/room/traproom.c");
	roomtrap->set("depth", depth/3 + random(depth*2/3));
	roomtrap->set("owner", me);
	roomtrap->set("limit", me->query_skill("digging", 1)/10);
	roomtrap->set("roomfrom", roomfrom);
	roomtrap->set("from", arg);

	if( !undefinedp(default_dirs[arg]) )
		dir = default_dirs[arg];
	else	dir = arg;

	if(objectp(roomfrom))
		roomfrom->set("exits/" + arg, file_name(roomtrap));

	if(objectp(roomto)) {
		if( strsrch(arg, "up") >= 0 || strsrch(arg, "down") >= 0 )
			roomtrap->set("exits/" + arg, file_name(roomto));
		else
			roomtrap->set("exits/" + arg + "up", file_name(roomto));

		roomtrap->set("roomto", roomto);

		exits = roomto->query("exits");
		dirs = keys(exits);
		for(i=0; i<sizeof(dirs); i++) {
			if( exits[dirs[i]] == file_name(roomfrom) ) {
				roomto->set("exits/" + dirs[i], file_name(roomtrap));
				roomtrap->set("exits/" + dirs[i] + "up", file_name(roomfrom));
				roomtrap->set("to", dirs[i]);
				break;
			}
		}
	}

	if(objectp(roomfrom) && objectp(roomto)) {
		roomfrom->set("exits/jump" + roomtrap->query("from"), file_name(roomto));
		roomto->set("exits/jump" + roomtrap->query("to"), file_name(roomfrom));
	}

	message_vision(GRN "\n$N偷偷摸摸地举起铁锹，朝着" + dir + "方猛挖一通。。。\n\n" NOR, me);
	remove_call_out("digging");
	call_out("digging", depth/100, me, depth);
	me->start_busy(depth/100);

	return 1;
}

void digging(object me, int depth)
{
	if( me->is_busy() ) {
		call_out("digging", 3, me, depth);
		if(random(5)==1) message_vision(GRN "\n$N起劲地往地下挖着挖着。。。\n" NOR, me);
	}
	else {
		me->improve_skill("digging", depth / 20);
		me->receive_damage("jingli", depth * (environment(me))->query("cost") / 10, "挖陷阱累死了");
		tell_object(me, "你大汗淋漓地挖好了一个陷阱！\n");
	}
}

int help (object me)
{
	write(@HELP
指令格式 : [trap <方向>]

这个指令让你向某个方向挖掘一个陷阱。

HELP
);
	return 1;
}
