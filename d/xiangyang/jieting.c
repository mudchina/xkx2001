//Cracked by Roath
// Room: /d/xiangyang/jieting.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIW "洁亭" NOR);
	set("long", @LONG
进入庭院，绕过镂空攀蔓的屏风，是装点园林德怪石群；穿过题有“墨园
觅境”的牌坊，一座翘角飞檐的小亭—“洁亭”出现眼前。亭前立有“米家山
水”、“米氏故”的两块石碑，祠内挂着石刻拓橡，陈列着米氏父子生平简
介。院内四壁嵌着米芾父子及黄庭坚、蔡襄、赵孟俯等人的手迹。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"migongci",
]));

	setup();
	replace_program(ROOM);
}
