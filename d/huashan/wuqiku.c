//Cracked by Roath
// wuqiku.c 华山兵器房
// qfy July 7, 1996

inherit ROOM;

void create()
{
	set("short", "兵器房");
	set("long", @LONG
这里是华山派的兵器房，墙上各处挂了许多长剑，短剑和竹剑。
LONG
	);

	set("exits", ([
		"east" : __DIR__"square",
	]));

	set("objects", ([
		__DIR__"obj/changjian" : 2,
		__DIR__"obj/duanjian" : 2,
		__DIR__"obj/zhujian" : 3,
	]));

	set("cost", 0);
	setup();
	//replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	object *inv;
	int i, j=0;

	inv = all_inventory(me);

	for (i=0; i<sizeof(inv); i++) {
		if ((string)inv[i]->query("skill_type")=="sword") j++;
        }
	
	if ( j == 1 ) me->set_temp("marks/剑", 1);
	if ( j > 1 ) return notify_fail("别那么自私！你不能带走超过一把兵器。\n");

	return ::valid_leave(me, dir);
}

