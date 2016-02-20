//Cracked by Roath
// Room: /d/qilian/lanzhou.c

inherit ROOM;

void create()
{
	set("short", "兰州");
	set("long", @LONG
西北第一大城，既是西北的经济中心，也是文化中心。兰州的文化集
各家丰采，既有传统的释、道、儒三家影响，也有回教的投影，比起京城、
扬州，细腻稍有不足，但飞扬之势却有过之。
LONG
	);
	set("no_clean_up", 0);
	set("cost", 2);
	set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/xlama" : 1,
  "/d/taishan/npc/shu-sheng" : 1,
  "/kungfu/class/wudang/daotong" : 1,
]));
	set("outdoors", "qilian-shan");
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"lanzhou-beimen",
  "east" : __DIR__"dangpu",
  "west" : __DIR__"weststreet",
  "south" : __DIR__"lanzhou-nanmen",
  "northeast" : __DIR__"biaoju",
]));

	setup();
	replace_program(ROOM);
}
