//Cracked by Roath
//Chaos, Ryu, 3/10/97

inherit ROOM;

void create()
{
	set("short", "树林");
	set("long", @LONG
这是一片普通树林，与岛上一入就迷失方向的桃林不大一样。林中一条小路横贯
东西。东北面地势越来越高，似乎有座山峰；往东走树林愈现茂密，看来不太好走。
LONG
	);
	 set("exits", ([
                "west" : __DIR__"xiaojing",
                "east" : __DIR__"shulin2",
        ]));
	set("cost", 4);
	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}
