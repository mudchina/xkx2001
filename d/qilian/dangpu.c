//Cracked by Roath
// Room: /d/qilian/dangpu.c

inherit ROOM;

void create()
{
	set("short", "铁面当铺");
	set("long", @LONG
这是家远近闻名的当铺，三开间的门面，一块写着『铁面当铺』四
个金字的黑匾，足足七尺高的紫檀木的柜台被磨得光可照人，柜台后面
有五个大柜子，分别陈列着各式武器(weapon)、护具穿戴(armor)、药
物(drug)、书藉(book)、和其它各式杂物(misc)。柜台后柜台后的老
朝奉头也不抬的只顾拨拉着算盘，柜台上方挂着一块牌子，上书："你
情我愿，概不赊欠"。
LONG
	);
	set("no_sleep_room", "1");
	set("no_clean_up", 0);
	 set("no_beg",1);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"lanzhou",
]));
	set("objects", ([
		__DIR__"npc/chaofeng" : 1,
	]));
	setup();
	replace_program(ROOM);
}
