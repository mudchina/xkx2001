//Cracked by Roath
// baza 巴扎
// maco 2/17/2000

inherit ROOM;

void create()
{
	set("short", "大巴扎");
	set("long", @LONG
在维吾尔族中，无论大小市集都称之为「巴扎」，每逢巴扎日
，男女老少，无不穿戴整齐，或者骑马乘驴，或是驾车牵骆，抑或
徒手步行，从附近数十里的地方来赶巴扎，买卖各种土产商品，巴
扎上车水马龙，叫卖声不绝於耳。
LONG
	);
	set("exits", ([ 
	    "southwest" : __DIR__"shule",
            "east" : __DIR__"baza2",
            "west" : __DIR__"baza3",
	]));
	set("objects", ([ 
	    "/d/xingxiu/npc/amite" : 1,
	    "/d/xingxiu/npc/w-girl" : 1,
	]) );
	set("outdoors","xingxiuhai");

	set("cost", 1);
	setup();
}
