//Cracked by Roath
// xiakedao/guangchang.c
// modified by aln  5 / 98

inherit __DIR__"no_pk_room";

void create()
{
        set("short", "广场");
        set("long", @LONG
眼前突然开阔，这是个能容下上千人的大广场。各色信标旗帜遍
插四周，在风中猎猎飞舞，煞是好看。相隔不远即有青衣弟子按剑侍
立，面无表情。广场中摆满了桌子(table)和椅子(chair)，几位黄衣仆人
正在前后照应。
LONG );

        set("exits", ([
      	        "south" : __DIR__"xiaolu",
		"north" : __DIR__"guangchang",
        ]));

	set("item_desc",([
	    "" : "\n",
	]));

	set("outdoors", "xiakedao" );
	set("cost", 0);

	setup();
}
