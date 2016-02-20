//Cracked by Roath
// xiakedao/xiaolu2.c
// ssy

inherit __DIR__"no_pk_room";

void create()
{
        set("short", "小路");
        set("long", @LONG
走在青石铺成的小路上，脚步十分轻捷。西边隐约可见大海，东
边则是一条山路。小路两旁都是密林，枝叶遮天蔽日，林中鸟雀叽喳，
与呼呼的风声混成一片。
LONG );

      set("exits", ([
		     "south" : __DIR__"ybting",
		     "north" : __DIR__"wanghait",
		     "eastup"  : __DIR__"shanlu3",
		     "west":__DIR__"haibian2",
      ]));

	set("outdoors", "xiakedao" );
	set("cost", 2);
	set("objects", ([ 
	    __DIR__ + "npc/dahan" : 1,
          "/d/city/obj/branch1" : 1,
          "/d/city/obj/branch2" : 1,
      ]));

	setup();
}
