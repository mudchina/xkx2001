//Cracked by Roath
// Room: /d/dali/chhill2.c

inherit ROOM;

int do_get(string);

void create()
{
	set("short", "茶花山坡");
	set("long", @LONG
你走在茶花山的坡道上，坡道上遍地生长茂盛的茶花。大部分是凡品，但偶
尔也会有一两株佳品藏匿其中。西望不远是大理城的城墙。
LONG);
	set("objects", ([
		__DIR__"obj/chahua" : 1,
		]));
	set("exits", ([
		"northup" : __DIR__"chhill3.c",
		"southdown"  : __DIR__"minov3",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
}
void init()
{
	add_action("do_get","get");
}
int do_get(string arg)
{
	object me, ob, weapon;
	me=this_player();

	if (arg=="cha" || arg=="chahua" || arg=="all" || arg=="cha hua")
	{
		if (!objectp(ob=present("cha", environment(me))))
		{
			tell_object(me, "这里没什么好品种的茶花值得挖走。\n");
			return 1;
		}
		if (!objectp(weapon=me->query_temp("weapon"))
			|| weapon->query("id")!="huachu")
		{
			tell_object(me, "你没有称手的工具来移植这株茶花！\n");
			return 1;
		}
		if (random(2)==1)
		{
			message_vision("$N小心翼翼地用花锄掘出茶花的根，把整株茶花移了起来。\n", me);
			ob->move(me);
		}
		else
		{
			message_vision("$N急急忙忙地挖茶花，一不小心把根挖断了，好好的一株茶花，完了。\n", me);
			destruct(ob);
		}
		return 1;
	}
	return 0;
}
