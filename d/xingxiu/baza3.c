//Cracked by Roath
// baza 巴扎
// maco 2/17/2000

inherit ROOM;

void create()
{
	set("short", "巴扎西侧");
	set("long", @LONG
这儿是巴扎的西边，贩卖的货品有类、面粉、骆驼、牛羊、
香料、皮革、木材等等。散居各地的维族商旅与农夫牧人都会在此
赶集交易，人潮络绎不绝。
LONG
	);
	set("exits", ([ 
            "east" : __DIR__"baza1",
	]));
	set("objects", ([ 
	    "/d/xingxiu/npc/zaierger" : 1,
//	    "/d/xingxiu/npc/w-girl" : 1,
	]) );
	set("outdoors","xingxiuhai");

	set("cost", 1);
	setup();
}
