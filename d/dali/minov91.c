//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov91.c

inherit ROOM;

void create()
{
	set("short", "乌蒙村落");
	set("long", @LONG
这里是山的缓坡，乌夷人搬石去土，把这里修成一层一层阶梯状的平台，民
居分别建在各处平台上，互不连接，各自有石砌围墙，村中道路也由石头铺成。
LONG);
	set("exits", ([
		"north" : __DIR__"minov92",
		"south" : __DIR__"minov93",
		"westdown" : __DIR__"minov89",
		"eastup" : __DIR__"minov94",
		]));
	set("area", "乌弄城");
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}
