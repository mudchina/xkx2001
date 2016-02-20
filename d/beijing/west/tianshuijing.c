//Cracked by Roath
// Room: /d/beijing/west/tianshuijing.c

inherit ROOM;

void create()
{
	set("short", "甜水井胡同");
	set("long", @LONG
这条胡同虽不起眼，但因为胡同里有一口甜水井而得名。北京城中
水井都出苦水，甜水井极少。紫禁城里用水都要每天去玉泉山运回，这
几口不多的甜水井就对北京城普通百姓尤为重要。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"youandajie",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
