//Cracked by Roath
//Chaos, Ryu, 3/10/97

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这是一条平缓的山路，你慢慢向上行去，山路两旁种植着松柏桦之类的高大乔木，
间杂以各种罕见药草，如灵芝、首乌之类。越往上行，山路越见陡峭，但幸好还不算
太难走。
LONG
	);
	 set("exits", ([
                "south" : __DIR__"citeng",
                "northup" : __DIR__"shanlu2",
        ]));
	set("cost", 3);
	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}
