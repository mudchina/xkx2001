//Cracked by Roath
// Room: /d/xixia/xiaolou.c

inherit ROOM;

void create()
{
	set("short", "小楼");
	set("long", @LONG
这是一幢三层楼的木制建筑。端的是金碧辉煌，气象万千。赫连铁树
住在这里。底层是一排落地长窗和朱红色的圆柱。二楼有个小阳台，三楼
楼顶的琉璃瓦在阳光下闪闪发光，和皇城大殿的金顶同为全城都可看到的
建筑。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"jjdayuan",
]));
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/yahuan" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
