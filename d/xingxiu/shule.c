//Cracked by Roath
// shule.c 疏勒
// maco 2/17/2000

inherit ROOM;

void create()
{
	set("short", "疏勒");
	set("long", @LONG
疏勒是汉代西域三十六国之一，张骞通使西域时就曾远达到此，西
汉设西域都护府、东汉初班超两次到西域，就是以疏勒为大本营。丝路
南北路在此交会，西去东来的商旅都在此驻留休息，因而也是文化荟萃
之地，古迹、名胜与文化遗产丰盛，周围的巴扎充满浓的西域情调。
LONG
	);
	set("exits", ([ 
	    "south" : __DIR__"caoyuan4",
	    "west" : __DIR__"qingzhensi",
	    "north" : __DIR__"huyang5",
	    "northeast" : __DIR__"baza1",
	]));
	set("objects", ([ 
	    "/d/xingxiu/npc/kid" : 1,
	    "/d/xingxiu/npc/w-girl" : 1,
	]) );
	set("outdoors","xingxiuhai");

	set("cost", 1);
	setup();
}
