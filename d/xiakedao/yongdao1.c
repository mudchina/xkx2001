//Cracked by Roath
// xiakedao/yongdao1.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";

void create()
{
        set("short", "甬道");
        set("long", @LONG
这是一条长长的甬道，两侧墙上点着油灯，光线虽暗，道路却也
清晰可辨。外面瀑布轰轰之声不绝于耳，洞口水花飞溅，地上甚是湿
滑。面前有几条岔道。
LONG );

      set("exits", ([
		"north" : __DIR__"yongdao4",
		"south" : __DIR__"yongdao2",
		"east" : __DIR__"yongdao3",
      	"out" : __DIR__"pubu",
      ]));

	set("indoors", "xiakedao" );
	set("cost", 2);
	setup();
}

