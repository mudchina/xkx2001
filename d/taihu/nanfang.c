//Cracked by Roath
//Kane

inherit ROOM;

void create()
{
	set("short", "男厢房");
	set("long", @LONG
这里是归云庄男弟子的休息室，摆着几张木床。床旁都有一支
高脚架子，用来挂衣物。西首一扇小窗。外面是花园。
LONG
	);
	set("sleep_room", 1);
        set("no_fight", 1);

	set("exits", ([
		"west" : __DIR__"huating",
	]));
	set("cost", 1);
	set("outdoors", "taihu");

	setup();
	replace_program(ROOM);
}
