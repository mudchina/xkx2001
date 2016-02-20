//Cracked by Roath
// husun.c

inherit ROOM;

void create()
{
        set("short", "猢狲愁");
	set("long", @LONG
前面又是一处十分陡峭的山岭，上面有四只铁猿，盘踞台畔，据说以
前从华山水帘洞出来的猿猴，每到这里就要返回去，连它们也感到难于超
越，此岭因而得名。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  		"northdown" : __DIR__"laojun",
  		"southup" : __DIR__"canglong",
	]));
	
	set("objects", ([
	         __DIR__"npc/s-houzi" : 2,
	         __DIR__"npc/b-houzi" : 2,
	]));         
	
        set("no_clean_up", 0);
        set("outdoors", "xx" );

	set("cost", 6);
        setup();
        replace_program(ROOM);
}
 
