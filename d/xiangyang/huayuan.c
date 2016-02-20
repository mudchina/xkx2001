//Cracked by Roath
// Room: /d/xiangyang/huayuan.c

inherit ROOM;

void create()
{
	set("short", "後花园");
	set("long", @LONG
你来到花园中，觉宁静安闲，楼阁庭院秀丽雅致，花木扶疏
，幽香扑鼻。假山前小桥流水，造景清幽，几块太湖石散布其前。
鹅卵石小径分向两边，西南角有条小路绕过山石，东边通达一列厢
房。
LONG
	);
	set("outdoors", "xiangyang");
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : 3, "y" : -6 ]) );
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"huajing",
  "east" : __DIR__"huajing2",
  "southwest" : __DIR__"xiaolu",
]));

	setup();
	replace_program(ROOM);
}
