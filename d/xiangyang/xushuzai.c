//Cracked by Roath
// Room: /d/xiangyang/xushuzai.c

inherit ROOM;

void create()
{
	set("short", "徐庶宅");
	set("long", @LONG
相传三国时徐庶曾因替人报仇，失手杀人，就擒後脱逃，更名“单福”流寓
於此。这间大屋共前後两院三进。四周数树木苍苍，二条水渠贴墙基而过，显得
十分清幽。大院内立一徐庶像(xiang)，前立一大巨碑(bei)。
LONG
	);
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : -12, "y" : -2 ]) );
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"qilidian",
]));
	set("item_desc", ([
		"xiang" : "抬头看时，见那塑像葛巾布袍，皂绦乌履，相貌甚是清癯。\n",
		"bei" : "大碑上刻着“汉徐庶故”五字。\n",
	]));
	setup();
	replace_program(ROOM);
}
