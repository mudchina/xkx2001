//Cracked by Roath
// Room: /d/beijing/zijincheng/taihedian.c

inherit ROOM;

void create()
{
	set("short", "太和殿 ");
	set("long", @LONG
俗称金銮殿，又称奉天殿，皇极殿，是皇帝举行典礼的大殿。殿
高35米，面积2370多平方米。镂金砌玉，十分豪华。这里平时是不
用的,主要用于举行盛大典礼,包括皇帝即位,皇帝大婚,册立皇后,命将
出征,以及每年元旦,冬至,万寿(皇帝生日)三大节受文武百官超贺及赐
宴等。

这就是举世皆知的太和殿。 它是当今万岁召见百官和接受外国贡
礼的场所。 在九阶白玉的台阶上， 皇上坐在金色的龙椅(chair) 上，
俯视众臣。 四名带刀侍卫小心的注意任何可能发生的情况。 群臣匍俯
在地，三呼 "万岁！ 万岁！ 万万岁！"。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"zhonghedian",
  "south" : __DIR__"guang1",
]));
	set("item_desc", ([ /* sizeof() == 1 */
  "chair" : "这是一张宽大红木龙椅， 椅背上雕着九龙戏珠的 
图案。 你仔细一看， 这颗珠子竟然是夜明珠。
",
]));
	set("objects", ([ /* sizeof() == 1 */
  "/d/beijing/npc/long" : 1,
]));
	set("no_clean_up", 0);
	set("valid_startroom", 1);

	setup();
	replace_program(ROOM);
}
