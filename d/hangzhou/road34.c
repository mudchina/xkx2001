//Cracked by Roath
// Room: /d/hangzhou/road34.c
// modified by aln  2 / 98

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
大道上挤满了来灵隐寺上香和上飞来峰的游客。北边过了小溪就
是灵隐寺了。南边是上飞来峰的路。
LONG
	);
	set("cost", 1);
	set("outdoors", "hangzhou");
	set("exits", ([ /* sizeof() == 4 */
        	"east" : __DIR__"road33",
                "south" : __DIR__"feilai0",
                "westup" : __DIR__"lingyin0",
        ]));

	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
