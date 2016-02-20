//Cracked by Roath
// Room: /d/xixia/center.c

inherit ROOM;

void create()
{
	set("short", "城中心");
	set("long", @LONG
这里是西夏都城灵州的中心广场，也是四条大街的交汇处，北面
是皇城，南面是商业繁华地段，西面是普通商人区和骠骑营，东面衙
门和王公贵族们的府第。灵州是西域最大的物资集散地和商业中心，
也是西域通往中原的必经之地。各色人等来来往往，马嘶人喊，热闹
非凡，广场空地上卖艺的、要饭的、大腹便便的财主、提笼携鸟的王
公贵戚到处都是，偶尔也有行色匆匆的江湖人士一晃而过。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"nandajie",
  "west" : __DIR__"xidajie",
  "north" : __DIR__"beidajie",
  "east" : __DIR__"dongdajie",
]));
	set("no_clean_up", 0);
	set("outdoors", "xixia");
	set("cost", 1);
	setup();
	replace_program(ROOM);
}
