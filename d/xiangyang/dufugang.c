//Cracked by Roath
// Room: /d/xiangyang/dufugang.c

inherit ROOM;

void create()
{
	set("short", "杜甫岗");
	set("long", @LONG
 你到得一座小山之上，升崖远眺，但见汉水浩浩南流，四郊遍野都是难民
，拖男带女的涌向襄阳。从山上望下去，见道旁有块石碑，碑上刻着一行大字
：“唐工部郎杜甫故”。
LONG
	);
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : 0, "y" : 11 ]) );
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"aozhan",
  "southdown" : __DIR__"migonglu",
]));
	set("outdoors", "xiangyang");
	setup();
	replace_program(ROOM);
}
