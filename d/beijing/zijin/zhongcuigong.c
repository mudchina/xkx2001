//Cracked by Roath
// Room: /d/beijing/qianqing/jinghemen.c

inherit ROOM;

void create()
{
    set("short", "钟粹宫");
	set("long", @LONG
东六宫之一,这是明清两代后妃们居住的地方.咸丰幼年时曾随
母亲孝全成皇后在此宫殿,以后慈安太后也在这住过.

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east"  : __DIR__"gzxd10",
  "west" : __DIR__"tongdao6",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
