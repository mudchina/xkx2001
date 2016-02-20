//Cracked by Roath
// Room: /d/dali/dlkd2.c

inherit ROOM;

void create()
{
	set("short", "客店二楼");
	set("long", @LONG
这家客店是座竹楼，你二楼的走廊上，可以听到从客房里不时地呼呼的打酣
声，一阵高过一阵。不时有睡意朦胧的旅客进进出出，到楼下的掌柜处付了钱再
上来睡觉。
LONG);
	set("exits", ([
		"down" : __DIR__"dlkd1",
		"enter" : __DIR__"dlkd3",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("no_sleep_room",1);
	setup();
}
int valid_leave(object me, string dir)
{
	if(me == present("xiao er"))
		return ::valid_leave(me, dir);

	if ( !me->query_temp("rent_paid") && dir == "enter" )
		return notify_fail("门锁着呐，进不去! \n");

	return ::valid_leave(me, dir);
}
