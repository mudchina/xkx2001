//Cracked by Roath
// Room: /d/xixia/xiaoba.c

inherit ROOM;

void create()
{
	set("short", "小坝");
	set("long", @LONG
这里是黄河边的一条小支流大柳河与黄河汇合的地方，当地百姓为了防止黄
河的泥沙倒灌进大柳河而在这里修了一座小小的石坝，小坝不高，有三孔泄沙的
洞，一扇结实的石闸门，两边是绞盘用来控制闸门的升降。小坝使得大柳河两岸
的百姓免受了黄河泥沙的侵扰。
LONG
	);
	set("cost", 2);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"hytan",
  "southwest" : __DIR__"qtxia",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
