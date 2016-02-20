//Cracked by Roath
// Room: /d/xixia/majiu.c

inherit ROOM;

void create()
{
	set("short", "马厩");
	set("long", @LONG
这里是骠骑营的马厩，清一色的蒙古高头战马。西夏军中多是骑
兵，所以行军作战来去如风，快若闪电，西夏铁骑的彪悍连大辽的骑
兵都颇有不如。骠骑营的战马俱是精选，膘肥体壮，马夫们正给马槽
里添黑豆和草料，一股马粪味和草料的混合味道飘了过来。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"biaoqiyin",
]));
	set("no_clean_up", 0);
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}
