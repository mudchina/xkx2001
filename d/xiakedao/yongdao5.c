//Cracked by Roath
// xiakedao/yongdao5.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";

void create()
{
        set("short", "甬道");
        set("long", @LONG
下了数级石阶，这里的甬道较为宽阔。地上平铺着厚重的石砖，
踩上去脚步声颇为沉闷。四下洒扫得一尘不染，石壁上有些凹下的小
坑，其中是点燃的油灯。东面人声喧哗，不时传出阵阵轰笑。
LONG );

      set("exits", ([
		"north" : __DIR__"yongdao2",
		"east" : __DIR__"xianliao",
		"west" : __DIR__"bingqi",
		"south" : __DIR__"liangong",
      ]));

	set("indoors", "xiakedao" );
	set("cost", 0);
    	set("objects", ([ 
		__DIR__ +"npc/xingxiu" : 1, 
    	]));

	setup();
}


