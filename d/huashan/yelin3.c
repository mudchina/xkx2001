//Cracked by Roath
// 华山荒山３
// qfy 26/6/1996

inherit ROOM;

void create()
{
        set("short", "荒山旷地");
	set("long", @LONG
这是华山后山的一片荒山旷地，四周都是一株株高巨无比的大树。
左侧是一面石壁，有个山洞。
LONG
        );
        set("exits", ([ /* sizeof() == 6 */
  		"enter" : __DIR__"shandong3",		
		"east" : __DIR__"yelin2",
  		"west" : __DIR__"yelin2",
	        "southeast" : __DIR__"yelin2",
       	 	"southwest" : __DIR__"yelin2",
	]));

	set("cost", 2);
        setup();
}
