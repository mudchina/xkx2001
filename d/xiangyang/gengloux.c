//Cracked by Roath
// Room: /d/xiangyang/gengloux.c

inherit ROOM;

void create()
{
	set("short", "更楼巷");
	set("long", @LONG
这是一条死巷，再上去通更楼。地上乱放了些残羹剩饭，一旁几张藤椅子
上坐着几个懒懒散散的人，其中一两个埋头大睡，其他杂人则互相嬉闹，没人
在意你的来到。
LONG
	);
        set("coordinates", ([ "x" : 1, "y" : 2 ]) );
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "southup" : __DIR__"genglou",
  "west" : __DIR__"beijie1",
]));
	set("outdoors", "xiangyang");

	setup();
	replace_program(ROOM);
}
