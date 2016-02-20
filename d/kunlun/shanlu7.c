//Cracked by Roath
// Room: /d/mingjiao/shanlu7.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这是一条弯弯曲曲的小山路，两边种满了绿竹，路边偶而开着几朵喇
叭花。绿竹挡住两边昆仑山的美景，透过竹林，只能隐隐看到被云雾环绕
的山峰。
LONG
	);
	set("outdoors", "mingjiao");
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"yongdao",
  "west" : __DIR__"qingshilu1",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
