//Cracked by Roath
// Room: /d/xiangyang/aozhangang.c

inherit ROOM;

void create()
{
	set("short", "鏖战岗");
	set("long", @LONG
 你到得一座小山之上，升崖远眺，但见汉水浩浩南流，四郊遍野都是难民
，拖男带女的涌向襄阳。从山上望下去，见道旁有块石碑，碑上刻着一行大字
：“唐工部郎杜甫故”。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"dufugang",
  "westdown" : __DIR__"dengcheng",
]));

	setup();
	replace_program(ROOM);
}
