//Cracked by Roath
// haohanpo.c 武当好汉坡
// by Fang 8/19/96

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"好汉坡"NOR);
	set("long", @LONG
	此处连绵十几里山势陡峭，名为好汉坡，山路两旁种满了细竹，翠色横空
景象怡人，不知不觉让你忘记了爬坡的疲劳。坡顶有一座回龙观，是展望岳顶的最
佳去处，但见天柱峰青紫插天，如在眼前，而相去实际上还有五十里。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"southdown" : __DIR__"shanlu",
		"northdown" : __DIR__"bailin",
	]));

	set("cost", 3);
	setup();
	replace_program(ROOM);
}

