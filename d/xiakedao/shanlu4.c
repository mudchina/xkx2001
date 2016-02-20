//Cracked by Roath
// xiakedao/shanlu4.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";

void create()
{
        set("short", "山路");
        set("long", @LONG
这是通往山顶的小路，路旁杂草丛生，夹杂着一些不知名的野花。
四周静悄悄地没有人声。你深深吸口气，一阵山野的芬芳直入心扉。
LONG );

      set("exits", ([
		"westup" : __DIR__"shanding",
		"northdown"  : __DIR__"shanxia",
      ]));
      set("no_clean_up", 1);
	set("objects", ([ 
          "/d/city/obj/branch4" : 1,
      ]));
	
	set("outdoors", "xiakedao" );
	set("cost", 2);
	setup();
}

