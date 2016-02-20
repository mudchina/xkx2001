//Cracked by Roath
// Room: /d/mingjiao/shmen.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "圣火门");
	set("long", @LONG
一条青石铺成的大路笔直的通到一座血红高墙下，路两边整齐的排列
着两排巨松。松前摆置着数尊青石怪兽(guaishou)，更添威武。血墙正中
是一高大宽门。门外包有铁皮，间隔有序的布满了拳头大小的铜钉，阳光
一照，闪闪发光。大门两旁各有一小门，供弟子夜晚出入。
LONG
);
	set("item_desc",([
		"guaishou" : "一人多高的石兽雕得张牙舞爪，看模样不像中土之物。\n",
	]));
	set("exits", ([ /* sizeof() == 4 */
  "southdown" : __DIR__"daguangchang",
  "west" : __DIR__"guangchang70",
  "enter" : __DIR__"shting",
  "east" : __DIR__"guangchang74",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
