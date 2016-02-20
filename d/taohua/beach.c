//Cracked by Roath
//Chaos, Ryu, 3/10/97

inherit ROOM;

void create()
{
	set("short", "海滨");
	set("long", @LONG
这里是一片空阔的海滩。一面是海，一面是一片桃花林。一些大青石东一块，
西一块的散放在海滩上。北面是一座高台。
LONG
	);
	 set("exits", ([
                "west" : __DIR__"citeng",
                "northup" : __DIR__"guanchao",
        ]));
	 
	set("objects", ([
                __DIR__"obj/shizi" : 3,
        ]));
	
	set("cost", 2);
	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}
