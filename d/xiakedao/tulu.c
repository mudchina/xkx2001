//Cracked by Roath
// xiakedao/tulu.c
// modified by aln  5 / 98
// Ssy

inherit __DIR__"no_pk_room";

void create()
{
        set("short", "土路");
        set("long", @LONG
一条踩出来的黄土小路，阵阵尘土飞扬，你不得不眯起眼睛。路
面也不甚平坦，土块石子在脚下磕磕绊绊。路旁的果树结实累累，几
个小男孩正爬上爬下地摘果子吃。
LONG );

      set("exits", ([
		     "east" : __DIR__"caodi",
		     "west" : __DIR__"wanghait",
      ]));

	set("outdoors", "xiakedao" );
	set("cost", 2);

	setup();
}
