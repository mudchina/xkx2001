//Cracked by Roath
// 华山荒山野林１
// qfy 26/6/1996

inherit ROOM;

void create()
{
        set("short", "荒山野林");
	set("long", @LONG
这是华山后山的一片荒山野林，四周都是一株株高巨无比的大树。大
树茂密的枝叶，互相交织着，是以阳光难以渗透，使人有不辨天日之感。
右侧是一面石壁，长满了迷迷麻麻的山藤。但仔细一看，山藤缝隙间隐约
露出空间，似乎是个山洞。
LONG
        );
        set("exits", ([ /* sizeof() == 6 */
  		"enter" : __DIR__"shandong2",		
		"east" : __DIR__"yelin2",
  		"west" : __DIR__"yelin2",
	        "southeast" : __DIR__"yelin2",
       	 	"southwest" : __DIR__"yelin2",
	]));

	set("cost", 4);
        setup();
}
