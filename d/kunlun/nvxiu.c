//Cracked by Roath
// Room: /d/mingjiao/nvxiu.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "女寝室");
	set("long", @LONG
室中轻漫着一种幽香，靠南墙下是一座松木梳妆台，上悬一圆形铜镜。
西边是几张松床，轻纱漫掩，似有人正在就寝。东面有两三个女弟子围着
木桌，轻嘻笑语，其中一位忽然面上一红，低头笑而不语。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"zoulang46",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
