//Cracked by Roath
// xiakedao/shufang.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";

void create()
{
        set("short", "书房");
        set("long", @LONG
这是侠客岛的书房，房里是几个直达屋顶的大书架，上面摆满了
书。这些书均是岛主从各地高价搜罗而来。诗词书画，武学秘典，无
所不包。一位老者正在随意翻阅，看见你进来放下书迎了过来。
LONG );

      set("exits", ([
		"west" : __DIR__"yongdao4",
      ]));
	set("objects", ([	
		__DIR__ + "npc/xueshi" : 1,
	]));
	set("indoors", "xiakedao" );
	set("cost", 0);
	setup();
}
