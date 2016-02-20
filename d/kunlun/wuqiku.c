//Cracked by Roath
// Room: /d/mingjiao/wuqiku.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "武器库");
	set("long", @LONG
这里是一间不小的房间，屋里一排排整齐的摆放着架子，架上或放，
或靠，或摆，或挂不少兵器，十八般兵刃样样具全，还有不少大铁锤。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"shanlu28",
]));
	set("objects",([
		__DIR__"npc/wujincao" : 1,
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
