//Cracked by Roath
// Room: /d/beijing/east/dianmen.c

inherit ROOM;

void create()
{
	set("short", "地安门");
	set("long", @LONG
地安门是皇城的后门，与皇城正面的天安门遥遥相对，虽
不如天安门气势恢宏，但红墙高耸，黄色琉璃瓦闪闪发光，富
丽堂皇，威严肃穆兼而有之。再往南就是紫禁城了，普通百姓
是不能靠近的。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"zhaoyangdajie2",
  "south" : __DIR__"shouhuangdian",
  "north" : "/d/beijing/west/gulou",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
