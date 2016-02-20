//Cracked by Roath
// Room: /d/beijing/zijincheng/qianqinggong.c

inherit ROOM;

void create()
{
	set("short", "乾清宫");
	set("long", @LONG
这是皇帝的寝宫，皇后在此居住，其他妃嫔可以按照皇帝的召唤
进御，后来皇帝也有时在此召见臣工，临朝听政，引见庶僚，接见外
国使臣以及读书学习披阅奏章等。
在宫门的正上方悬挂着一块大匾(bian).
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"yard1",
  "north" : __DIR__"jiaotaidian",
  "westdown" : __DIR__"maoqindian",
  "eastdown" : __DIR__"yuchafang",
]));
	set("item_desc", ([ /* sizeof() == 1 */
  "bian" : "匾上写着「正大光明」四个大字。清朝皇帝将继承人的
名字密写两份，一份带在身边，一份封在建储匣内，放到
乾清宫「正大光明」匾的后面，皇帝死后由顾命大臣共同
打开身边密藏的一份和建储匣，会同廷臣宣布即位皇子。
",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
