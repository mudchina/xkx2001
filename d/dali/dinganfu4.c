//Cracked by Roath
// Room: /d/dali/dinganfu4.c

inherit ROOM;

void create()
{
	set("short", "厢房");
	set("long", @LONG
这是大理国女子官员的卧室，武将及以下级别的官员可在此休息睡觉，几张
张收拾得干干净净的床铺沿墙摆了一圈。
LONG);
	set("exits", ([
		"west" : __DIR__"dinganfu2",
		]));
	set("no_fight", 1);
	set("no_clean_up", 0);
	set("sleep_room", 1);
	setup();
}
void init()
{
	add_action("do_get", "get");
}
int do_get(string arg)  
{
	string a,b,c;
	object obj;

	if (arg && objectp(obj = present(arg, environment(this_player()))) && obj->is_character())
	{
		write("你不能搬动玩家的身体。\n");
		return 1;
	}
	if (!arg || sscanf(arg, "%s %s %s", a, b, c) != 3 ) return 0;
	if (b != "from") return 0;
	if (objectp(obj = present(c, environment(this_player()))) && obj->is_character())
	{
		write("你不能从睡着了的玩家身上偷东西。\n");
		return 1;
	}
	return 0;
}
