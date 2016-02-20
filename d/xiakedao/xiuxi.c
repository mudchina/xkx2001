//Cracked by Roath
// xiakedao/xiuxi.c
// modified by aln  5 / 98

inherit __DIR__"no_pk_room";

void create()
{
        set("short", "休息室");
        set("long", @LONG
山洞里只点着一个小油灯，灯光昏暗。几张床依次排开，上面有
人迷迷糊糊地躺着。一张靠里面的床还空着，如果你累了，就可以在
这里睡觉(sleep)。墙上好象贴着一张小条子(tiaozi)。
LONG );

      set("exits", ([
      	"east" : __DIR__"yongdao4",
      ]));
	set("sleep_room", 1);
	set("no_fight", 1);

	set("item_desc",([
	    "tiaozi" : 
"最近发现，经常有小人乘他人沉睡时偷东西，所以请切记，如有贵重
东西千万小心。\n",
	]));

	set("cost", 0);
	setup();
}
