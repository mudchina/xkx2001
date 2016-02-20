//Cracked by Roath
// xiakedao/xiaolu.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";

void create()
{
        set("short", "小路");
        set("long", @LONG
这是一条普通的石子路，路面碎石随意地组合着，显出淡淡的图
案。
LONG );

      set("exits", ([
		     "south" : __DIR__"shanxia",
		     "east" : __DIR__"jiaoshi1",
      ]));

	set("outdoors", "xiakedao" );
	set("cost", 0);
	set("objects", ([ 
          "/d/city/obj/branch3" : 1,
      ]));
	setup();
}
