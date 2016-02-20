//Cracked by Roath
// baza 巴扎
// maco 2/17/2000

inherit ROOM;

void create()
{
	set("short", "巴扎东侧");
	set("long", @LONG
这儿是巴扎的东头，各式各样的土产、蔬果、工艺品，应有尽
有。巴札中人山人海，万头钻动，到处是叫卖声、讨价声、赶驴声。
LONG
	);
	set("exits", ([ 
            "west" : __DIR__"baza1",
	]));
	set("objects", ([ 
	    "/d/xingxiu/npc/aixihan" : 1,
//	    "/d/xingxiu/npc/w-girl" : 1,
	]) );
	set("outdoors","xingxiuhai");

	set("cost", 1);
	setup();
}
