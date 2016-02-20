//Cracked by Roath
// Room: /d/dali/southgate.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"南门"NOR);
	set("long", @LONG
此间是大理国都大理城的南门，大理城实名阳苜咩城，南诏于初建来，经历
代而至当今的段氏的“大理国”，皆以此城为都。城墙由石块和土垒成，高二丈
五，厚达二丈。城下三两个盔甲鲜明的军士瞪大了眼睛观察着来来往往的行人，
偶尔盘问几个形迹可疑份子。
LONG);
	set("objects", ([
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/dalishibing" : 3,
		]));
	set("exits", ([
		"eastup" : __DIR__"minov12",
		"north" : __DIR__"dalicheng12",
		"south" : __DIR__"shqiao",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	set("no_sleep_room",1);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
