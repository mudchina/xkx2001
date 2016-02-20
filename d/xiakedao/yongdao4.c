//Cracked by Roath
// xiakedao/yongdao4.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";

void create()
{
        set("short", "甬道");
        set("long", @LONG
这里甬道略显狭窄，仅容两人并肩而过。顶壁也甚是低矮，伸手
便可触及。油灯晃动，在身后拉出长长的阴影；脚步踢嗒，甬道彼端
响起阵阵回声，感觉有些异样。
LONG );

      set("exits", ([
		"west" : __DIR__"xiuxi",
		"south" : __DIR__"yongdao1",
		"east" : __DIR__"shufang",
		"north" : __DIR__"yangxinju",
      ]));

	set("indoors", "xiakedao" );
	set("cost", 0);
    	set("objects", ([ 
		__DIR__ +"npc/dali" : 1, 
    	]));

	set("no_clean_up", 1);
	setup();
}

