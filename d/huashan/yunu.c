//Cracked by Roath
// 华山玉女峰
// modified by qfy 26/6/1996

inherit ROOM;

void create()
{
        set("short", "玉女峰");
	set("long", @LONG
这里是华山的中峰，玉女峰。玉女峰地势略为平缓，不似其它四峰般
险峻，江湖上赫赫有名的华山剑派就在此处。东边有所小小的庙宇，那就
是玉女祠了。南面稀稀落落有十几间房子，是华山派的地方，闲杂游客最
好别往那里去。
LONG
        );
        
	set("exits", ([ /* sizeof() == 4 */
  	 	"northdown" : __DIR__"zhenyue",
  		"east" : __DIR__"yunuci",
  		"south" : __DIR__"square",
  		"northup" : __DIR__"shanlu1",
		"westdown" : __DIR__"xiaolu1", 
	]));
	
	set("objects", ([
		__DIR__"npc/s-houzi" : 2,
		__DIR__"npc/b-houzi" : 1,
		"/clone/obj/car" : 1,
	]));

        set("no_clean_up", 0);
        set("outdoors", "xx" );

	set("cost", 3);
        setup();
        replace_program(ROOM);
}
