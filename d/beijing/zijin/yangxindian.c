//Cracked by Roath
// Room: /d/beijing/zijincheng/yangxindian.c

inherit ROOM;

void create()
{
	set("short", "养心殿");
	set("long", @LONG
皇帝多在这里居住和进行日常活动。正厅设有宝座，御案。宝座
后面有一排书架，藏有历代皇帝有关治国的经验，教训的著述。一些
官员在提拔，调动之前常被领到这里觐见皇帝。西间是皇帝批阅奏折，
以及同大臣商量国事的地方。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"yongshougong",
  "east" : __DIR__"neiyoumen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
