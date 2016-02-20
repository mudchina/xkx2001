//Cracked by Roath
// Ryu, 5/10/97

inherit ROOM;
string look_bei();
void create()
{
	set("short", "果子沟");
	set("long", @LONG
果子沟的野果树，主要分布在头台附近的几十道山岭上，所以头台
的花最多最艳。那五色的野果花，顺着山坡一溜儿往上开，一树树，一
簇簇，红艳艳，白闪闪，直上山顶，与天上的彩云连接，千姿百态，如
锦缎，似朝霞。几里地外也能闻到馥郁的花香。沟底有块小小石碑(bei)。
LONG
	);
	set("exits", ([
                "east" : __DIR__"ertai",
                "northup" : __DIR__"tianchi",
        ]));
	set("objects", ([
		"/d/city/npc/obj/apple" : 1,
		"/d/wudang/obj/mitao" : 1,
		"/d/city/npc/obj/pear" : 1,
		"/d/xingxiu/obj/hamigua" : 1,
	]));
	set("item_desc",([
                "bei"         :       (: look_bei :),
        ]));
	set("cost", 2);
	set("outdoors", "tianshan");

	setup();
}
string look_bei()
{
        return
        "\n"
        "                   不    树    地\n\n"
	"                   露    阴    皆\n\n"
	"             耶    日    蓊    林\n"
	"             律		  \n"
	"             楚    色    郁    檎\n"
	"             才                  \n";
}
